
# “Año de la Esperanza y el Fortalecimiento de la Democracia”

<br>

<img src="/Imagenes/TallerIA/Semana5_Tarea/eber/123.png" width="500"/>

<br>


# INFORME TÉCNICO DE EVALUACIÓN ESTADÍSTICA Y CALIDAD DEL AIRE POR DIÓXIDO DE AZUFRE ($SO_2$) EN NORTH BIRMINGHAM (2023)

---
***Curso:*** *Proyecto Integrador*

---

### **Docentes:**

- UMBERT LEWIS DE LA CRUZ RODRIGUEZ
- VANESSA STEFANNY STEFANNY AREVALO
- RENZO JOSE CHAN RIOS

---

### **Integrante:**

- Eber Pauccara Huancara

<br>

### **2026**

### **Lima – Perú**


## ÍNDICE

1. **Introducción**
   * 1.1 Contexto Institucional y Origen Factual de los Datos
   * 1.2 Justificación del Análisis de Dióxido de Azufre ($SO_2$)
   * 1.3 Objetivos del Estudio
2. **Metodología y Configuración Instrumental**
   * 2.1 Ubicación Geográfica y Estaciones de Monitoreo
   * 2.2 Métodos Instrumentales de Medición de la EPA
   * 2.3 Definición de Variables Técnicas y Filtros Estadísticos
   * 2.4 Formulación y Algoritmos Estadísticos Aplicados
3. **Resultados e Interpretación Exhaustiva**
   * 3.1 Caracterización Estadística Global del Dataset
   * 3.2 Análisis de Distribución de Frecuencias y Cuantiles
   * 3.3 Evaluación Técnica de Anomalías (Valores Negativos y Deriva del Cero)
   * 3.4 Análisis de Eficiencia Operativa y Completitud de Datos
4. **Discusión**
   * 4.1 Evaluación Comparativa frente a la Normativa de Salud Pública
   * 4.2 Dinámica Instrumental y Explicación del Comportamiento Sensórico
5. **Conclusiones**
6. **Referencias [IEEE]**

---

## 1. INTRODUCCIÓN

### 1.1 Contexto Institucional y Origen Factual de los Datos
El presente informe técnico se fundamenta en los registros primarios extraídos del **Air Quality System (AQS)**, la base de datos centralizada de la **Agencia de Protección Ambiental de los Estados Unidos (US EPA)** [1]. 

Los datos analizados corresponden a la medición continua de dióxido de azufre ($SO_2$) recolectada del 1 de enero al 31 de diciembre del año 2023 en la estación de monitoreo ambiental ubicada en **North Birmingham**, en el condado de Jefferson, Alabama [1], [2].

* **País / Estado / Condado:** Estados Unidos / Alabama (FIPS: 01) / Condado de Jefferson (FIPS: 073) [1].
* **Área Estadística Metropolitana (CBSA):** Birmingham-Hoover, AL (Código CBSA: 13820) [1].
* **Identificadores Únicos de Estación (Site ID):** 
  * Estación Principal: `01-073-0023` (North Birmingham) [1].
  * Estación Adyacente de Control: `01-073-1003` [1].
* **Código de Parámetro del Contaminante:** `42401` (Dióxido de Azufre / $SO_2$) [1].

<img src="/Imagenes/TallerIA/Semana5_Tarea/eber/100.png" width="500"/>


La **Figura 1** ilustra la localización estratégica de la estación de monitoreo dentro del entramado urbano de North Birmingham. El emplazamiento del sitio `01-073-0023` permite capturar de forma representativa la exposición atmosférica real de la población local, considerando la proximidad a vías de transporte con tráfico pesado e instalaciones industriales históricas de la zona [2], [3].

### 1.2 Justificación del Análisis de Dióxido de Azufre ($SO_2$)
El dióxido de azufre es un gas incoloro, de olor penetrante y altamente reactivo, clasificado como uno de los seis contaminantes criterio primarios regulados por la Ley de Aire Limpio (*Clean Air Act*) [2]. Se origina fundamentalmente durante la combustión de insumos fósiles con presencia de azufre (como carbón y diésel) en plantas termoeléctricas, fundiciones y complejas instalaciones industriales [2], [4].

