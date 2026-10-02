#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <DHT.h>

// ================= CONFIGURACIÓN WIFI =================
const char* WIFI_SSID = "iPhone";
const char* WIFI_PASS = "20170051";

// ================= CONFIGURACIÓN MQTT =================
const char* MQTT_SERVER = "mqtt.rcr-labs.com";
const int MQTT_PORT = 1883;

const char* MQTT_USER = "alumno";
const char* MQTT_PASSWORD = "UPCH2026";
const char* CLIENT_ID = "ESP32_Equipo04";

// Topics MQTT
const char* TOPIC_PUB = "equipo04/sensor/datos";
const char* TOPIC_SUB = "equipo04/actuadores/led";

// ================= DHT11 =================
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// ================= OBJETOS Y VARIABLES =================
WiFiClient espClient;
PubSubClient client(espClient);

unsigned long ultimoEnvio = 0;
const long intervaloEnvio = 5000;

//conexión WiFi
void setupWiFi() {
  delay(10);

  Serial.println();
  Serial.print("Conectando a Wi-Fi: ");
  Serial.println(WIFI_SSID);

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado con éxito");
  Serial.print("Dirección IP local: ");
  Serial.println(WiFi.localIP());
}

//callback MQTT
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensaje recibido en topic [");
  Serial.print(topic);
  Serial.print("]: ");

  String mensaje = "";

  for (unsigned int i = 0; i < length; i++) {
    mensaje += (char)payload[i];
  }

  Serial.println(mensaje);

  if (String(topic) == TOPIC_SUB) {
    if (mensaje == "ON") {
      digitalWrite(2, HIGH);
      Serial.println("Comando: Encender LED");
    }
    else if (mensaje == "OFF") {
      digitalWrite(2, LOW);
      Serial.println("Comando: Apagar LED");
    }
  }
}

//reconexión MQTT
void reconnect() {
  while (!client.connected()) {

    Serial.print("Intentando conectar con broker MQTT...");

    if (client.connect(CLIENT_ID, MQTT_USER, MQTT_PASSWORD)) {

      Serial.println(" ¡Conectado!");

      client.subscribe(TOPIC_SUB);

      Serial.print("Suscrito a: ");
      Serial.println(TOPIC_SUB);

    } else {

      Serial.print(" Falló. Código de error rc=");
      Serial.print(client.state());

      Serial.println(" Reintentando en 5 segundos...");

      delay(5000);
    }
  }
}

void setup() {

  Serial.begin(115200);

  setupWiFi();

  client.setServer(MQTT_SERVER, MQTT_PORT);
  client.setCallback(callback);

  pinMode(2, OUTPUT);

  dht.begin();
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  unsigned long ahora = millis();

  if (ahora - ultimoEnvio >= intervaloEnvio) {

    ultimoEnvio = ahora;

    //leer DHT11
    float temperatura = dht.readTemperature();
    float humedad = dht.readHumidity();

    //comprobar si la lectura fue válida
    if (isnan(temperatura) || isnan(humedad)) {
      Serial.println("Error al leer el DHT11");
      return;
    }

    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" °C");

    Serial.print("Humedad: ");
    Serial.print(humedad);
    Serial.println(" %");

    //crear JSON
    StaticJsonDocument<200> doc;

    doc["dispositivo"] = CLIENT_ID;
    doc["temperatura"] = temperatura;
    doc["humedad"] = humedad;

    char jsonBuffer[256];

    serializeJson(doc, jsonBuffer);

    //publicar MQTT
    Serial.print("Publicando en ");
    Serial.print(TOPIC_PUB);
    Serial.print(": ");
    Serial.println(jsonBuffer);

    client.publish(TOPIC_PUB, jsonBuffer);
  }
}