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

En esta etapa se realizó una revisión inicial de los factores físico-químicos relacionados con la calidad del agua en la crianza de trucha arco iris (*Oncorhynchus mykiss*), tomando como principal referencia el *Manual de Cultivo de Trucha en Ambientes Convencionales* de FONDEPES [[1]](#ref1).

El objetivo de esta etapa no es desarrollar todavía una solución tecnológica, sino comprender los fenómenos y principios científicos relacionados con las condiciones del agua y su influencia sobre la trucha.

**Nota sobre unidades:** las concentraciones se expresan en ppm (partes por millón). En agua dulce, 1 ppm equivale aproximadamente a 1 mg/L.

---

## 2. Indicador 1: Identificación del principio de la tecnología

El principio fundamental identificado consiste en que las condiciones físico-químicas del agua influyen directamente en la supervivencia, crecimiento y bienestar de la trucha arco iris (*Oncorhynchus mykiss*).

Entre los principales parámetros relacionados con estas condiciones se encuentran el oxígeno disuelto, la temperatura, el pH y la turbidez [[1]](#ref1), así como la conductividad [[7]](#ref7), [[8]](#ref8).

La trucha es un pez de respiración branquial: toma el oxígeno directamente del agua y su metabolismo depende de la temperatura del medio. Por ello, cualquier cambio en las propiedades del agua se traduce en un cambio en su fisiología, su alimentación y su supervivencia [[1]](#ref1), [[5]](#ref5).

### 2.1 Oxígeno disuelto

#### Fundamento científico

El oxígeno disuelto corresponde a la cantidad de oxígeno gaseoso (O₂) disponible en el agua para la respiración de los organismos acuáticos. Este oxígeno ingresa al agua por intercambio con la atmósfera y se consume por la respiración de los peces y de otros organismos.

La trucha extrae el oxígeno del agua a través de las branquias. Cuando la concentración disminuye (hipoxia), el pez sufre estrés fisiológico y, en estudios experimentales con trucha arco iris juvenil, la hipoxia ambiental produjo retraso del crecimiento y alteraciones en el metabolismo del calcio [[2]](#ref2). En casos extremos provoca asfixia y mortalidad [[1]](#ref1), [[2]](#ref2).

#### Valores de referencia

De acuerdo con FONDEPES, se recomienda que la concentración de oxígeno disuelto no sea menor a **5.5 ppm** [[1]](#ref1):

| Concentración | Condición | Fuente |
|---|---|---|
| **< 3.0 ppm** | Crítica, asociada a mortalidad | [[1]](#ref1) |
| **3.1 – 4.5 ppm** | Estrés grave | [[1]](#ref1) |
| **5.5 ppm** | Mínima recomendada | [[1]](#ref1) |
| **6.0 – 8.5 ppm** | Favorable para el cultivo | [[1]](#ref1) |

Por ello, se identifica como principio fundamental la relación entre la disponibilidad de oxígeno en el agua y las condiciones necesarias para la supervivencia y desarrollo de la trucha.

#### Factores que determinan cuánto oxígeno puede disolverse

La cantidad máxima de oxígeno que el agua puede contener (solubilidad) no es constante: depende de la **temperatura**, la **presión** y la **salinidad** [[3]](#ref3). En general, el agua más cálida, más salina o sometida a menor presión (mayor altitud) disuelve menos oxígeno. Por eso, estos tres factores deben considerarse para estimar correctamente el oxígeno disuelto.

La salinidad puede estimarse a partir de la conductividad del agua mediante la siguiente ecuación empírica [[3]](#ref3):

$$
S = 5.572 \times 10^{-4}(SC) + 2.02 \times 10^{-9}(SC)^2
$$

Donde:

- **S:** salinidad estimada del agua.
- **SC:** conductividad del agua.

Esta ecuación puede no ser aplicable si la composición actual del agua es muy diferente a la del agua de mar [[3]](#ref3).

Con los parámetros anteriores se puede estimar la concentración de oxígeno disuelto utilizando factores de corrección, mediante la siguiente expresión utilizada en las estimaciones de Weiss (1970) y Benson-Krause (1980, 1984) [[3]](#ref3):

$$
[DO] = DO_0 \times F_s \times F_p
$$

Donde:

- **DO:** oxígeno disuelto.
- **DO₀:** concentración base de oxígeno disuelto en agua dulce.
- **Fs:** factor de corrección de salinidad.
- **Fp:** factor de corrección de presión.

El USGS utilizó las formulaciones de Weiss y posteriormente adoptó las de Benson y Krause en **DOTABLES 3.0**, publicada en 2011 [[3]](#ref3).

#### Métodos para determinar el oxígeno disuelto

Existen tres métodos principales para determinar el oxígeno disuelto en agua [[4]](#ref4), [[10]](#ref10):

| Método | Principio científico | Cómo se obtiene el resultado | Ventajas | Limitaciones |
|---|---|---|---|---|
| **Colorimétrico** | Un reactivo cambia de color en presencia de oxígeno; la intensidad del color es proporcional a la concentración de oxígeno disuelto. | Se compara el color de la muestra con una escala de colores patrón, o se mide con un fotómetro. | Rápido y sencillo; útil para mediciones de campo [[10]](#ref10). | Medición aproximada; menor exactitud que los otros métodos [[10]](#ref10). |
| **Winkler (titulación o yodométrico)** | Reacción química en cadena: (1) el oxígeno disuelto oxida hidróxido de manganeso (II) y lo fija en la muestra; (2) al acidificar en presencia de yoduro, se libera yodo en cantidad equivalente al oxígeno original; (3) ese yodo se cuantifica titulando con tiosulfato [[11]](#ref11). | Del volumen de titulante consumido se calcula la concentración de oxígeno. | Método químico de referencia, ampliamente aplicado y base para calibrar otros métodos [[10]](#ref10), [[11]](#ref11). | Requiere reactivos, procedimiento manual y cuidado al manipular la muestra, porque el oxígeno del aire puede ingresar y alterar el resultado [[10]](#ref10). No es continuo. |
| **Electrométrico (sensor o sonda)** | El oxígeno se difunde a través de una membrana hacia un electrodo; la señal eléctrica generada es proporcional al oxígeno presente en el agua [[10]](#ref10). | El equipo convierte la señal eléctrica en concentración, normalmente con compensación de temperatura. | Medición directa, en sitio y continua; apto para monitoreo automatizado. | Requiere calibración y mantenimiento (membrana o sensor) y se ve afectado por la temperatura y la salinidad. |

> **Relación con el proyecto:** el método electrométrico es el que permite medición continua, por eso será relevante en etapas posteriores. En el TRL 1 solo se identifica el principio físico de cada método; no se selecciona ningún sensor.

### 2.2 Temperatura

#### Fundamento científico

La trucha es un animal de sangre fría (ectotermo): su temperatura corporal sigue la del agua. Por eso la temperatura controla la velocidad de su metabolismo, su consumo de alimento y su crecimiento [[1]](#ref1), [[5]](#ref5).

Además, la temperatura determina cuánto oxígeno puede contener el agua [[3]](#ref3). Cuando sube, el agua retiene menos oxígeno mientras el pez necesita más; esta combinación explica por qué ambos parámetros deben analizarse juntos. Estudios experimentales en *Oncorhynchus mykiss* demostraron que la temperatura y el oxígeno disuelto interactúan y afectan el crecimiento y la condición fisiológica de los peces [[5]](#ref5).

Según FONDEPES, un rango aproximado de **11 °C a 16 °C** presenta condiciones favorables para el cultivo [[1]](#ref1).

#### Principios de medición

Además de los termómetros de líquido en vidrio, la temperatura puede medirse con sensores electrónicos [[6]](#ref6):

| Sensor | Principio físico | Característica |
|---|---|---|
| **Termómetro de resistencia de platino (RTD)** | La resistencia eléctrica del platino aumenta de forma predecible con la temperatura. | Alta exactitud y estabilidad. |
| **Termistor** | La resistencia de un material semiconductor cambia fuertemente con la temperatura. | Alta sensibilidad; amplio uso en sensores compactos. |
| **Termopar** | Dos metales distintos unidos generan un voltaje que depende de la temperatura (efecto Seebeck). | Amplio rango de medición; menor exactitud que el RTD. |

### 2.3 Potencial de hidrógeno (pH)

#### Fundamento científico

El pH es una escala que expresa la concentración de iones hidrógeno (H⁺) en el agua y permite determinar su grado de acidez o alcalinidad. La escala va de 0 a 14: valores menores a 7 son ácidos, 7 es neutro y valores mayores a 7 son alcalinos. Es una escala logarítmica, por lo que un cambio de una unidad representa una variación de diez veces en la concentración de H⁺.

Para la crianza de trucha arco iris se considera favorable un rango aproximado entre **7.0 y 8.0** [[1]](#ref1). Las variaciones significativas de este parámetro pueden generar condiciones inadecuadas para el desarrollo de los peces y afectar sus procesos fisiológicos. FONDEPES identifica valores de riesgo por debajo de 6.0 o por encima de 9.0 [[1]](#ref1).

### 2.4 Turbidez

#### Fundamento científico

La turbidez mide qué tan opaca o turbia está el agua por la presencia de partículas y sólidos suspendidos (arcilla, materia orgánica, restos de alimento, plancton). Estas partículas dispersan y absorben la luz que atraviesa el agua; a mayor cantidad de partículas, mayor turbidez.

Una elevada concentración de estos materiales puede afectar las branquias de los peces y disminuir la calidad del medio acuático [[1]](#ref1). Como las branquias son el órgano de intercambio de oxígeno, su obstrucción o irritación afecta directamente la respiración.

Por esta razón, la turbidez fue identificada como un parámetro relevante para comprender las condiciones ambientales asociadas con la crianza de trucha arco iris.

### 2.5 Conductividad

#### Fundamento científico

La conductividad eléctrica mide la capacidad del agua para conducir corriente eléctrica. El agua pura conduce muy poco; la corriente es transportada por los iones de las sales disueltas (por ejemplo, calcio, sodio, cloruros y sulfatos). Por tanto, a mayor cantidad de sales disueltas, mayor conductividad. Se expresa en microsiemens por centímetro (µS/cm) [[7]](#ref7).

Su medición suele referirse a una temperatura estándar (por ejemplo, 20 °C), porque la conductividad varía con la temperatura [[7]](#ref7).

#### Valores reportados en cultivos de trucha

| Sistema | Conductividad | Fuente |
|---|---|---|
| Raceways en Nepal (condiciones consideradas adecuadas) | **35 – 204 µS/cm** | [[8]](#ref8) |
| Sistemas de recirculación (RAS), valor de referencia | **20 – 500 µS/cm a 20 °C** | [[7]](#ref7) |

La conductividad se relaciona además con la salinidad, como muestra la ecuación empírica de la sección 2.1 [[3]](#ref3), y por eso resulta útil como variable complementaria para caracterizar cambios en el medio acuático [[7]](#ref7).

### 2.6 Principio identificado

A partir de la revisión realizada se establece que la calidad del agua depende de la interacción de diferentes parámetros físico-químicos y que sus variaciones pueden generar condiciones favorables o de riesgo para la trucha arco iris.

| Interacción | Explicación |
|---|---|
| Temperatura ↔ Oxígeno disuelto | Al subir la temperatura disminuye el oxígeno que el agua puede contener y aumenta la demanda del pez [[3]](#ref3), [[5]](#ref5). |
| Conductividad ↔ Salinidad ↔ Oxígeno disuelto | La conductividad permite estimar la salinidad, que a su vez corrige la estimación del oxígeno [[3]](#ref3). |
| Turbidez ↔ Respiración | Los sólidos suspendidos afectan las branquias y, con ello, la captación de oxígeno [[1]](#ref1). |

Este conocimiento constituye una base científica para investigaciones y desarrollos tecnológicos posteriores.

---

## 3. Indicador 2: Generación de conocimiento

A partir de la revisión documental realizada, se organizaron los principales parámetros físico-químicos relacionados con las condiciones adecuadas para la crianza de trucha arco iris (*Oncorhynchus mykiss*).

Esta organización permitió establecer rangos de referencia que facilitan la identificación de condiciones favorables y situaciones de riesgo.

| Parámetro | Condición favorable / referencia | Condición de riesgo o fuera de referencia |
|---|---|---|
| **Oxígeno disuelto** | 6.0 – 8.5 ppm [[1]](#ref1) | < 5.5 ppm [[1]](#ref1) |
| **Temperatura** | 11 – 16 °C [[1]](#ref1) | < 3 °C o > 20 °C [[1]](#ref1) |
| **pH** | 7.0 – 8.0 [[1]](#ref1) | < 6.0 o > 9.0 [[1]](#ref1) |
| **Turbidez** | Baja presencia de sólidos en suspensión [[1]](#ref1) | Elevada presencia de sólidos [[1]](#ref1) |
| **Conductividad** | 20 – 500 µS/cm a 20 °C [[7]](#ref7) | Fuera del rango de referencia: > 500 µS/cm [[7]](#ref7) |

### 3.1 Los parámetros no actúan de forma aislada

La información revisada permitió reconocer que estos parámetros no deben analizarse de manera aislada. Por ejemplo, las condiciones de temperatura se relacionan con la disponibilidad de oxígeno disuelto [[3]](#ref3), [[5]](#ref5), mientras que una elevada presencia de sólidos puede afectar directamente las branquias de los peces [[1]](#ref1).

### 3.2 Variación según la profundidad

Durante el análisis se identificó que las condiciones físico-químicas del agua pueden presentar diferencias según la profundidad de la columna de agua. En sistemas acuícolas se han observado diferencias verticales en la concentración de oxígeno asociadas a procesos de estratificación (formación de capas con distintas propiedades) y mezcla del agua [[9]](#ref9).

| Zona de la columna de agua | Características | Relevancia |
|---|---|---|
| **Superficie** | Mayor intercambio gaseoso con la atmósfera y mayor exposición a la radiación solar. | Zona de ingreso natural de oxígeno y de mayor variación térmica. |
| **Zona media** | Espacio de desplazamiento y actividad de las truchas. | Representa las condiciones que experimenta directamente el pez. |
| **Fondo** | Puede acumular alimento no consumido, heces y materia orgánica. | Esa materia orgánica puede modificar las condiciones locales del agua. |

Esta diferenciación permitió generar como conocimiento inicial que una medición realizada en un único punto de la columna de agua podría no representar completamente las condiciones presentes en todo el ambiente acuático [[9]](#ref9).

Por lo tanto, la revisión permitió integrar información sobre los rangos físico-químicos adecuados para la trucha y reconocer la importancia de considerar la distribución espacial de estas variables. Este conocimiento constituye una base para continuar investigando el comportamiento de la calidad del agua en sistemas de crianza de trucha.

---

## 4. Indicador 3: Pregunta de investigación

A partir del problema identificado y de la revisión inicial se plantea la siguiente pregunta de investigación:

> **¿Cómo varían los principales parámetros físico-químicos del agua, especialmente el oxígeno disuelto, la temperatura, el pH, la turbidez y la conductividad, y cómo pueden estas variaciones relacionarse con condiciones adecuadas o de riesgo para la crianza de trucha arco iris (*Oncorhynchus mykiss*)?**

Esta pregunta busca comprender el fenómeno antes de proponer una solución tecnológica.

### Preguntas complementarias y su sustento

| Pregunta complementaria | Base científica que la origina |
|---|---|
| ¿Qué parámetro físico-químico presenta mayor importancia para identificar condiciones de riesgo en la crianza de truchas? | El oxígeno disuelto se identifica como uno de los parámetros más críticos por su relación con estrés y mortalidad [[1]](#ref1), [[2]](#ref2). |
| ¿Existe variación de las condiciones del agua según la profundidad? | Se han observado diferencias verticales de oxígeno por estratificación y mezcla [[9]](#ref9). |
| ¿Cómo influye la temperatura sobre las condiciones de oxígeno disuelto? | La temperatura determina la solubilidad del oxígeno y afecta el crecimiento junto con este [[3]](#ref3), [[5]](#ref5). |
| ¿Qué relación existe entre las variaciones simultáneas de oxígeno disuelto, temperatura, pH, turbidez y conductividad en las condiciones del ambiente acuático? | Los parámetros interactúan entre sí y no deben analizarse de forma aislada [[1]](#ref1), [[5]](#ref5), [[7]](#ref7). |
| ¿Qué relación existe entre la conductividad del agua y las variaciones en la concentración de sales disueltas? | La conductividad depende de los iones disueltos y permite estimar la salinidad [[3]](#ref3), [[7]](#ref7). |

---

## 5. Indicador 4: No se declara un uso aplicativo de la tecnología

En el nivel TRL 1, el trabajo se concentra en la comprensión de los principios científicos relacionados con la calidad del agua y las condiciones necesarias para la crianza de trucha arco iris (*Oncorhynchus mykiss*).

### 5.1 Qué se estudia en esta etapa

| Aspecto estudiado | Principio científico asociado |
|---|---|
| Propiedades físico-químicas del agua | Interacción entre oxígeno, temperatura, pH, turbidez y conductividad [[1]](#ref1), [[7]](#ref7). |
| Importancia del oxígeno disuelto | La trucha respira por branquias; la hipoxia genera estrés, retraso del crecimiento y mortalidad [[1]](#ref1), [[2]](#ref2). |
| Influencia de la temperatura | Controla el metabolismo del pez y la solubilidad del oxígeno [[3]](#ref3), [[5]](#ref5). |
| Rangos de pH | Rango favorable 7.0 – 8.0 [[1]](#ref1). |
| Efectos de la turbidez y los sólidos | Afectan las branquias y la calidad del medio [[1]](#ref1). |
| Diferencias según profundidad | Estratificación y mezcla de la columna de agua [[9]](#ref9). |
| Conductividad eléctrica | Refleja los iones disueltos; valores reportados en cultivos de trucha [[7]](#ref7), [[8]](#ref8). |

### 5.2 Qué queda fuera de esta etapa

Por lo tanto, en este nivel no se evalúa todavía una solución tecnológica específica ni se busca demostrar el funcionamiento de un sistema aplicado.

| Aspecto | Etapa en que corresponde |
|---|---|
| Selección de sensores | Etapas posteriores de madurez tecnológica |
| Diseño electrónico | Etapas posteriores |
| Programación | Etapas posteriores |
| Comunicación IoT | Etapas posteriores |
| Desarrollo de una aplicación | Etapas posteriores |
| Fabricación de una carcasa | Etapas posteriores |
| Construcción de un prototipo | Etapas posteriores |

De esta manera, el resultado del TRL 1 es principalmente la generación de una base científica y conceptual que permita comprender el fenómeno antes de plantear una solución tecnológica.

---

## 6. Indicador 5: Generación y revisión de conocimiento científico

Para establecer la base científica de esta investigación se realizó una revisión documental inicial sobre las condiciones necesarias para el cultivo de trucha arco iris (*Oncorhynchus mykiss*).

Como fuente técnica inicial se utilizó el *Manual de Cultivo de Trucha en Ambientes Convencionales* de FONDEPES, donde se describen parámetros relevantes para la calidad del agua, como el oxígeno disuelto, la temperatura, el pH y la presencia de sólidos en suspensión [[1]](#ref1).

Esta revisión fue complementada con literatura científica y técnica relacionada con los principales fenómenos estudiados:

| Tema revisado | Fuente(s) | Aporte principal |
|---|---|---|
| Efectos de la hipoxia en la trucha arco iris | [[2]](#ref2) | La falta de oxígeno retrasa el crecimiento y altera el metabolismo del calcio. |
| Influencia de temperatura, salinidad y presión en el oxígeno disuelto | [[3]](#ref3) | Ecuaciones para estimar la solubilidad del oxígeno en agua. |
| Métodos para determinar el oxígeno disuelto | [[4]](#ref4), [[10]](#ref10), [[11]](#ref11) | Principios de los métodos colorimétrico, Winkler y electrométrico. |
| Interacción entre temperatura y oxígeno disuelto | [[5]](#ref5) | Ambos factores interactúan sobre el crecimiento y la condición del pez. |
| Medición de la temperatura del agua | [[6]](#ref6) | Alternativas al termómetro de vidrio: RTD, termistores y termopares. |
| Conductividad eléctrica en cultivos de trucha | [[7]](#ref7), [[8]](#ref8) | Valores de referencia y valores registrados en sistemas reales. |
| Variación vertical del oxígeno | [[9]](#ref9) | Diferencias de oxígeno por estratificación en la columna de agua. |

La comparación entre estas fuentes permitió contrastar la información técnica presentada por FONDEPES con resultados obtenidos en investigaciones experimentales y documentos técnicos, fortaleciendo la base científica relacionada con la calidad del agua.

Asimismo, permitió reconocer que parámetros como el oxígeno disuelto, la temperatura, el pH, la turbidez y la conductividad pueden analizarse de manera conjunta para comprender mejor las condiciones físico-químicas del agua utilizadas en la crianza de trucha.

De esta manera, la revisión realizada permite sustentar los principios identificados durante el TRL 1 y proporciona una base científica para continuar con etapas posteriores de investigación.

---

## 7. Conocimiento obtenido durante el TRL 1

Como resultado de la revisión realizada durante esta etapa, se identificaron los siguientes conocimientos principales:

1. La calidad del agua influye directamente en la supervivencia, crecimiento y bienestar de la trucha arco iris (*Oncorhynchus mykiss*) [[1]](#ref1).

2. El oxígeno disuelto constituye uno de los parámetros más críticos, debido a que concentraciones bajas pueden generar estrés, asfixia e incluso mortalidad en los peces [[1]](#ref1), [[2]](#ref2).

3. La cantidad de oxígeno que el agua puede contener depende de la temperatura, la presión y la salinidad [[3]](#ref3).

4. El oxígeno disuelto puede determinarse mediante tres métodos con principios distintos: colorimétrico (cambio de color proporcional al oxígeno), Winkler (titulación yodométrica) y electrométrico (difusión de oxígeno a través de una membrana hacia un electrodo) [[4]](#ref4), [[10]](#ref10), [[11]](#ref11).

5. La temperatura del agua influye en procesos como el metabolismo, la alimentación y el crecimiento de la trucha, e interactúa con el oxígeno disuelto [[1]](#ref1), [[5]](#ref5).

6. El pH y la turbidez también son parámetros importantes para caracterizar las condiciones del ambiente acuático y detectar situaciones que puedan resultar desfavorables para los peces [[1]](#ref1).

7. Las condiciones físico-químicas del agua pueden presentar diferencias según la profundidad, especialmente entre la superficie, la zona media y el fondo [[9]](#ref9).

8. La conductividad eléctrica constituye un parámetro útil para caracterizar las condiciones físico-químicas del agua debido a su relación con la presencia de sustancias iónicas disueltas. En sistemas de cultivo de trucha arco iris se han reportado diferentes valores de conductividad dependiendo de las características del agua y del sistema de cultivo [[7]](#ref7), [[8]](#ref8).

9. Se identificó la necesidad de continuar investigando la relación entre estas variables para comprender de manera más completa las condiciones favorables y de riesgo presentes en los sistemas de crianza de trucha.

En conjunto, estos conocimientos constituyen la base científica inicial necesaria para continuar con etapas posteriores de investigación y desarrollo tecnológico.

---

## 8. Cumplimiento de indicadores del TRL 1

| Indicador TRL 1 | Evidencia desarrollada |
|---|---|
| **Identificación del principio de la tecnología** | Se identificó la relación entre las condiciones físico-químicas del agua y la supervivencia y desarrollo de la trucha arco iris, junto con el fundamento científico de cada parámetro y de los métodos de medición del oxígeno disuelto [[1]](#ref1), [[3]](#ref3), [[4]](#ref4), [[10]](#ref10). |
| **Generación de conocimiento** | Se organizaron los principales parámetros críticos, sus rangos de referencia, sus interacciones y las posibles diferencias de las condiciones del agua según la profundidad [[1]](#ref1), [[9]](#ref9). |
| **Responde a una pregunta de investigación** | Se formuló una pregunta orientada a comprender la variación de los principales parámetros físico-químicos del agua y su relación con condiciones adecuadas o de riesgo para la trucha. |
| **No declara un uso aplicativo de la tecnología** | En esta etapa no se evalúa una solución tecnológica específica; el análisis se concentra en los principios científicos y en la comprensión del fenómeno. |
| **Genera como resultado artículos científicos** | Se complementó la documentación técnica con literatura científica y técnica sobre oxígeno disuelto, temperatura, hipoxia, conductividad y variación de parámetros en sistemas acuícolas [[2]](#ref2)–[[11]](#ref11). |

### Síntesis

A partir de las actividades desarrolladas se evidencia el cumplimiento de los principales componentes conceptuales del TRL 1: identificación de principios fundamentales, generación inicial de conocimiento y formulación de una pregunta de investigación.

El componente relacionado con la generación de artículos científicos requiere continuar fortaleciendo la revisión de literatura y documentar los resultados de la investigación antes de considerarlo completamente alcanzado.

---

## 9. Conclusión

La etapa TRL 1 permitió identificar y organizar los principios científicos fundamentales relacionados con la calidad del agua y su influencia en la crianza de trucha arco iris (*Oncorhynchus mykiss*).

A partir de la revisión realizada, se reconoció al oxígeno disuelto, la temperatura, el pH, la turbidez y la conductividad como parámetros relevantes para caracterizar las condiciones del ambiente acuático. Se explicó el fundamento científico de cada uno y los principios de los tres métodos de medición del oxígeno disuelto. Asimismo, se identificó que estas condiciones pueden presentar diferencias según la profundidad de la columna de agua.

En conjunto, la investigación desarrollada permitió generar una base inicial de conocimiento y comprender los principales factores físico-químicos relacionados con condiciones favorables o de riesgo para la crianza de trucha, proporcionando sustento científico para continuar con etapas posteriores de investigación y desarrollo tecnológico.

---

## Referencias

<a id="ref1"></a>[1] Fondo Nacional de Desarrollo Pesquero (FONDEPES), *Manual de Cultivo de Trucha en Ambientes Convencionales*. Lima, Perú: Ministerio de la Producción, Dirección General de Capacitación y Desarrollo Técnico en Acuicultura, 2013.

<a id="ref2"></a>[2] Z.-S. Hou, H.-S. Wen, J.-F. Li, F. He, Y. Li, and X. Qi, “Environmental hypoxia causes growth retardation, osteoclast differentiation and calcium dyshomeostasis in juvenile rainbow trout (*Oncorhynchus mykiss*),” *Science of the Total Environment*, vol. 705, Art. no. 135272, 2020, doi: [10.1016/j.scitotenv.2019.135272](https://doi.org/10.1016/j.scitotenv.2019.135272).

<a id="ref3"></a>[3] U.S. Geological Survey, “Change to solubility equations for oxygen in water,” *Office of Water Quality Technical Memorandum 2011.03*, Jul. 13, 2011. [Online]. Available: [https://water.usgs.gov/water-resources/memos/documents/WQ.2011.03.pdf](https://water.usgs.gov/water-resources/memos/documents/WQ.2011.03.pdf)

<a id="ref4"></a>[4] N. H. Omer, “Water quality parameters,” in *Water Quality—Science, Assessments and Policy*, J. K. Summers, Ed. London, U.K.: IntechOpen, 2020, doi: [10.5772/intechopen.89657](https://doi.org/10.5772/intechopen.89657).

<a id="ref5"></a>[5] X. Jiang, S. Dong, R. Liu, M. Huang, K. Dong, J. Ge, Q. Gao, and Y. Zhou, “Effects of temperature, dissolved oxygen, and their interaction on the growth performance and condition of rainbow trout (*Oncorhynchus mykiss*),” *Journal of Thermal Biology*, vol. 98, Art. no. 102928, 2021, doi: [10.1016/j.jtherbio.2021.102928](https://doi.org/10.1016/j.jtherbio.2021.102928).

<a id="ref6"></a>[6] D. C. Ripple and G. F. Strouse, “Selection of alternatives to liquid-in-glass thermometers,” *Journal of ASTM International*, vol. 2, no. 9, 2005, doi: [10.1520/JAI13404](https://doi.org/10.1520/JAI13404).

<a id="ref7"></a>[7] R. Pepe-Victoriano, P. Pepe-Vargas, A. Pérez-Aravena, H. Aravena-Ambrosetti, J. I. Huanacuni, F. Méndez-Abarca, G. Olivares-Cantillano, O. Acosta-Angulo, and L. Espinoza-Ramos, “Evaluation of water quality in the production of rainbow trout (*Oncorhynchus mykiss*) in a recirculating aquaculture system (RAS) in the precordilleran region of northern Chile,” *Water*, vol. 17, no. 11, Art. no. 1685, 2025, doi: [10.3390/w17111685](https://doi.org/10.3390/w17111685).

<a id="ref8"></a>[8] R. P. Bhagat and S. Barat, “Water quality parameters for the culture of rainbow trout, *Oncorhynchus mykiss* (Walbaum) in the raceways of Kathmandu, Nepal,” *Our Nature*, vol. 13, no. 1, pp. 50–57, 2015, doi: [10.3126/on.v13i1.14209](https://doi.org/10.3126/on.v13i1.14209).

<a id="ref9"></a>[9] M. Oberle, S. Salomon, B. Ehrmaier, P. Richter, M. Lebert, and S. M. Strauch, “Diurnal stratification of oxygen in shallow aquaculture ponds in central Europe and recommendations for optimal aeration,” *Aquaculture*, vol. 501, pp. 482–487, 2019, doi: [10.1016/j.aquaculture.2018.12.005](https://doi.org/10.1016/j.aquaculture.2018.12.005).

<a id="ref10"></a>[10] California State Water Resources Control Board, Surface Water Ambient Monitoring Program (SWAMP), “Dissolved oxygen measurement principles and methods,” *Information Paper*, Data Quality Management System, s. f. [Online]. Available: [https://www.waterboards.ca.gov/water_issues/programs/swamp/docs/cwt/guidance/311.pdf](https://www.waterboards.ca.gov/water_issues/programs/swamp/docs/cwt/guidance/311.pdf)

<a id="ref11"></a>[11] American Public Health Association (APHA), American Water Works Association (AWWA), and Water Environment Federation (WEF), *Standard Methods for the Examination of Water and Wastewater*, 23rd ed. Washington, DC, USA: APHA, 2017, ISBN: 978-0-87553-287-5.