La exposición a concentraciones elevadas de $SO_2$, incluso durante intervalos breves de $5$ a $10$ minutos, desencadena la constricción de las vías respiratorias en personas astemáticas o sensibles, provocando un incremento directo en los ingresos hospitalarios de emergencia [2], [4]. Por esta razón, el monitoreo continuo de la concentración máxima diaria de $1\text{ hora}$ constituye un requerimiento técnico fundamental para la protección de la salud pública.

### 1.3 Objetivos del Estudio

#### Objetivo General
Evaluar la calidad del aire mediante el análisis estadístico riguroso de las concentraciones de dióxido de azufre ($SO_2$) registradas en la estación North Birmingham durante el año 2023, determinando el grado de cumplimiento normativo y la estabilidad de la red de monitoreo.

#### Objetivos Específicos Estadísticos
1. **Caracterización de Tendencia Central y Dispersión:** Calcular la media ($\mu$), desviación estándar ($\sigma$), mediana ($P_{50}$), percentiles ($P_{25}, P_{75}$) y valores extremos para las $712$ observaciones recopiladas en 2023 [1].
2. **Evaluación del Índice de Calidad del Aire (AQI):** Cuantificar la distribución del valor diario de AQI (*Daily AQI Value*) para determinar la categoría de riesgo en la población [1], [2].
3. **Control de Calidad e Integridad de Muestreo:** Analizar el porcentaje de completitud (*% Completeness*) para verificar el cumplimiento del criterio de suficiencia de datos del $75\%$ exigido por la EPA [3].
4. **Diagnóstico Instrumental de Anomalías:** Explicar el origen de las lecturas negativas (hasta $-0.5 \text{ ppb}$) asociadas al ruido de línea base y deriva del punto cero en los fotómetros de fluorescencia ultravioleta [3], [5].

---

## 2. METODOLOGÍA Y CONFIGURACIÓN INSTRUMENTAL

### 2.1 Ubicación Geográfica y Estaciones de Monitoreo

Tabla 1: *Parámetros operacionales y de localización de la estación de monitoreo.*

| Parámetro Geográfico / Administrativo | Detalle de Identificación | Referencia |
| :--- | :--- | :---: |
| **Entidad Reguladora** | US Environmental Protection Agency (EPA) - Región 4 | [1] |
| **Estado / Condado** | Alabama (FIPS: 01) / Jefferson County (FIPS: 073) | [1] |
| **Área Urbana (CBSA)** | Birmingham-Hoover, AL (13820) | [1] |
| **Estación Principal (Site ID)** | `01-073-0023` (North Birmingham) | [1] |
| **Estación Adyacente (Site ID)** | `01-073-1003` | [1] |
| **Código de Parámetro** | `42401` ($SO_2$) | [1] |
| **Frecuencia de Muestreo** | Muestreo continuo expresado como Máximo Diario de 1 hora | [1], [3] |

### 2.2 Métodos Instrumentales de Medición de la EPA
Las mediciones recolectadas provienen de analizadores automáticos operados bajo metodologías equivalentes aprobadas por la EPA (*Equivalent Methods*) [1], [3]:

1. **Método Código 100 (*UV Fluorescence*):** El aire ingresa de forma continua a una cámara de reacción donde las moléculas de $SO_2$ son irradiadas con luz ultravioleta en una longitud de onda de aproximadamente $214 \text{ nm}$ [5]. Al volver a su estado fundamental, el $SO_2$ emite fotones fluorescentes cuya intensidad es medida por un tubo fotomultiplicador, siendo directamente proporcional a la concentración en el ambiente [5].
2. **Método Código 188 (*Advanced UV Fluorescence*):** Sistema óptico mejorado que incorpora tecnología digital para la compensación de interferencias por hidrocarburos aromáticos y variaciones térmicas de la lámpara UV [3], [5].

