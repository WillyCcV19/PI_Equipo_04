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

### 1.1 ¿Qué es el TRL y por qué comenzamos en el nivel 1?

Los Niveles de Madurez Tecnológica (*Technology Readiness Levels*, TRL) son una escala que surgió en la NASA y que hoy sirve como guía para que investigadores e innovadores identifiquen en qué etapa se encuentra su desarrollo y qué esfuerzos necesitan para avanzar [[12]](#ref12). En el Perú, el Consejo Nacional de Ciencia, Tecnología e Innovación (Concytec) implementó una metodología TRL de nueve niveles para evaluar proyectos de investigación, innovación y emprendimiento, y la puso a disposición del Sistema Nacional de Ciencia, Tecnología e Innovación (Sinacti) en la plataforma Vincúlate [[12]](#ref12).

Esta escala permite ubicar una tecnología en una de cuatro fases: investigación básica, investigación aplicada, desarrollo tecnológico o innovación [[12]](#ref12). El **TRL 1** corresponde al inicio de una nueva tecnología [[12]](#ref12): es el nivel más bajo de madurez, en el que se observan y reportan los principios básicos que, más adelante, podrían sustentar una solución [[13]](#ref13). El resultado típico de este nivel es la existencia de artículos científicos publicados sobre los principios de la tecnología [[13]](#ref13).

Dicho de forma sencilla: en el TRL 1 todavía no construimos nada. Nos dedicamos a **entender el fenómeno** con el rigor suficiente como para que lo que se construya después tenga un fundamento sólido.

### 1.2 Contexto del trabajo

Este informe corresponde al TRL 1 del proyecto integrador del Grupo 4. Nuestro tema de estudio es la **calidad del agua en la crianza de trucha arco iris** (*Oncorhynchus mykiss*). La razón es práctica: la trucha es una especie exigente con su medio, y el agua es, a la vez, su ambiente, su fuente de oxígeno y el vehículo de sus desechos. Si las condiciones del agua se desvían de lo adecuado, el pez lo sufre de inmediato en su respiración, su crecimiento y su supervivencia [[1]](#ref1), [[2]](#ref2).

Para esta primera etapa tomamos como referencia técnica principal el *Manual de Cultivo de Trucha en Ambientes Convencionales* de FONDEPES [[1]](#ref1) y lo contrastamos con literatura científica y técnica internacional [[2]](#ref2)–[[11]](#ref11), [[14]](#ref14)–[[16]](#ref16).

### 1.3 Objetivo y alcance

El objetivo de esta etapa **no es desarrollar una solución tecnológica**, sino comprender los fenómenos y principios científicos que relacionan las condiciones del agua con la vida de la trucha. Por eso este documento se organiza según los cinco indicadores del TRL 1 (secciones 2 a 6) y cierra con el conocimiento obtenido, el cumplimiento de indicadores y la conclusión.

### 1.4 Convenciones del documento

| Aspecto | Convención |
|---|---|
| Concentraciones | Se expresan en ppm (partes por millón). En agua dulce, 1 ppm equivale aproximadamente a 1 mg/L. |
| Conductividad | Se expresa en µS/cm (microsiemens por centímetro) y se indica la temperatura de referencia cuando la fuente la menciona. |
| Turbidez | Se expresa en NTU (unidades nefelométricas de turbidez) [[14]](#ref14). |
| Citas | Numeradas entre corchetes; cada una enlaza a la sección de Referencias, donde el DOI o URL lleva al documento original. |

---

## 2. Indicador 1: Identificación del principio de la tecnología

### 2.1 El principio en una frase

El principio fundamental identificado es que **las condiciones físico-químicas del agua determinan directamente la supervivencia, el crecimiento y el bienestar de la trucha arco iris** (*Oncorhynchus mykiss*).

Los parámetros que concentran esta relación son el oxígeno disuelto, la temperatura, el pH y la turbidez [[1]](#ref1), a los que se suma la conductividad como variable que caracteriza la carga de sales del medio [[7]](#ref7), [[8]](#ref8).

### 2.2 ¿Por qué la trucha es tan sensible al agua?

La trucha respira por branquias: extrae del agua el oxígeno que necesita, de modo que su respiración depende por completo de cuánto oxígeno haya disuelto y de qué tan limpias estén sus branquias [[1]](#ref1), [[2]](#ref2). Además, es un animal de sangre fría: su temperatura corporal sigue a la del agua, por lo que la temperatura del medio regula su metabolismo, su apetito y su crecimiento [[1]](#ref1), [[5]](#ref5). En otras palabras, la trucha no puede "aislarse" del agua; lo que ocurre en el agua ocurre dentro del pez.

Cada parámetro que se describe a continuación se presenta con la misma lógica: **qué es, por qué importa para la trucha, qué valores se consideran adecuados y cómo se mide**.

---

### 2.3 Oxígeno disuelto

#### 2.3.1 ¿Qué es?

El oxígeno disuelto es la cantidad de oxígeno gaseoso (O₂) que se encuentra mezclado en el agua y que está disponible para la respiración de los organismos acuáticos. Entra al agua principalmente por intercambio con la atmósfera y se consume con la respiración de los peces y de otros organismos del sistema. En estanques, además, su concentración cambia a lo largo del día y entre capas de agua, como se verá más adelante [[9]](#ref9).

#### 2.3.2 ¿Por qué es crítico para la trucha?

Es uno de los parámetros más críticos en la crianza de trucha, porque una reducción significativa de su concentración puede producir estrés, asfixia y mortalidad [[1]](#ref1), [[2]](#ref2). Los efectos no se limitan a la muerte súbita: en trucha arco iris juvenil, la hipoxia ambiental produjo retraso del crecimiento y alteraciones en el metabolismo del calcio [[2]](#ref2). Es decir, un oxígeno bajo sostenido también "frena" al pez aunque no lo mate.

#### 2.3.3 Valores de referencia

De acuerdo con FONDEPES, la concentración de oxígeno disuelto no debería ser menor a **5.5 ppm**; los valores de referencia son [[1]](#ref1):

| Concentración | Condición | Interpretación |
|---|---|---|
| **< 3.0 ppm** | Crítica | Asociada a mortalidad. |
| **3.1 – 4.5 ppm** | Estrés grave | El pez sobrevive, pero con afectación seria. |
| **5.5 ppm** | Mínima recomendada | Umbral por debajo del cual se considera riesgo. |
| **6.0 – 8.5 ppm** | Favorable | Rango de trabajo recomendado para el cultivo. |

#### 2.3.4 ¿De qué depende cuánto oxígeno puede contener el agua?

El agua no puede disolver cualquier cantidad de oxígeno: existe un máximo (solubilidad) que depende de tres factores [[3]](#ref3):

| Factor | Efecto sobre el oxígeno que el agua puede contener |
|---|---|
| **Temperatura** | A mayor temperatura, menor solubilidad. |
| **Presión** | A menor presión (por ejemplo, a mayor altitud), menor solubilidad. |
| **Salinidad** | A mayor salinidad, menor solubilidad. |

Estos tres factores son los que contemplan las ecuaciones utilizadas por el USGS. Este organismo empleó primero las formulaciones de Weiss y luego adoptó las de Benson y Krause en la herramienta **DOTABLES 3.0**, publicada en 2011 [[3]](#ref3).

La salinidad no siempre se mide de forma directa; puede estimarse a partir de la conductividad mediante la siguiente ecuación empírica [[3]](#ref3):

$$
S = 5.572 \times 10^{-4}(SC) + 2.02 \times 10^{-9}(SC)^2
$$

Donde **S** es la salinidad estimada del agua y **SC** es su conductividad. Esta ecuación puede no ser aplicable cuando la composición del agua es muy diferente a la del agua de mar [[3]](#ref3); por eso, en agua dulce de cultivo debe usarse con cautela.

Con temperatura, presión y salinidad se calcula la concentración de oxígeno mediante factores de corrección, siguiendo la expresión de las estimaciones de Weiss (1970) y Benson-Krause (1980, 1984) [[3]](#ref3):

$$
[DO] = DO_0 \times F_s \times F_p
$$

Donde **DO** es el oxígeno disuelto, **DO₀** la concentración base en agua dulce, **Fs** el factor de corrección de salinidad y **Fp** el factor de corrección de presión [[3]](#ref3).

#### 2.3.5 Métodos para medir el oxígeno disuelto

Existen tres métodos principales: colorimétrico, Winkler (titulación) y electrométrico [[4]](#ref4), [[10]](#ref10). Cada uno se basa en un principio científico distinto.

**a) Método colorimétrico.** Se basa en que ciertos reactivos cambian de color en presencia de oxígeno, y la intensidad del color es proporcional a la cantidad de oxígeno disuelto. El resultado se obtiene comparando el color con una escala patrón o midiéndolo con un fotómetro. Es un método rápido y práctico para el campo, pero su exactitud es menor que la de los otros dos [[10]](#ref10).

**b) Método de Winkler (titulación).** Es un método químico en el que el oxígeno se "captura" y luego se cuantifica mediante una cadena de reacciones [[11]](#ref11):

1. *Fijación del oxígeno:* el oxígeno disuelto oxida el hidróxido de manganeso (II) y forma un precipitado de manganeso oxidado.

$$
Mn^{2+} + 2OH^- \rightarrow Mn(OH)_2 \qquad 2Mn(OH)_2 + O_2 \rightarrow 2MnO(OH)_2
$$

2. *Liberación de yodo:* al acidificar en presencia de yoduro, el manganeso oxidado libera yodo (I₂) en una cantidad equivalente al oxígeno que había en la muestra.

$$
MnO(OH)_2 + 2I^- + 4H^+ \rightarrow Mn^{2+} + I_2 + 3H_2O
$$

3. *Titulación:* el yodo liberado se mide agregando tiosulfato hasta que desaparece el color. A partir del volumen de tiosulfato consumido se calcula el oxígeno de la muestra (1 molécula de O₂ equivale a 4 de tiosulfato).

$$
I_2 + 2S_2O_3^{2-} \rightarrow 2I^- + S_4O_6^{2-}
$$

Es el método químico de referencia y se usa ampliamente para verificar otros métodos, pero exige reactivos, trabajo manual y cuidado al manipular la muestra, porque el oxígeno del aire puede ingresar y alterar el resultado [[10]](#ref10), [[11]](#ref11). No permite medición continua.

**c) Método electrométrico (sensor o sonda).** El oxígeno se difunde a través de una membrana hacia un electrodo y genera una señal eléctrica proporcional a la cantidad de oxígeno presente [[10]](#ref10). El equipo convierte esa señal en concentración y normalmente compensa la temperatura. Su gran ventaja es que mide directamente en el sitio y de forma continua; su limitación es que requiere calibración y mantenimiento del sensor.

| Método | Principio | Exactitud | Uso típico | Medición continua |
|---|---|---|---|---|
| Colorimétrico | Cambio de color proporcional al oxígeno | Menor [[10]](#ref10) | Campo, revisión rápida | No |
| Winkler | Fijación del oxígeno, liberación de yodo y titulación | Alta; método de referencia [[10]](#ref10), [[11]](#ref11) | Laboratorio y verificación | No |
| Electrométrico | Difusión del oxígeno hacia un electrodo y señal eléctrica | Alta si está bien calibrado [[10]](#ref10) | Monitoreo en sitio | Sí |

**Método y función del sensor:** Para el monitoreo continuo del oxígeno disuelto se considera el método electrométrico o amperométrico mediante un sensor electroquímico. El oxígeno presente en el agua atraviesa una membrana y genera una respuesta eléctrica relacionada con su concentración. La función del sensor es transformar esta respuesta en una lectura de oxígeno disuelto, normalmente expresada en mg/L o ppm [[10]](#ref10), [[11]](#ref11).

> En este nivel solo se identifica el principio de cada método. No se selecciona ningún sensor ni equipo, porque eso corresponde a etapas posteriores.

---

### 2.4 Temperatura

#### 2.4.1 ¿Qué es y por qué importa?

La temperatura mide el grado de calor del agua. Para la trucha es decisiva por dos razones que se refuerzan entre sí:

1. **Regula el cuerpo del pez.** Al ser un animal de sangre fría, su metabolismo, su consumo de alimento y su crecimiento dependen de la temperatura del agua [[1]](#ref1), [[5]](#ref5).
2. **Regula el oxígeno disponible.** Cuanto más cálida el agua, menos oxígeno puede contener [[3]](#ref3), justo cuando el pez, más activo, lo necesita más.

Por esta doble influencia, la temperatura y el oxígeno disuelto interactúan y afectan conjuntamente el crecimiento y la condición fisiológica de la trucha arco iris, como lo demostró un estudio experimental con esta especie [[5]](#ref5).

#### 2.4.2 Valores de referencia

| Condición | Rango | Fuente |
|---|---|---|
| Favorable para el cultivo | **11 – 16 °C** | [[1]](#ref1) |
| De riesgo | **< 3 °C o > 20 °C** | [[1]](#ref1) |

#### 2.4.3 ¿Cómo se mide?

Además de los termómetros de líquido en vidrio, existen sensores electrónicos [[6]](#ref6):

| Sensor | Principio físico | Característica general |
|---|---|---|
| **Termómetro de resistencia de platino (RTD)** | La resistencia eléctrica del platino cambia de forma predecible con la temperatura. | Muy exacto y estable. |
| **Termistor** | La resistencia de un semiconductor varía mucho con la temperatura. | Muy sensible y compacto. |
| **Termopar** | Dos metales unidos generan un voltaje que depende de la temperatura (efecto Seebeck). | Amplio rango; menor exactitud que el RTD. |

**Método y función del sensor:** La temperatura puede determinarse mediante sensores resistivos, como termistores o RTD. Estos sensores aprovechan la variación de la resistencia eléctrica del material frente a cambios de temperatura. En un RTD de platino, por ejemplo, la resistencia aumenta de manera predecible cuando aumenta la temperatura [6]. La función del sensor es transformar esta variación eléctrica en una lectura de temperatura.

---

### 2.5 Potencial de hidrógeno (pH)

#### 2.5.1 ¿Qué es?

El pH es una medida de qué tan ácida o básica es el agua [[15]](#ref15). Su escala va de 0 a 14: el agua pura tiene pH 7 (neutro), los valores menores indican acidez creciente y los mayores, alcalinidad creciente [[15]](#ref15). La escala es logarítmica: un agua con pH 5 es diez veces más ácida que una con pH 6 [[15]](#ref15).

#### 2.5.2 ¿Por qué importa para la trucha?

El pH es un buen indicador de que el agua está cambiando químicamente, ya que puede verse afectado por las sustancias que contiene [[15]](#ref15). Para el pez, las variaciones significativas generan condiciones inadecuadas y afectan sus procesos fisiológicos [[1]](#ref1). Además, el pH influye en la forma química en que se presentan otras sustancias disueltas, por lo que su monitoreo ayuda a interpretar el resto de los parámetros.

#### 2.5.3 Valores de referencia

| Condición | Rango | Fuente |
|---|---|---|
| Favorable | **7.0 – 8.0** | [[1]](#ref1) |
| De riesgo | **< 6.0 o > 9.0** | [[1]](#ref1) |

**Método y función del sensor:** El pH se determina mediante un método electrométrico utilizando un electrodo de vidrio sensible a la actividad de los iones hidrógeno y un electrodo de referencia. La diferencia de potencial eléctrico a través de la membrana de vidrio depende del pH de la muestra y puede relacionarse mediante la ecuación de Nernst [17](#ref17). La función del sensor es convertir esta diferencia de potencial en un valor de pH.

---

### 2.6 Turbidez

#### 2.6.1 ¿Qué es?

La turbidez es la claridad del agua: qué tan cloudy u opaca está [[14]](#ref14). Se debe a partículas y sólidos suspendidos, como sedimentos arrastrados desde el suelo, que dispersan la luz que atraviesa el agua. En la práctica se mide haciendo pasar luz por la muestra y se reporta en NTU [[14]](#ref14).

#### 2.6.2 ¿Por qué importa para la trucha?

Una elevada concentración de sólidos suspendidos puede afectar las branquias de los peces y disminuir la calidad del medio acuático [[1]](#ref1). Como las branquias son el órgano con el que la trucha obtiene oxígeno, un agua muy turbia perjudica indirectamente la respiración. Además, la turbidez es útil como señal de alerta: sus lecturas pueden indicar una posible contaminación en un cuerpo de agua [[14]](#ref14).

| Condición | Descripción | Fuente |
|---|---|---|
| Favorable | Baja presencia de sólidos en suspensión | [[1]](#ref1) |
| De riesgo | Elevada presencia de sólidos | [[1]](#ref1) |

**Método y función del sensor:** La turbidez se determina mediante un método óptico o nefelométrico. El sensor dirige luz hacia la muestra y detecta la cantidad de luz dispersada por las partículas suspendidas. Cuanto mayor sea la cantidad de luz dispersada, mayor será la turbidez [14]. La función del sensor es transformar la respuesta óptica en un valor de turbidez, normalmente expresado en NTU.

---

### 2.7 Conductividad

#### 2.7.1 ¿Qué es?

La conductividad eléctrica mide la capacidad del agua para conducir corriente. Depende de los tipos y cantidades de sustancias disueltas, y se expresa para una temperatura determinada [[16]](#ref16). En términos sencillos: el agua pura conduce muy poco, y cada sal que se disuelve aporta iones que facilitan el paso de la corriente. Por eso es una variable útil para caracterizar la carga de sales e iones del medio [[7]](#ref7).

#### 2.7.2 La importancia de la temperatura de referencia

La conductividad cambia con la temperatura, por lo que siempre debe reportarse con su temperatura de referencia. El USGS reporta sus mediciones a 25 °C [[16]](#ref16), mientras que los valores de referencia de los sistemas de recirculación consultados se dan a 20 °C [[7]](#ref7). Esto debe tenerse presente al comparar datos de distintas fuentes.

#### 2.7.3 Valores reportados en cultivos de trucha

| Sistema | Conductividad | Fuente |
|---|---|---|
| Raceways en Nepal (condiciones consideradas adecuadas) | **35 – 204 µS/cm** | [[8]](#ref8) |
| Sistemas de recirculación (referencia) | **20 – 500 µS/cm a 20 °C** | [[7]](#ref7) |

La conductividad se vincula además con la salinidad mediante la ecuación empírica de la sección 2.3.4 [[3]](#ref3), lo que la conecta directamente con el cálculo del oxígeno disuelto.

**Método y función del sensor:** La conductividad se determina mediante un método conductimétrico utilizando una celda con electrodos en contacto con el agua. Los iones disueltos permiten el paso de corriente eléctrica, por lo que un aumento en su concentración generalmente incrementa la conductividad [16]. La función del sensor es medir esta capacidad de conducción eléctrica y expresarla normalmente en µS/cm. Debido a que la conductividad depende de la temperatura, la medición debe considerar una temperatura de referencia [16].

---

### 2.8 Síntesis del principio identificado

La calidad del agua depende de la interacción de varios parámetros físico-químicos, y sus variaciones generan condiciones favorables o de riesgo para la trucha. Los parámetros no actúan por separado:

| Interacción | Qué ocurre |
|---|---|
| Temperatura ↔ Oxígeno disuelto | Al subir la temperatura baja el oxígeno que el agua puede contener y aumenta la demanda del pez [[3]](#ref3), [[5]](#ref5). |
| Conductividad ↔ Salinidad ↔ Oxígeno disuelto | La conductividad permite estimar la salinidad, que corrige el cálculo del oxígeno [[3]](#ref3). |
| Turbidez ↔ Respiración | Los sólidos suspendidos afectan las branquias y la captación de oxígeno [[1]](#ref1). |

Este conocimiento constituye una base científica para investigaciones y desarrollos tecnológicos posteriores.

---

## 3. Indicador 2: Generación de conocimiento

### 3.1 Organización del conocimiento: rangos de referencia

A partir de la revisión documental organizamos los parámetros críticos en rangos de referencia, que permiten reconocer condiciones favorables y situaciones de riesgo:

| Parámetro | Condición favorable / referencia | Condición de riesgo o fuera de referencia |
|---|---|---|
| **Oxígeno disuelto** | 6.0 – 8.5 ppm [[1]](#ref1) | < 5.5 ppm [[1]](#ref1) |
| **Temperatura** | 11 – 16 °C [[1]](#ref1) | < 3 °C o > 20 °C [[1]](#ref1) |
| **pH** | 7.0 – 8.0 [[1]](#ref1) | < 6.0 o > 9.0 [[1]](#ref1) |
| **Turbidez** | Baja presencia de sólidos en suspensión [[1]](#ref1) | Elevada presencia de sólidos [[1]](#ref1) |
| **Conductividad** | 20 – 500 µS/cm a 20 °C [[7]](#ref7) | > 500 µS/cm [[7]](#ref7) |

### 3.2 Los parámetros se influyen entre sí

Una lectura aislada puede engañar. Por ejemplo, una temperatura aceptable no garantiza buen oxígeno, porque el oxígeno depende también de la presión y la salinidad [[3]](#ref3), y su efecto sobre el pez se combina con el de la temperatura [[5]](#ref5). Del mismo modo, una elevada presencia de sólidos puede afectar directamente las branquias [[1]](#ref1) y comprometer la captación de oxígeno aunque la concentración medida sea adecuada. Por ello, el análisis debe ser conjunto.

### 3.3 Variación según la profundidad

En sistemas acuícolas se han observado diferencias verticales en la concentración de oxígeno asociadas a procesos de estratificación y mezcla de la columna de agua [[9]](#ref9). La estratificación es la formación de capas de agua con propiedades distintas, y la mezcla es el proceso que las vuelve a homogeneizar. En el estudio de estanques poco profundos citado, el oxígeno mostró un comportamiento diurno con diferencias entre capas [[9]](#ref9).

Para organizar este conocimiento dividimos la columna de agua en tres zonas:

| Zona | Características | Por qué importa |
|---|---|---|
| **Superficie** | Mayor intercambio gaseoso con la atmósfera y mayor exposición a la radiación solar. | Es la zona de ingreso natural de oxígeno y de mayor variación de temperatura. |
| **Zona media** | Espacio donde se desplazan y permanecen las truchas. | Representa las condiciones que el pez realmente experimenta. |
| **Fondo** | Puede acumular alimento no consumido, heces y materia orgánica. | Esos residuos pueden modificar las condiciones locales del agua. |

De aquí surge el conocimiento inicial más importante de este indicador: **una medición en un solo punto de la columna de agua podría no representar las condiciones de todo el ambiente acuático** [[9]](#ref9). Reconocerlo desde el TRL 1 evita partir de supuestos que luego habría que corregir.

### 3.4 Síntesis

La revisión permitió (1) establecer los rangos de referencia de cada parámetro, (2) comprender cómo se relacionan entre sí y (3) reconocer la importancia de la distribución espacial de las variables. Esto constituye la base para continuar investigando el comportamiento de la calidad del agua en sistemas de crianza de trucha.

---

## 4. Indicador 3: Pregunta de investigación

### 4.1 Pregunta principal

Con base en el problema identificado y la revisión inicial, planteamos la siguiente pregunta de investigación:

> **¿Cómo varían los principales parámetros físico-químicos del agua, especialmente el oxígeno disuelto, la temperatura, el pH, la turbidez y la conductividad, y cómo pueden estas variaciones relacionarse con condiciones adecuadas o de riesgo para la crianza de trucha arco iris (*Oncorhynchus mykiss*)?**

La pregunta apunta a **comprender el fenómeno**, no a proponer una solución, en coherencia con el nivel TRL 1 [[12]](#ref12), [[13]](#ref13).

### 4.2 Preguntas complementarias y su origen

| Pregunta complementaria | Base científica que la origina |
|---|---|
| ¿Qué parámetro presenta mayor importancia para identificar condiciones de riesgo en la crianza de truchas? | El oxígeno disuelto se identifica como uno de los más críticos por su relación con estrés y mortalidad [[1]](#ref1), [[2]](#ref2). |
| ¿Existe variación de las condiciones del agua según la profundidad? | Se han observado diferencias verticales de oxígeno por estratificación y mezcla [[9]](#ref9). |
| ¿Cómo influye la temperatura sobre las condiciones de oxígeno disuelto? | La temperatura determina la solubilidad del oxígeno [[3]](#ref3) y actúa junto con él sobre el crecimiento [[5]](#ref5). |
| ¿Qué relación existe entre las variaciones simultáneas de oxígeno disuelto, temperatura, pH, turbidez y conductividad? | Los parámetros interactúan y no deben analizarse de forma aislada [[1]](#ref1), [[5]](#ref5), [[7]](#ref7). |
| ¿Qué relación existe entre la conductividad y las variaciones en la concentración de sales disueltas? | La conductividad depende de las sustancias disueltas [[16]](#ref16) y permite estimar la salinidad [[3]](#ref3). |

---

## 5. Indicador 4: No se declara un uso aplicativo de la tecnología

### 5.1 Qué significa este indicador

En el TRL 1 el trabajo se concentra en comprender los principios científicos; todavía no se plantea cómo se aplicará ese conocimiento [[12]](#ref12), [[13]](#ref13). Declararlo explícitamente es parte de la honestidad metodológica: evita afirmar avances tecnológicos que aún no existen.

### 5.2 Qué se estudia en esta etapa

| Aspecto estudiado | Principio científico asociado |
|---|---|
| Propiedades físico-químicas del agua | Interacción entre oxígeno, temperatura, pH, turbidez y conductividad [[1]](#ref1), [[7]](#ref7). |
| Importancia del oxígeno disuelto | La trucha respira por branquias; la hipoxia genera estrés, retraso del crecimiento y mortalidad [[1]](#ref1), [[2]](#ref2). |
| Influencia de la temperatura | Regula el metabolismo del pez y la solubilidad del oxígeno [[3]](#ref3), [[5]](#ref5). |
| Rangos de pH | Rango favorable 7.0 – 8.0 [[1]](#ref1). |
| Efectos de la turbidez y los sólidos | Afectan las branquias y la calidad del medio [[1]](#ref1), [[14]](#ref14). |
| Diferencias según profundidad | Estratificación y mezcla de la columna de agua [[9]](#ref9). |
| Conductividad eléctrica | Refleja las sustancias disueltas; valores reportados en cultivos de trucha [[7]](#ref7), [[8]](#ref8), [[16]](#ref16). |

### 5.3 Qué queda fuera de esta etapa

No se evalúa una solución tecnológica específica ni se busca demostrar el funcionamiento de un sistema. Los siguientes aspectos corresponden a niveles posteriores de madurez, cuando la tecnología pasa de la investigación básica a la aplicada y al desarrollo [[12]](#ref12):

| Aspecto | Etapa en que corresponde |
|---|---|
| Selección de sensores | Niveles posteriores |
| Diseño electrónico | Niveles posteriores |
| Programación | Niveles posteriores |
| Comunicación IoT | Niveles posteriores |
| Desarrollo de una aplicación | Niveles posteriores |
| Fabricación de una carcasa | Niveles posteriores |
| Construcción de un prototipo | Niveles posteriores |

El resultado del TRL 1 es, por tanto, una base científica y conceptual que permita entender el fenómeno antes de plantear una solución.

---

## 6. Indicador 5: Generación y revisión de conocimiento científico

### 6.1 Por qué este indicador es central en el TRL 1

En el TRL 1, la evidencia esperada son artículos científicos publicados sobre los principios de la tecnología [[13]](#ref13). Por eso este indicador es el que respalda a todos los demás: sin literatura que sustente los principios, el resto sería solo una afirmación.

### 6.2 Cómo se realizó la revisión

Tomamos como fuente técnica inicial el manual de FONDEPES, que describe parámetros relevantes de calidad del agua: oxígeno disuelto, temperatura, pH y sólidos en suspensión [[1]](#ref1). Luego la complementamos con literatura científica y técnica, y contrastamos lo que dice el manual con resultados experimentales y documentos técnicos.

### 6.3 Matriz de fuentes revisadas

| Tema revisado | Fuente(s) | Aporte principal |
|---|---|---|
| Parámetros de calidad del agua en cultivo de trucha | [[1]](#ref1) | Rangos de referencia de oxígeno, temperatura, pH y sólidos. |
| Efectos de la hipoxia en la trucha arco iris | [[2]](#ref2) | La falta de oxígeno retrasa el crecimiento y altera el metabolismo del calcio. |
| Influencia de temperatura, salinidad y presión en el oxígeno disuelto | [[3]](#ref3) | Ecuaciones de solubilidad del oxígeno en agua. |
| Métodos para determinar el oxígeno disuelto | [[4]](#ref4), [[10]](#ref10), [[11]](#ref11) | Principios de los métodos colorimétrico, Winkler y electrométrico. |
| Interacción temperatura–oxígeno disuelto | [[5]](#ref5) | Ambos factores interactúan sobre el crecimiento y la condición del pez. |
| Medición de la temperatura del agua | [[6]](#ref6) | Alternativas al termómetro de vidrio: RTD, termistores y termopares. |
| Conductividad en cultivos de trucha | [[7]](#ref7), [[8]](#ref8), [[16]](#ref16) | Valores de referencia, valores registrados y fundamento de la medición. |
| Variación vertical del oxígeno | [[9]](#ref9) | Diferencias de oxígeno por estratificación en la columna de agua. |
| Turbidez y pH | [[14]](#ref14), [[15]](#ref15), [[17]](#ref17) | Definición, principio de medición e importancia como indicadores de calidad. |
| Metodología TRL en el Perú | [[12]](#ref12), [[13]](#ref13) | Marco de niveles de madurez y resultados esperados del TRL 1. |

### 6.4 Qué aportó la comparación entre fuentes

Contrastar el manual de FONDEPES con estudios internacionales permitió confirmar que el oxígeno es un parámetro crítico [[1]](#ref1), [[2]](#ref2) y que la temperatura debe analizarse junto con él [[3]](#ref3), [[5]](#ref5). También permitió detectar un límite importante: **los valores de conductividad provienen de contextos distintos** (raceways en Nepal [[8]](#ref8) y sistemas de recirculación [[7]](#ref7)), por lo que no deben tomarse como valores definitivos para otras condiciones sin contrastarlos.

---

## 7. Conocimiento obtenido durante el TRL 1

1. La calidad del agua influye directamente en la supervivencia, crecimiento y bienestar de la trucha arco iris [[1]](#ref1).

2. El oxígeno disuelto es uno de los parámetros más críticos: concentraciones bajas generan estrés, asfixia, retraso del crecimiento y mortalidad [[1]](#ref1), [[2]](#ref2).

3. La cantidad de oxígeno que el agua puede contener depende de la temperatura, la presión y la salinidad [[3]](#ref3).

4. El oxígeno disuelto puede determinarse con tres métodos de principio distinto: colorimétrico (cambio de color), Winkler (fijación química y titulación) y electrométrico (señal eléctrica de un sensor) [[4]](#ref4), [[10]](#ref10), [[11]](#ref11).

5. La temperatura regula el metabolismo, la alimentación y el crecimiento de la trucha, e interactúa con el oxígeno disuelto [[1]](#ref1), [[5]](#ref5). Puede medirse con RTD, termistores o termopares [[6]](#ref6).

6. El pH indica qué tan ácida o básica es el agua y revela cambios químicos [[15]](#ref15); el rango favorable para la trucha es 7.0 – 8.0 [[1]](#ref1).

7. La turbidez mide la claridad del agua y puede afectar las branquias si los sólidos son elevados [[1]](#ref1), [[14]](#ref14).

8. La conductividad refleja las sustancias disueltas [[16]](#ref16) y se ha registrado en cultivos de trucha en valores de 35 a 204 µS/cm [[8]](#ref8) y con referencia de 20 a 500 µS/cm a 20 °C [[7]](#ref7).

9. Las condiciones del agua pueden variar entre superficie, zona media y fondo, por lo que una medición en un solo punto puede no representar todo el sistema [[9]](#ref9).

10. Es necesario seguir investigando la relación simultánea entre estas variables para comprender las condiciones favorables y de riesgo.

Estos conocimientos constituyen la base científica inicial para las siguientes etapas de investigación y desarrollo.

---

## 8. Cumplimiento de indicadores del TRL 1

### 8.1 Matriz de cumplimiento

| Indicador TRL 1 | Evidencia desarrollada | Secciones | Estado |
|---|---|---|---|
| **Identificación del principio de la tecnología** | Relación entre las condiciones físico-químicas del agua y la supervivencia de la trucha, con fundamento científico de cada parámetro y de los métodos de medición del oxígeno. [[1]](#ref1), [[3]](#ref3), [[4]](#ref4), [[10]](#ref10) | 2 | Cumplido |
| **Generación de conocimiento** | Rangos de referencia, interacciones entre parámetros y variación según la profundidad. [[1]](#ref1), [[9]](#ref9) | 3 | Cumplido |
| **Responde a una pregunta de investigación** | Pregunta principal y preguntas complementarias con su base científica. | 4 | Cumplido |
| **No declara un uso aplicativo de la tecnología** | Se declara qué se estudia y qué queda fuera de esta etapa. [[12]](#ref12), [[13]](#ref13) | 5 | Cumplido |
| **Genera como resultado artículos científicos** | Revisión de literatura científica y técnica [[2]](#ref2)–[[11]](#ref11), [[14]](#ref14)–[[17]](#ref17). | 6 | En fortalecimiento |

### 8.2 Síntesis y limitaciones

Se evidencia el cumplimiento de los componentes conceptuales del TRL 1: principios identificados, conocimiento generado y pregunta de investigación formulada.

Reconocemos, con honestidad, las siguientes limitaciones:

| Limitación | Implicancia |
|---|---|
| El indicador de artículos científicos debe seguir fortaleciéndose [[13]](#ref13). | Ampliar la cantidad de artículos revisados, priorizando estudios en contextos similares al peruano. |
| Los valores de conductividad provienen de contextos distintos [[7]](#ref7), [[8]](#ref8). | Contrastarlos antes de adoptarlos como referencia propia. |
| Los rangos del manual de FONDEPES corresponden a ambientes convencionales [[1]](#ref1). | Verificar su aplicabilidad a las condiciones específicas de estudio. |
| No se han generado datos propios. | Es esperable en TRL 1, que se basa en revisión documental. |

---

## 9. Conclusión

La etapa TRL 1 nos permitió identificar y organizar los principios científicos que relacionan la calidad del agua con la vida de la trucha arco iris (*Oncorhynchus mykiss*). Entendimos que el oxígeno disuelto, la temperatura, el pH, la turbidez y la conductividad son parámetros que se influyen entre sí y que, juntos, definen si el ambiente es favorable o de riesgo para el pez [[1]](#ref1), [[3]](#ref3), [[5]](#ref5), [[7]](#ref7).

Además, explicamos el fundamento científico de cada parámetro y los principios de los tres métodos de medición del oxígeno disuelto, e identificamos que las condiciones del agua pueden variar según la profundidad [[9]](#ref9), lo que obliga a no confiar en una medición puntual.

En coherencia con la metodología TRL adoptada en el Perú [[12]](#ref12), este trabajo se limita a los principios básicos y no declara una solución tecnológica. Con ello queda una base de conocimiento inicial y una pregunta de investigación clara, que sustentan la continuación del proyecto hacia los siguientes niveles de madurez.

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

<a id="ref12"></a>[12] M. Ríos, “Concytec implementa herramienta para identificar niveles de tecnología en proyectos de investigación e innovación,” *Gestión*, Lima, Perú, Mar. 25, 2022. [Online]. Available: [https://gestion.pe/tecnologia/concytec-implementa-herramienta-para-identificar-niveles-de-tecnologia-en-proyectos-de-investigacion-e-innovacion-noticia/](https://gestion.pe/tecnologia/concytec-implementa-herramienta-para-identificar-niveles-de-tecnologia-en-proyectos-de-investigacion-e-innovacion-noticia/)

<a id="ref13"></a>[13] Ministerio de Industria, Comercio y Turismo (España), “Niveles de madurez de la tecnología,” *Economía Industrial*, n.º 393, s. f. [Online]. Available: [https://www.mintur.gob.es/publicaciones/publicacionesperiodicas/economiaindustrial/revistaeconomiaindustrial/393/notas.pdf](https://www.mintur.gob.es/publicaciones/publicacionesperiodicas/economiaindustrial/revistaeconomiaindustrial/393/notas.pdf)

<a id="ref14"></a>[14] U.S. Geological Survey, “Turbidity and water,” *USGS Water Science School*, s. f. [Online]. Available: [https://www.usgs.gov/water-science-school/science/turbidity-and-water](https://www.usgs.gov/water-science-school/science/turbidity-and-water)

<a id="ref15"></a>[15] U.S. Geological Survey, “pH and water,” *USGS Water Science School*, s. f. [Online]. Available: [https://www.usgs.gov/water-science-school/science/ph-and-water](https://www.usgs.gov/water-science-school/science/ph-and-water)

<a id="ref16"></a>[16] D. B. Radtke, J. V. Davis, and F. D. Wilde, “Specific electrical conductance (Version 1.2),” *U.S. Geological Survey Techniques of Water-Resources Investigations*, book 9, chap. A6.3, 2005, doi: [10.3133/twri09A6.3](https://doi.org/10.3133/twri09A6.3).

<a id="ref17"></a>[17] U.S. Geological Survey, *Chapter A6.4. Measurement of pH*, U.S. Geological Survey Techniques and Methods, book 9, chap. A6.4, 2021. [Online]. Available: [https://pubs.usgs.gov/publication/tm9A6.4](https://pubs.usgs.gov/publication/tm9A6.4)
