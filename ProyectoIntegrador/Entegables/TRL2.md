# TRL 2 – Formulación del Concepto Tecnológico

## 1. Introducción

### 1.1 ¿Qué representa el TRL 2?

El TRL 2 corresponde a una etapa de investigación aplicada en la que, a partir de los principios científicos identificados previamente, se formula un concepto tecnológico y se analizan sus posibles aplicaciones. En este nivel la aplicación propuesta todavía es especulativa, por lo que no se busca demostrar experimentalmente el funcionamiento de un prototipo, sino sustentar la viabilidad conceptual de una solución mediante literatura científica, antecedentes tecnológicos y una propuesta de proyecto.

Para este nivel se consideran como principales evidencias los artículos científicos relacionados directamente con la propuesta tecnológica, el análisis de patentabilidad y protección, y la formulación del perfil o propuesta del proyecto.

### 1.2 Antecedentes provenientes del TRL 1

Durante el TRL 1 se identificaron los principios científicos relacionados con la calidad del agua para la crianza de trucha arco iris (*Oncorhynchus mykiss*). Se determinaron como variables de interés el oxígeno disuelto, la temperatura, el pH, la turbidez y la conductividad, debido a su relación con las condiciones físico-químicas del medio acuático.

Asimismo, se analizaron los principios y métodos que permiten medir estas variables, estableciendo una base científica para considerar posteriormente su monitoreo mediante tecnologías de sensado.

### 1.3 Objetivo del TRL 2

El objetivo de esta etapa es formular el concepto tecnológico de **FishMon 365**, una propuesta de sistema para el monitoreo de parámetros de calidad del agua en la crianza de trucha arco iris, sustentando su posible funcionamiento mediante antecedentes científicos y tecnológicos.

Para ello se realizará una revisión del estado del arte de sistemas de monitoreo aplicados a acuicultura, se formulará una arquitectura conceptual de la solución, se establecerán sus funciones principales y se realizará una revisión preliminar de antecedentes relacionados con propiedad intelectual y patentabilidad.

## 2. Estado del arte de la propuesta tecnológica

### 2.1 Sistemas tecnológicos de monitoreo de calidad del agua

Diversas investigaciones muestran que las tecnologías IoT permiten monitorear continuamente parámetros físico-químicos del agua mediante sensores, unidades de procesamiento y sistemas de comunicación.

