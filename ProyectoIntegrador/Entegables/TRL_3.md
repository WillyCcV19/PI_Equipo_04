# TRL 3 – Desarrollo y preparación de la prueba de concepto experimental de FishMon 365

**Universidad Peruana Cayetano Heredia**  
**Ingeniería Informática e Industrial – Proyecto Integrador | 2026-II**  
**Grupo 4**

> **Estado documental:** avance de TRL 3 en etapa de impresión 3D y ensamblaje. Las actividades de prueba, calibración y validación descritas como futuras **no se han ejecutado ni constituyen resultados**. Este documento continúa los TRL 1 y 2 aportados por el equipo; las características de hardware son selecciones conceptuales del TRL 2, pendientes de contrastarse con el montaje real.

## 1. Introducción

### 1.1. ¿Qué representa el TRL 3?

El nivel de madurez tecnológica 3 corresponde a la **demostración analítica y experimental de las funciones o características críticas de un concepto tecnológico**. A diferencia del TRL 2, donde se formula la aplicación, en TRL 3 se prepara y ejecuta una prueba de concepto que permite comprobar, mediante evidencia reproducible, si los principios y subsistemas esenciales pueden funcionar. No equivale a la validación de un producto completo en su ambiente operativo; esa pretensión excedería la evidencia propia de esta etapa [1], [2].

Para FishMon 365, la prueba de concepto deberá examinar, de manera progresiva, la lectura de variables de calidad del agua, la adquisición y transmisión de datos, la asociación de cada lectura con una profundidad y la operación básica del mecanismo de posicionamiento. El ensamblaje físico es una condición preparatoria importante, pero **no demuestra por sí mismo TRL 3**.

### 1.2. Continuidad con el TRL 1

En TRL 1 se identificó la relación entre las condiciones físico-químicas del agua y la crianza de trucha arco iris (*Oncorhynchus mykiss*). Se estudiaron cinco variables: oxígeno disuelto, temperatura, pH, turbidez y conductividad. Se documentó además que la temperatura y el oxígeno interactúan y que pueden existir diferencias espaciales en la columna de agua [3]–[7]. Estas conclusiones justifican la elección de un sistema multiparámetro y el interés por medir a distintas profundidades; **no demuestran todavía que el prototipo mida correctamente**.

### 1.3. Continuidad con el TRL 2

En TRL 2 se formuló **FishMon 365**, una boya de monitoreo para acuicultura formada por un módulo flotante y otro sumergible móvil. La arquitectura propuesta incluye sensores para las cinco variables, un Arduino Nano para adquisición, un ESP32 con LoRa para comunicación, un mecanismo motorizado de descenso/elevación, alimentación por batería y un dashboard con alertas. Se seleccionaron conceptualmente: sensor genérico de pH con amplificador personalizado, sensor infrarrojo de turbidez con fototransistor, circuito de conductividad basado en LM324, termistor NTC 10K sumergible y DFRobot Gravity DO Sensor. Estas elecciones proceden del TRL 2 y **deben verificarse contra los componentes efectivamente adquiridos y montados**.

### 1.4. Estado real y alcance del presente informe

A la fecha de redacción, el equipo informa que **está imprimiendo los modelos tridimensionales y ensamblando los componentes**. Por tanto, se documentan la justificación, los requisitos, el diseño de la prueba de concepto, los procedimientos de fabricación y montaje y los protocolos previstos. Quedan pendientes los resultados instrumentales, la calibración, las mediciones en agua, las pruebas de transmisión, las pruebas de autonomía y la comprobación del movimiento. No se atribuyen al prototipo valores de precisión, estabilidad, latencia, estanqueidad ni alcance de comunicación sin datos propios.

### 1.5. Convenciones

Se expresará oxígeno disuelto en mg/L, temperatura en °C, pH sin unidades, turbidez en NTU y conductividad en µS/cm indicando la temperatura de referencia. Cada ensayo futuro deberá registrar fecha, responsable, versión del prototipo, equipo patrón, condiciones ambientales y datos originales. Las referencias numéricas remiten a fuentes al final del documento. Las secciones **[PENDIENTE]** son campos de completado, no afirmaciones de cumplimiento.

