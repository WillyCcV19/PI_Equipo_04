/****************************************
 * Este ejemplo funciona para usuarios
 * tanto Industrial como STEM.
 *
 * Desarrollado por Jose Garcia
 * https://github.com/jotathebest/
 ****************************************/

/****************************************
 * Incluir Bibliotecas
 ****************************************/
#include "UbidotsEsp32Mqtt.h"

/****************************************
 * Definir Constantes
 ****************************************/
const char *UBIDOTS_TOKEN = "BBUS-FrvQ42QunoLdK7rZiQ38NOB0xE0UeQ";   // Coloca aquí tu TOKEN de Ubidots
const char *WIFI_SSID = "dasmodel";       // Coloca aquí tu SSID de Wi-Fi
const char *WIFI_PASS = "cisco12345";       // Coloca aquí tu contraseña de Wi-Fi
const char *DEVICE_LABEL = "ESP-32";    // Etiqueta de tu dispositivo
const char *VARIABLE_LABEL = "Turbidez";  // Etiqueta de tu variable

const int PUBLISH_FREQUENCY = 1000;  // Frecuencia de actualización en ms
unsigned long timer;
uint8_t analogPin = 34;  // GPIO15 del ESP32
Ubidots ubidots(UBIDOTS_TOKEN);

/****************************************
 * Funciones Auxiliares
 ****************************************/
void callback(char *topic, byte *payload, unsigned int length) {
  Serial.print("Mensaje recibido [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

/****************************************
 * Funciones Principales
 ****************************************/

void setup() {
  // Código de configuración, se ejecuta una sola vez
  Serial.begin(115200);
  ubidots.setDebug(true);  // Cambia a false para desactivar mensajes de depuración
  ubidots.connectToWifi(WIFI_SSID, WIFI_PASS);
  ubidots.setCallback(callback);
  ubidots.setup();
  ubidots.reconnect();
  timer = millis();
}

void loop() {
  // Código principal, se ejecuta repetidamente
  if (!ubidots.connected()) {
    ubidots.reconnect();}
  if (millis() - timer > PUBLISH_FREQUENCY) {
    int value = analogRead(analogPin);
    ubidots.add(VARIABLE_LABEL, value);
    ubidots.publish(DEVICE_LABEL);
    timer = millis();}

  ubidots.loop();
}