El siguiente documento explicará:
- ¿Qué tecnología se está desarrollando?
- ¿Qué se hará para comprobar que funciona?
- ¿Qué evidencia demuestra que los principios tecnológicos son viables?

## 1. Fundamento y objetivo de la prueba de concepto

### 1.1. Fundamento

FishMon 365 surge de la necesidad de mantener condiciones adecuadas de calidad del agua para la crianza de truchas, buscando automatizar las mediciones y facilitar la detección oportuna de cambios en parámetros físico-químicos importantes.

Se propone un sistema de sensores sumergibles con profundidad controlable para realizar mediciones en distintos niveles de la columna de agua, debido a que sus condiciones pueden variar según la profundidad.

### 1.2. Objetivo de la prueba de concepto

Comprobar la viabilidad de medir tres de los cinco parámetros (conductividad, oxígeno disuelto y pH), evaluar el funcionamiento de los circuitos de acondicionamiento de señal y verificar, de forma analítica, que las carcasas resisten las cargas de inmersión y de operación.

## 2. Pruebas de concepto

### 2.1. Simulación de los circuitos de acondicionamiento de señal

Los siguientes circuitos fueron simulados para comprobar el correcto cálculo del valor de las resistencias en sus respectivos circuitos acondicionadores de señal. A partir de ello, fue posible calcular algunos valores a partir de señales ficticias.

#### 2.1.1. Acondicionamiento del sensor de pH

Se utilizó una tensión de referencia de 1.5 V para generar una tierra virtual, debido a las limitaciones en la salida del amplificador operacional CA3140. Alimentado con 5 V, este puede entregar señales aproximadamente entre 0 y 3 V, por lo que se decidió trabajar alrededor de una referencia de 1.5 V.

Con una ganancia de 2.5, la señal máxima de entrada antes de alcanzar los límites de salida es de aproximadamente ±0.6 V respecto a la referencia. Considerando una respuesta de 0.06 V por unidad de pH, una variación de ±7 unidades respecto al pH 7 produciría una señal de aproximadamente ±0.42 V, manteniéndose dentro del rango de entrada establecido.

En la Figura 1 se observa una señal de entrada cuadrada que abarca el rango de operación del sensor de pH (±0.425 V), medida respecto a una referencia de 1.522 V. Al ser amplificada con una ganancia de 2.5, la señal de salida alcanza una amplitud de ±1.063 V alrededor de la misma referencia, obteniendo un valor máximo teórico de 2.585 V. Este valor es cercano al máximo de 2.686 V obtenido en la simulación, cuya diferencia podría deberse a un pico transitorio poco perceptible en la señal.

<p align="center">
  <img src="/Imagenes/ModuloElec/simulacion_ph.png" width="800"/>
  <br>
  <em>Figura 1. Simulación del circuito de acondicionamiento del sensor de pH.</em>
</p>

#### 2.1.2. Acondicionamiento del sensor de oxígeno disuelto

Se utilizó un amplificador no inversor con ganancia de 38.6 y una resistencia tipo *shunt* de 7.5 kΩ en la entrada, que completa un divisor de voltaje con la celda galvánica simulada. Este tipo de celda está presente en los sensores galvánicos de oxígeno disuelto, que entregan un voltaje pero tienen una alta impedancia.

La intensidad máxima teórica que puede medir es de 5.19 µA (1.5 V / 7500 Ω / 38.6). Con la celda galvánica simulada se mide un voltaje de entrada de 23.8 mV (0.5 V × 7.5 kΩ / (150 + 7.5) kΩ), con una corriente de 3.17 µA (23.8 mV / 7500 Ω). La salida es de 0.894 V respecto a 1.5 V; al dividirla entre la ganancia (38.6) se obtienen 23.2 mV, valor cercano al voltaje de entrada, lo que permite calcular la intensidad del sensor (Figura 2).

