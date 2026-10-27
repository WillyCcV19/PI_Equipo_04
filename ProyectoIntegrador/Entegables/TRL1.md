# TRL 1 – Identificación de Principios Fundamentales

<div align="center">

### Universidad Peruana Cayetano Heredia

**Carrera de Ingeniería Informática – Proyecto Integrador**  
**2026-II**

### Grupo 4

Quispitongo Leon Verenisse Mary  
Karita John Kenneth  
Cabrera Cermeno Ruben Andre  
Ccatamayo Vasquez Willy Simeon  
Pauccara Huancara Eber  

</div>

---

## 1. Introducción

La primera etapa del desarrollo tecnológico corresponde al **TRL 1**, nivel en el cual se estudian y reportan los principios básicos que podrían servir posteriormente como fundamento para una tecnología.

En esta etapa se realizó una revisión inicial de los factores físico-químicos relacionados con la calidad del agua en la crianza de trucha arco iris (*Oncorhynchus mykiss*), tomando como principal referencia el *Manual de Cultivo de Trucha en Ambientes Convencionales* de FONDEPES.

El objetivo de esta etapa no es desarrollar todavía una solución tecnológica, sino comprender los fenómenos y principios científicos relacionados con las condiciones del agua y su influencia sobre la trucha.

---

## 2. Indicador 1: Identificación del principio de la tecnología

El principio fundamental identificado consiste en que las condiciones físico-químicas del agua influyen directamente en la supervivencia, crecimiento y bienestar de la trucha arco iris (*Oncorhynchus mykiss*).

Entre los principales parámetros relacionados con estas condiciones se encuentran el oxígeno disuelto, la temperatura, el pH, la turbidez y la conductividad [1].

### Oxígeno disuelto

El oxígeno disuelto corresponde a la cantidad de oxígeno disponible en el agua para la respiración de los organismos acuáticos.

En la crianza de trucha constituye uno de los parámetros más críticos, debido a que una reducción significativa de su concentración puede producir estrés, asfixia y mortalidad [1], [3].

De acuerdo con FONDEPES, se recomienda que la concentración de oxígeno disuelto no sea menor a **5.5 mg/L**. Asimismo, se identifican los siguientes valores de referencia [1]:

- **< 3.0 mg/L:** condición crítica asociada a mortalidad.
- **3.1 – 4.5 mg/L:** condición de estrés grave.
- **5.5 mg/L:** concentración mínima recomendada.
- **6.0 – 8.5 mg/L:** rango favorable para el cultivo.

Por ello, se identifica como principio fundamental la relación existente entre la disponibilidad de oxígeno en el agua y las condiciones necesarias para la supervivencia y desarrollo de la trucha.

Para obtener una mejor estimación de los niveles de oxígeno disuelto se consideran parámetros como la temperatura, presión y salinidad.

La salinidad puede estimarse a partir de la conductividad del agua mediante la siguiente ecuación empírica:

$$
S = 5.572 \times 10^{-4}(SC) + 2.02 \times 10^{-9}(SC)^2
$$

[6]

Donde:

- **S:** salinidad estimada del agua.
- **SC:** conductividad del agua.

Esta ecuación puede no ser aplicable si la composición actual del agua es muy diferente a la del agua de mar [Fuente].

Con los parámetros mencionados anteriormente se puede estimar la concentración de oxígeno disuelto utilizando distintos factores de corrección, mediante la siguiente expresión utilizada en las estimaciones de Weiss (1970) y Benson-Krause (1980, 1984):

$$
[DO] = DO_0 \times F_s \times F_p
$$

Donde:

- **DO:** oxígeno disuelto.
- **DO₀:** concentración base de oxígeno disuelto en agua dulce.
- **Fs:** factor de corrección de salinidad.
- **Fp:** factor de corrección de presión.

Para mayor detalle, véase [6].

El USGS utilizó las formulaciones de Weiss y posteriormente adoptó las de Benson y Krause en **DOTABLES 3.0**, publicada en 2011.

