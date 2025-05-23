//* Aula 82 comunicacao IOT
#include <Arduino.h>
#include "internet.h"
#include <PubSubClient.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include <DHT.h>
#define TEMPORIZADOR_H


const char *mqtt_server = "broker.hivemq.com";                 // nome do servodor
const int mqtt_port = 1883;                                    // porta de acesso mqtt,
const char *mqtt_client_id = "gabs1.2";                        // nome do esp
const char *mqtt_topic_sub = "senai134/mesa04/gabs1.2/espsub"; // servidor para receber mensagem
const char *mqtt_topic_pub = "senai134/mesa04/gabs1.2/esppub"; // publicar

WiFiClient espClient;           // dar nome do acesso de objeto wifi
PubSubClient client(espClient); // objeto denomeado
DHT dht(23, DHT22);

Temporizador cronometro(2000);  

void callback(char*, byte*, unsigned int); // callback, retona a mensagem recebido no topic
void conectarMQTT();

void setup() {
Serial.begin(9600);
dht.begin();
 
 conectaWiFi();
    client.setServer(mqtt_server, mqtt_port);
    client.setCallback(callback);
}

void loop() {
 checkWiFi();
    if (!client.connected())
    {
        conectarMQTT();
    }
    client.loop();
  static int estado = 0;  // variável para alternar entre 0 e 1

  if (cronometro.estaPronto()) {
    if (estado == 0) {
      client.publish(mqtt_topic_pub, "Mensagem A");
      estado = 1;
    } else {
      client.publish(mqtt_topic_pub, "Mensagem B");
      estado = 0;
    }
    cronometro.reiniciar();
  }
}





















void conectarMQTT()
{
    while (!client.connected())
    {
        Serial.print("conectando ao MQTT... ");
        if (client.connect(mqtt_client_id))
        {

            Serial.println("conectado!");
            client.subscribe(mqtt_topic_sub);
        }
        else
        {
            Serial.print("falha rc=");
            Serial.print(client.state());
            Serial.println("tentendo novamente em 5 segundos ");
            delay(5000);
        }
    }
}