Adrián, Jiménez y Amundarain analizaron 13 investigaciones sobre monitoreo de calidad del agua con IoT. Aproximadamente el 69 % empleó microcontroladores Arduino y los parámetros más monitoreados fueron pH, temperatura, turbidez, sólidos disueltos, conductividad y oxígeno disuelto [[1]](#ref1). Su propuesta integra sensores, microcontrolador, comunicación inalámbrica, almacenamiento y visualización de datos.

Santamaría Masapuncho y Bayas Altamirano implementaron en Ecuador un sistema IoT organizado en tres capas: percepción, red y aplicación. Utilizaron sensores de pH, turbidez y cloro residual junto con Arduino Mega y NodeMCU ESP8266. El sistema alcanzó una disponibilidad de 97.3 % y una latencia media de 3.2 segundos [[2]](#ref2). El estudio también resalta la importancia de la calibración y mantenimiento de los sensores.

En Perú, Garcia-Gonzales y García-Estrella desarrollaron un sistema IoT de bajo costo que integró sensores de pH, turbidez, temperatura, sólidos disueltos y conductividad eléctrica. Durante 60 días se recopilaron 2880 registros automáticos, demostrando la posibilidad de realizar monitoreo continuo mediante sensores de bajo costo [[3]](#ref3).

Los tres antecedentes muestran que es técnicamente posible integrar sensores de diferentes parámetros físico-químicos con sistemas de procesamiento y comunicación IoT. Sin embargo, las aplicaciones revisadas se orientan principalmente al agua potable y al monitoreo ambiental. En consecuencia, se identifica la oportunidad de estudiar la adaptación de estas tecnologías al monitoreo de las condiciones del agua en sistemas de crianza de trucha arco iris, considerando variables específicas como oxígeno disuelto, temperatura, pH, turbidez y conductividad.

### 2.2 Aplicación de IoT en acuicultura

En el ámbito acuícola existen propuestas que emplean tecnologías IoT para monitorear las condiciones del agua y apoyar la gestión de los sistemas de cultivo.

PROCIENCIA registra un proyecto peruano orientado al desarrollo de un sistema IoT multiparámetro para estanques de trucha arco iris (*Oncorhynchus mykiss*). La propuesta considera el monitoreo en tiempo real de temperatura, pH y oxígeno disuelto, junto con procesamiento y transmisión de datos hacia servicios en la nube [[4]](#ref4).

Cuenca Luna et al. desarrollaron WiFish, una plataforma IoT para monitoreo acuícola basada en microcontroladores ESP32, sensores de pH y temperatura, transmisión por Wi-Fi y procesamiento en la nube. El sistema permite visualizar datos en tiempo real, generar alertas y realizar supervisión remota mediante una aplicación móvil [[5]](#ref5).

Estos antecedentes respaldan la formulación de FishMon 365 al demostrar que en sistemas acuícolas es posible integrar sensores para medir variables de calidad del agua, transmitir los datos mediante tecnologías IoT, almacenarlos en plataformas digitales y generar alertas para el monitoreo remoto. En particular, WiFish valida una arquitectura basada en ESP32, conectividad Wi-Fi, procesamiento en la nube y visualización mediante una aplicación móvil, mientras que el proyecto registrado por PROCIENCIA evidencia la aplicación de sistemas multiparámetro específicamente en el cultivo de trucha arco iris [4], [5].

### 2.3 Sistemas de monitoreo multiparámetro

Los sistemas multiparámetro permiten integrar varios sensores dentro de una misma plataforma para obtener una visión más completa de la calidad del agua.

Adrián, Jiménez y Amundarain identificaron sistemas IoT capaces de monitorear simultáneamente variables como pH, temperatura, turbidez, sólidos disueltos, conductividad y oxígeno disuelto, utilizando microcontroladores y módulos de comunicación para centralizar las mediciones [[1]](#ref1).

Por otro lado, WiFish integra sensores de pH y temperatura con un microcontrolador ESP32, transmisión por Wi-Fi, procesamiento en la nube, visualización remota y generación de alertas [[5]](#ref5).

Estos antecedentes muestran que es viable combinar diferentes sensores dentro de una sola arquitectura tecnológica, lo que respalda el enfoque multiparámetro de FishMon 365 para supervisar oxígeno disuelto, temperatura, pH, turbidez y conductividad.

### 2.4 Comparación de soluciones existentes

A partir de los antecedentes revisados, se compararon las principales características de las soluciones tecnológicas relacionadas con el monitoreo de calidad del agua.

| Solución / antecedente | Variables monitoreadas | Procesamiento / comunicación | Visualización y alertas | Aplicación |
|---|---|---|---|---|
| Sistemas revisados por Adrián et al. [[1]](#ref1) | pH, temperatura, turbidez, TDS, conductividad y oxígeno disuelto, según el sistema | Principalmente Arduino; diferentes tecnologías IoT | Depende de cada implementación | Monitoreo de calidad del agua |
| Santamaría Masapuncho y Bayas Altamirano [[2]](#ref2) | pH, turbidez y cloro residual | Arduino Mega + NodeMCU ESP8266 / Wi-Fi | Plataforma IoT y alertas | Planta de tratamiento de agua |
| Garcia-Gonzales y García-Estrella [[3]](#ref3) | pH, turbidez, temperatura, TDS y conductividad | Arduino Mega / comunicación IoT | Registro y monitoreo de datos | Agua en zona rural |
| Proyecto PROCIENCIA [[4]](#ref4) | Temperatura, pH y oxígeno disuelto | Microcontroladores / servicios en la nube | Monitoreo en tiempo real | Estanques de trucha arco iris |
| WiFish [[5]](#ref5) | pH y temperatura | ESP32 / Wi-Fi / Huawei Cloud | Aplicación móvil, bot de Telegram y alertas | Acuicultura |
| **FishMon 365** | **Oxígeno disuelto, temperatura, pH, turbidez y conductividad** | **Arduino Nano para lectura de sensores + ESP32 con LoRa para recepción y transmisión de datos** | **Dashboard para visualización de datos y generación de alertas** | **Crianza de trucha arco iris** |

FishMon 365 plantea una arquitectura en la que el Arduino Nano se encuentra conectado a los sensores sumergidos y se encarga de realizar la lectura de las variables de calidad del agua. Posteriormente, los datos son enviados al ESP32, que cumple la función de recibir la información y transmitirla mediante comunicación LoRa. Finalmente, las mediciones son enviadas a un dashboard para su visualización y para la generación de alertas.

## 3. Formulación del concepto tecnológico

### 3.1 Concepto de FishMon 365

FishMon 365 se plantea como un sistema tecnológico para el monitoreo continuo de la calidad del agua en sistemas de crianza de trucha arco iris (*Oncorhynchus mykiss*).

La propuesta integra sensores para medir oxígeno disuelto, temperatura, pH, turbidez y conductividad. Las señales generadas por estos sensores serán recibidas por un Arduino Nano, encargado de realizar la lectura de las variables monitoreadas y enviar la información obtenida hacia un ESP32.

El ESP32 recibirá los datos provenientes del Arduino Nano y se encargará de su transmisión inalámbrica mediante tecnología LoRa. Finalmente, la información será enviada hacia un dashboard, donde podrá ser visualizada de forma remota y se podrán generar alertas cuando alguno de los parámetros se encuentre fuera de los rangos establecidos.

### 3.2 Problema que busca atender

El monitoreo de la calidad del agua es una actividad importante en la crianza de trucha, ya que las variaciones en parámetros físico-químicos pueden modificar las condiciones del entorno acuático.

FishMon 365 busca reducir la dependencia de mediciones manuales y facilitar el seguimiento continuo de las condiciones del agua mediante sensores y transmisión remota de datos. De esta manera, el usuario podrá disponer de información actualizada sobre diferentes parámetros sin necesidad de realizar constantemente mediciones presenciales.

### 3.3 Propuesta de solución tecnológica

La propuesta consiste en desarrollar un sistema distribuido de monitoreo compuesto por una unidad de sensado, una unidad de adquisición de datos, una unidad de comunicación y una plataforma de visualización.

Los sensores sumergidos medirán las variables de calidad del agua y enviarán sus señales hacia un Arduino Nano. Este dispositivo será responsable de recibir y procesar las lecturas de los sensores y transferir la información hacia un ESP32.

Posteriormente, el ESP32 se encargará de transmitir los datos mediante comunicación LoRa. Finalmente, la información será integrada en un dashboard que permitirá consultar las mediciones, visualizar el comportamiento de las variables y generar alertas cuando los valores registrados se encuentren fuera de los rangos establecidos para la crianza de trucha arco iris.

### 3.4 Variables y sensores considerados

FishMon 365 considera cinco variables principales para el monitoreo de la calidad del agua: oxígeno disuelto, temperatura, pH, turbidez y conductividad.

Para cada variable se evaluaron diferentes alternativas de sensado mediante una matriz morfológica, considerando su posible integración con la arquitectura electrónica propuesta. A partir de esta evaluación se seleccionó una alternativa de sensor para cada parámetro:

- **pH:** sensor de pH con módulo de acondicionamiento de señal.
- **Turbidez:** sensor de turbidez para medición de partículas suspendidas en el agua.
- **Conductividad:** sensor de conductividad eléctrica con sonda para contacto con el agua.
- **Temperatura:** termistor NTC 10K sumergible.
- **Oxígeno disuelto:** sensor con sonda para medición de oxígeno disuelto en el agua.

Las señales obtenidas por estos sensores serán recibidas por el Arduino Nano, encargado de realizar la adquisición de las mediciones. Posteriormente, la información será enviada al ESP32 para su transmisión mediante LoRa y finalmente será presentada en el dashboard de FishMon 365.

La selección de estos sensores permite formular un sistema multiparámetro capaz de supervisar simultáneamente las principales variables de calidad del agua consideradas para la crianza de trucha arco iris.

## 4. Arquitectura conceptual de FishMon 365

La arquitectura conceptual de FishMon 365 se plantea a partir de lo identificado en el TRL 1, donde se reconoció que las condiciones del agua pueden variar según la profundidad. Por esta razón, el sistema considera mediciones en distintos niveles de la columna de agua.

FishMon 365 estará conformado por dos módulos principales: un módulo sumergible y un módulo flotante.

### 4.1 Módulo sumergible

El módulo sumergible contendrá los sensores encargados de medir las variables de calidad del agua: oxígeno disuelto, temperatura, pH, turbidez y conductividad. Este módulo será el encargado de realizar las mediciones directamente dentro del agua.

Se plantea que el módulo sumergible pueda tomar lecturas en tres niveles de profundidad:

- una profundidad baja o cercana al fondo;
- una profundidad intermedia;
- una profundidad cercana a la superficie.

De esta manera, el sistema permitirá comparar el comportamiento de las variables según la profundidad y obtener una representación más completa de las condiciones del agua.

### 4.2 Módulo flotante

El módulo flotante estará ubicado en la superficie y contendrá los elementos de comunicación y alimentación del sistema. En este módulo se considera integrar el ESP32, el sistema de transmisión LoRa, la batería y el mecanismo de soporte del sistema. Adicionalmente, se evalúa la incorporación de un motor como parte del funcionamiento del módulo, según los requerimientos del diseño final.

### 4.3 Adquisición y transferencia de datos

Las señales generadas por los sensores del módulo sumergible serán recibidas y organizadas por el sistema de adquisición de datos. Posteriormente, la información será enviada al módulo flotante, donde el ESP32 se encargará de recibir los datos y prepararlos para su transmisión.

### 4.4 Comunicación inalámbrica

El módulo flotante transmitirá la información mediante tecnología LoRa, permitiendo enviar las mediciones hacia un sistema receptor para su posterior visualización.

### 4.5 Visualización y alertas

Los datos transmitidos serán presentados en un dashboard, donde el usuario podrá visualizar las mediciones obtenidas en las distintas profundidades y recibir alertas cuando alguna variable se encuentre fuera de los rangos establecidos para la crianza de trucha arco iris.

### 4.6 Flujo conceptual del sistema

El funcionamiento general de FishMon 365 se resume de la siguiente manera:

1. El módulo sumergible toma mediciones de calidad del agua.
2. Las mediciones se realizan en tres niveles de profundidad.
3. La información es transferida hacia el módulo flotante.
4. El ESP32 recibe los datos y los transmite mediante LoRa.
5. La información llega al sistema receptor.
6. Los datos se muestran en un dashboard.
7. El sistema genera alertas cuando se detectan valores fuera de rango.

## 5. Funcionamiento esperado del sistema

FishMon 365 se plantea como una boya IoT autónoma capaz de realizar mediciones de calidad del agua en diferentes niveles de profundidad y transmitir los datos de manera inalámbrica para su monitoreo remoto.

El funcionamiento esperado del sistema se desarrolla de la siguiente manera:

1. El módulo flotante permanece en la superficie y contiene los elementos principales de alimentación, control y comunicación.
2. Mediante un mecanismo de descenso y elevación, el módulo sumergible se desplaza hacia los niveles de medición definidos: superficie, media agua y fondo.
3. En cada nivel, los sensores registran las variables de oxígeno disuelto, temperatura, pH, turbidez y conductividad.
4. Las señales generadas por los sensores son recibidas por el Arduino Nano, encargado de adquirir y organizar las lecturas.
5. La información obtenida es enviada mediante un único enlace hacia el ESP32 con LoRa ubicado en el módulo flotante.
6. El ESP32 transmite los datos de forma inalámbrica mediante tecnología LoRa hacia un sistema receptor.
7. La información recibida es almacenada y mostrada en un dashboard.
8. Las mediciones son comparadas con los rangos definidos para la crianza de trucha arco iris.
9. Cuando alguna variable se encuentra fuera del rango establecido, el sistema genera una alerta para informar al usuario.

De esta manera, FishMon 365 busca proporcionar datos multiparámetro y multinivel que faciliten el seguimiento continuo de las condiciones del agua.

## 6. Requisitos conceptuales

A partir del concepto tecnológico planteado y de los requerimientos previamente definidos para FishMon 365, se establecen los siguientes requisitos conceptuales:

### 6.1 Monitoreo multiparámetro

El sistema deberá permitir la medición de cinco variables relacionadas con la calidad del agua:

- oxígeno disuelto;
- temperatura;
- pH;
- turbidez;
- conductividad.

### 6.2 Monitoreo a diferentes profundidades

El módulo sumergible deberá realizar mediciones en tres niveles de la columna de agua:

- superficie;
- media agua;
- fondo.

Esto permitirá obtener datos de diferentes zonas del sistema de cultivo y comparar posibles variaciones según la profundidad.

### 6.3 Adquisición de datos

El Arduino Nano deberá recibir las señales provenientes de los sensores y organizar las lecturas antes de transferirlas al módulo de comunicación.

### 6.4 Comunicación inalámbrica

El sistema deberá integrar un ESP32 con tecnología LoRa para transmitir los datos recopilados desde la boya hacia un punto receptor.

### 6.5 Alimentación autónoma

FishMon 365 deberá contar con una fuente de alimentación basada en baterías y un sistema de carga y protección que permita su funcionamiento sin conexión permanente a la red eléctrica.

### 6.6 Movimiento del módulo sumergible

El sistema deberá incorporar un mecanismo de descenso y elevación que permita posicionar el módulo sumergible en los diferentes niveles de profundidad definidos para realizar las mediciones.

### 6.7 Visualización de datos

Las mediciones obtenidas deberán mostrarse mediante un dashboard que permita identificar la variable monitoreada, el valor registrado y el nivel de profundidad correspondiente.

### 6.8 Generación de alertas

El sistema deberá comparar las mediciones con los rangos establecidos para la crianza de trucha arco iris y generar alertas cuando se detecten valores fuera de los límites definidos.

### 6.9 Mantenimiento

El diseño deberá facilitar el acceso a sensores, batería, cables y componentes electrónicos para permitir su reemplazo, mantenimiento y calibración periódica.

## 7. Análisis de patentabilidad y protección

### 7.1 Búsqueda de patentes relacionadas

Como parte del análisis preliminar de patentabilidad de FishMon 365, se realizó una búsqueda de patentes relacionadas con tecnologías para la medición y monitoreo de la calidad del agua.

Entre las patentes identificadas se encuentran soluciones orientadas a instrumentos portátiles de medición, integración de múltiples sensores y transmisión inalámbrica de datos de calidad del agua.

Una de las patentes revisadas corresponde a un instrumento portátil diseñado para realizar mediciones de calidad del agua y proteger los componentes utilizados durante el proceso de medición [[6]](#ref6).

También se identificó una patente de un instrumento multiparámetro que integra sensores de conductividad o salinidad, potencial de oxidación-reducción, pH, gases disueltos y oxígeno disuelto, además de permitir el almacenamiento de los datos obtenidos [[7]](#ref7).

Asimismo, se encontró una patente correspondiente a un sistema inalámbrico de monitoreo multiparámetro de calidad del agua. Esta solución integra sensores, baterías, circuitos de control y módulos de comunicación inalámbrica conectados con un servidor para proporcionar información en tiempo real [[8]](#ref8).

Adicionalmente, se identificó la patente **WO2022119461A1**, denominada *Aquaculture monitoring device*, específicamente orientada al monitoreo acuícola. La propuesta utiliza una estructura con elementos de flotación e integra sensores de temperatura, pH y oxígeno disuelto, un microcomputador, una fuente de alimentación y conectividad inalámbrica. El sistema permite registrar las mediciones y enviar notificaciones cuando alguno de los parámetros presenta valores críticos [[9]](#ref9).

Esta patente resulta especialmente relevante para FishMon 365 debido a que combina monitoreo de calidad del agua, flotabilidad, sensores y comunicación inalámbrica dentro de una aplicación acuícola.

### 7.2 Comparación de las patentes con FishMon 365

Las patentes revisadas presentan características tecnológicas que también forman parte del concepto de FishMon 365, como el uso de múltiples sensores, procesamiento electrónico de las mediciones y transmisión de información hacia sistemas externos.

La patente *Aquaculture monitoring device* presenta una mayor similitud con FishMon 365, debido a que está diseñada específicamente para acuicultura, incorpora una estructura flotante y monitorea parámetros como temperatura, pH y oxígeno disuelto.

Sin embargo, FishMon 365 plantea una arquitectura compuesta por un módulo flotante y un módulo sumergible móvil. El sistema propone medir cinco variables —oxígeno disuelto, temperatura, pH, turbidez y conductividad— y realizar las mediciones en tres niveles de la columna de agua: superficie, media agua y fondo.

Además, FishMon 365 plantea un mecanismo de descenso y elevación del módulo sumergible, un Arduino Nano para la adquisición de las señales de los sensores, un ESP32 con LoRa para la transmisión de datos y un dashboard para la visualización y generación de alertas.

### 7.3 Evaluación preliminar de protección

La búsqueda realizada permite identificar que varios elementos individuales de FishMon 365, como los sensores multiparámetro, la transmisión inalámbrica, las estructuras flotantes y el almacenamiento de información, ya se encuentran presentes en tecnologías patentadas.

Por esta razón, una posible diferenciación de FishMon 365 no debería sustentarse únicamente en el uso de sensores o comunicación inalámbrica, sino en la integración y funcionamiento conjunto de sus componentes.

Entre los elementos que requieren un análisis posterior se encuentran:

- la combinación de un módulo flotante y un módulo sumergible móvil;
- el mecanismo de descenso y elevación de los sensores;
- la medición secuencial en superficie, media agua y fondo;
- la asociación de las mediciones con cada nivel de profundidad;
- la integración de cinco parámetros de calidad del agua en una sola solución;
- la comunicación mediante LoRa y la visualización mediante dashboard;
- la aplicación específica del sistema en la crianza de trucha arco iris.

La identificación de estos elementos no permite afirmar todavía que FishMon 365 sea patentable. Para determinarlo será necesario realizar una revisión más detallada de las reivindicaciones de las patentes encontradas y evaluar criterios como novedad y actividad inventiva.

## 8. Perfil del proyecto FishMon 365

### 8.1 Problema

La crianza de trucha arco iris requiere mantener condiciones adecuadas de calidad del agua. Sin embargo, las mediciones manuales y esporádicas pueden dificultar la detección oportuna de cambios en parámetros físico-químicos importantes.

Asimismo, las condiciones del agua pueden presentar variaciones según la profundidad, por lo que una medición realizada en un único punto puede no representar completamente el estado de la columna de agua.

### 8.2 Objetivo general

Desarrollar conceptualmente un sistema IoT autónomo para el monitoreo multiparámetro y multinivel de la calidad del agua en sistemas de crianza de trucha arco iris, utilizando sensores, comunicación LoRa y una plataforma de visualización con generación de alertas.

### 8.3 Objetivos específicos

- Monitorear oxígeno disuelto, temperatura, pH, turbidez y conductividad.
- Obtener mediciones en superficie, media agua y fondo.
- Integrar los sensores mediante un Arduino Nano para la adquisición de datos.
- Transmitir las mediciones mediante un ESP32 con tecnología LoRa.
- Visualizar la información obtenida en un dashboard.
- Generar alertas cuando las variables monitoreadas se encuentren fuera de los rangos establecidos.
- Plantear una arquitectura modular que facilite el mantenimiento y reemplazo de los componentes.

### 8.4 Usuarios y beneficiarios

FishMon 365 está orientado principalmente a productores y responsables de sistemas de crianza de trucha arco iris que requieran supervisar las condiciones del agua de forma continua.

La disponibilidad de información remota podría facilitar la identificación temprana de variaciones en las condiciones del cultivo y apoyar la toma de decisiones relacionadas con el manejo del agua.

### 8.5 Propuesta tecnológica

La propuesta consiste en una boya IoT compuesta por un módulo flotante y un módulo sumergible.

El módulo sumergible integra los sensores y el Arduino Nano para realizar las mediciones de calidad del agua. El módulo flotante contiene el ESP32 con LoRa, la batería y el mecanismo encargado del descenso y elevación del módulo sumergible.

La información obtenida será transmitida hacia un dashboard para su almacenamiento, visualización y generación de alertas.

### 8.6 Resultados esperados

A nivel conceptual, se espera obtener:

- una arquitectura definida para el sistema FishMon 365;
- una selección preliminar de sensores y componentes;
- un esquema de monitoreo en tres niveles de profundidad;
- una estrategia de comunicación mediante LoRa;
- una propuesta de visualización mediante dashboard;
- criterios para la generación de alertas;
- una base tecnológica para etapas posteriores de implementación y validación.

### 8.7 Alcance

En el TRL 2 se desarrolla la formulación conceptual de FishMon 365 y se sustenta su posible aplicación mediante antecedentes científicos y tecnológicos.

En esta etapa no se busca demostrar experimentalmente el funcionamiento completo del sistema, sino definir su estructura, componentes, funciones y aplicación propuesta.

### 8.8 Limitaciones

En esta etapa todavía no se validan experimentalmente aspectos como:

- precisión real de los sensores;
- alcance efectivo de la comunicación LoRa;
- autonomía real de la batería;
- funcionamiento del mecanismo de descenso y elevación;
- resistencia del sistema en condiciones reales de cultivo;
- funcionamiento integral del dashboard y las alertas.

Estos aspectos deberán evaluarse en niveles posteriores de madurez tecnológica.

## 9. Cumplimiento de indicadores del TRL 2

| Indicador del TRL 2 | Evidencia desarrollada en FishMon 365 |
|---|---|
| Artículos científicos directamente relacionados con la propuesta tecnológica | Se revisaron investigaciones sobre monitoreo IoT de calidad del agua, acuicultura y sistemas multiparámetro en la Sección 2. |
| Estado del arte de la aplicación tecnológica | Se analizaron y compararon soluciones existentes relacionadas con sensores, IoT, transmisión de datos, visualización y alertas. |
| Formulación del concepto tecnológico | Se definió FishMon 365 como una boya IoT autónoma para monitoreo multiparámetro y multinivel. |
| Arquitectura conceptual | Se establecieron un módulo flotante, un módulo sumergible, Arduino Nano, ESP32 con LoRa, sensores, mecanismo de movimiento y dashboard. |
| Aplicación propuesta | El sistema se orienta al monitoreo de la calidad del agua en la crianza de trucha arco iris. |
| Perfil o propuesta del proyecto | Se definieron el problema, objetivos, usuarios, propuesta tecnológica, resultados esperados, alcance y limitaciones. |
| Análisis de patentabilidad y protección | Se desarrollará mediante la búsqueda y comparación de antecedentes patentados relacionados con sistemas IoT de monitoreo acuícola y calidad del agua. |

## 10. Conclusión

Durante el TRL 2 se formuló el concepto tecnológico de FishMon 365 como una propuesta de monitoreo IoT para la calidad del agua en sistemas de crianza de trucha arco iris.

A partir de los principios científicos identificados en el TRL 1 y de la revisión de antecedentes tecnológicos, se definió una arquitectura compuesta por un módulo flotante y un módulo sumergible. La propuesta considera la medición de oxígeno disuelto, temperatura, pH, turbidez y conductividad en tres niveles de profundidad: superficie, media agua y fondo.

El concepto integra un Arduino Nano para la adquisición de las señales de los sensores, un ESP32 con LoRa para la transmisión inalámbrica, un mecanismo de descenso y elevación del módulo sumergible y un dashboard para la visualización de datos y generación de alertas.

De esta manera, FishMon 365 cuenta con una propuesta tecnológica formulada y sustentada conceptualmente, constituyendo la base para continuar hacia etapas posteriores de desarrollo, implementación y validación experimental.
---

## Referencias

<a id="ref1"></a>[1] M. Adrián, I. Jiménez, and I. Amundarain, “Sistemas de monitoreo de calidad del agua en acueductos usando sensores IoT (Internet de las cosas),” 2026. [Online]. Available: [https://www.researchgate.net/publication/415921220_Sistemas_de_monitoreo_de_calidad_del_agua_en_acueductos_usando_sensores_IoT_Internet_de_las_cosas](https://www.researchgate.net/publication/415921220_Sistemas_de_monitoreo_de_calidad_del_agua_en_acueductos_usando_sensores_IoT_Internet_de_las_cosas)

<a id="ref2"></a>[2] A. H. Santamaría Masapuncho and M. M. Bayas Altamirano, “Monitoreo y evaluación de parámetros de calidad de agua obtenidos por la Internet de las cosas (IoT) para la planta de tratamiento de agua potable El Carrizal, perteneciente a la parroquia San Miguel, del Cantón Salcedo, provincia de Cotopaxi,” *Revista Ingenio Global*, vol. 4, no. 2, pp. 280–300, 2025, doi: [10.62943/rig.v4n2.2025.380](https://doi.org/10.62943/rig.v4n2.2025.380). [Online]. Available: [https://editorialinnova.com/index.php/rig/article/view/380](https://editorialinnova.com/index.php/rig/article/view/380)

<a id="ref3"></a>[3] A. A. Garcia-Gonzales and C. García-Estrella, “Monitoreo de la calidad del agua para zonas rurales mediante un sistema de sensores de bajo costo basados en IoT,” *Revista Amazonía Digital*, vol. 5, no. 1, Art. no. e452, 2026, doi: [10.55873/rad.v5i1.452](https://doi.org/10.55873/rad.v5i1.452). [Online]. Available: [https://revistas.unamad.edu.pe/index.php/rad/article/view/452](https://revistas.unamad.edu.pe/index.php/rad/article/view/452)

<a id="ref4"></a>[4] Programa Nacional de Investigación Científica y Estudios Avanzados (PROCIENCIA), “Desarrollo y escalamiento de un sistema IoT multiparámetro para la gestión automatizada de calidad del agua en múltiples estanques de cultivo de *Oncorhynchus mykiss*,” Proyecto PE501097073-2025, Universidad Nacional Toribio Rodríguez de Mendoza de Amazonas, Perú, 2025. [Online]. Available: https://observatorio.prociencia.gob.pe/DetalleSubvencion/woz8JiZ4/desarrollo-y-escalamiento-de-un-sistema-iot-multiparametro-para-la-gestion-automatizada-de-calidad-del-agua-en-multiples-estanques-de-cultivo-de-oncorhynchus-mykiss

<a id="ref5"></a>[5] A. J. Cuenca Luna, R. D. Quelal Villarreal, F. S. Donoso Martínez, F. G. Cuzme Rodríguez, and P. D. Muñoz Criollo, “WiFish: Plataforma de monitoreo de acuicultura basada en IoT y cloud computing con cifrado AES-128,” *Revista Colombiana de Tecnologías de Avanzada (RCTA)*, vol. 2, no. 46, pp. 190–200, 2025, doi: [10.24054/rcta.v2i46.4140](https://doi.org/10.24054/rcta.v2i46.4140). [Online]. Available: [https://ojs.unipamplona.edu.co/index.php/rcta/article/view/4140](https://ojs.unipamplona.edu.co/index.php/rcta/article/view/4140)

<a id="ref6"></a>[6] Beijing Yongcheng Also Credit Science and Technology Development Co., Ltd., “Handheld water quality measuring instrument,” Utility Model CN216791993U, Jun. 21, 2022. [Online]. Available: https://worldwide.espacenet.com/patent/search/family/081998412/publication/CN216791993U?q=ti%20all%20%22Handheld%20water%20quality%20measuring%20instrument%22

<a id="ref7"></a>[7] Point Four Water Quality Technologies (Suzhou) Co., Ltd., “Handheld water quality measuring instrument,” Patent CN102809637A, Jan. 4, 2012. [Online]. Available: https://worldwide.espacenet.com/patent/search/family/047233397/publication/CN102809637A?q=ti%20all%20%22Handheld%20water%20quality%20measuring%20instrument%22

<a id="ref8"></a>[8] Hangzhou Zonwon Technology Co., Ltd., “Wireless water quality multi-parameter monitoring system,” Patent CN103969414A, Aug. 6, 2014. [Online]. Available: https://worldwide.espacenet.com/patent/search/family/051239164/publication/CN103969414A?q=ti%20all%20%22Wireless%20multi-parameter%20water-quality%20monitoring%20system%22

<a id="ref9"></a>[9] S. F. C. Salva, A. K. A. Gordo, M. E. P. Ceniza, and A. S. Chavez, “Aquaculture monitoring device,” Patent WO2022119461A1, Jun. 9, 2022. [Online]. Available: https://patents.google.com/patent/WO2022119461A1/en
