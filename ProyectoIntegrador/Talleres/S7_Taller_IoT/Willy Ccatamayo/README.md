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
const char* password = "20170051";   // Contraseña de Compartir Internet

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

# Actividad 03: Monitoreo del potenciómetro mediante Arduino Cloud

## Procedimiento realizado

Para esta actividad se utilizó Arduino Cloud para visualizar la variación del potenciómetro conectado al ESP32.

1. **Configuración del dispositivo:** Se registró el ESP32 Dev Module con el nombre “Actividad3” y se vinculó a un Thing en Arduino Cloud.

2. **Configuración de la red:** Se ingresaron el nombre del hotspot “iPhone”, su contraseña y la clave del dispositivo para permitir la conexión con la plataforma. Durante las primeras pruebas se observaron intentos fallidos de conexión.

3. **Creación de la variable:** Se configuró la variable `potenciometro` como un número entero, con permiso de solo lectura y actualización cuando cambia su valor.

<img width="1821" height="687" alt="3 6" src="https://github.com/user-attachments/assets/cfd6ba9c-0845-44bc-af05-3b16cae0c542" />


4. **Programación del ESP32:** Se utilizó un código que obtiene varias lecturas del ADC, calcula su promedio y asigna el resultado a la variable `potenciometro`. También se imprimieron las lecturas en el monitor serial para comprobar sus cambios.

5. **Configuración del dashboard:** Se agregó un widget de tipo Chart y se vinculó a la variable `potenciometro` para representar sus valores a lo largo del tiempo.

6. **Prueba de funcionamiento:** Se varió la posición del potenciómetro y se revisaron las lecturas del monitor serial, la variable en Arduino Cloud y el estado de conexión del ESP32.

## Resultados

<img width="1681" height="749" alt="3 5" src="https://github.com/user-attachments/assets/93c29b21-8770-4abb-9fa7-94b18c1f939b" />

En el monitor serial se registraron diferentes lecturas, como 1308, 3274 y 1521, mostrando la variación del potenciómetro. Además, Arduino Cloud registró un último valor de 3712 en la variable configurada, lo que confirma la recepción de datos en la plataforma.

<img width="1901" height="853" alt="3 7" src="https://github.com/user-attachments/assets/aab43476-99e5-4ef8-89ec-cd194a73ee85" />

Finalmente, el dispositivo apareció con el estado ONLINE y asociado a la red “iPhone”, confirmando su conexión con Arduino Cloud.



# Actividad 04: Monitoreo de temperatura mediante ThingSpeak

## Procedimiento realizado

Se utilizó el sensor de temperatura LM35 conectado al ESP32 para registrar sus mediciones en ThingSpeak.

1. **Lectura del sensor:** Se programó el ESP32 para obtener la lectura del ADC, convertirla a voltaje y calcular la temperatura del LM35.

2. **Conexión WiFi:** Se configuró la conexión del ESP32 a una red con acceso a Internet para enviar las mediciones a la plataforma.

3. **Configuración de ThingSpeak:** Se utilizó un canal y se destinó el campo 1 al registro de temperatura, con el gráfico titulado “Temperatura LM35”.

4. **Envío de datos:** Se empleó la función `ThingSpeak.writeField()` para enviar la temperatura utilizando el identificador del canal y la clave de escritura. El programa incluyó una espera de 15 segundos entre envíos.

5. **Verificación:** Se revisaron los mensajes del monitor serial y el gráfico del canal para comprobar la recepción de las mediciones.

## Resultados

<img width="1600" height="913" alt="image" src="https://github.com/user-attachments/assets/df4e1e8b-07dc-4ab2-bc23-21d13e8a0b5d" />


En el monitor serial se muestran las lecturas del sensor y mensajes de envío de temperatura a ThingSpeak. El código verifica la respuesta del servidor y muestra un mensaje de confirmación cuando recibe el código 200.

<img width="1600" height="925" alt="image" src="https://github.com/user-attachments/assets/5330062a-0928-4edd-af5d-c509e590e030" />

En ThingSpeak se observa el gráfico “Temperatura LM35” y un total de 98 registros en el canal al momento de la captura. Esto confirma que la plataforma recibió datos y permitió visualizar las mediciones de temperatura a lo largo del tiempo.



# Actividad 05: Control remoto de un LED desde Ubidots

## Descripción de la actividad

1. **Configuración del control web:** Se creó un botón virtual en el dashboard de Ubidots para enviar las órdenes de encendido y apagado al ESP32.

2. **Conexión del LED:** Se conectó un LED rojo en la placa de pruebas junto al ESP32, utilizando una resistencia limitadora y un pin digital configurado como salida.

3. **Programación del ESP32:** Se configuró la conexión WiFi y la recepción de las órdenes de control para cambiar el estado del LED desde la plataforma.

<img width="1919" height="1199" alt="image" src="https://github.com/user-attachments/assets/a657c5f6-0898-4663-a9b8-1195329a8336" />

## Resultados e interpretación

Al activar el botón virtual en Ubidots, se envió una orden por Internet al ESP32 y el LED rojo se encendió. Al desactivar el botón, el dispositivo recibió la orden de apagado.

Esta prueba permitió comprobar la comunicación entre la plataforma web y el ESP32, así como el control remoto de un actuador mediante Internet.

<img width="320" height="513" alt="image" src="https://github.com/user-attachments/assets/fd5d36dd-e99c-4b51-b56b-105a733762ef" />