## 2. Fundamento científico y tecnológico de la prueba de concepto

### 2.1. Necesidad de monitoreo multiparámetro

La calidad del agua para trucha no puede caracterizarse únicamente con una variable. El oxígeno disuelto está vinculado con la respiración y el desempeño fisiológico, mientras que la temperatura influye tanto en el metabolismo como en la solubilidad del oxígeno [3], [4]. El pH, la turbidez y la conductividad aportan información complementaria sobre el medio acuático [5], [8], [9]. Por ello, la prueba de concepto debe comprobar que cada cadena de medición produce datos identificables y que el sistema puede asociarlos sin confusión.

### 2.2. Justificación del monitoreo multinivel

En cuerpos de agua y estanques pueden presentarse gradientes verticales de oxígeno asociados a mezcla y estratificación [6]. Sin embargo, los patrones dependen de la profundidad, circulación, clima y operación del sistema. En consecuencia, la decisión de medir cerca de superficie, zona media y fondo se considera una **hipótesis de diseño pertinente**, no una demostración de que existirán diferencias en el estanque donde se utilice FishMon 365.

### 2.3. Principios de transducción y adquisición

- **Oxígeno disuelto:** la sonda propuesta deberá convertir una respuesta fisicoquímica relacionada con el oxígeno en una señal interpretable. La ecuación de conversión y la compensación aplicable dependen del modelo concreto; no deben suponerse sin su ficha técnica [10].
- **Temperatura:** el termistor NTC modifica su resistencia con la temperatura. Se deberá comprobar el circuito de acondicionamiento y la conversión resistencia–temperatura, considerando tolerancias y calibración [11].
- **pH:** la medición potenciométrica depende de la diferencia de potencial de un electrodo y de su referencia; requiere acondicionamiento de alta impedancia y calibración con soluciones tampón [12].
- **Turbidez:** el método óptico utiliza cambios en transmisión o dispersión de luz; la relación entre señal y NTU exige calibración para la geometría y el sensor realmente empleados [8].
- **Conductividad:** una celda de electrodos permite estimar conductancia; la conversión a conductividad depende de la constante de celda y de la temperatura. El diseño con LM324 es preliminar y deberá revisarse respecto de excitación, polarización y acondicionamiento [9].

### 2.4. Adquisición, comunicación y visualización

Los antecedentes de sistemas IoT de calidad del agua muestran la pertinencia de separar sensado, procesamiento, comunicación y visualización [13], [14]. En FishMon 365 se propone que el Arduino Nano digitalice o reciba las señales de los sensores y transfiera datos al ESP32. El ESP32 preparará los paquetes para LoRa; un receptor o pasarela deberá conectar esos paquetes con el almacenamiento y el dashboard. **LoRa no envía datos directamente a un dashboard de internet sin una ruta de recepción e integración definida.** La topología concreta, interfaces y protocolos deben documentarse antes del ensayo.

## 3. Objetivos e hipótesis de la prueba de concepto

### 3.1. Objetivo general

Desarrollar y preparar una prueba de concepto experimental de FishMon 365 mediante la fabricación y ensamblaje de su arquitectura modular, y establecer protocolos reproducibles para comprobar posteriormente la adquisición multiparámetro, el posicionamiento multinivel, la comunicación inalámbrica y la visualización de datos.

### 3.2. Objetivos específicos

1. Documentar los requisitos funcionales y las interfaces críticas derivados del TRL 2.
2. Fabricar y registrar las piezas físicas de los módulos flotante y sumergible conforme al diseño 3D vigente.
3. Ensamblar progresivamente los componentes mecánicos y electrónicos, verificando compatibilidad dimensional y accesibilidad para mantenimiento.
4. Preparar protocolos de comprobación de sensores, transmisión, movimiento, alimentación y dashboard.
5. Definir criterios de aceptación, trazabilidad y gestión de fallas para las pruebas futuras.
6. Analizar los resultados experimentales cuando estén disponibles y determinar si respaldan una prueba de concepto TRL 3.

### 3.3. Hipótesis tecnológica [POR COMPROBAR]

