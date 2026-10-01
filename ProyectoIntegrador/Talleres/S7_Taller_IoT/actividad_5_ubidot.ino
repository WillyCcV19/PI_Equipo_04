/****************************************
 * ESP32 + Ubidots
 * Control de LED desde Ubidots
 ****************************************/

#include "UbidotsEsp32Mqtt.h"

/****************************************
 * Configuración
 ****************************************/

const char *UBIDOTS_TOKEN = "BBUS-FrvQ42QunoLdK7rZiQ38NOB0xE0UeQ";
const char *WIFI_SSID = "dasmodel";
const char *WIFI_PASS = "cisco12345";

const char *DEVICE_LABEL = "dasmod";

const int ledPin = 33;

/****************************************
 * Objeto Ubidots
 ****************************************/

Ubidots ubidots(UBIDOTS_TOKEN);

/****************************************
 * Callback
 * Recibe el valor de "led" desde Ubidots
 ****************************************/

void callback(char *topic, byte *payload, unsigned int length) {

  Serial.print("Mensaje recibido [");
  Serial.print(topic);
  Serial.print("] ");
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.println(message);
  if (message == "1.0") {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED ENCENDIDO");
  }
  if (message == "0.0") {
    digitalWrite(ledPin, LOW);
    Serial.println("LED APAGADO");
  }
}

/****************************************
 * SETUP
 ****************************************/

void setup() {

  Serial.begin(115200);
  // Configurar LED
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  // Configurar Ubidots
  ubidots.setDebug(true);
  // Conectar a WiFi
  ubidots.connectToWifi(WIFI_SSID, WIFI_PASS);
  // Configurar callback
  ubidots.setCallback(callback);
  // Configurar MQTT
  ubidots.setup();
  // Conectar a Ubidots
  ubidots.reconnect();

  ubidots.subscribeLastValue(DEVICE_LABEL, "led");
}

/****************************************
 * LOOP
 ****************************************/

void loop() {
  // Reconectar si se pierde la conexión
  if (!ubidots.connected()) {
    ubidots.reconnect();
    
  }
  // Mantener la conexión MQTT
  ubidots.loop();
}