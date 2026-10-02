## Ejercicio 1: Lectura de un potenciómetro con ESP32
## Mejorar el código anterior haciendo uso de un promediado de los datos y convirtiendo los valores del ADC a valores de voltaje.

En este ejercicio se conectó un potenciómetro al ESP32 utilizando el pin analógico GPIO 34. Primero se realizó la lectura directa de los valores del ADC y se visualizaron en el monitor serial.
Posteriormente, se mejoró la lectura tomando 10 muestras consecutivas y calculando su promedio, con el fin de obtener un valor más estable.
Finalmente, el valor promedio del ADC se convirtió a voltaje mediante la relación entre el rango del ADC y el voltaje de referencia de 3.3 V.

### Código utilizado
<img width="1600" height="944" alt="image" src="https://github.com/user-attachments/assets/dfb474d4-aaea-479c-9268-c1a3ff628181" />

### Circuito Implementado

<img width="736" height="839" alt="image" src="https://github.com/user-attachments/assets/51b4d3ce-6d4f-4c91-852b-95dfe66a73a0" />


## Ejercicio 2: Conexión del ESP32 a una red WiFi

En este ejercicio se creó una red WiFi utilizando la función de **Hotspot o zona WiFi de un smartphone**. El objetivo fue conectar el ESP32 a dicha red y verificar la comunicación mostrando en el monitor serial la dirección IP asignada al dispositivo.

Para realizar la conexión se utilizaron el nombre de la red (`SSID`) y la contraseña del hotspot del celular.

### Funcionamiento

El programa realiza los siguientes pasos:

1. Inicializa la comunicación serial a 115200 baudios.
2. El ESP32 intenta conectarse al hotspot utilizando el nombre de red y contraseña configurados.
3. Mientras no se establece la conexión, se muestran puntos en el monitor serial.
4. Una vez conectado, se muestra el mensaje WiFi conectado.
5. Finalmente, se imprime la dirección IP asignada al ESP32.


### Evidencias
<img width="1600" height="930" alt="image" src="https://github.com/user-attachments/assets/85a3aa75-629b-46dd-be8a-101ab75625be" />

### Resultado

Se logró conectar correctamente el ESP32 al hotspot creado desde el smartphone.

En el monitor serial se visualizaron los datos de la conexión:

- **SSID:** dasmodel
- **Dirección IP:** 10.69.108.27
- **RSSI:** -50 dBm

El valor RSSI representa la intensidad de la señal WiFi recibida por el ESP32. En este caso, el valor obtenido indica una buena conexión con el hotspot.



## Ejercicio 3: Visualización del potenciómetro en ThingSpeak

En este ejercicio se conectó un potenciómetro al ESP32 y se enviaron sus lecturas a la plataforma IoT ThingSpeak mediante una conexión WiFi.

El potenciómetro fue conectado al pin analógico GPIO 34 del ESP32. El valor leído por el ADC varía aproximadamente entre 0 y 4095 dependiendo de la posición del potenciómetro.

Para enviar estos datos a Internet, el ESP32 se conectó a una red WiFi utilizando el nombre y contraseña de la red.

### Configuración en ThingSpeak

Primero se creó un canal en ThingSpeak con un campo llamado:

Field 1: Potenciometro

Luego se obtuvieron los siguientes datos del canal:

- Channel ID
- Write API Key

Estos datos permiten que el ESP32 pueda identificar el canal y enviar información hacia ThingSpeak.

### Funcionamiento

El programa realiza los siguientes pasos:

1. El ESP32 se conecta a la red WiFi.
2. Se realiza una lectura del potenciómetro mediante el GPIO 34.
3. El valor obtenido se muestra en el monitor serial.
4. El ESP32 envía el dato al `Field 1` del canal de ThingSpeak.
5. ThingSpeak almacena los valores recibidos y los representa gráficamente.

Se utilizó un intervalo de aproximadamente 15 segundos entre cada envío de información.

### Evidencias
<img width="1600" height="958" alt="image" src="https://github.com/user-attachments/assets/b31444c2-0532-44db-a79c-1a000f861c1b" />

#### Variación del potenciómetro en ThingSpeak
<img width="1600" height="910" alt="image" src="https://github.com/user-attachments/assets/947108b7-c144-46d3-b3e3-181f6241d389" />

### Resultado

Se logró conectar el ESP32 a ThingSpeak mediante WiFi y enviar correctamente las lecturas obtenidas del potenciómetro.