**Hipótesis principal:** una arquitectura modular que integre sensores físico-químicos, adquisición con Arduino Nano, comunicación mediante ESP32/LoRa y posicionamiento vertical permitirá obtener y registrar mediciones diferenciadas por profundidad en condiciones experimentales controladas.

**Hipótesis secundarias:** (a) cada cadena de medición podrá producir lecturas comparables con un instrumento o método de referencia; (b) los paquetes recibidos conservarán la identidad de parámetro, tiempo y profundidad; (c) el mecanismo podrá posicionar el módulo de sensado en los tres niveles establecidos sin comprometer la integridad del conjunto. Son proposiciones a ensayar, no conclusiones.

## 4. Arquitectura técnica propuesta

### 4.1. Subsistemas y responsabilidades

| Subsistema | Componentes conceptuales del TRL 2 | Función esperada | Estado de verificación |
|---|---|---|---|
| Sensado | Sondas de OD, NTC 10K, pH, turbidez, conductividad | Transformar variables del agua en señales | Pendiente |
| Adquisición | Arduino Nano | Lectura, conversión y organización de mediciones | Pendiente |
| Comunicación | ESP32 y LoRa | Recibir y transmitir registros | Pendiente |
| Mecánico sumergible | Carcasa y soportes impresos | Alojar y posicionar sensores | Impresión/ensamblaje en curso |
| Mecánico flotante | Boya/carcasa y soportes | Alojar alimentación, control y motor | Impresión/ensamblaje en curso |
| Posicionamiento | Motor, transmisión y sujeción | Descenso y elevación | Pendiente |
| Energía | Batería y protección | Alimentar el sistema | Pendiente |
| Visualización | Receptor/pasarela, almacenamiento, dashboard | Mostrar datos y alertas | Pendiente |

### 4.2. Cadena funcional de datos

**Agua → sensores → acondicionamiento → Arduino Nano → interfaz de transferencia → ESP32 → enlace LoRa → receptor/pasarela → almacenamiento → dashboard/alertas.**

Se debe completar el tipo de interfaz Arduino–ESP32 (UART, I²C u otra), niveles lógicos, velocidad de transmisión, formato de paquetes, tratamiento de errores, sincronización horaria y mecanismo de confirmación de recepción. No se asume una interfaz específica sin el esquemático definitivo.

### 4.3. Arquitectura mecánica

El módulo flotante deberá soportar el conjunto de control, comunicación, batería y mecanismo motorizado, manteniendo distribución de masas y acceso de mantenimiento. El módulo sumergible alojará las sondas y el circuito de adquisición, respetando las necesidades de contacto con agua de cada sensor. Debe evitarse que la protección de componentes electrónicos impida el contacto correcto de las sondas con la muestra.

### 4.4. Consideraciones de seguridad e integridad

Antes de sumergir cualquier módulo con electrónica, deberá revisarse la estanqueidad, los pasacables, el aislamiento, la protección eléctrica, la sujeción mecánica y la recuperación segura del conjunto. El ensayo de estanqueidad inicial se realizará sin electrónica energizada. La selección de materiales de impresión deberá considerar absorción de agua, uniones entre capas, orientación de fabricación y compatibilidad con sellos; una pieza impresa no debe presumirse hermética por su apariencia [15].

## 5. Desarrollo físico del prototipo: avance actual

### 5.1. Modelado y fabricación aditiva

A partir del modelado 3D presentado en TRL 2, se está avanzando en la fabricación de las piezas que conformarán los módulos. La manufactura aditiva permite iterar geometrías y comprobar ajuste de componentes, pero las propiedades finales dependen del material, orientación de capas, parámetros de impresión y posprocesado [15], [16]. No se especifican aquí material, impresora, porcentaje de relleno, altura de capa ni dimensiones porque el equipo todavía no ha aportado esos datos.

**Registro de fabricación por completar:**

| Campo | Dato del equipo |
|---|---|
| Versión CAD y enlace/captura | [PENDIENTE] |
| Pieza y función | [PENDIENTE] |
| Material y fabricante | [PENDIENTE] |
| Impresora y tecnología | [PENDIENTE] |
| Orientación, altura de capa, relleno y soportes | [PENDIENTE] |
| Fecha de impresión y duración | [PENDIENTE] |
| Defectos observados y correcciones | [PENDIENTE] |
| Fotografía de pieza fabricada | [PENDIENTE] |