<p align="center">
  <img src="/Imagenes/ModuloElec/simulacion_do.png" width="800"/>
  <br>
  <em>Figura 2. Simulación del circuito de acondicionamiento del sensor de oxígeno disuelto.</em>
</p>

#### 2.1.3. Acondicionamiento del sensor de conductividad

Se utilizó un circuito para generar una señal pulsante de 100 mV alrededor de una referencia de 3 V. Esta señal alimenta un divisor de voltaje compuesto por una resistencia conocida de 1000 Ω y una de prueba de 150 Ω (en la Figura 3 aparece colocada al revés); luego pasa por un amplificador con ganancia 6.

Con las señales "salida pulso respecto a ref", "salida de divisor respecto a ref" y "salida conductividad" se puede calcular la resistencia desconocida, pues son las medidas del divisor de voltaje:
- Vin = "salida pulso respecto a ref" = 96.8 mV
- Vout = "salida de divisor respecto a ref" = 12.9 mV
- Vout × 6 = "salida conductividad" = 79.4 mV
- R1 = 1000 Ω

Con R2 = R1 × Vout / (Vin − Vout) se obtiene R2 = 153 Ω, cercano a los 150 Ω reales.

Debido a que la conductividad es la inversa de la resistencia, medir con precisión una resistencia utilizando pulsos de excitación indica que el sensor de conductividad puede realizar bien su trabajo.

<p align="center">
  <img src="/Imagenes/ModuloElec/simulacion_cond.png" width="800"/>
  <br>
  <em>Figura 3. Simulación del circuito de acondicionamiento del sensor de conductividad.</em>
</p>

### 2.2. Caracterización y calibración de sensores

#### 2.2.1. Oxígeno disuelto

El objetivo fue caracterizar de manera preliminar la respuesta del sensor de oxígeno disuelto (DFRobot Gravity SEN0237) en agua aireada y en agua con sulfito de sodio, e identificar lecturas de referencia para una posterior calibración en los puntos de 0% y 100% de saturación.

Detalles de la prueba:
- Para lograr una concentración cercana (no verificada) a 0% de oxígeno disuelto se disolvió 1 g de sulfito de sodio en 30 mL de agua destilada (1 g era la resolución mínima de la balanza utilizada).
- Para lograr un valor aproximado (no verificado) de 100% se agitó el agua vigorosamente y se dejó airear varias veces.
- El osciloscopio posee 8 cuadros de altura, con escala variable por cuadro.
- Las mediciones son valores RMS tomados durante 12 segundos (12 cuadros horizontales, 1 segundo cada uno).

<table>
  <tr>
    <td align="center">
      <img src="/Imagenes/Simulaciones/img2.jpeg" width="100%">
      <br>
      <em>Figura 4. Materiales para medir OD con el sensor DFRobot Gravity SEN0237.</em>
    </td>
    <td align="center">
      <img src="/Imagenes/Simulaciones/img5.jpeg" width="100%">
      <br>
      <em>Figura 5. Amplificador provisional para comprobar el funcionamiento del sensor de OD.</em>
    </td>
  </tr>
</table>

**Resultados**

Sensor sumergido en solución con sulfito de sodio (≈ 0% de oxígeno disuelto):

| Tiempo (min:s) | Voltaje (mV) | Escala por cuadro (mV) |
|--|--|--|
|1:30|47|500|
|2:00|26|500|
|2:30|9|500|

Sensor en agua aireada (≈ 100% de saturación):

| Tiempo (min:s) | Voltaje (mV) | Escala por cuadro (mV) |
|--|--|--|
|1:30|1200|500|
|2:30|1030|500|
|3:30|940|500|
|4:30|870|500|
|5:00|850|500|

En la solución con sulfito, la lectura baja hasta unos 9 mV en 2.5 minutos, cercana al cero esperado. En agua aireada, la lectura desciende y tiende a estabilizarse alrededor de 850 mV después de unos 5 minutos. Estos dos valores sirven como puntos de referencia preliminares de 0% y 100% para la calibración, considerando que el sensor necesita varios minutos para estabilizarse.

