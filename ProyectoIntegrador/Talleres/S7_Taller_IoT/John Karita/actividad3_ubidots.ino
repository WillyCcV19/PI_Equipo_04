#include "UbidotsESPMQTT.h"

#define TOKEN "BBUS-FrvQ42QunoLdK7rZiQ38NOB0xE0UeQ"  // Token de ubidots [En este caso no me importa compartirlo]
#define WIFINAME "dasmodel"                          // SSID
#define WIFIPASS "cisco12345"                        // Contraseña

Ubidots client(TOKEN);

void callback(char* topic, byte* payload, unsigned int length) { // Función auxiliar
  Serial.print("Message arrived [");          // Indicar el mensaje llegado
  Serial.print(topic);                        // Mencionar la etiqueta
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);           // Y el contenido del mensaje
  }
  Serial.println();}

void setup() {
  Serial.begin(115200);
  client.setDebug(true);                     // Activar mensajes de depuración
  client.wifiConnection(WIFINAME, WIFIPASS); // Conectarse a la red
  client.begin(callback);}

void loop() {
  if(!client.connected()){                   // En caso de no estar conectado intentar conectarse
      client.reconnect();}
  
  client.add("stuff", 10.2);                 // Insertar variables de etiqueta junto a sus valores para enviarlos
  client.ubidotsPublish("source1");
  client.add("stuff", 10.2);
  client.add("more-stuff", 120.2);
  client.ubidotsPublish("source2");
  client.loop();}
