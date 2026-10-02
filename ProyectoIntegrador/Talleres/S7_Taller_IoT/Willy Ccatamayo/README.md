# Actividad 01: Promediado del ADC y conversión a voltaje

## Procedimiento realizado

Se mejoró el código del ESP32 para tomar 20 lecturas del potenciómetro conectado al pin 34 y calcular su promedio, reduciendo las fluctuaciones de la medición. Luego, se convirtió el promedio del ADC a un voltaje aproximado mediante la fórmula `voltaje = promedio × 3.3 / 4095`. Ambos resultados se mostraron en el monitor serial a 115200 baudios.

## Resultados

<img width="825" height="787" alt="1" src="https://github.com/user-attachments/assets/af2f9b44-70c4-4921-9fcd-163c5825ec61" />


En el monitor serial se observa que el promedio del ADC aumenta desde 0 hasta 4095, mientras el voltaje calculado pasa de 0.00 a 3.30 V. Por ejemplo, un promedio de 1084.70 corresponde a 0.87 V y uno de 2515.90 corresponde a 2.03 V. Esta variación es consistente con el ajuste del potenciómetro. Las últimas lecturas permanecen en 4095 y 3.30 V, indicando que el ADC alcanzó su valor máximo.

El promediado ayuda a reducir las fluctuaciones entre lecturas. Los voltajes son aproximados, ya que se calculan mediante la fórmula utilizada en el programa.

## Código utilizado

```cpp
const int potPin = 34;       // Pata central del potenciómetro
const int numLecturas = 20;  // Lecturas para calcular el promedio

void setup() {
  Serial.begin(115200);
}

void loop() {
  long suma = 0;

  // Tomar 20 lecturas
  for (int i = 0; i < numLecturas; i++) {
    suma += analogRead(potPin);
    delay(10);
  }

  float promedio = suma / 20.0;
  float voltaje = promedio * 3.3 / 4095.0;  // Voltaje aproximado

  Serial.print("Promedio ADC: ");
  Serial.print(promedio, 1);
  Serial.print(" | Voltaje aproximado: ");
  Serial.print(voltaje, 2);
  Serial.println(" V");

  delay(500);
}
```


# Actividad 02: Conexión del ESP32 a un hotspot WiFi

## Procedimiento realizado

Se creó una red WiFi mediante la función de compartir Internet del smartphone. Se programó el ESP32 para escanear las redes disponibles, mostrar sus nombres e intensidad de señal y conectarse al hotspot llamado “iPhone”. El programa muestra la dirección IP asignada cuando se establece la conexión.

## Resultados

<img width="480" height="816" alt="image" src="https://github.com/user-attachments/assets/b5690826-b07e-436d-a63c-7bf51be2e184" />

<img width="1919" height="1020" alt="2" src="https://github.com/user-attachments/assets/850e4916-6c04-4e58-bf0f-6959c2c2daac" />

La captura muestra las redes WiFi detectadas y su intensidad de señal en dBm. Un valor menos negativo indica una señal más fuerte. Al final aparece el mensaje “Conectando a iPhone…”, indicando que el ESP32 está intentando conectarse. Todavía no aparece el mensaje de conexión exitosa ni la dirección IP, por lo que esta captura confirma el escaneo y el inicio de la conexión, pero no su finalización.

## Código utilizado

```cpp
#include <WiFi.h>

const char* ssid     = "iPhone";          // Nombre del hotspot
const char* password = "TU_CONTRASEÑA";   // Contraseña de Compartir Internet

void setup() {
  Serial.begin(115200);
  delay(1000);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // 1. Escaneo de redes
  Serial.println("Escaneando redes WiFi...");
  int n = WiFi.scanNetworks();
  for (int i = 0; i < n; i++) {
    Serial.printf("%d: %s (%d dBm)\n", i + 1, WiFi.SSID(i).c_str(), WiFi.RSSI(i));
  }

  // 2. Conexión al hotspot del iPhone
  Serial.printf("\nConectando a %s", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // 3. Mostrar IP asignada
  Serial.println("\n¡Conectado!");
  Serial.print("Dirección IP asignada: ");
  Serial.println(WiFi.localIP());
}

void loop() {
}
```