### 5.2. Ensamblaje mecánico en curso

El ensamblaje actual comprende la integración progresiva de piezas impresas y componentes físicos. Para evitar afirmaciones no sustentadas, se registrará cada unión únicamente cuando exista fotografía, hoja de montaje o inspección. La secuencia de trabajo prevista es: inspección dimensional, ajuste en seco, verificación de alojamientos, instalación de fijaciones, montaje de mecanismos, organización de cables, preparación de sellos y revisión final antes de ensayos en agua.

**Bitácora de ensamblaje:** fecha; pieza; versión; componente acoplado; responsable; observación; acción correctiva; fotografía; estado (pendiente/en curso/terminado). **Estado declarado actualmente:** ensamblaje en curso, sin lista de componentes terminados confirmada.

### 5.3. Tolerancias, ajustes y mantenimiento

Se recomienda verificar interferencias entre piezas, holguras de movimiento, accesibilidad a sensores, posibilidad de reemplazo de batería y desmontaje sin destruir sellos. Los resultados de estas inspecciones se registrarán como **verificaciones de fabricación**, diferenciándolas de la comprobación funcional experimental.

### 5.4. Evidencias gráficas [PENDIENTES]

**Figura 1.** Vista general del CAD actualizado.  
**Figura 2.** Piezas impresas del módulo flotante.  
**Figura 3.** Piezas impresas del módulo sumergible.  
**Figura 4.** Ensamblaje mecánico parcial.  
**Figura 5.** Ubicación prevista de sensores, motor, batería y controladores.  

No se insertan imágenes ficticias. Cada figura deberá llevar fecha, autor, versión y descripción técnica.

## 6. Integración electrónica y de software: especificación preparatoria

### 6.1. Matriz de interfaces por completar

| Origen | Destino | Señal/protocolo | Tensión/alimentación | Evidencia |
|---|---|---|---|---|
| Sensor OD | Arduino Nano | [POR DEFINIR] | [POR DEFINIR] | Esquemático/ficha |
| Sensor temperatura | Arduino Nano | [POR DEFINIR] | [POR DEFINIR] | Esquemático/ficha |
| pH y acondicionador | Arduino Nano | [POR DEFINIR] | [POR DEFINIR] | Esquemático/ficha |
| Turbidez | Arduino Nano | [POR DEFINIR] | [POR DEFINIR] | Esquemático/ficha |
| Conductividad/LM324 | Arduino Nano | [POR DEFINIR] | [POR DEFINIR] | Esquemático/ficha |
| Arduino Nano | ESP32 | [POR DEFINIR] | Compatibilidad lógica por verificar | Esquemático |
| ESP32/LoRa | Receptor/pasarela | LoRa; configuración [POR DEFINIR] | [POR DEFINIR] | Registro de paquetes |
| Receptor/pasarela | Dashboard | [POR DEFINIR] | No aplica | Registro servidor |

### 6.2. Estructura propuesta de cada registro

Cada lectura debería incorporar, como mínimo: `id_dispositivo`, `fecha_hora`, `profundidad_o_nivel`, `parametro`, `valor`, `unidad`, `estado_sensor` y `secuencia`. La inclusión de un identificador y secuencia permitirá detectar duplicados o pérdidas; la marca temporal y la profundidad permitirán comparar niveles. Este esquema es una **recomendación de diseño**, no una función ya implementada.

### 6.3. Alertas y umbrales

Los rangos del TRL 1, tomados de FONDEPES y literatura especializada, son referencias biológicas iniciales, no umbrales instrumentales automáticamente validados para cualquier cultivo. La configuración final deberá considerar especie, etapa de crecimiento, condiciones locales, incertidumbre de medición e histéresis para evitar alertas repetitivas [3], [4]. La lógica de alertas aún no se ha ensayado.

## 7. Metodología de prueba de concepto: protocolos preparados, no ejecutados