#### 2.2.2. pH

Se utilizó un amplificador con ganancias de 3 y 5 y se midieron soluciones tampón de pH 4, 7 y 10 (Figura 6).

<p align="center">
  <img src="/Imagenes/Simulaciones/img3.jpeg" width="800"/>
  <br>
  <em>Figura 6. Montaje para la medición del sensor de pH.</em>
</p>

**Resultados** (lecturas de voltaje de salida, en mV)

Amplificación ×5:

|pH 4|pH 7|pH 10|
|--|--|--|
|86|-6.2|-200|
|86.8|-31.6|-199|
|86.2|-47.2|-206|
|87|-47.6|-208|
|87|-52|-214|
|**Promedio: 86.6**|**Promedio: -36.9**|**Promedio: -205.4**|

Amplificación ×3:

|pH 4|pH 7|pH 10|
|--|--|--|
|117|-60|-222|
|106|-52.6|-214|
|94|-67.3|-218|
|95.7|-68|-230|
|102|-63|-225|
|**Promedio: 102.9**|**Promedio: -62.2**|**Promedio: -221.8**|

En ambas ganancias el voltaje disminuye de forma ordenada al aumentar el pH, lo que confirma que el sensor responde a los cambios de pH. Con ganancia ×5, la lectura en pH 7 deriva de −6.2 a −52 mV, por lo que el sensor requiere más tiempo de estabilización antes de registrar el valor. Estos promedios servirán como puntos de calibración de 3 valores (pH 4, 7 y 10).

#### 2.2.3. Conductividad

Los resultados se obtuvieron con el circuito ensamblado de la Figura 7, cuyo esquemático se muestra en la sección 2.1.3.

<p align="center">
  <img src="/Imagenes/Simulaciones/img4.jpeg" width="800"/>
  <br>
  <em>Figura 7. Circuito de conductividad ensamblado.</em>
</p>

|Resistencia real (Ω)|Resistencia medida (Ω)|Error (%)|
|------------------|------------------|------|
|5000              |4950              |-1    |
|3330              |3290              |-1.2  |
|2500              |2480              |-0.8  |
|2040              |2050              |0.5   |
|1530              |1540              |0.7   |
|1020              |1020              |0     |
|510               |510               |0     |
|255               |237               |-7.1  |
|170               |160               |-5.9  |
|128               |121               |-4.7  |

El error de medición no supera el ±10% en todo el rango probado. Entre 510 Ω y 5000 Ω el error es menor a ±1.2%; por debajo de 255 Ω aumenta hasta un 7.1%, ya que con resistencias bajas la caída de voltaje en el divisor es pequeña y pesan más el ruido y la resolución de la medición. Este rango de resistencias bajas corresponde al agua de mayor conductividad.

### 2.3. Simulaciones estructurales de las piezas de carcasa

Las simulaciones estáticas demuestran de forma analítica que las piezas estructurales críticas de FISHMON 365 resisten las cargas de operación. Los resultados dependen del material con que se fabrique cada pieza, por lo que la sonda y el carrete se evaluaron con distintos materiales (ABS, PETG y TPU).

El nivel TRL 3 exige una prueba de concepto analítica y/o experimental de las funciones críticas. En este proyecto, la función crítica estructural es que el dispositivo soporte el agua, la corriente y el izado de la sonda sin romperse ni deformarse. Así mismo, este documento cubre la parte analítica de esa prueba mediante análisis por elementos finitos (FEA).

Piezas evaluadas:

- Sonda (cuerpo + tapa + empaquetadura de sellado): queda sumergida hasta 5 m.
- Boya (cuerpo + cono): flota y aloja el mecanismo y la electrónica.
- Corona del reductor sinfín–corona: transmite el torque del motor.
- Carrete: enrolla el cable que sube y baja la sonda; va montado en el eje del motor.
- Carcasa del motorreductor: sostiene los ejes y rodamientos del mecanismo de izado.