Finalmente, existen tres métodos principales para determinar el oxígeno disuelto en agua [5]:

- Método colorimétrico.
- Método de Winkler o titulación.
- Método electrométrico.

### Temperatura

La temperatura del agua influye en procesos biológicos como el metabolismo, el consumo de alimento y el crecimiento de la trucha.

Según FONDEPES, un rango aproximado de **11 °C a 16 °C** presenta condiciones favorables para el cultivo [1].

Estudios experimentales en *Oncorhynchus mykiss* también han demostrado que la temperatura y el oxígeno disuelto interactúan y pueden afectar el crecimiento y la condición fisiológica de los peces [2].

La temperatura puede medirse mediante distintos tipos de termómetros, además de los termómetros de líquido en vidrio, entre ellos [7]:

- Termómetros de resistencia de platino (RTD).
- Termistores.
- Termopares.

### Potencial de hidrógeno (pH)

El pH permite determinar el grado de acidez o alcalinidad del agua.

Para la crianza de trucha arco iris se considera favorable un rango aproximado entre **7.0 y 8.0** [1].

Las variaciones significativas de este parámetro pueden generar condiciones inadecuadas para el desarrollo de los peces y afectar sus procesos fisiológicos.

### Turbidez

La turbidez está relacionada con la presencia de partículas y sólidos suspendidos en el agua.

Una elevada concentración de estos materiales puede afectar las branquias de los peces y disminuir la calidad del medio acuático [1].

Por esta razón, la turbidez también fue identificada como un parámetro relevante para comprender las condiciones ambientales asociadas con la crianza de trucha arco iris.

### Conductividad

La conductividad eléctrica del agua representa su capacidad para conducir corriente eléctrica y está relacionada con la concentración de sales e iones disueltos presentes en el medio.

En la documentación técnica revisada para FishMon 365 se considera como referencia un rango aproximado de **20 a 500 µS/cm**, mientras que valores superiores a **500 µS/cm** pueden considerarse una señal de alerta. Asimismo, cambios bruscos en la conductividad pueden indicar modificaciones en la concentración de sales disueltas o posibles aportes de sedimentos al agua.

La conductividad también resulta relevante porque puede utilizarse como una variable auxiliar para estimar la salinidad del agua, parámetro que interviene en los cálculos de solubilidad y concentración del oxígeno disuelto.

### Principio identificado

A partir de la revisión realizada se establece que la calidad del agua depende de la interacción de diferentes parámetros físico-químicos y que sus variaciones pueden generar condiciones favorables o de riesgo para la trucha arco iris.

Este conocimiento constituye una base científica para investigaciones y desarrollos tecnológicos posteriores.

---

## 3. Indicador 2: Generación de conocimiento

A partir de la revisión documental realizada, se organizaron los principales parámetros físico-químicos relacionados con las condiciones adecuadas para la crianza de trucha arco iris (*Oncorhynchus mykiss*).

Esta organización permitió establecer rangos de referencia que facilitan la identificación de condiciones favorables y situaciones de riesgo [1].

| Parámetro | Condición favorable | Condición de riesgo |
|---|---|---|
| **Oxígeno disuelto** | 6.0 – 8.5 mg/L | < 5.5 mg/L |
| **Temperatura** | 11 – 16 °C | < 3 °C o > 20 °C |
| **pH** | 7.0 – 8.0 | < 6.0 o > 9.0 |
| **Turbidez** | Baja presencia de sólidos en suspensión | Elevada presencia de sólidos |
| **Conductividad** | 20 – 500 µS/cm | > 500 µS/cm |

La información revisada permitió reconocer que estos parámetros no deben analizarse de manera aislada.

Por ejemplo, las condiciones de temperatura pueden relacionarse con la disponibilidad de oxígeno disuelto, mientras que una elevada presencia de sólidos puede afectar directamente las branquias de los peces [1].

Asimismo, durante el análisis se identificó que las condiciones físico-químicas del agua pueden presentar diferencias según la profundidad de la columna de agua.