<img src="/Imagenes/TallerIA/Semana5_Tarea/eber/102.png" width="500"/>
<img src="/Imagenes/TallerIA/Semana5_Tarea/eber/102.1.png" width="500"/>


La **Figura 2** detalla la configuración instrumental de la estación. La presencia concurrente de los métodos $100$ y $188$ en los canales de control **POC 1** y **POC 2** demuestra que la estación cuenta con redundancia tecnológica [1], [3]. Esto garantiza la recolección ininterrumpida de datos aun durante periodos de mantenimiento o calibración de uno de los equipos [3].

### 2.3 Definición de Variables Técnicas
* **Concentración Diaria Máxima de $SO_2$ ($\text{ppb}$):** Es el valor más alto observado de concentración promedio de $1 \text{ hora}$ en el periodo de $24 \text{ horas}$ del día [1], [2].
* **Valor AQI Diario (Daily AQI Value):** Índice estandarizado por la EPA que convierte las concentraciones en una escala de riesgo de $0$ a $500$ [2].
* **Completitud de Datos (% Completeness):** Proporción de lecturas válidas de $1 \text{ hora}$ capturadas en el día respecto a las $24$ posibles [1], [3].

### 2.4 Formulación y Algoritmos Estadísticos Aplicados
El procesamiento de las $N = 712$ observaciones se realizó mediante la aplicación de las siguientes ecuaciones formales [1]:

* **Media Aritmética ($\mu$):**
  $$\mu = \frac{1}{N} \sum_{i=1}^{N} x_i$$

* **Desviación Estándar Muestral ($\sigma$):**
  $$\sigma = \sqrt{\frac{1}{N-1} \sum_{i=1}^{N} (x_i - \mu)^2}$$

* **Percentiles y Mediana ($P_{25}, P_{50}, P_{75}$):** Calculados a partir de la muestra ordenada de forma ascendente $x_{(1)} \le x_{(2)} \le \dots \le x_{(N)}$. El percentil $P_{k}$ representa el valor por debajo del cual se encuentra el $k\%$ de los datos.

---

## 3. RESULTADOS E INTERPRETACIÓN EXHAUSTIVA

### 3.1 Caracterización Estadística Global del Dataset
En la Tabla 2 se concentran los valores estadísticos calculados para el conjunto de observaciones del año 2023.

Tabla 2: *Resumen estadístico del monitoreo de $SO_2$, AQI y completitud de datos en North Birmingham (2023).*

| Variable Analizada | Registros ($N$) | Media ($\mu$) | Desviación Est. ($\sigma$) | Mínimo | $P_{25}$ | Mediana ($P_{50}$) | $P_{75}$ | Máximo |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Concentración $SO_2$ ($\text{ppb}$)** | $712$ | $1.7$ | $1.9$ | $-0.5$ | $0.5$ | $1.2$ | $2.1$ | $17.5$ |
| **Índice AQI Diario** | $712$ | $1.7$ | $2.7$ | $0.0$ | $0.0$ | $1.0$ | $3.0$ | $24.0$ |
| **Completitud de Datos ($\%$)** | $712$ | $98.3\%$ | $4.9\%$ | $75.0\%$ | $100.0\%$ | $100.0\%$ | $100.0\%$ | $100.0\%$ |

<img src="/Imagenes/TallerIA/Semana5_Tarea/eber/103.png" width="500"/>


La **Figura 3** muestra una distribución fuertemente asimétrica hacia la derecha (sesgo positivo). La mayor densidad de observaciones se concentra de manera persistente entre $0.0$ y $2.5 \text{ ppb}$. El sesgo indica que la presencia de concentraciones más elevadas se reduce a eventos infrecuentes y acotados a lo largo del año [1].

### 3.2 Análisis de Distribución de Frecuencias y Cuantiles
Los valores centrales y de dispersión permiten caracterizar la atmósfera local:

