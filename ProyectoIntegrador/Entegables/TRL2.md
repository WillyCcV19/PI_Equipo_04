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

---

## Referencias

<a id="ref1"></a>[1] M. Adrián, I. Jiménez, and I. Amundarain, “Sistemas de monitoreo de calidad del agua en acueductos usando sensores IoT (Internet de las cosas),” 2026. [Online]. Available: [https://www.researchgate.net/publication/415921220_Sistemas_de_monitoreo_de_calidad_del_agua_en_acueductos_usando_sensores_IoT_Internet_de_las_cosas](https://www.researchgate.net/publication/415921220_Sistemas_de_monitoreo_de_calidad_del_agua_en_acueductos_usando_sensores_IoT_Internet_de_las_cosas)

<a id="ref2"></a>[2] A. H. Santamaría Masapuncho and M. M. Bayas Altamirano, “Monitoreo y evaluación de parámetros de calidad de agua obtenidos por la Internet de las cosas (IoT) para la planta de tratamiento de agua potable El Carrizal, perteneciente a la parroquia San Miguel, del Cantón Salcedo, provincia de Cotopaxi,” *Revista Ingenio Global*, vol. 4, no. 2, pp. 280–300, 2025, doi: [10.62943/rig.v4n2.2025.380](https://doi.org/10.62943/rig.v4n2.2025.380). [Online]. Available: [https://editorialinnova.com/index.php/rig/article/view/380](https://editorialinnova.com/index.php/rig/article/view/380)

<a id="ref3"></a>[3] A. A. Garcia-Gonzales and C. García-Estrella, “Monitoreo de la calidad del agua para zonas rurales mediante un sistema de sensores de bajo costo basados en IoT,” *Revista Amazonía Digital*, vol. 5, no. 1, Art. no. e452, 2026, doi: [10.55873/rad.v5i1.452](https://doi.org/10.55873/rad.v5i1.452). [Online]. Available: [https://revistas.unamad.edu.pe/index.php/rad/article/view/452](https://revistas.unamad.edu.pe/index.php/rad/article/view/452)

<a id="ref4"></a>[4] Programa Nacional de Investigación Científica y Estudios Avanzados (PROCIENCIA), “Desarrollo y escalamiento de un sistema IoT multiparámetro para la gestión automatizada de calidad del agua en múltiples estanques de cultivo de *Oncorhynchus mykiss*,” Proyecto PE501097073-2025, Universidad Nacional Toribio Rodríguez de Mendoza de Amazonas, Perú, 2025. [Online]. Available: https://observatorio.prociencia.gob.pe/DetalleSubvencion/woz8JiZ4/desarrollo-y-escalamiento-de-un-sistema-iot-multiparametro-para-la-gestion-automatizada-de-calidad-del-agua-en-multiples-estanques-de-cultivo-de-oncorhynchus-mykiss

<a id="ref5"></a>[5] A. J. Cuenca Luna, R. D. Quelal Villarreal, F. S. Donoso Martínez, F. G. Cuzme Rodríguez, and P. D. Muñoz Criollo, “WiFish: Plataforma de monitoreo de acuicultura basada en IoT y cloud computing con cifrado AES-128,” *Revista Colombiana de Tecnologías de Avanzada (RCTA)*, vol. 2, no. 46, pp. 190–200, 2025, doi: [10.24054/rcta.v2i46.4140](https://doi.org/10.24054/rcta.v2i46.4140). [Online]. Available: [https://ojs.unipamplona.edu.co/index.php/rcta/article/view/4140](https://ojs.unipamplona.edu.co/index.php/rcta/article/view/4140)