En sistemas acuícolas se han observado diferencias verticales en la concentración de oxígeno asociadas a procesos de estratificación y mezcla del agua [4].

### Zonas de la columna de agua

**Superficie:** corresponde a la zona con mayor intercambio gaseoso con la atmósfera y mayor exposición a la radiación solar.

**Zona media:** representa una zona relevante debido a que corresponde al espacio de desplazamiento y actividad de las truchas.

**Fondo:** puede presentar acumulación de alimento no consumido, heces y materia orgánica, factores que pueden modificar las condiciones locales del agua.

Esta diferenciación permitió generar como conocimiento inicial que una medición realizada en un único punto de la columna de agua podría no representar completamente las condiciones presentes en todo el ambiente acuático.

Por lo tanto, la revisión realizada permitió integrar información sobre los rangos físico-químicos adecuados para la trucha y reconocer la importancia de considerar la distribución espacial de estas variables.

Este conocimiento constituye una base para continuar investigando el comportamiento de la calidad del agua en sistemas de crianza de trucha.

---

## 4. Indicador 3: Pregunta de investigación

A partir del problema identificado y de la revisión inicial se plantea la siguiente pregunta de investigación:

> **¿Cómo varían los principales parámetros físico-químicos del agua, especialmente el oxígeno disuelto, la temperatura, el pH, la turbidez y la conductividad, y cómo pueden estas variaciones relacionarse con condiciones adecuadas o de riesgo para la crianza de trucha arco iris (*Oncorhynchus mykiss*)?**

Esta pregunta busca comprender el fenómeno antes de proponer una solución tecnológica.

De manera complementaria pueden plantearse las siguientes preguntas:

- ¿Qué parámetro físico-químico presenta mayor importancia para identificar condiciones de riesgo en la crianza de truchas?
- ¿Existe variación de las condiciones del agua según la profundidad?
- ¿Cómo influye la temperatura sobre las condiciones de oxígeno disuelto?
- ¿Qué relación existe entre las variaciones simultáneas de oxígeno disuelto, temperatura, pH y turbidez en las condiciones del ambiente acuático?
- ¿Qué relación existe entre la conductividad del agua y las variaciones en la concentración de sales disueltas?


---

## 5. Indicador 4: No se declara un uso aplicativo de la tecnología

En el nivel TRL 1, el trabajo se concentra en la comprensión de los principios científicos relacionados con la calidad del agua y las condiciones necesarias para la crianza de trucha arco iris (*Oncorhynchus mykiss*).

En esta etapa, el análisis se limita principalmente a estudiar:

- Las propiedades físico-químicas del agua.
- La importancia del oxígeno disuelto para la supervivencia de la trucha.
- La influencia de la temperatura sobre las condiciones del medio acuático.
- Los rangos de pH asociados con condiciones adecuadas para la especie.
- Los efectos de la turbidez y los sólidos en suspensión.
- Las posibles diferencias de estos parámetros según la profundidad de la columna de agua.
- La conductividad del agua y su relación con la presencia de sales e iones disueltos.

Por lo tanto, en este nivel no se evalúa todavía una solución tecnológica específica ni se busca demostrar el funcionamiento de un sistema aplicado.

Aspectos como la selección de sensores, el diseño electrónico, la programación, la comunicación IoT, el desarrollo de una aplicación, la fabricación de una carcasa o la construcción de un prototipo corresponden a etapas posteriores de madurez tecnológica.

De esta manera, el resultado del TRL 1 es principalmente la generación de una base científica y conceptual que permita comprender el fenómeno antes de plantear una solución tecnológica.

---

## 6. Indicador 5: Generación y revisión de conocimiento científico

Para establecer la base científica de esta investigación se realizó una revisión documental inicial sobre las condiciones necesarias para el cultivo de trucha arco iris (*Oncorhynchus mykiss*).

Como fuente técnica inicial se utilizó el *Manual de Cultivo de Trucha en Ambientes Convencionales* de FONDEPES, donde se describen parámetros relevantes para la calidad del agua, como el oxígeno disuelto, la temperatura, el pH y la presencia de sólidos en suspensión [1].