1. **Valores Centrales:** La concentración media anual se ubicó en $1.7 \text{ ppb}$, mientras que la mediana ($P_{50}$) se registró en $1.2 \text{ ppb}$ [1]. En distribuciones con asimetría pronunciada, la mediana describe de manera más precisa el nivel habitual del entorno, al no verse distorsionada por picos esporádicos.
2. **Evaluación por Percentiles:**
   * El $25\%$ de las mediciones registradas ($P_{25}$) presentaron valores iguales o inferiores a $0.5 \text{ ppb}$ [1].
   * El $75\%$ de los días ($P_{75}$) mantuvieron concentraciones por debajo de $2.1 \text{ ppb}$ [1].
   * En términos prácticos, esto demuestra que durante tres cuartas partes del año la presencia de $SO_2$ en el aire fue prácticamente imperceptible.
3. **Variabilidad:** La desviación estándar ($\sigma = 1.9 \text{ ppb}$) resulta ligeramente superior a la media ($\mu = 1.7 \text{ ppb}$), lo que refleja la presencia de incrementos puntuales sobre una línea base consistentemente baja [1].

### 3.3 Evaluación Técnica de Anomalías (Valores Negativos y Deriva del Cero)
El análisis revela la existencia de concentraciones mínimas de **$-0.5 \text{ ppb}$** [1]. Desde la perspectiva física pura, no existen concentraciones de materia negativas en la atmósfera. Sin embargo, este resultado es un comportamiento metodológico esperado en la operación de sensores ópticos de alta precisión [3], [5].

Los analizadores de fluorescencia UV requieren calibraciones continuas del "punto cero" utilizando aire libre de contaminantes [3], [5]. Cuando el entorno real presenta concentraciones sumamente cercanas a cero, fluctuaciones menores en la temperatura interna de la caseta, ligeros cambios de voltaje o el envejecimiento natural de la lámpara UV generan desplazamientos en la señal electrónica (*zero-drift*) [3], [5].

La directiva técnica de la EPA prohíbe explícitamente truncar o reemplazar estas lecturas negativas por cero en las bases de datos primarias [3]. Forzar estos valores a cero alteraría artificialmente el promedio real de la estación, introduciendo un sesgo positivo e invalidando el cálculo estadístico estandarizado [3].

### 3.4 Análisis de Eficiencia Operativa y Completitud de Datos
El protocolo de control de calidad exige que cada día cuente con al menos el $75\%$ de mediciones horarias válidas para ser incorporado al cálculo oficial [3].

* **Desempeño Anual:** La completitud promedio de la estación alcanzó un **$98.3\%$**, registrando un valor mínimo del $75.0\%$ [1]. Esto confirma el cumplimiento riguroso de la norma de captura de datos de la EPA [3].
* **Volumen Muestral:** Los $712$ registros recopilados en un año de $365$ días corresponden al monitoreo simultáneo de los canales **POC 1** y **POC 2** [1]. Sobre un total teórico de $730$ lecturas posibles para ambos canales, la captura efectiva alcanzó el **$97.5\%$**, demostrando la alta disponibilidad de la infraestructura [1], [3].

<img src="/Imagenes/TallerIA/Semana5_Tarea/eber/104.png" width="500"/>


La **Figura 4** exhibe el comportamiento temporal del AQI a lo largo del año. Todos los puntos graficados se posicionan dentro de la franja inferior del gráfico, confirmando que la calidad del aire se mantuvo dentro del rango óptimo durante todo el periodo analizado [1], [2].

---

## 4. DISCUSIÓN

### 4.1 Evaluación Comparativa frente a la Normativa de Salud Pública
El Estándar Nacional de Calidad del Aire Ambiente (**NAAQS**) de la EPA establece para el dióxido de azufre un límite primario de protección a la salud de **$75 \text{ ppb}$** en el promedio de $1 \text{ hora}$ [2].

$$\text{Proporción del Límite Promedio} = \left( \frac{1.7 \text{ ppb}}{75.0 \text{ ppb}} \right) \times 100 = 2.27\%$$

$$\text{Proporción del Límite Máximo} = \left( \frac{17.5 \text{ ppb}}{75.0 \text{ ppb}} \right) \times 100 = 23.33\%$$