#### 2.3.1. Metodología

Se realizaron análisis estáticos lineales en **SimScale**, con la geometría modelada en **Onshape** y exportada en formato STEP.

| Parámetro                                          | Valor                                    |
| -------------------------------------------------- | ---------------------------------------- |
| Tipo de análisis                                   | Estático lineal (FEA)                    |
| Material                                           | ABS, PETG y TPU 95A                      |
| Módulo de elasticidad (E)                          | ABS 1.8 GPa · PETG 2.0 GPa · TPU 26 MPa  |
| Coeficiente de Poisson (ν)                         | ABS 0.35 · PETG 0.38 · TPU 0.45          |
| Densidad                                           | ABS 1200 · PETG 1270 · TPU 1220 kg/m3    |
| Límite elástico                                    | ABS 40 MPa · PETG 50 MPa · TPU 8.6 MPa   |
| Contacto entre piezas (cuerpo–empaquetadura–tapa)  | Bonded (unido)                           |
| Criterio de falla                                  | Esfuerzo de Von Mises                    |

El factor de seguridad se calculó así:

<img src="/Imagenes/Simulaciones/form1.png" width="300"/>

FS = Límite elástico del material / Esfuerzo máximo (40 MPa ABS, 50 MPa PETG, 8.6 MPa TPU)

Criterio de aceptación: FS >=2, para cubrir defectos de impresión 3D, desgaste y variaciones del material.

#### 2.3.2. Justificación de las cargas

Cada carga se calculó a partir de las condiciones de uso del dispositivo en estanques de trucha, tomando el caso más desfavorable.

| Carga                            | Valor     | Origen                                                           |
| -------------------------------- | --------- | ---------------------------------------------------------------- |
| Presión hidrostática en la sonda | 49 050 Pa | Profundidad máxima de 5 m (lista de exigencias)                  |
| Presión sobre la boya            | 2 000 Pa  | Estimación conservadora de la parte sumergida                    |
| Fuerza de la corriente           | 2 N       | Arrastre con v = 0.3 m/s, velocidad típica en estanques          |
| Peso interno de la boya          | 10 N      | Masa estimada de 1 kg (motor, carrete, electrónica, batería)     |
| Fuerza máxima del cable          | 87 N      | Torque máximo del motor tras la reducción / radio del carrete    |
| Fuerza en el diente de la corona | 22 N      | Torque máximo / radio de la corona                               |
| Empuje axial del sinfín          | 30 N      | Reacción del engranaje sobre los apoyos del sinfín               |
| Torque en el carrete             | 1.52 N·m  | Fuerza máxima del cable × radio del tambor del carrete (17.5 mm) |

**Presión hidrostática:**

<img src="/Imagenes/Simulaciones/form2.png" width="300"/>

P = 1000\*9.81\*5= 49050 Pa

**Fuerza de arrastre de la corriente:**

<img src="/Imagenes/Simulaciones/form3.png" width="300"/>

FD= 1.6-2N (v= 0.3 m/s)

**Torque de salida del motor 28BYJ-48:**

T= 34 mN.m \* 32= 1.1Nm

**Fuerza máxima del cable** (carrete de 25 mm de diámetro):

<img src="/Imagenes/Simulaciones/form4.png" width="300"/>

F= 1.1/0.0125= 87N

La fuerza de 87 N corresponde al peor caso, cuando el motor trabaja a su torque máximo; por ejemplo, si la sonda se atasca. En operación normal, el cable solo soporta el peso aparente de la sonda en el agua (2–3 N).

**Torque en el carrete** (tambor de 35 mm de diámetro):

T = 87 N \* 0.0175 m = 1.52 N.m. Se aplicó este valor en el caso del carrete como condición conservadora.

