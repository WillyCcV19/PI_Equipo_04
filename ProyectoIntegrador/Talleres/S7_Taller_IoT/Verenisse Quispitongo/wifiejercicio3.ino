#include <WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "dasmodel";
const char* password = "cisco12345";

unsigned long channelID = 3515259;
const char* writeAPIKey = "6VGPPNQCVZEOKKKP";

WiFiClient client;

int lm35Pin = 34;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  Serial.print("Conectando al WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi conectado");

  ThingSpeak.begin(client);
}

void loop() {

  // Leer ADC
  int valorADC = analogRead(lm35Pin);
  // convertir ADC a voltaje
  float voltaje = (valorADC * 3.3) / 4095.0;
  // LM35: 10 mV por grado Celsius
  float temperatura = voltaje * 100.0;

  Serial.print("ADC: ");
  Serial.print(valorADC);
  Serial.print(" | Voltaje: ");
  Serial.print(voltaje, 3);
  Serial.print(" V | Temperatura: ");
  Serial.print(temperatura, 2);
  Serial.println(" °C");

  // enviar temperatura a ThingSpeak
  int respuesta = ThingSpeak.writeField(
    channelID,
    1,
    temperatura,
    writeAPIKey
  );

  if (respuesta == 200) {
    Serial.println("Temperatura enviada a ThingSpeak");
  } else {
    Serial.print("Error al enviar. Codigo: ");
    Serial.println(respuesta);
  }

  delay(15000);
}