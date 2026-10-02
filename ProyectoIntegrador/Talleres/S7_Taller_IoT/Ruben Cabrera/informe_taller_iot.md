# Informe – Taller IoT con ESP32


---

## Introducción

En este taller se trabajó con la placa ESP32 en cinco actividades: la lectura de una señal analógica mediante un potenciómetro, el escaneo y la conexión a redes WiFi, el envío de datos a la plataforma Arduino Cloud para visualizarlos en tiempo real, el envío de la lectura de un sensor de temperatura a plataformas IoT y el control de un LED desde la nube. En este informe se interpretan las salidas obtenidas en cada ejercicio.

---

## Ejercicio 1: Lectura promediada de un potenciómetro

### Descripción del código

El programa toma **20 lecturas** del pin analógico conectado al potenciómetro, con una pausa de 10 ms entre cada una, y calcula su promedio para reducir el ruido de la señal. Luego convierte ese promedio a voltaje con la fórmula:

$$
V = \frac{\text{promedio ADC} \times 3.3}{4095}
$$

Finalmente, imprime el valor ADC promedio y el voltaje aproximado en el monitor serial cada 500 ms.

### Salida obtenida

![Salida del ejercicio 1](/Imagenes/taller_iot/img_Cabrera/ejer1.jpeg)

### Interpretación

- El ADC del ESP32 tiene una resolución de **12 bits**, por lo que sus lecturas van de **0 a 4095**.
- Todas las lecturas muestran **4095.00**, que equivale a **3.30 V**. Es el valor máximo del ADC: el pin estaba recibiendo el voltaje completo de alimentación.
- Que el valor se mantenga constante indica que el potenciómetro estaba **girado al tope** durante la captura. En el ejercicio 3 se comprueba que, al girarlo, el valor sí recorre todo el rango de 0 a 4095.
- El promedio de 20 lecturas funciona como un **filtro**: en posiciones intermedias, el ADC del ESP32 suele variar varias unidades entre lecturas, y promediar estabiliza el resultado.

### Observaciones

- El texto del monitor serial (`ADC promedio:` con dos decimales) no coincide exactamente con el del código mostrado (`Promedio ADC:` con un decimal). Esto indica que la salida corresponde a una versión anterior del sketch, cargada antes de la última edición.
- En el cálculo del promedio se divide entre `20.0` de forma fija. Es preferible dividir entre `numLecturas`, para que el cálculo siga siendo correcto si se cambia la cantidad de lecturas.

---

## Ejercicio 2: Escaneo de redes WiFi y conexión

### Descripción del código

El programa utiliza la librería `WiFi.h` para escanear las redes WiFi cercanas y mostrar cada una con su intensidad de señal (RSSI, en dBm). Después intenta conectarse a la red `iPhone`, un hotspot creado desde un celular.

### Salida obtenida

![Salida del ejercicio 2](/Imagenes/taller_iot/img_Cabrera/ejer2.jpeg)

### Interpretación del escaneo

El ESP32 detectó **25 redes**, ordenadas de mayor a menor intensidad de señal. El RSSI siempre es negativo, y mientras más cercano a 0, mejor es la señal:

| Rango RSSI | Calidad de señal | Ejemplos detectados |
|---|---|---|
| −30 a −50 dBm | Excelente | dasmodel (−43 dBm) |
| −50 a −60 dBm | Muy buena | UPCH_CENTRAL (−52 dBm), UPCH_RECTORADO (−56 dBm) |
| −60 a −70 dBm | Buena | ajam, Redmi Note 14 Pro 5G, POCO_F5, Estudiantes |
| −70 a −80 dBm | Débil | Antena, UPCH_CENTRAL (−78 dBm), DIRECT-74-HP |
| Menor a −80 dBm | Muy débil | Invitados (−83 dBm), Kmbm (−88 dBm), Docentes (−89 dBm) |

Algunas redes aparecen **repetidas** con distinta intensidad (Estudiantes, Docentes, Invitados, Administrativos, UPCH_CENTRAL). No es un error: son **varios puntos de acceso** de la red de la universidad que transmiten el mismo nombre desde distintas ubicaciones, y el ESP32 detecta cada uno por separado. También se detectaron hotspots de celulares y redes `DIRECT-…` de impresoras con WiFi Direct.

### Interpretación del intento de conexión