#### 2.3.3. Casos simulados

Se simularon siete casos de carga; en cada uno se fijó la zona por donde la pieza se sujeta en el ensamble real.

| Caso | Pieza                        | Apoyo fijo                               | Cargas aplicadas                                                              |
| ---- | ---------------------------- | ---------------------------------------- | ----------------------------------------------------------------------------- |
| 1    | Sonda + tapa + empaquetadura | Punto de sujeción del cable              | Presión de 49 050 Pa en todas las caras exteriores                            |
| 2    | Sonda + tapa + empaquetadura | Punto de sujeción del cable              | Presión de 49 050 Pa + 87 N de tirón del cable                                |
| 3    | Boya (cuerpo + cono)         | Punta del cono (salida del cable)        | Presión de 2 000 Pa en el cono y el cilindro                                  |
| 4    | Boya (cuerpo + cono)         | Punta del cono                           | 2 N laterales (corriente) + 10 N verticales (peso interno)                    |
| 5    | Corona                       | Agujero central (eje)                    | 22 N tangenciales en un diente                                                |
| 6    | Carcasa del motorreductor    | Alojamientos de los tornillos de la base | 87 N en el apoyo del eje de la corona + 30 N axiales en los apoyos del sinfín |
| 7    | Carrete                      | Agujero en D (eje del motor)             | 87 N del cable en el tambor + torque de 1.52 N·m                              |

En la sonda se usó contacto _bonded_ entre el cuerpo, la tapa y la empaquetadura para representar el sellado. Los casos 1, 2 y 7 se simularon con distintos materiales para comparar su comportamiento.

#### 2.3.4. Resultados

Los resultados dependen del material. Con materiales rígidos (ABS y PETG) todos los casos superan el criterio de FS >= 2. Con TPU, que es un material flexible, la sonda resiste la presión pero se deforma mucho más, y en el carrete el esfuerzo en el agujero del eje supera su límite elástico.

| Caso | Pieza                                                  | Esfuerzo máx. Von Mises (MPa) | Deformación máx. (mm) | FS   | Resultado       |
| ---- | ------------------------------------------------------ | ----------------------------- | --------------------- | ---- | --------------- |
| 1    | Sonda – presión a 5 m (PETG)                           | 5.82                          | 0.25                  | 8.6  | Resiste         |
| 1    | Sonda – presión a 5 m (TPU)                            | 5.09                          | 15.9                  | 1.7  | Resiste, FS < 2 |
| 2    | Sonda – presión + cable 87 N (ABS + empaquetadura TPU) | 2.67                          | 0.13                  | 15   | Resiste         |
| 2    | Sonda – presión + cable 87 N (todo TPU)                | 2.49                          | 7.7                   | 3.5  | Resiste         |
| 3    | Boya – flotación                                       | 0.85                          | 0.04                  | 47   | Resiste         |
| 4    | Boya – corriente + peso interno                        | 0.67                          | 0.025                 | 60   | Resiste         |
| 5    | Corona – fuerza en el diente                           | 5.1                           | 0.013                 | 7.9  | Resiste         |
| 6    | Carcasa del motorreductor                              | 2.05                          | 0.054                 | 19.5 | Resiste         |
| 7    | Carrete – cable 87 N + torque (ABS)                    | 16.2                          | 0.14                  | 2.5  | Resiste         |
| 7    | Carrete – cable 87 N + torque (TPU)                    | 14.6                          | 9.4                   | 0.6  | No resiste      |

Las capturas de Von Mises y desplazamiento de cada caso se adjuntan como evidencia. En las imágenes de desplazamiento, el azul es la zona fija y el rojo el punto de mayor deformación; el rojo no indica falla.

Además, se revisó el esfuerzo de Von Mises solo en la empaquetadura de la sonda, que es la pieza que asegura el sellado:

