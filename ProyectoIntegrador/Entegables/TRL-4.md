> [!WARNING]
> **BORRADOR – Documento en elaboración.** Este TRL-4 es un plan de pruebas: los criterios de aceptación son una propuesta y las tablas de resultados se completarán a medida que se realicen las pruebas en laboratorio.

El siguiente documento explicará:
- ¿Qué componentes de FISHMON 365 se integran en esta etapa?
- ¿Qué pruebas de laboratorio se realizarán para validar que funcionan juntos?
- ¿Qué criterios y evidencias demostrarán que se alcanza el nivel TRL 4?

## 1. Fundamento y objetivo de la validación en laboratorio

### 1.1. Fundamento

En el TRL 3 se demostró la viabilidad de los principios de funcionamiento de FISHMON 365: los circuitos de acondicionamiento de pH, oxígeno disuelto y conductividad fueron simulados y probados por separado, y las piezas estructurales fueron evaluadas mediante simulaciones por elementos finitos.

El nivel TRL 4 corresponde a la **validación de componentes y subsistemas en un entorno de laboratorio**. En esta etapa los componentes dejan de probarse de forma aislada y se integran en un prototipo de baja fidelidad (protoboard o placa provisional, piezas impresas en 3D y mecanismo de izado de prueba), para comprobar que funcionan juntos bajo condiciones controladas.

### 1.2. Objetivo de la validación

Validar en laboratorio el funcionamiento integrado de los subsistemas principales de FISHMON 365:
- Módulo electrónico: lectura simultánea y calibrada de pH, oxígeno disuelto y conductividad mediante el microcontrolador.
- Módulo mecánico: estanqueidad de la sonda impresa, flotación de la boya y funcionamiento del mecanismo de izado (motor + carrete).
- Módulo de energía: consumo del sistema y autonomía estimada con la batería.

### 1.3. Alcance

Las pruebas se realizan en laboratorio, con agua de grifo, soluciones de calibración y recipientes de profundidad limitada. La validación en un estanque de truchas real y a 5 m de profundidad corresponde a niveles posteriores (TRL 5–6).

## 2. Pruebas de validación

Cada prueba indica su objetivo, los materiales, el procedimiento, el criterio de aceptación y la tabla donde se registran los resultados.

### 2.1. Calibración de los sensores integrados al microcontrolador

**Objetivo:** convertir las lecturas del ADC del microcontrolador en unidades físicas (pH, mg/L y µS/cm) usando los circuitos de acondicionamiento validados en el TRL 3.

#### 2.1.1. Calibración de pH

**Materiales:** sensor de pH, circuito de acondicionamiento (sección 2.1.1 del TRL 3), microcontrolador, soluciones tampón de pH 4.00, 7.00 y 10.00, agua destilada para enjuagar.

**Procedimiento:**
1. Enjuagar el electrodo con agua destilada antes de cada solución.
2. Sumergir el electrodo en cada solución tampón y esperar a que la lectura se estabilice (al menos 2 minutos).
3. Registrar 5 lecturas por solución.
4. Calcular la recta de calibración (pendiente y desfase) por regresión lineal.
5. Verificar la calibración midiendo una muestra de pH conocido que no se haya usado en la calibración.

**Criterio de aceptación:** error de verificación <= +-0.2 unidades de pH y coeficiente de determinación R² >= 0.99.

| Solución tampón | Lectura 1 (mV) | Lectura 2 (mV) | Lectura 3 (mV) | Lectura 4 (mV) | Lectura 5 (mV) | Promedio (mV) |
|--|--|--|--|--|--|--|
| pH 4.00 | | | | | | |
| pH 7.00 | | | | | | |
| pH 10.00 | | | | | | |

| Pendiente (mV/pH) | Desfase (mV) | R² | pH de verificación (real) | pH medido | Error |
|--|--|--|--|--|--|
| | | | | | |

