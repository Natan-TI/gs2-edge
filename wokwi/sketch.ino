#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

const char *SSID = "Wokwi-GUEST";
const char *PASSWORD = "";

// Configurações de MQTT
const char *BROKER_MQTT = "mqtt.tago.io";
const int BROKER_PORT = 1883;
const char *ID_MQTT = "natan";
const char *USERNAME = "";  // Deixe em branco se não for usar um nome de usuário MQTT
const char *PASSWORD_MQTT = "f2b9963e-8b14-4a67-9c8d-5ea8d440e0c5";  // Adicione a senha aqui
const char *TOPIC_SEND_VARIABLE = "tago/data/post";  // Tópico para enviar as variáveis

// Variáveis globais
WiFiClient espClient;
PubSubClient MQTT(espClient);
unsigned long publishUpdate = 0;
const int TAMANHO = 200;
#define PUBLISH_DELAY 1000    // delay
int qual = 0;

// Hardware
const int buttonSaida1 = 18; // Pino do primeiro botão de saída
const int buttonEntrada1 = 19; // Pino do primeiro botão de entrada

const int buttonSaida2 = 23; // Pino do segundo botão de saída
const int buttonEntrada2 = 5; // Pino do segundo botão de entrada

int buttonStateEntrada1, buttonStateSaida1, buttonStateEntrada2, buttonStateSaida2 = 0;
int count1, count2 = 0;


void initWiFi() {
  Serial.print("Conectando com a rede: ");
  Serial.println(SSID);
  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Conectado com sucesso: ");
  Serial.println(SSID);
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void initMQTT() {
  MQTT.setServer(BROKER_MQTT, BROKER_PORT);
}

void reconnectMQTT() {
  while (!MQTT.connected()) {
    Serial.print("Tentando conectar com o Broker MQTT: ");
    Serial.println(BROKER_MQTT);

    if (MQTT.connect(ID_MQTT, USERNAME, PASSWORD_MQTT)) {
      Serial.println("Conectado ao broker MQTT!");
    } else {
      Serial.println("Falha na conexão com MQTT. Tentando novamente em 2 segundos.");
      delay(2000);
    }
  }
}

void checkWiFIAndMQTT() {
  if (WiFi.status() != WL_CONNECTED) reconnectWiFi();
  if (!MQTT.connected()) reconnectMQTT();
}

void reconnectWiFi(void)
{
  if (WiFi.status() == WL_CONNECTED)
    return;

  // Conecta na rede WI-FI
  WiFi.begin(SSID, PASSWORD); 

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Wifi conectado com sucesso");
  Serial.print(SSID);
  Serial.println("IP: ");
  Serial.println(WiFi.localIP());
}

int countPeople(int count, int entrada, int saida) {
  if (entrada == HIGH) {
    count++;
  }  
  if (saida == HIGH && count > 0) {
    count--;
  }
  return count;
}

void setup() {
  Serial.begin(115200);
  pinMode(buttonSaida1, INPUT);
  pinMode(buttonEntrada1, INPUT);
  pinMode(buttonSaida2, INPUT);
  pinMode(buttonEntrada2, INPUT);
  initWiFi();
  initMQTT();
}

void loop() {
  checkWiFIAndMQTT();
  MQTT.loop();

  delay(1000);
  buttonStateEntrada1 = digitalRead(buttonEntrada1);
  buttonStateSaida1 = digitalRead(buttonSaida1);
  buttonStateEntrada2 = digitalRead(buttonEntrada2);
  buttonStateSaida2 = digitalRead(buttonSaida2);

  count1 = countPeople(count1, buttonStateEntrada1, buttonStateSaida1);
  count2 = countPeople(count2, buttonStateEntrada2, buttonStateSaida2);

  delay(500);
  Serial.print("Hospital 1: ");
  Serial.println(count1);
  Serial.print("Hospital 2: ");
  Serial.println(count2);

  if (count1 > count2) {
    qual = 2;
  } else {
    qual = 1;
  }

  if ((millis() - publishUpdate) >= PUBLISH_DELAY) {
    publishUpdate = millis();
    if (!isnan(count1) && !isnan(count2)) {
      StaticJsonDocument<TAMANHO> doc_hospital1;
      doc_hospital1["variable"] = "hospital1";
      doc_hospital1["unit"] = " pessoas";
      doc_hospital1["value"] = count1;

      StaticJsonDocument<TAMANHO> doc_hospital2;
      doc_hospital2["variable"] = "hospital2";
      doc_hospital2["unit"] = " pessoas";
      doc_hospital2["value"] = count2;

      StaticJsonDocument<TAMANHO> qualHospital;
      qualHospital["variable"] = "lotacao";
      qualHospital["value"] = qual;

      

      char buffer_pessoas1[TAMANHO];
      serializeJson(doc_hospital1, buffer_pessoas1);
      MQTT.publish(TOPIC_SEND_VARIABLE, buffer_pessoas1);
      Serial.println(buffer_pessoas1);

      char buffer_pessoas2[TAMANHO];
      serializeJson(doc_hospital2, buffer_pessoas2);
      MQTT.publish(TOPIC_SEND_VARIABLE, buffer_pessoas2);
      Serial.println(buffer_pessoas2);

      char buffer_qual[TAMANHO];
      serializeJson(qualHospital, buffer_qual);
      MQTT.publish(TOPIC_SEND_VARIABLE, buffer_qual);
      Serial.println(buffer_qual);

    }
  }
}
