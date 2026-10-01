Taller de Internet de las Cosas (IoT)

## Actividad 01: Adquisición, filtrado y conversión de señal analógica a voltaje

| Evidencia | Código utilizado | Resultado e interpretación |
|---|---|---|
| <img src="/Imagenes/taller_iot/91.png" width="1000"/>| ```cpp<br>int potPin = 34;<br>``` | Realicé la conexión del potenciómetro al pin 34 del ESP32 para obtener la lectura de la señal analógica. |
|<img src="/Imagenes/taller_iot/92.png" width="1000"/>| ```cpp<br>valores[i] = analogRead(potPin);<br>suma = suma + valores[i];<br>delay(50);<br>``` | Realicé varias lecturas del potenciómetro para observar la variación de la señal. Para disminuir estas variaciones utilicé 10 lecturas y calculé su promedio. |
| <img src="/Imagenes/taller_iot/93.png" width="1000"/> | ```cpp<br>float promedio = suma / 10.0;<br>float voltaje = (promedio * 3.3) / 4095.0;<br>``` | Obtuve un **ADC promedio de 3504.70**. Luego convertí este valor a voltaje mediante la fórmula del ADC, obteniendo aproximadamente **2.82 V**. |

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
| <img src="/Imagenes/taller_iot/94.png" width="1000"/> | ```cpp<br>#include <WiFi.h><br>``` | Realicé el escaneo de las redes disponibles y se identificó la red **dasmodel** con una intensidad de **-43 dBm**. |
| <img src="/Imagenes/taller_iot/95.png" width="1000"/> | ```cpp<br>WiFi.begin(ssid, password);<br>while (WiFi.status() != WL_CONNECTED) {<br>  delay(500);<br>}<br>Serial.println("WiFi conectado");<br>Serial.println(WiFi.localIP());<br>``` | La conexión se realizó correctamente y el ESP32 mostró el mensaje **“WiFi conectado”**. La dirección IP asignada fue **10.69.108.27** y se registró una intensidad de señal de **-50 dBm**. |

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
| <img src="/Imagenes/taller_iot/96.png" width="1000"/> | ```cpp<br>int valor = analogRead(potPin);<br>int respuesta = ThingSpeak.writeField(<br>  channelID, 1, valor, writeAPIKey<br>);<br>``` | Realicé la lectura del potenciómetro y envié su valor al **Campo 1** de ThingSpeak. La respuesta obtenida fue **200**, por lo que el envío se realizó correctamente. |
| <img src="/Imagenes/taller_iot/97.png" width="1000"/> | ```cpp<br>if (respuesta == 200) {<br>  Serial.println("dato enviado correctamente a ThingSpeak");<br>}<br>delay(15000);<br>``` | En el dashboard se observaron las variaciones del potenciómetro, con lecturas aproximadamente entre **0 y 737**. Los datos fueron enviados periódicamente cada **15 segundos**. |

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
## Actividad 04: Visualización de lecturas continuas de sensores en Ubidots

| Evidencia | Descripción de la actividad | Resultado e interpretación |
|---|---|---|
| <img src="/Imagenes/taller_iot/actividad4_b.jpg" width="1000"/> | **Armado y conexión física del sensor**<br>Conecté el sensor de turbidez a la placa de pruebas mediante cables jumper, enlazando sus salidas hacia la tarjeta de desarrollo para capturar las lecturas del medio líquido. | El circuito quedó correctamente instalado en la mesa de trabajo, permitiendo enviar la señal analógica capturada por el sensor hacia la tarjeta para su procesamiento. |
| <img src="/Imagenes/taller_iot/actividad4_a.jpg" width="1000"/> | **Monitoreo y gráfica de turbidez en Ubidots**<br>Configuré un panel en la plataforma en la nube (Ubidots) denominado "Turbidez" para recibir y graficar las variaciones continuas del sensor en tiempo real. | La plataforma registró exitosamente la señal transmitida por internet, mostrando en la gráfica los picos y variaciones de turbidez a lo largo del tiempo de medición. |

---

## Actividad 05: Control remoto de actuadores (LED) desde la plataforma IoT

| Evidencia | Descripción de la actividad | Resultado e interpretación |
|---|---|---|
| <img src="/Imagenes/taller_iot/Captura de pantalla 2026-10-01 142318.png" width="1000"/> | **Creación del botón de control en la plataforma web**<br>Configuré una plataforma en la nube (Ubidots) creando un botón virtual encendido de color verde para mandar señales de control a la distancia[cite: 18, 47]. | Al presionar el botón virtual en la pantalla, la plataforma envió la orden por internet para activar el foco LED desde la página web en tiempo real[cite: 47]. |
| <img src="/Imagenes/taller_iot/WhatsApp Image 2026-10-01 at 2.30.36 PM.jpeg" width="1000"/> | **Conexión e instalación del foco LED en la placa**<br>Conecté un foco LED rojo a la placa de pruebas junto a la tarjeta programable para que reciba las órdenes transmitidas por internet[cite: 5, 42]. | Al recibir la instrucción mandada desde la página web, la tarjeta encendió el foco LED rojo en la placa de manera inmediata[cite: 42]. |