| Caso | Material de la sonda           | Von Mises máx. en la empaquetadura (MPa) | FS de la empaquetadura |
| ---- | ------------------------------ | ---------------------------------------- | ---------------------- |
| 1    | PETG (empaquetadura de caucho) | 0.10                                     | ≈ 50 (caucho, 5 MPa)   |
| 1    | TPU                            | 3.80                                     | 2.3                    |
| 2    | ABS + empaquetadura TPU        | 0.18                                     | ≈ 48                   |
| 2    | Todo TPU                       | 1.94                                     | 4.4                    |

La empaquetadura trabaja por debajo del límite de su material en todos los casos, por lo que mantiene el sellado entre las piezas.


#### 2.3.5. Evidencia gráfica

Capturas de SimScale de cada caso: primero el esfuerzo de Von Mises y al lado el desplazamiento. En la sonda se agrega el esfuerzo de Von Mises solo en la empaquetadura.

##### Caso 1. Presión de la sonda sumergida a 5 metros
<table>
  <tr>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso1_petg_vm.jpg" width="100%">
      <br>
      <em>PETG – Von Mises</em>
    </td>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso1_petg_desp.jpg" width="100%">
      <br>
      <em>PETG – Desplazamiento</em>
    </td>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso1_petg_emp.jpg" width="100%">
      <br>
      <em>PETG – Von Mises en la empaquetadura</em>
    </td>
  </tr>
  <tr>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso1_tpu_vm.jpg" width="100%">
      <br>
      <em>TPU – Von Mises</em>
    </td>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso1_tpu_desp.jpg" width="100%">
      <br>
      <em>TPU – Desplazamiento</em>
    </td>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso1_tpu_emp.jpg" width="100%">
      <br>
      <em>TPU – Von Mises en la empaquetadura</em>
    </td>
  </tr>
</table>

##### Caso 2. Sonda a presión y con un cable que ejerce 87 N
<table>
  <tr>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso2_abs_vm.jpg" width="100%">
      <br>
      <em>ABS + empaquetadura TPU – Von Mises</em>
    </td>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso2_abs_desp.jpg" width="100%">
      <br>
      <em>ABS + empaquetadura TPU – Desplazamiento</em>
    </td>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso2_abs_emp.jpg" width="100%">
      <br>
      <em>ABS + empaquetadura TPU – Von Mises en la empaquetadura</em>
    </td>
  </tr>
  <tr>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso2_tpu_vm.jpg" width="100%">
      <br>
      <em>Todo TPU – Von Mises</em>
    </td>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso2_tpu_desp.jpg" width="100%">
      <br>
      <em>Todo TPU – Desplazamiento</em>
    </td>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso2_tpu_emp.jpg" width="100%">
      <br>
      <em>Todo TPU – Von Mises en la empaquetadura</em>
    </td>
  </tr>
</table>

##### Caso 3. Flotación de la boya
<table>
  <tr>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso3_1.png" width="100%">
      <br>
    </td>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso3_2.png" width="100%">
      <br>
    </td>
  </tr>
</table>

##### Caso 4. Flotación de la boya con una corriente y fuerza de gravedad
<table>
  <tr>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso4_1.png" width="100%">
      <br>
    </td>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso4_2.png" width="100%">
      <br>
    </td>
  </tr>
</table>

##### Caso 5. Prueba de fuerza en el diente del motorreductor
<table>
  <tr>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso5_1.png" width="100%">
      <br>
    </td>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso5_2.png" width="100%">
      <br>
    </td>
  </tr>
</table>

##### Caso 6. Prueba de carcasa del motorreductor
<table>
  <tr>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso6_1.png" width="100%">
      <br>
    </td>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso6_2.png" width="100%">
      <br>
    </td>
  </tr>
</table>