#### 2.1.2. Calibración de oxígeno disuelto

**Materiales:** sensor DFRobot Gravity SEN0237, circuito de acondicionamiento (sección 2.1.2 del TRL 3), microcontrolador, solución de sulfito de sodio (0%), agua aireada (100% de saturación), termómetro.

**Procedimiento:**
1. Medir la temperatura del agua, ya que la concentración de saturación depende de ella.
2. Calibrar el punto de 0% en la solución de sulfito de sodio, esperando a que la lectura se estabilice.
3. Calibrar el punto de 100% en agua aireada durante al menos 5 minutos (en el TRL 3 se observó que el sensor tarda unos 5 minutos en estabilizarse).
4. Convertir el voltaje a mg/L usando la tabla de saturación de oxígeno según la temperatura.
5. Repetir la medición de agua aireada 3 veces para comprobar la repetibilidad.

**Criterio de aceptación:** diferencia <= +-0.5 mg/L entre la lectura de agua aireada y el valor de saturación teórico a la temperatura medida.

| Punto | Temperatura (C) | Voltaje estable (mV) | Tiempo de estabilización (min) | OD teórico (mg/L) | OD medido (mg/L) | Error (mg/L) |
|--|--|--|--|--|--|--|
| 0% (sulfito) | | | | 0 | | |
| 100% (aireada) – rep. 1 | | | | | | |
| 100% (aireada) – rep. 2 | | | | | | |
| 100% (aireada) – rep. 3 | | | | | | |

#### 2.1.3. Calibración de conductividad

**Materiales:** celda de conductividad, circuito de acondicionamiento (sección 2.1.3 del TRL 3), microcontrolador, soluciones estándar de conductividad (por ejemplo, 1413 µS/cm y 12.88 mS/cm), termómetro.

**Procedimiento:**
1. Medir la resistencia de la celda en cada solución estándar.
2. Calcular la constante de la celda (K = conductividad estándar × resistencia medida).
3. Aplicar la compensación de temperatura a 25 C.
4. Verificar con agua de grifo y comparar con un conductímetro de referencia, si está disponible.

**Criterio de aceptación:** error <= +-10% respecto a la solución estándar (mismo criterio que en el TRL 3).

| Solución | Conductividad real (µS/cm) | Temperatura (C) | Resistencia medida (Ω) | Conductividad medida (µS/cm) | Error (%) |
|--|--|--|--|--|--|
| Estándar 1 | 1413 | | | | |
| Estándar 2 | 12 880 | | | | |
| Agua de grifo | (conductímetro de referencia) | | | | |

### 2.2. Lectura simultánea de los tres sensores

**Objetivo:** comprobar que los tres sensores funcionan a la vez sin interferirse. La señal pulsante del circuito de conductividad y la tierra virtual compartida pueden alterar las lecturas de pH y de oxígeno disuelto cuando todos los electrodos están en el mismo recipiente.

**Procedimiento:**
1. Sumergir los tres sensores en el mismo recipiente con agua.
2. Registrar las lecturas de pH y OD con el circuito de conductividad apagado.
3. Encender el circuito de conductividad y registrar de nuevo.
4. Registrar los tres parámetros cada minuto durante 60 minutos para evaluar la estabilidad.

**Criterio de aceptación:** la diferencia en pH y OD con la conductividad encendida o apagada es menor que el error permitido en la calibración (+-0.2 pH y +-0.5 mg/L), y la variación durante 60 minutos se mantiene dentro de ese mismo margen.

| Condición | pH | OD (mg/L) | Conductividad (µS/cm) |
|--|--|--|--|
| Conductividad apagada | | | — |
| Conductividad encendida | | | |
| Diferencia | | | — |

| Parámetro | Mínimo en 60 min | Máximo en 60 min | Variación |
|--|--|--|--|
| pH | | | |
| OD (mg/L) | | | |
| Conductividad (µS/cm) | | | |