Esta revisión fue complementada con literatura científica y técnica relacionada con los principales fenómenos estudiados.

Se revisaron investigaciones y fuentes relacionadas con:

- La interacción entre temperatura y oxígeno disuelto en *Oncorhynchus mykiss* [2].
- Los efectos de la hipoxia en la trucha arco iris [3].
- La variación vertical del oxígeno en sistemas acuícolas [4].
- Los principales métodos utilizados para determinar el oxígeno disuelto en agua [5].
- La influencia de la temperatura, salinidad y presión en la estimación de la concentración de oxígeno disuelto [6].
- Los métodos e instrumentos empleados para la medición de la temperatura del agua [7].
- La conductividad eléctrica como parámetro relacionado con la presencia de sales e iones disueltos en el agua y como variable auxiliar para estimar la salinidad.

La comparación entre estas fuentes permitió contrastar la información técnica presentada por FONDEPES con resultados obtenidos en investigaciones experimentales y documentos técnicos, fortaleciendo la base científica relacionada con la calidad del agua. Asimismo, permitió reconocer que parámetros como el oxígeno disuelto, la temperatura, el pH, la turbidez y la conductividad pueden analizarse de manera conjunta para comprender mejor las condiciones físico-químicas del agua utilizadas en la crianza de trucha. De esta manera, la revisión realizada permite sustentar los principios identificados durante el TRL 1 y proporciona una base científica para continuar con etapas posteriores de investigación.

---

## 7. Conocimiento obtenido durante el TRL 1

Como resultado de la revisión realizada durante esta etapa, se identificaron los siguientes conocimientos principales:

1. La calidad del agua influye directamente en la supervivencia, crecimiento y bienestar de la trucha arco iris (*Oncorhynchus mykiss*) [1].
2. El oxígeno disuelto constituye uno de los parámetros más críticos, debido a que concentraciones bajas pueden generar estrés, asfixia e incluso mortalidad en los peces [1].
3. La temperatura del agua influye en procesos como el metabolismo, la alimentación y el crecimiento de la trucha [1].
4. El pH y la turbidez también son parámetros importantes para caracterizar las condiciones del ambiente acuático y detectar situaciones que puedan resultar desfavorables para los peces [1].
5. Las condiciones físico-químicas del agua pueden presentar diferencias según la profundidad, especialmente entre la superficie, la zona media y el fondo [4].
6. Se identificó la necesidad de continuar investigando la relación entre estas variables para comprender de manera más completa las condiciones favorables y de riesgo presentes en los sistemas de crianza de trucha.
7. La conductividad permite caracterizar indirectamente la concentración de sales e iones disueltos presentes en el agua y puede utilizarse como variable auxiliar para estimar la salinidad, la cual influye en la estimación de la concentración de oxígeno disuelto.

En conjunto, estos conocimientos constituyen la base científica inicial necesaria para continuar con etapas posteriores de investigación y desarrollo tecnológico.

---

## 8. Cumplimiento de indicadores del TRL 1

| Indicador TRL 1 | Evidencia desarrollada |
|---|---|
| **Identificación del principio de la tecnología** | Se identificó la relación entre las condiciones físico-químicas del agua y la supervivencia y desarrollo de la trucha arco iris. |
| **Generación de conocimiento** | Se organizaron los principales parámetros críticos, sus rangos de referencia y las posibles diferencias de las condiciones del agua según la profundidad. |
| **Responde a una pregunta de investigación** | Se formuló una pregunta orientada a comprender la variación de los principales parámetros físico-químicos del agua y su relación con condiciones adecuadas o de riesgo para la trucha. |
| **No declara un uso aplicativo de la tecnología** | En esta etapa no se evalúa una solución tecnológica específica; el análisis se concentra en los principios científicos y en la comprensión del fenómeno. |
| **Genera como resultado artículos científicos** | Se complementó la documentación técnica con literatura científica sobre temperatura, oxígeno disuelto, hipoxia y variación de parámetros en sistemas acuícolas, fortaleciendo la base científica de la investigación [2]–[4]. |

