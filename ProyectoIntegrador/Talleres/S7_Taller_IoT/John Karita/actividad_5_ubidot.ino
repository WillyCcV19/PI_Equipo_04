#include "UbidotsEsp32Mqtt.h"

const char *UBIDOTS_TOKEN = "BBUS-FrvQ42QunoLdK7rZiQ38NOB0xE0UeQ"; // Token [no me importa compartirlo]
const char *WIFI_SSID = "dasmodel";                                // SSID
const char *WIFI_PASS = "cisco12345";                              // Contraseña
const char *DEVICE_LABEL = "dasmod";                               // Etiqueta de dispositivo
const int ledPin = 33;                                             // Pin digital del LED
Ubidots ubidots(UBIDOTS_TOKEN);

void callback(char *topic, byte *payload, unsigned int length) {
  Serial.print("Mensaje recibido [");                              // Indicar recepción
  Serial.print(topic);
  Serial.print("] ");
  String message = "";
  for (int i = 0; i < length; i++) {                               // Obtener el mensaje
    message += (char)payload[i];}
  Serial.println(message);                                         // Imprimirlo
  if (message == "1.0") {                                          // Conmutar LED según mensaje recibido. Ver condiciones abajo
    digitalWrite(ledPin, HIGH);
    Serial.println("LED ENCENDIDO");}
  if (message == "0.0") {
    digitalWrite(ledPin, LOW);
    Serial.println("LED APAGADO");}}

void setup() {
  Serial.begin(115200);                                            // Iniciar comunicación serial
  pinMode(ledPin, OUTPUT);                                         // Con propósito de depuración
  digitalWrite(ledPin, HIGH);
  ubidots.setDebug(true);                                          // Dejar mensajes de depuración
  ubidots.connectToWifi(WIFI_SSID, WIFI_PASS);                     // Conectarse a la red
  ubidots.setCallback(callback);
  ubidots.setup();
  ubidots.reconnect();
  ubidots.subscribeLastValue(DEVICE_LABEL, "led");}                // Suscribirse

void loop() {
  if (!ubidots.connected()) {                                      // Intentar conectarse en caso perder conexión
    ubidots.reconnect();}
  ubidots.loop();}