### 7.1. Diseño experimental general

La estrategia será incremental: **prueba individual de sensor → verificación de adquisición → comunicación → posicionamiento → integración parcial → prueba de concepto del flujo completo**. Esta progresión reduce la dificultad de atribuir una falla a un subsistema. Antes de cada ensayo se fijarán criterios de aceptación, repeticiones justificadas, controles, condiciones de prueba y método de análisis.

### 7.2. Protocolo P01: inspección dimensional y ajuste

**Objetivo:** verificar compatibilidad entre piezas impresas y componentes. **Materiales:** CAD acotado, instrumento de medición dimensional y hoja de inspección. **Procedimiento:** identificar cotas críticas, medir cada pieza, calcular desviaciones y documentar interferencias. **Datos:** dimensión nominal, medida real, desviación y observaciones. **Aceptación:** tolerancias definidas previamente para cada interfaz. **Estado:** [PENDIENTE DE REGISTRO].

### 7.3. Protocolo P02: estanqueidad sin energización

**Objetivo:** identificar ingreso de agua en carcasas o uniones. **Procedimiento previsto:** ensamblar carcasa sin electrónica energizada, colocar testigos secos, sumergir a profundidad y tiempo controlados, inspeccionar interior y documentar filtraciones. **Variables:** profundidad, duración, condición de juntas y presencia de humedad. **Aceptación:** ausencia de ingreso de agua en el ensayo especificado; no equivale a certificación IP. **Estado:** [NO EJECUTADO].

### 7.4. Protocolo P03: calibración y contraste de sensores

**Objetivo:** determinar la respuesta inicial de cada cadena de medición frente a referencias apropiadas. **Diseño previsto:** utilizar soluciones patrón o instrumentos de referencia adecuados para pH y conductividad; referencia termométrica para temperatura; patrones o procedimientos ópticos adecuados para turbidez; y método de referencia de oxígeno disuelto apropiado, por ejemplo titulación Winkler o instrumento calibrado [9], [10], [12], [17]. Registrar lotes, incertidumbre y condiciones. **Variables:** valor de referencia, lectura del prototipo, temperatura, repeticiones y tiempo de estabilización. **Estado:** [NO EJECUTADO].

La comparación debe usar **error absoluto** `|x_medido − x_referencia|` y, cuando proceda, **error relativo porcentual** `100 × |x_medido − x_referencia| / |x_referencia|`; este último no se empleará cuando el valor de referencia sea cero o muy próximo a cero. Para pH se priorizará la diferencia en unidades de pH, no un porcentaje de pH. También se evaluarán dispersión, sesgo y estabilidad según el sensor.

### 7.5. Protocolo P04: comunicación y trazabilidad de paquetes

**Objetivo:** comprobar el envío desde adquisición hasta receptor. **Procedimiento:** generar secuencias de datos identificables, registrar paquetes emitidos y recibidos, comparar integridad de campos y medir pérdidas y tiempos de recepción. **Indicadores:** porcentaje de paquetes recibidos `100 × N_recibidos/N_enviados`, errores de integridad y latencia, si existe sincronización temporal válida. **Estado:** [NO EJECUTADO].

### 7.6. Protocolo P05: posicionamiento a tres profundidades

**Objetivo:** verificar que el mecanismo puede alcanzar tres posiciones repetibles. **Procedimiento:** definir profundidades reales en centímetros, ejecutar ciclos de descenso y elevación en un banco seguro, medir posición alcanzada y documentar atascos o deslizamientos. **Indicadores:** error de posición, repetibilidad, tiempo de desplazamiento y fallas por ciclo. **Estado:** [NO EJECUTADO].

### 7.7. Protocolo P06: integración de datos y dashboard

**Objetivo:** comprobar que cada dato se muestra con variable, unidad, fecha y profundidad correctas. **Procedimiento:** enviar datos de prueba etiquetados, comparar con los registros almacenados, verificar alertas con valores simulados claramente identificados y documentar fallas. **Advertencia:** los datos simulados sirven para probar software, **no para demostrar precisión de sensores**. **Estado:** [NO EJECUTADO].

