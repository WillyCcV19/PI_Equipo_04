// * https://github.com/jotathebest/ ← Origen del código original
#include "UbidotsEsp32Mqtt.h"
const char *UBIDOTS_TOKEN = "BBUS-FrvQ42QunoLdK7rZiQ38NOB0xE0UeQ";   // Token de ubidots [no me importa compartir este token]
const char *WIFI_SSID = "dasmodel";                                  // SSID
const char *WIFI_PASS = "cisco12345";                                // Contraseña
const char *DEVICE_LABEL = "ESP-32";                                 // Etiqueta de dispositivo
const char *VARIABLE_LABEL = "Turbidez";                             // Etiqueta de variable

const int PUBLISH_FREQUENCY = 1000;                                  // Frecuencia de actualización en ms
unsigned long timer;
uint8_t analogPin = 34;                                              // Designar pin de lectura
Ubidots ubidots(UBIDOTS_TOKEN);

void callback(char *topic, byte *payload, unsigned int length) {     // Función auxiliar
  Serial.print("Mensaje recibido [");                                // Indicar recepción
  Serial.print(topic);                                               // Imprimir etiqueta de variable
  Serial.print("] ");
  for (int i = 0; i < length; i++) {                                 // Imprimir contenidos
    Serial.print((char)payload[i]);}
  Serial.println();}

void setup() {
  Serial.begin(115200);                                              // Iniciar comunicación serial
  ubidots.setDebug(true);                                            // Desactivar mensajes de depuración
  ubidots.connectToWifi(WIFI_SSID, WIFI_PASS);                       // Conectarse a la red
  ubidots.setCallback(callback);
  ubidots.setup();
  ubidots.reconnect();
  timer = millis();}

void loop() {
  if (!ubidots.connected()) {                                        // Reconectarse en caso perder la conexión
    ubidots.reconnect();}
  if (millis() - timer > PUBLISH_FREQUENCY) {                        // Si el tiempo transcurrido es igual al periodo designado
    int value = analogRead(analogPin);                               // Leer pin analógico
    ubidots.add(VARIABLE_LABEL, value);                              // Designar variable a publicar junto al valor leído
    ubidots.publish(DEVICE_LABEL);                                   // Publicar valor
    timer = millis();}                                               // Designar nuevo tiempo inicial
  ubidots.loop();}