### 2.3. Estanqueidad de la sonda impresa

**Objetivo:** validar de forma experimental que la sonda impresa en 3D (cuerpo + tapa + empaquetadura) no deja ingresar agua. En el TRL 3 esto solo se verificó de forma analítica y quedó pendiente.

**Materiales:** sonda impresa con su empaquetadura, papel absorbente o papel indicador de humedad, balde o tanque, balanza.

**Procedimiento:**
1. Colocar papel absorbente seco dentro de la sonda y pesarlo.
2. Cerrar la sonda con la empaquetadura y los tornillos o el sistema de cierre previsto.
3. Sumergirla a la mayor profundidad disponible en el laboratorio.
4. Retirarla a las 1, 6 y 24 horas, secar el exterior, abrirla y revisar el papel (aspecto y peso).
5. Registrar fotos de la sonda sumergida y del papel después de cada prueba.

**Criterio de aceptación:** sin ingreso de agua visible ni aumento de peso del papel después de 24 horas.

| Tiempo de inmersión | Profundidad (m) | Material de la sonda | Peso inicial del papel (g) | Peso final del papel (g) | ¿Ingreso de agua? |
|--|--|--|--|--|--|
| 1 h | | | | | |
| 6 h | | | | | |
| 24 h | | | | | |

> La prueba a 5 m de profundidad (49 050 Pa) no es posible en laboratorio; queda para la validación en campo.

### 2.4. Flotación y estabilidad de la boya

**Objetivo:** comprobar que la boya impresa flota con la carga interna prevista (motor, carrete, electrónica y batería, unos 1 kg) y se mantiene estable.

**Procedimiento:**
1. Pesar la boya vacía y con toda la carga interna.
2. Colocarla en un tanque y marcar la línea de flotación.
3. Medir la altura que queda fuera del agua y la inclinación.
4. Aplicar un empuje lateral leve (simulando la corriente) y observar si regresa a su posición.
5. Dejarla flotando 1 hora y revisar si ingresa agua.

**Criterio de aceptación:** la boya flota con la carga completa, la línea de flotación queda por debajo de la tapa, la inclinación es menor a 10 grados y recupera su posición tras el empuje.

| Condición | Masa total (kg) | Altura fuera del agua (mm) | Inclinación (grados) | ¿Recupera su posición? | ¿Ingreso de agua? |
|--|--|--|--|--|--|
| Boya vacía | | | | | |
| Boya con carga completa | | | | | |

### 2.5. Mecanismo de izado (motor + carrete)

**Objetivo:** validar que el motor y el carrete suben y bajan la sonda de forma controlada y que el carrete impreso soporta la operación. En el TRL 3 se estimó un torque de 1.52 N·m en el carrete para el caso más desfavorable.

**Materiales:** motor seleccionado, carrete impreso (en ABS, según el caso 7 del TRL 3), cable, sonda con su peso real, driver del motor, multímetro o sensor de corriente, cinta métrica, cronómetro.

**Procedimiento:**
1. Montar el carrete en el eje del motor y fijar el conjunto a una estructura de prueba.
2. Bajar y subir la sonda una distancia conocida (por ejemplo, 1 m) dentro de un tanque o en vertical.
3. Medir el tiempo, la corriente consumida y la distancia real recorrida.
4. Programar una profundidad objetivo y medir el error de posición.
5. Repetir 10 ciclos de subida y bajada y revisar el carrete y el agujero del eje (desgaste o deformación).

**Criterio de aceptación:** el sistema sube y baja la sonda sin atascarse en los 10 ciclos, el error de posición es <= +-5 cm y el carrete no presenta grietas ni deformación visible en el agujero del eje.

| Ciclo | Distancia objetivo (m) | Distancia real (m) | Error (cm) | Tiempo de subida (s) | Corriente máx. (A) | Observaciones |
|--|--|--|--|--|--|--|
| 1 | | | | | | |
| 2 | | | | | | |
| 3 | | | | | | |
| … | | | | | | |
| 10 | | | | | | |