### 7.8. Protocolo P07: consumo y autonomía preliminar

**Objetivo:** estimar consumo por modo operativo y verificar protecciones. **Procedimiento:** medir corriente y tensión en adquisición, comunicación y movimiento; registrar duración de los modos; estimar energía por ciclo. **Estimación:** `E_ciclo ≈ Σ(V_i × I_i × t_i)` con unidades consistentes. La autonomía teórica deberá contrastarse con capacidad utilizable, eficiencia y condiciones reales. **Estado:** [NO EJECUTADO].

## 8. Indicadores y criterios de aceptación

| Indicador | Fórmula o evidencia | Criterio antes de probar | Estado |
|---|---|---|---|
| Ajuste dimensional | Desviación respecto del CAD | Tolerancia por pieza [DEFINIR] | Pendiente |
| Estanqueidad inicial | Inspección de testigos e interior | Profundidad y duración [DEFINIR] | Pendiente |
| Error de temperatura | Diferencia frente a referencia | Límite [DEFINIR] | Pendiente |
| Error de pH | Diferencia en unidades de pH | Límite [DEFINIR] | Pendiente |
| Error de turbidez | Diferencia frente a referencia | Límite [DEFINIR] | Pendiente |
| Error de conductividad | Diferencia con compensación térmica indicada | Límite [DEFINIR] | Pendiente |
| Error de oxígeno | Diferencia en mg/L frente a referencia | Límite [DEFINIR] | Pendiente |
| Integridad de paquetes | Registros recibidos y válidos | Porcentaje [DEFINIR] | Pendiente |
| Posicionamiento | Error y dispersión por nivel | Límite [DEFINIR] | Pendiente |
| Integración dashboard | Coincidencia de campos y alertas | Casos de prueba [DEFINIR] | Pendiente |

**Nota metodológica:** no se inventan umbrales de precisión o alcance. Los límites deben justificarse con especificaciones de los componentes, incertidumbre del método patrón y necesidades de uso, **antes** de observar los resultados.

## 9. Estado de avance y trazabilidad

| Actividad | Evidencia disponible en los documentos entregados | Estado declarado |
|---|---|---|
| Principios científicos | TRL 1 | Documentado |
| Concepto, arquitectura y selección preliminar | TRL 2 | Documentado conceptualmente |
| Modelado 3D preliminar | Descrito en TRL 2; captura no incluida en el texto | Documentado conceptualmente |
| Impresión 3D | Información comunicada por el equipo | En curso; falta bitácora |
| Ensamblaje de componentes | Información comunicada por el equipo | En curso; falta bitácora |
| Esquemático y cableado definitivo | No aportado | Pendiente de confirmar |
| Calibración de sensores | Sin registros aportados | No acreditada |
| Ensayos de movimiento y estanqueidad | Sin registros aportados | No acreditados |
| Comunicación LoRa y dashboard | Sin resultados aportados | No acreditados |
| Prueba de concepto experimental | Sin datos experimentales aportados | **No acreditada todavía** |

### 9.1. Formato de bitácora

`Fecha | Responsable | Subsistema | Versión CAD/firmware | Actividad | Materiales/equipos | Observación | Evidencia (foto/archivo) | Incidencia | Acción siguiente`.

### 9.2. Control de versiones

Asignar una versión identificable a CAD, esquemático, firmware y configuración de ensayos. Cada dato experimental debe asociarse a la versión realmente utilizada para que una modificación posterior no invalide la trazabilidad.

## 10. Resultados experimentales [SECCIÓN RESERVADA]

**10.1. Resultados de inspección y estanqueidad:** [AGREGAR TABLAS, FOTOGRAFÍAS Y ANÁLISIS].  
**10.2. Resultados de calibración:** [AGREGAR VALORES PATRÓN, LECTURAS, ERRORES E INCERTIDUMBRE].  
**10.3. Resultados de comunicación:** [AGREGAR REGISTROS Y MÉTRICAS].  
**10.4. Resultados del mecanismo multinivel:** [AGREGAR CICLOS Y ERRORES].  
**10.5. Resultados de integración:** [AGREGAR TRAZAS Y CAPTURAS].  
**10.6. Discusión frente a hipótesis:** [REDACTAR SOLO DESPUÉS DE ENSAYAR].

