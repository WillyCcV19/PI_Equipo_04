## Ejercicio 1: Lectura de un potenciómetro con ESP32
## Mejorar el código anterior haciendo uso de un promediado de los datos y convirtiendo los valores del ADC a valores de voltaje.

En este ejercicio se conectó un potenciómetro al ESP32 utilizando el pin analógico GPIO 34. Primero se realizó la lectura directa de los valores del ADC y se visualizaron en el monitor serial.
Posteriormente, se mejoró la lectura tomando 10 muestras consecutivas y calculando su promedio, con el fin de obtener un valor más estable.
Finalmente, el valor promedio del ADC se convirtió a voltaje mediante la relación entre el rango del ADC y el voltaje de referencia de 3.3 V.

### Código utilizado
<img width="1600" height="944" alt="image" src="https://github.com/user-attachments/assets/dfb474d4-aaea-479c-9268-c1a3ff628181" />

### Circuito Implementado


## Ejercicio 2: Conexión del ESP32 a una red WiFi

En este ejercicio se creó una red WiFi utilizando el hotspot de un smartphone. Luego, el ESP32 se conectó a dicha red mediante el nombre y contraseña configurados.
Una vez establecida la conexión, se mostró en el monitor serial la dirección IP asignada al ESP32.

### Evidencias
<img width="1600" height="930" alt="image" src="https://github.com/user-attachments/assets/85a3aa75-629b-46dd-be8a-101ab75625be" />

### Resultado
Se logró conectar correctamente el ESP32 a la red WiFi creada desde el smartphone y visualizar en el monitor serial la dirección IP asignada.



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