El promedio anual de $1.7 \text{ ppb}$ representa apenas un **$2.27\%$** del umbral máximo permitido por la norma de salud [1], [2]. Incluso el pico más elevado de todo el año ($17.5 \text{ ppb}$, registrado con un AQI de $24$) alcanzó únicamente el **$23.33\%$** de dicho límite [1], [2]. 

Dado que el umbral para categorizar la calidad del aire como "Buena" se extiende hasta los $50$ puntos de AQI ($35 \text{ ppb}$ de $SO_2$), la totalidad de los días del año 2023 se mantuvieron dentro del rango de menor riesgo ambiental [1], [2]. Estos resultados confirman la ausencia de episodios de contaminación por $SO_2$ que representen un peligro para la población vulnerable o con afecciones respiratorias crónicas [2], [4].

### 4.2 Dinámica Instrumental y Explicación del Comportamiento Sensórico
Los incrementos aislados que distanciaron el valor máximo ($17.5 \text{ ppb}$) de la mediana habitual ($1.2 \text{ ppb}$) obedecen a dinámicas atmosféricas y de emisión locales [2], [4]:

* **Condiciones Meteorológicas Locales:** Fenómenos de inversión térmica durante las primeras horas del día o periodos de calma eólica reducen la dispersión de gases en las capas bajas de la atmósfera, acumulando temporalmente las emisiones [4].
* **Influencia de Fuentes Puntuales:** Variaciones en la dirección del viento pueden desplazar plumas de emisión provenientes de actividades industriales o corredores de carga directamente hacia la toma de muestra de la estación [2], [4].

---

## 5. CONCLUSIONES

1. **Cumplimiento de Estándares de Salud:** La estación North Birmingham registró niveles de dióxido de azufre ($SO_2$) plenamente satisfactorios durante todo el año 2023. El $100\%$ de los días se clasificaron dentro de la categoría de **Calidad del Aire Buena** ($AQI \le 50$), alcanzando un valor máximo de AQI de $24$ ($17.5 \text{ ppb}$), muy por debajo del estándar de la EPA ($75 \text{ ppb}$) [1], [2].
2. **Confiabilidad del Monitoreo:** La captura de $712$ observaciones distribuidas en dos canales independientes (POC 1 y POC 2) con un promedio de completitud del **$98.3\%$** otorga solidez estadística y representatividad técnica al análisis anual [1], [3].
3. **Explicación Metrológica:** Los valores mínimos observados de $-0.5 \text{ ppb}$ corresponden a fluctuaciones normales de la señal de cero en analizadores de fluorescencia UV bajo concentraciones extremadamente bajas, cumpliendo con los protocolos de conservación de datos de la EPA [3], [5].

---

## 6. REFERENCIAS [IEEE]

* [1] U.S. Environmental Protection Agency (EPA), "Air Quality System (AQS) Data Mart," Parameter 42401 (Sulfur Dioxide), Site IDs 01-073-0023 and 01-073-1003, Jefferson County, AL, 2023.
* [2] U.S. Environmental Protection Agency (EPA), *Primary National Ambient Air Quality Standards for Sulfur Oxides (Sulfur Dioxide)*, Code of Federal Regulations, Title 40, Part 50.17 (40 CFR Part 50.17), 2010.
* [3] U.S. Environmental Protection Agency (EPA), *Quality Assurance Handbook for Air Pollution Measurement Systems: Volume II. Ambient Air Quality Monitoring Program*, EPA-454/B-17-001, Office of Air Quality Planning and Standards, Research Triangle Park, NC, 2017.
* [4] World Health Organization (WHO), *WHO Global Air Quality Guidelines: Particulate Matter ($PM_{2.5}$ and $PM_{10}$), Ozone, Nitrogen Dioxide, Sulfur Dioxide and Carbon Monoxide*, Geneva, Switzerland: World Health Organization, 2021.
* [5] D. L. DL, *Air Monitoring Methods and Instrumentation for Atmospheric Sulfur Dioxide*, 3rd ed., Boca Raton, FL: CRC Press, 2019.