Al modificar la posición del potenciómetro, los valores enviados también cambiaron, permitiendo visualizar su variación mediante una gráfica en tiempo real en ThingSpeak.

# Actividad 04: Monitoreo de temperatura con LM35 y ThingSpeak

## Objetivo

Implementar un sistema IoT utilizando un sensor **LM35 conectado al ESP32**, con el fin de obtener mediciones de temperatura y enviarlas mediante WiFi a la plataforma **ThingSpeak**, donde se puede observar su variación mediante una gráfica.

## Componentes utilizados

- ESP32
- Sensor de temperatura LM35
- Protoboard
- Cables jumper
- Conexión WiFi
- Plataforma ThingSpeak

## Funcionamiento

El sensor LM35 genera una salida analógica que cambia dependiendo de la temperatura. Esta señal es leída por el ADC del ESP32.
Primero se obtiene la lectura analógica:

```cpp
int valorADC = analogRead(lm35Pin);
```

Luego, el valor del ADC se convierte a voltaje:

```cpp
float voltaje = (valorADC * 3.3) / 4095.0;
```

Se utiliza `4095` debido a que el ADC del ESP32 trabaja con una resolución de 12 bits, permitiendo valores entre aproximadamente 0 y 4095.

### Conversión de voltaje a temperatura

El LM35 entrega aproximadamente **10 mV por cada grado Celsius**, es decir:

```text
10 mV = 0.01 V = 1 °C
```

Por este motivo, para convertir el voltaje a temperatura se divide entre `0.01`:

```text
Temperatura = Voltaje / 0.01
```

lo cual es equivalente a multiplicar por 100:

```cpp
float temperatura = voltaje * 100.0;
```

Por ejemplo:

```text
0.25 V × 100 = 25 °C
```

De esta manera, la lectura analógica del sensor puede expresarse directamente en grados Celsius.

## Envío de datos a ThingSpeak

El ESP32 se conectó a una red WiFi y posteriormente se utilizó la librería de ThingSpeak para enviar las mediciones.
La plataforma fue inicializada mediante:

```cpp
ThingSpeak.begin(client);
```

La temperatura obtenida se envió al `Field 1` del canal creado en ThingSpeak:

```cpp
int respuesta = ThingSpeak.writeField(
    channelID,
    1,
    temperatura,
    writeAPIKey
);
```

## Resultados obtenidos

Durante la ejecución se visualizaron en el monitor serial los valores obtenidos por el sensor.

<div align="center">
  <img width="85%" alt="image" src="https://github.com/user-attachments/assets/bffa854f-df20-454c-872f-8aeff3cbfe57" />
</div>

<p align="center">
  <em>Lecturas del LM35 y envío de datos a ThingSpeak.</em>
</p>

En el monitor serial se observaron diferentes valores del ADC, voltaje y temperatura. Además, el mensaje:

```text
Temperatura enviada a ThingSpeak
```

permitió comprobar que las mediciones estaban siendo enviadas correctamente a la plataforma.

Posteriormente, en ThingSpeak se observó la variación de la temperatura mediante una gráfica.

<div align="center">
  <img width="80%" alt="image" src="https://github.com/user-attachments/assets/2176f058-8ee8-4e18-a330-6ad8252c85bc" />
</div>

<p align="center">
  <em>Variación de temperatura registrada en ThingSpeak.</em>
</p>

La gráfica muestra las diferentes mediciones recibidas desde el ESP32. Durante las pruebas se produjeron algunos cambios bruscos debido a conexiones, desconexiones y ajustes realizados al sensor durante la implementación. Finalmente, las mediciones se estabilizaron alrededor de los valores observados en el monitor serial.

## Resultado

Se logró obtener información del sensor LM35 mediante el ESP32 y enviar las mediciones a ThingSpeak utilizando una conexión WiFi.

La plataforma permitió visualizar de manera remota la variación de la temperatura, demostrando el funcionamiento básico de un sistema IoT compuesto por un sensor, un microcontrolador, conexión a Internet y una plataforma de visualización.


## Conclusión

La actividad permitió implementar un sistema de monitoreo de temperatura utilizando el LM35 y el ESP32. La señal analógica del sensor fue convertida primero a voltaje y posteriormente a grados Celsius.

Finalmente, los valores fueron enviados correctamente a ThingSpeak, donde fue posible observar su comportamiento mediante una gráfica.