- Después del escaneo aparece `Conectando a iPhone...` seguido de muchos puntos, que representan los intentos de conexión. La conexión **no se logró**.
- La red `iPhone` **no aparece entre las 25 redes detectadas**, por lo que el ESP32 no podía conectarse a ella. Una causa probable es que el hotspot transmitía en la banda de **5 GHz**, mientras que el ESP32 **solo trabaja en 2.4 GHz**. En iPhone esto se soluciona activando la opción **"Maximizar compatibilidad"** en los ajustes de Compartir Internet.
- Al final aparecen **caracteres ilegibles**. Esto suele indicar que el ESP32 **se reinició**: al arrancar, la placa imprime mensajes a 74880 baudios, y el monitor configurado en 115200 baudios los muestra como caracteres extraños. El reinicio pudo deberse a un tiempo de espera definido en el código, al watchdog o a una caída de voltaje.

---

## Ejercicio 3: Monitoreo del potenciómetro en Arduino Cloud

### Descripción

El ESP32 lee el potenciómetro y envía el valor promedio a una variable de **Arduino Cloud**. El valor se visualiza en un widget **Chart** del dashboard en modo **LIVE**, y al mismo tiempo en el monitor serial web del sketch `Actividad3` (puerto COM3, 115200 baudios).

### Salida obtenida

![Salida del ejercicio 3](/Imagenes/taller_iot/img_Cabrera/ejer3.jpeg)

### Interpretación de los valores

- Los valores **varían entre 0 y 4095**, es decir, todo el rango del ADC. Esto confirma que el potenciómetro está correctamente conectado y que se giró de un extremo al otro durante la prueba.
- **0** equivale a 0 V (potenciómetro al mínimo) y **4095** a 3.3 V (al máximo). Los valores intermedios corresponden a posiciones parciales; por ejemplo, 2125 = 1.71 V y 1308 = 1.05 V.
- Los valores se muestran como **enteros**, lo que indica que la variable enviada a la nube es de tipo entero.

### Interpretación de la gráfica

- Cada **pico** (cerca de 4K) corresponde al potenciómetro girado al máximo, y cada **valle** (en 0) al mínimo. Las oscilaciones reflejan los giros de ida y vuelta durante la prueba.
- Hacia el final de la gráfica , la curva se **estabiliza cerca de 3,500**: el potenciómetro se dejó en una posición fija.
- La gráfica tiene **menos puntos** que el monitor serial. Esto es esperado: Arduino Cloud no envía cada lectura, sino que sincroniza la variable con una frecuencia limitada, mientras que el monitor serial muestra todas las lecturas.
- El widget **suaviza la curva** uniendo los puntos con líneas curvas, por lo que la gráfica se ve más continua que los datos reales.


---

## Ejercicio 4: Envío de la temperatura a ThingSpeak

### Actividad

Escribir un código que muestre en tiempo real la variación de uno de los sensores del kit Keystudio (LM35, LDR, etc.) conectado al ESP32 en las plataformas de IoT Arduino Cloud, ThingSpeak y Ubidots.

### Descripción del código

Se utilizó el sensor de temperatura **LM35**. El programa lee el valor del ADC, lo convierte a voltaje y luego a temperatura en C, e imprime los tres valores en el monitor serial. Después envía la temperatura al **campo 1** de un canal de **ThingSpeak** con la función `ThingSpeak.writeField(channelID, 1, temperatura, writeAPIKey)`. El programa espera **15 segundos** entre cada envío.

### Salida obtenida

![Salida del ejercicio 4](/Imagenes/taller_iot/img_Cabrera/ejercicio4.png)

### Interpretación

- Cada lectura muestra tres valores: el **ADC** (entre 124 y 138), el **voltaje** (entre 0.100 y 0.111 V) y la **temperatura** (entre 23.99 y 25.12 C).
- Después de cada lectura aparece `Temperatura enviada a ThingSpeak`. Este mensaje solo se imprime cuando la función devuelve el código **200**, que en HTTP significa que la solicitud fue **exitosa**. Por lo tanto, todos los envíos llegaron correctamente al canal.
- El LM35 entrega **10 mV por cada C**. En los datos se observa esa relación: una diferencia de 0.004 V entre lecturas corresponde a una diferencia de 0.4 C. La temperatura obtenida, alrededor de **24 C**, es coherente con la temperatura de un ambiente interior.
- La variación entre lecturas (menos de 1.2 C) no refleja un cambio real de temperatura, sino el **ruido del ADC**: cada unidad del ADC equivale a unos 0.8 mV, por lo que una variación de pocas unidades produce cambios de algunas décimas de grado.
- La pausa de **15 segundos** responde al límite de la cuenta gratuita de ThingSpeak, que acepta como máximo una actualización cada 15 segundos por canal. Si se envían datos más rápido, el servidor los rechaza.

### Observaciones

- El ruido podría reducirse promediando varias lecturas antes de calcular la temperatura, como se hizo en el ejercicio 1.
- El ADC del ESP32 es poco preciso en voltajes bajos, cercanos a 0 V, que es justamente el rango en el que trabaja el LM35 a temperatura ambiente. Para mejorar la precisión se puede usar la función `analogReadMilliVolts()`, que aplica la calibración interna del ESP32.

---

## Ejercicio 5: Control de un LED desde la nube con Ubidots

### Actividad

Conectar un LED en uno de los pines digitales del ESP32 y controlar su encendido desde alguna de las plataformas web de su preferencia.

### Descripción

Se eligió la plataforma **Ubidots**. En el dashboard `Turbidez` se agregó un widget **Switch** vinculado a la variable `led` del dispositivo `dasmod`. Al activar o desactivar el switch, Ubidots cambia el valor de la variable a 1 o 0. El ESP32, conectado a la plataforma, recibe ese valor y enciende o apaga el LED conectado al pin digital.

### Salida obtenida

![Salida del ejercicio 5](/Imagenes/taller_iot/img_Cabrera/ejercicio5.png)

### Interpretación

- El widget **Switch** muestra el control de la variable `led` del dispositivo `dasmod`. Su color **verde** indica que está en estado **encendido** (valor 1), por lo que el LED conectado al ESP32 debería estar prendido.
- Este ejercicio funciona en sentido contrario a los anteriores: en lugar de que el ESP32 **envíe** datos a la nube, el ESP32 **recibe** una orden desde la nube y la ejecuta sobre un actuador. Así, el LED puede controlarse desde cualquier lugar con acceso a internet.
- El dashboard también tiene dos gráficos de línea (**Line chart**), con el rango de tiempo desde el 1 de octubre de 2026 a las 13:23 hasta el momento actual. Ambos aparecen **vacíos**, lo que indica que las variables asociadas a esos gráficos no recibieron datos en ese periodo. Estos gráficos no forman parte de esta actividad, que solo requiere el control del LED.

### Evidencia del LED encendido

![LED encendido desde Ubidots](/Imagenes/taller_iot/img_Cabrera/ejercicio55.png)

- La foto muestra el **circuito físico**: el ESP32 montado en el protoboard, alimentado por USB-C, y el LED rojo conectado a la placa mediante dos cables (uno al pin digital de control y otro a tierra).
- El **LED rojo está encendido**, lo que coincide con el estado **activado** del switch en el dashboard de Ubidots. Esto confirma que la orden enviada desde la nube llegó al ESP32 y se ejecutó sobre el pin digital.
- La pequeña luz roja sobre la placa, junto al conector USB, es el **LED de encendido del ESP32**, que indica que la placa está alimentada. No forma parte del ejercicio.

---

## Conclusiones

1. El ADC de 12 bits del ESP32 convierte voltajes de 0 a 3.3 V en valores de 0 a 4095, y promediar varias lecturas permite obtener mediciones más estables.
2. El escaneo WiFi permite evaluar la calidad de señal de las redes cercanas mediante el RSSI. Para conectarse, la red debe transmitir en la banda de 2.4 GHz, la única compatible con el ESP32.
3. Arduino Cloud permite visualizar en tiempo real los datos del sensor desde un dashboard web, lo que muestra la integración entre el hardware y una plataforma IoT en la nube.
4. Los caracteres ilegibles en el monitor serial son una señal útil para diagnosticar reinicios de la placa.
5. ThingSpeak permite almacenar y graficar datos de sensores mediante solicitudes HTTP. El código de respuesta 200 confirma que cada envío fue exitoso, y el límite de una actualización cada 15 segundos debe respetarse en el código.
6. Ubidots permite controlar actuadores desde un dashboard web. Esto demuestra que la comunicación IoT funciona en ambos sentidos: el ESP32 puede enviar datos a la nube y también recibir órdenes desde ella.