##### Caso 7. Prueba del carrete con el tirón del cable y el torque del motor
<table>
  <tr>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso7_abs_vm.jpg" width="100%">
      <br>
      <em>ABS – Von Mises</em>
    </td>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso7_abs_desp.jpg" width="100%">
      <br>
      <em>ABS – Desplazamiento</em>
    </td>
  </tr>
  <tr>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso7_tpu_vm.jpg" width="100%">
      <br>
      <em>TPU – Von Mises</em>
    </td>
    <td align="center">
      <img src="/Imagenes/Modulo_mecanico/caso7_tpu_desp.jpg" width="100%">
      <br>
      <em>TPU – Desplazamiento</em>
    </td>
  </tr>
</table>

#### 2.3.6. Conclusión de las simulaciones estructurales
El análisis demuestra que el concepto estructural de FISHMON 365 es viable, y que el comportamiento de cada pieza depende del material con que se fabrique.

- **Función de sellado y resistencia al agua:** la sonda soporta la presión a 5 m con todos los materiales evaluados. Con materiales rígidos (PETG y ABS) la deformación es menor a 0.3 mm; con TPU llega a 7.7–15.9 mm. La empaquetadura trabaja por debajo de su límite en todos los casos y mantiene el sellado.
- **Función de flotación:** la boya resiste la presión, la corriente y el peso interno con margen amplio (FS >=47).
- **Función de izado:** la corona y la carcasa soportan el torque máximo del motor, y la deformación de la carcasa (0.054 mm) no compromete la alineación del engranaje. El carrete en ABS soporta el tirón del cable con FS = 2.5; en TPU, el esfuerzo en el agujero del eje (14.6 MPa) supera el límite elástico del material.

Con estos resultados, la prueba analítica de las funciones estructurales críticas queda cubierta, lo que respalda el nivel TRL 3.

## 3. Conclusión e indicadores del cumplimiento del TRL-3

Los resultados obtenidos respaldan la viabilidad técnica de los principios de funcionamiento de FISHMON 365. Las simulaciones eléctricas y las pruebas preliminares de los sensores demuestran que es posible acondicionar y medir las señales de conductividad, oxígeno disuelto y pH. Asimismo, las simulaciones estructurales confirman que las piezas críticas soportan las cargas previstas con materiales rígidos (ABS y PETG), con factores de seguridad superiores al mínimo establecido.

| Indicador | Criterio de cumplimiento | Evidencia | Estado |
|---|---|---|---|
| Acondicionamiento de pH | Salida dentro del rango de 0–3 V del amplificador | Simulación 2.1.1 | Cumple |
| Acondicionamiento de oxígeno disuelto | Voltaje recuperado ≈ voltaje de entrada de la celda | Simulación 2.1.2 (23.2 mV vs 23.8 mV) | Cumple |
| Acondicionamiento de conductividad | Resistencia calculada ≈ resistencia real | Simulación 2.1.3 (153 Ω vs 150 Ω) | Cumple |
| Respuesta del sensor de oxígeno disuelto | Lecturas diferenciadas en 0% y 100% de saturación | Prueba 2.2.1 (≈ 9 mV vs ≈ 850 mV) | Cumple |
| Respuesta del sensor de pH | Voltaje distinto y ordenado para pH 4, 7 y 10 | Prueba 2.2.2 | Cumple |
| Medición de conductividad | Error ≤ ±10% | Prueba 2.2.3 (error máx. 7.1%) | Cumple |
| Resistencia estructural | FS ≥ 2 con las cargas más desfavorables | Simulaciones 2.3 (ABS y PETG) | Cumple |
| Resistencia a la inmersión prolongada | Sin ingreso de agua tras inmersión prolongada | — | Pendiente (prueba experimental) |

En conjunto, estas evidencias respaldan la viabilidad del concepto y permiten justificar el nivel de madurez tecnológica TRL 3, aunque todavía será necesario realizar pruebas experimentales integradas y de resistencia al agua para validar el funcionamiento del sistema completo.