## 11. Riesgos y limitaciones técnicas preliminares

| Riesgo | Posible efecto | Mitigación propuesta |
|---|---|---|
| Ingreso de agua | Daño eléctrico y pérdida de mediciones | Ensayo de carcasa sin energización y revisión de sellos |
| Error de calibración | Datos incorrectos | Referencias trazables y registros de ajuste |
| Incompatibilidad de niveles lógicos | Daño o comunicación errática | Revisar esquemático y fichas técnicas |
| Interferencia o ruido analógico | Lecturas inestables | Separar rutas, revisar tierra, filtrar y contrastar |
| Falla del mecanismo | Pérdida de posicionamiento | Topes, recuperación manual y pruebas por ciclos |
| Desbalance de la boya | Inestabilidad | Revisar masas, empuje y centro de gravedad |
| Pérdida de paquetes LoRa | Series incompletas | Secuencia, registro de errores y política de reintento |
| Bioincrustación y suciedad | Deriva de sensores | Plan de limpieza y recalibración |

La prioridad de cada riesgo se determinará con evidencia de fabricación y ensayos, no con una clasificación numérica arbitraria.

## 12. Matriz de cumplimiento del TRL 3

| Componente de la demostración TRL 3 | Evidencia necesaria | Situación actual |
|---|---|---|
| Concepto tecnológico definido | TRL 2 y arquitectura | Disponible |
| Fundamento científico | TRL 1 y literatura | Disponible |
| Diseño de prueba de concepto | Protocolos y criterios | Preparado en este documento; por revisar |
| Componentes físicos para ensayar | Piezas impresas y montaje | En fabricación y ensamblaje |
| Demostración de funciones críticas | Ensayos y datos originales | Pendiente |
| Análisis de resultados | Errores, repetibilidad, fallas | Pendiente |
| Informe de prueba de concepto | Evidencias y conclusiones basadas en resultados | Pendiente |

**Evaluación de madurez:** el proyecto se encuentra **en desarrollo hacia TRL 3**; no es metodológicamente correcto afirmar que ha completado TRL 3 solo por estar imprimiendo y ensamblando.

## 13. Conclusiones preliminares

1. Los documentos TRL 1 y TRL 2 proporcionan continuidad científica y conceptual para formular la prueba de concepto de FishMon 365: cinco variables físico-químicas, medición multinivel y arquitectura modular con adquisición, comunicación y visualización.
2. El avance material reportado corresponde a fabricación aditiva y ensamblaje. Es una etapa necesaria para preparar las pruebas, pero no permite concluir todavía que los sensores, el mecanismo o la comunicación cumplen sus funciones.
3. Se han establecido protocolos y criterios de trazabilidad que permitirán producir evidencia reproducible, sin atribuir al proyecto resultados que aún no existen.
4. La demostración de TRL 3 deberá fundamentarse en resultados experimentales de las funciones críticas, analizados frente a criterios definidos previamente. Hasta entonces, la condición correcta es **prueba de concepto en preparación**.

## 14. Referencias

> **Criterio bibliográfico:** se priorizan artículos revisados por pares y documentos científicos/técnicos de instituciones estadounidenses. Los documentos NASA, USGS, NIST y APHA son referencias técnicas institucionales; no se presentan falsamente como artículos arbitrados. Las referencias procedentes de TRL 1/2 se conservan como continuidad documental; las especificaciones de componentes deberán completarse con fichas oficiales de los modelos reales.

