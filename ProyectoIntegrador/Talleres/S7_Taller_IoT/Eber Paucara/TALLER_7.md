Taller de Internet de las Cosas (IoT)

## Actividad 01: Adquisición, filtrado y conversión de señal analógica a voltaje

| Evidencia | Código utilizado | Resultado e interpretación |
|---|---|---|
| **Foto 1.1: Conexión física**<br><br>*(Insertar fotografía)* | ```cpp<br>int potPin = 34;<br>``` | Realicé la conexión del potenciómetro al pin 34 del ESP32 para obtener la lectura de la señal analógica. |
| **Foto 1.2: Lectura directa con ruido**<br><br>*(Insertar fotografía)* | ```cpp<br>valores[i] = analogRead(potPin);<br>suma = suma + valores[i];<br>delay(50);<br>``` | Realicé varias lecturas del potenciómetro para observar la variación de la señal. Para disminuir estas variaciones utilicé 10 lecturas y calculé su promedio. |
| **Foto 1.3: Promediado y voltaje**<br><br>*(Insertar fotografía)* | ```cpp<br>float promedio = suma / 10.0;<br>float voltaje = (promedio * 3.3) / 4095.0;<br>``` | Obtuve un **ADC promedio de 3504.70**. Luego convertí este valor a voltaje mediante la fórmula del ADC, obteniendo aproximadamente **2.82 V**. |

### Código completo utilizado

```cpp
int potPin = 34;
int valores[10];
int cantidad = 10;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int suma = 0;

  for (int i = 0; i < cantidad; i++) {
    valores[i] = analogRead(potPin);
    suma = suma + valores[i];
    delay(50);
  }

  float promedio = suma / 10.0;
  float voltaje = (promedio * 3.3) / 4095.0;

  Serial.print("ADC promedio: ");
  Serial.print(promedio);
  Serial.print(" | Voltaje aproximado: ");
  Serial.print(voltaje, 2);
  Serial.println(" V");

  delay(500);
}
```

---

## Actividad 02: Escaneo de redes inalámbricas y conexión a red local

| Evidencia | Código utilizado | Resultado e interpretación |
|---|---|---|
| **Foto 2.1: Escáner de redes Wi-Fi**<br><br>*(Insertar fotografía)* | ```cpp<br>#include <WiFi.h><br>``` | Realicé el escaneo de las redes disponibles y se identificó la red **dasmodel** con una intensidad de **-43 dBm**. |
| **Foto 2.2: Confirmación de conexión e IP**<br><br>*(Insertar fotografía)* | ```cpp<br>WiFi.begin(ssid, password);<br>while (WiFi.status() != WL_CONNECTED) {<br>  delay(500);<br>}<br>Serial.println("WiFi conectado");<br>Serial.println(WiFi.localIP());<br>``` | La conexión se realizó correctamente y el ESP32 mostró el mensaje **“WiFi conectado”**. La dirección IP asignada fue **10.69.108.27** y se registró una intensidad de señal de **-50 dBm**. |

### Código completo utilizado

```cpp
#include <WiFi.h>

const char* ssid = "dasmodel";
const char* password = "********";

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.print("Conectando a WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi conectado");
  Serial.print("Direccion IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
}
```

---

## Actividad 03: Telemetría del potenciómetro hacia ThingSpeak

| Evidencia | Código utilizado | Resultado e interpretación |
|---|---|---|
| **Foto 3.1: Envío de datos**<br><br>*(Insertar fotografía)* | ```cpp<br>int valor = analogRead(potPin);<br>int respuesta = ThingSpeak.writeField(<br>  channelID, 1, valor, writeAPIKey<br>);<br>``` | Realicé la lectura del potenciómetro y envié su valor al **Campo 1** de ThingSpeak. La respuesta obtenida fue **200**, por lo que el envío se realizó correctamente. |
| **Foto 3.2: Dashboard en ThingSpeak**<br><br>*(Insertar fotografía)* | ```cpp<br>if (respuesta == 200) {<br>  Serial.println("dato enviado correctamente a ThingSpeak");<br>}<br>delay(15000);<br>``` | En el dashboard se observaron las variaciones del potenciómetro, con lecturas aproximadamente entre **0 y 737**. Los datos fueron enviados periódicamente cada **15 segundos**. |

### Código completo utilizado

```cpp
#include <WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "dasmodel";
const char* password = "********";

unsigned long channelID = 3515259;
const char* writeAPIKey = "********";

WiFiClient client;
int potPin = 34;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  ThingSpeak.begin(client);
}

void loop() {
  int valor = analogRead(potPin);

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
```