### Síntesis

A partir de las actividades desarrolladas se evidencia el cumplimiento de los principales componentes conceptuales del TRL 1: identificación de principios fundamentales, generación inicial de conocimiento y formulación de una pregunta de investigación.

El componente relacionado con la generación de artículos científicos requiere continuar fortaleciendo la revisión de literatura y documentar los resultados de la investigación antes de considerarlo completamente alcanzado.

---

## 9. Conclusión

La etapa TRL 1 permitió identificar y organizar los principios científicos fundamentales relacionados con la calidad del agua y su influencia en la crianza de trucha arco iris (*Oncorhynchus mykiss*).

A partir de la revisión realizada, se reconoció al oxígeno disuelto, la temperatura, el pH, la turbidez y la conductividad como parámetros relevantes para caracterizar las condiciones del ambiente acuático. Asimismo, se identificó que estas condiciones pueden presentar diferencias según la profundidad de la columna de agua.

En conjunto, la investigación desarrollada permitió generar una base inicial de conocimiento y comprender los principales factores físico-químicos relacionados con condiciones favorables o de riesgo para la crianza de trucha, proporcionando sustento científico para continuar con etapas posteriores de investigación y desarrollo tecnológico.

---

## Referencias

[1] Fondo Nacional de Desarrollo Pesquero (FONDEPES), *Manual de Cultivo de Trucha en Ambientes Convencionales*. Lima, Perú: Ministerio de la Producción, Dirección General de Capacitación y Desarrollo Técnico en Acuicultura, 2013.

[2] X. Jiang, S. Dong, R. Liu, M. Huang, K. Dong, J. Ge, Q. Gao, and Y. Zhou, “Effects of temperature, dissolved oxygen, and their interaction on the growth performance and condition of rainbow trout (*Oncorhynchus mykiss*),” *Journal of Thermal Biology*, vol. 98, Art. no. 102928, 2021, doi: 10.1016/j.jtherbio.2021.102928.

[3] Z.-S. Hou, H.-S. Wen, J.-F. Li, F. He, Y. Li, and X. Qi, “Environmental hypoxia causes growth retardation, osteoclast differentiation and calcium dyshomeostasis in juvenile rainbow trout (*Oncorhynchus mykiss*),” *Science of the Total Environment*, vol. 705, Art. no. 135272, 2020, doi: 10.1016/j.scitotenv.2019.135272.

[4] M. Oberle, S. Salomon, B. Ehrmaier, P. Richter, M. Lebert, and S. M. Strauch, “Diurnal stratification of oxygen in shallow aquaculture ponds in central Europe and recommendations for optimal aeration,” *Aquaculture*, vol. 501, pp. 482–487, 2019, doi: 10.1016/j.aquaculture.2018.12.005.

[5] N. H. Omer, “Water quality parameters,” in *Water Quality—Science, Assessments and Policy*, J. K. Summers, Ed. London, U.K.: IntechOpen, 2020, doi: 10.5772/intechopen.89657.

[6] U.S. Geological Survey, “Change to solubility equations for oxygen in water,” *Office of Water Quality Technical Memorandum 2011.03*, Jul. 13, 2011. [Online]. Available: [https://water.usgs.gov/water-resources/memos/documents/WQ.2011.03.pdf](https://water.usgs.gov/water-resources/memos/documents/WQ.2011.03.pdf)

[7] D. C. Ripple and G. F. Strouse, “Selection of alternatives to liquid-in-glass thermometers,” *Journal of ASTM International*, vol. 2, no. 9, 2005, doi: 10.1520/JAI13404.

La investigación desarrollada permitió generar una base inicial de conocimiento, formular una pregunta de investigación y comprender el fenómeno antes de plantear una aplicación tecnológica específica.

Por lo tanto, la información obtenida constituye el sustento científico necesario para continuar con etapas posteriores de madurez tecnológica, en las que podrá avanzarse hacia la formulación y desarrollo de una solución tecnológica.