[1] J. C. Mankins, “Technology Readiness Levels: A White Paper,” NASA, 1995. [Documento técnico](https://www.nasa.gov/wp-content/uploads/2017/12/458490main_trl_definitions.pdf).  
[2] NASA, “Technology Readiness Levels,” *NASA Technology Transfer*. [Referencia institucional](https://www.nasa.gov/directorates/somd/space-communications-navigation-program/technology-readiness-levels/).  
[3] X. Jiang et al., “Effects of temperature, dissolved oxygen, and their interaction on the growth performance and condition of rainbow trout (*Oncorhynchus mykiss*),” *Journal of Thermal Biology*, 98, 102928, 2021. https://doi.org/10.1016/j.jtherbio.2021.102928.  
[4] Z.-S. Hou et al., “Environmental hypoxia causes growth retardation, osteoclast differentiation and calcium dyshomeostasis in juvenile rainbow trout (*Oncorhynchus mykiss*),” *Science of the Total Environment*, 705, 135272, 2020. https://doi.org/10.1016/j.scitotenv.2019.135272.  
[5] R. Pepe-Victoriano et al., “Evaluation of water quality in the production of rainbow trout (*Oncorhynchus mykiss*) in a recirculating aquaculture system (RAS) in the precordilleran region of northern Chile,” *Water*, 17(11), 1685, 2025. https://doi.org/10.3390/w17111685.  
[6] M. Oberle et al., “Diurnal stratification of oxygen in shallow aquaculture ponds in central Europe and recommendations for optimal aeration,” *Aquaculture*, 501, 482–487, 2019. https://doi.org/10.1016/j.aquaculture.2018.12.005.  
[7] U.S. Geological Survey, “Change to solubility equations for oxygen in water,” *Office of Water Quality Technical Memorandum 2011.03*, 2011. https://water.usgs.gov/water-resources/memos/documents/WQ.2011.03.pdf.  
[8] U.S. Geological Survey, “Turbidity and water,” *Water Science School*. https://www.usgs.gov/water-science-school/science/turbidity-and-water.  
[9] D. B. Radtke, J. V. Davis, and F. D. Wilde, “Specific electrical conductance,” *USGS Techniques of Water-Resources Investigations*, book 9, chap. A6.3, 2005. https://doi.org/10.3133/twri09A6.3.  
[10] California State Water Resources Control Board, “Dissolved oxygen measurement principles and methods,” *SWAMP Information Paper*. https://www.waterboards.ca.gov/water_issues/programs/swamp/docs/cwt/guidance/311.pdf.  
[11] D. C. Ripple and G. F. Strouse, “Selection of alternatives to liquid-in-glass thermometers,” *Journal of ASTM International*, 2(9), 2005. https://doi.org/10.1520/JAI13404.  
[12] U.S. Geological Survey, *Measurement of pH*, book 9, chap. A6.4, 2021. https://pubs.usgs.gov/publication/tm9A6.4.  
[13] A. J. Cuenca Luna et al., “WiFish: Plataforma de monitoreo de acuicultura basada en IoT y cloud computing con cifrado AES-128,” *Revista Colombiana de Tecnologías de Avanzada*, 2(46), 190–200, 2025. https://doi.org/10.24054/rcta.v2i46.4140.  
[14] A. A. Garcia-Gonzales and C. García-Estrella, “Monitoreo de la calidad del agua para zonas rurales mediante un sistema de sensores de bajo costo basados en IoT,” *Revista Amazonía Digital*, 5(1), e452, 2026. https://doi.org/10.55873/rad.v5i1.452.  
[15] B. M. Tymrak, M. Kreiger, and J. M. Pearce, “Mechanical properties of components fabricated with open-source 3-D printers under realistic environmental conditions,” *Materials & Design*, 58, 242–246, 2014. https://doi.org/10.1016/j.matdes.2014.02.038.  
[16] S. H. Ahn et al., “Anisotropic material properties of fused deposition modeling ABS,” *Rapid Prototyping Journal*, 8(4), 248–257, 2002. https://doi.org/10.1108/13552540210441166.  
[17] APHA, AWWA, and WEF, *Standard Methods for the Examination of Water and Wastewater*, 23rd ed., Washington, DC, 2017. ISBN 978-0-87553-287-5.

---

### Anexos por incorporar

**A.** Capturas CAD y planos acotados; **B.** bitácora de impresión; **C.** fotografías del ensamblaje; **D.** inventario y fichas de componentes; **E.** esquemáticos y mapa de pines; **F.** versiones de firmware; **G.** hojas de calibración y patrones; **H.** datos brutos de ensayos; **I.** gráficas y análisis; **J.** capturas del dashboard y registros de comunicación.
