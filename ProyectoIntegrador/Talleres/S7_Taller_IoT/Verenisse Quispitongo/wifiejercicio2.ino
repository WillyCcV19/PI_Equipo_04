#include <WiFi.h>
#include <ThingSpeak.h>
const char* ssid = "dasmodel";
const char* password = "cisco12345";
unsigned long channelID = 3515259;
const char* writeAPIKey = "6VGPPNQCVZEOKKKP";

WiFiClient client;
int potPin = 34;
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Conectando al WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("wiFi conectado");
  ThingSpeak.begin(client);
}

void loop() {
  int valor = analogRead(potPin);
  Serial.print("valor del potenciometro: ");
  Serial.println(valor);
  int respuesta = ThingSpeak.writeField(
    channelID,
    1,
    valor,
    writeAPIKey
  );

  if (respuesta == 200) {
    Serial.println("dato enviado correctamente a ThingSpeak");
  } else {
    Serial.print("error al enviar. Codigo: ");
    Serial.println(respuesta);
  }

  delay(15000);
}