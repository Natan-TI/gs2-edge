<h1 align="center">MedMaps - Global Solution - Edge</h1>
<img src="./images/circuito.png" width="900px;" alt="Foto do Projeto Arduino"/><br>
<img src="./images/dashboard.png" width="900px;" alt="Foto do Projeto Arduino"/><br>
<img src="./images/mqtt.png" width="900px;" alt="Foto do Projeto Arduino"/><br>
<img src="./images/variables.png" width="900px;" alt="Foto do Projeto Arduino"/><br>
  
## :link: `Links`
* Youtube: https://youtu.be/v5ge7pYHw2A
  <br>
* Wokwi: https://wokwi.com/projects/381664458690127873



## :memo: `Descrição do problema`

* A superlotação hospitalar resulta da imprevisibilidade na demanda por serviços de saúde, levando a picos repentinos de pacientes que sobrecarregam os recursos disponíveis. Isso causa distribuição inadequada de leitos, escassez de pessoal e congestionamento nas áreas de atendimento, impactando negativamente a qualidade e eficiência do cuidado médico. A falta de planejamento e estratégias preventivas agrava a situação, resultando em problemas de fluxo de pacientes e na dificuldade em lidar com emergências médicas de forma ágil e eficaz.

## :bulb: `Solução proposta`

* Nossa solução é um aplicativo inovador que permite aos usuários verificar a lotação dos hospitais em tempo real dentro de um determinado raio. Utilizando tecnologias de geolocalização, oferecemos informações detalhadas sobre a disponibilidade de leitos, ocupação e tempo de espera, capacitando os usuários a tomar decisões informadas sobre cuidados de saúde emergenciais ou planejados. Nossa aplicação visa proporcionar acesso rápido e preciso a informações vitais, contribuindo para uma melhor gestão da saúde e para a eficiência dos serviços hospitalares.


## :books: `Funcionalidades`

* <b>Função</b> `countPeople`: Verifica qual dos botões está pressionado, e adiciona ou decrementa 1 da variável "count"
  <br>
* <b>Botões de entrada</b>: Quando pressionado, adiciona uma pessoa na contagem.
  <br>
* <b>Botões de saída</b>:  Quando pressionado, remove uma pessoa da contagem.
  <br>
* <b>Dashboard</b>:  A informação de quantidades de pessoas no ônibus é armazenada e exibida num gráfico de volume

## :seedling: `Instruções de uso`

* Clonar repositório
  <br>
* Criar o projeto no Wokwi
  <br>
* Criar uma conta na Tago
  <br>
* Criar um device na Tago
  <br>
* Colar token e o user da Tago no código do Wokwi
  <br>
* Criar o dashboard
  <br>
* Rodar o programa

## :clipboard: `Requisitos`

* 1 ESP32
  <br>
* 4 Botões
  <br>
* Tago.io
  <br>
* Computador
  <br>
* Conexão Wifi

## :hammer: `Dependências`
* Biblioteca ArduinoJson, para enviar dados no formato JSON.
  <br>
* Biblioteca Wifi, para fazer a conexão do ESP32 com o wifi.
  <br>
* Biblioteca PubSubClient, para enviar dados via MQTT
  <br>
* Device na Tago.io

## :wrench: `Tecnologias utilizadas`

* ESP32;
  <br>
* C++;
  <br>
* Botões;
  <br>
* Tago.io;
  <br>
* MQTT;
  <br>
* JSON;


## :handshake: `Colaboradores`
<table>
  <tr>
    <td align="center">
        <sub>
          <b>Natan Eguchi dos Santos - RM98720</b>
          <br>
        </sub>
        <sub>
          <b>Kayky Paschoal Ribeiro - RM99929</b>
          <br>
        </sub>
    </td>
  </tr>
</table>

## :dart: `Status do projeto`
Em desenvolvimento :hourglass_flowing_sand: