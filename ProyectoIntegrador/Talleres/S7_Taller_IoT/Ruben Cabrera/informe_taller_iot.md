# Informe – Taller IoT con ESP32

**Autor:** Ruben Andre Cabrera Cermeño
**Equipo:** PI_Equipo_04
**Placa utilizada:** ESP32-WROOM-DA Module
**Herramientas:** Arduino IDE 2.3.10, Arduino Cloud

---

## Introducción

En este taller se trabajó con la placa ESP32 en tres actividades: la lectura de una señal analógica mediante un potenciómetro, el escaneo y la conexión a redes WiFi, y el envío de datos a la plataforma Arduino Cloud para visualizarlos en tiempo real. En este informe se interpretan las salidas obtenidas en cada ejercicio.

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
- Al final aparecen **caracteres ilegibles** (`�����`). Esto suele indicar que el ESP32 **se reinició**: al arrancar, la placa imprime mensajes a 74880 baudios, y el monitor configurado en 115200 baudios los muestra como caracteres extraños. El reinicio pudo deberse a un tiempo de espera definido en el código, al watchdog o a una caída de voltaje.

---

## Ejercicio 3: Monitoreo del potenciómetro en Arduino Cloud

### Descripción

El ESP32 lee el potenciómetro y envía el valor promedio a una variable de **Arduino Cloud**. El valor se visualiza en un widget **Chart** del dashboard en modo **LIVE**, y al mismo tiempo en el monitor serial web del sketch `Actividad3` (puerto COM3, 115200 baudios).

### Salida obtenida

![Salida del ejercicio 3](/Imagenes/taller_iot/img_Cabrera/ejer3.jpeg)

### Interpretación de los valores

- Los valores **varían entre 0 y 4095**, es decir, todo el rango del ADC. Esto confirma que el potenciómetro está correctamente conectado y que se giró de un extremo al otro durante la prueba.
- **0** equivale a 0 V (potenciómetro al mínimo) y **4095** a 3.3 V (al máximo). Los valores intermedios corresponden a posiciones parciales; por ejemplo, 2125 ≈ 1.71 V y 1308 ≈ 1.05 V.
- Los valores se muestran como **enteros**, lo que indica que la variable enviada a la nube es de tipo entero.

### Interpretación de la gráfica

- Cada **pico** (cerca de 4K) corresponde al potenciómetro girado al máximo, y cada **valle** (en 0) al mínimo. Las oscilaciones reflejan los giros de ida y vuelta durante la prueba.
- Hacia el final de la gráfica (≈16:46:26, hora UTC−05), la curva se **estabiliza cerca de 3,500**: el potenciómetro se dejó en una posición fija.
- La gráfica tiene **menos puntos** que el monitor serial. Esto es esperado: Arduino Cloud no envía cada lectura, sino que sincroniza la variable con una frecuencia limitada, mientras que el monitor serial muestra todas las lecturas.
- El widget **suaviza la curva** uniendo los puntos con líneas curvas, por lo que la gráfica se ve más continua que los datos reales.

### Observación

El eje Y del gráfico llega hasta 6K, aunque el valor máximo posible es 4095. Fijar el rango del eje entre 0 y 4095 haría la gráfica más clara.

---

## Conclusiones

1. El ADC de 12 bits del ESP32 convierte voltajes de 0 a 3.3 V en valores de 0 a 4095, y promediar varias lecturas permite obtener mediciones más estables.
2. El escaneo WiFi permite evaluar la calidad de señal de las redes cercanas mediante el RSSI. Para conectarse, la red debe transmitir en la banda de 2.4 GHz, la única compatible con el ESP32.
3. Arduino Cloud permite visualizar en tiempo real los datos del sensor desde un dashboard web, lo que muestra la integración entre el hardware y una plataforma IoT en la nube.
4. Los caracteres ilegibles en el monitor serial son una señal útil para diagnosticar reinicios de la placa.