### 2.6. Consumo de energía y autonomía

**Objetivo:** medir el consumo de cada modo de operación y estimar la autonomía con la batería seleccionada.

**Procedimiento:**
1. Medir la corriente del sistema en reposo, durante la medición de los sensores y durante el izado.
2. Registrar el tiempo que el sistema pasa en cada modo durante un ciclo de medición.
3. Calcular el consumo promedio y la autonomía (capacidad de la batería / corriente promedio).

**Criterio de aceptación:** autonomía estimada igual o mayor a la definida en la lista de exigencias del proyecto.

| Modo | Corriente (mA) | Tiempo por ciclo (s) | Carga por ciclo (mAh) |
|--|--|--|--|
| Reposo | | | |
| Medición de sensores | | | |
| Izado (subida/bajada) | | | |
| **Total por ciclo** | | | |

| Capacidad de la batería (mAh) | Ciclos por día | Consumo diario (mAh) | Autonomía estimada (días) |
|--|--|--|--|
| | | | |

## 3. Indicadores del cumplimiento del TRL-4

| Indicador | Criterio de cumplimiento | Prueba | Estado |
|---|---|---|---|
| Calibración de pH | Error <= +-0.2 pH, R² >= 0.99 | 2.1.1 | Pendiente |
| Calibración de oxígeno disuelto | Error <= +-0.5 mg/L | 2.1.2 | Pendiente |
| Calibración de conductividad | Error <= +-10% | 2.1.3 | Pendiente |
| Lectura simultánea sin interferencia | Diferencia menor al error de calibración | 2.2 | Pendiente |
| Estabilidad de lectura | Variación en 60 min dentro del error de calibración | 2.2 | Pendiente |
| Estanqueidad de la sonda | Sin ingreso de agua en 24 h | 2.3 | Pendiente |
| Flotación de la boya | Flota con 1 kg de carga, inclinación < 10 grados | 2.4 | Pendiente |
| Mecanismo de izado | 10 ciclos sin fallas, error <= +-5 cm | 2.5 | Pendiente |
| Autonomía | >= autonomía de la lista de exigencias | 2.6 | Pendiente |

El nivel TRL 4 se considera alcanzado cuando todos los indicadores están en estado **Cumple**, ya que eso demuestra que los subsistemas de FISHMON 365 funcionan integrados en el laboratorio.

## 4. Riesgos y limitaciones

- **Profundidad:** el laboratorio no permite reproducir la presión a 5 m; la estanqueidad a esa profundidad se valida en campo.
- **Interferencia eléctrica:** si la conductividad altera las lecturas de pH u OD, se deberá alternar la medición de los sensores (medir uno a la vez) o aislar sus tierras.
- **Material de impresión:** según el TRL 3, el comportamiento de la sonda y del carrete depende del material; los resultados de estas pruebas valen solo para el material con que se imprima cada pieza.
- **Calidad del agua de laboratorio:** el agua de grifo no reproduce las condiciones de un estanque de truchas (temperatura, materia orgánica, algas).

## 5. Conclusión

Este documento define las pruebas de laboratorio que permitirán validar FISHMON 365 en el nivel TRL 4. Al completarlas, se contará con evidencia de que los sensores calibrados, la sonda, la boya, el mecanismo de izado y el sistema de energía funcionan de forma integrada, lo que permitirá pasar a la validación en un entorno relevante (TRL 5).

## 6. Referencias

- DFRobot. *Gravity: Analog Dissolved Oxygen Sensor (SEN0237)* (documentación del producto).
- Intersil. *CA3140, CA3140A: 4.5 MHz, BiMOS Operational Amplifier with MOSFET Input/CMOS Output* (hoja de datos).
- FISHMON 365. *TRL-3: Prueba de concepto* (documento previo del proyecto).
