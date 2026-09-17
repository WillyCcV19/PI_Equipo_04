# INFORME TÉCNICO DE EVALUACIÓN ESTADÍSTICA Y CALIDAD DEL AIRE POR DIÓXIDO DE AZUFRE ($SO_2$) EN NORTH BIRMINGHAM (PERÍODO ANUAL 2023)

---

## ÍNDICE

1. **Introducción**
   * 1.1 Contexto Institucional y Origen Factual de los Datos
   * 1.2 Justificación del Análisis de Dióxido de Azufre ($SO_2$)
   * 1.3 Objetivos del Estudio (General y Objetivos Estadísticos Específicos)
2. **Metodología y Configuración Instrumental**
   * 2.1 Ubicación Geográfica y Estaciones de Monitoreo
   * 2.2 Métodos Instrumentales de Medición de la EPA
   * 2.3 Definición de Variables Técnicas y Filtros Estadísticos
   * 2.4 Fórmulas y Algoritmos Estadísticos Aplicados
3. **Resultados e Interpretación Exhaustiva**
   * 3.1 Caracterización Estadística Global del Dataset
   * 3.2 Interpretación de Distribución de Frecuencias y Cuantiles
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

Los datos analizados corresponden a la medición continua de dióxido de azufre ($SO_2$) recolectada durante todo el año 2023 (1 de enero al 31 de diciembre) en la estación de monitoreo ambiental ubicada en **North Birmingham**, en el condado de Jefferson, Alabama, Estados Unidos [1].

* **País / Estado / Condado:** Estados Unidos / Alabama (FIPS: 01) / Condado de Jefferson (FIPS: 073) [1].
* **Área Estadística Metropolitana (CBSA):** Birmingham-Hoover, AL (Código CBSA: 13820) [1].
* **Identificadores Únicos de Estación (Site ID):** 
  * Estación Principal: `01-073-0023` (North Birmingham) [1].
  * Estación Adyacente de Control: `01-073-1003` [1].
* **Código de Parámetro del Contaminante:** `42401` (Dióxido de Azufre / Sulfur Dioxide $SO_2$) [1].

![Ubicación Geográfica de la Estación North Birmingham](https://raw.githubusercontent.com/usuario/repositorio/main/imagenes/estacion_north_birmingham.png)
*Figura 1: Localización geográfica de la estación AQS Site 01-073-0023 en el Condado de Jefferson, Alabama [1].*

**Análisis e Interpretación de la Figura 1:** La estación de monitoreo se encuentra ubicada estratégicamente en un sector donde convergen zonas residenciales urbanas, arterias de transporte de alto flujo vehicular y áreas con antecedentes de actividad industrial [1], [3]. La posición del sitio ID `01-073-0023` permite capturar de manera representativa la exposición ambiental real a la que está expuesta la población del norte de Birmingham a lo largo del año.

### 1.2 Justificación del Análisis de Dióxido de Azufre ($SO_2$)
El dióxido de azufre es un gas incoloro, reactivo y de olor penetrante, clasificado como uno de los seis contaminantes criterio regulados bajo la Ley de Aire Limpio de los Estados Unidos [2]. Se origina fundamentalmente durante la combustión de insumos fósiles ricos en azufre (como carbón y petróleo) en centrales termoeléctricas, fundiciones y refinerías [2], [4].

Desde la perspectiva de la salud pública, la inhalación de $SO_2$ genera constricción de las vías respiratorias en cuestión de minutos, afectando de manera crítica a personas con asma, adultos mayores y niños [2], [4]. Por ello, la vigilancia de las concentraciones máximas diarias en intervalos de $1\text{ hora}$ constituye un indicador clave para prevenir riesgos epidemiológicos respiratorios [2].

### 1.3 Objetivos del Estudio

#### Objetivo General
Evaluar de forma cuantitativa la calidad del aire respecto a los niveles de dióxido de azufre ($SO_2$) registrados en North Birmingham durante el año 2023, examinando la variabilidad de las mediciones, el cumplimiento de los estándares de salud y la estabilidad de los instrumentos de monitoreo [1], [2].

#### Objetivos Específicos Estadísticos
1. **Caracterización de Tendencia Central y Dispersión:** Calcular y analizar la media ($\mu$), desviación estándar ($\sigma$), mediana ($P_{50}$), percentiles cuartílicos ($P_{25}, P_{75}$) y valores extremos (mínimo y máximo) sobre un tamaño de muestra de $712$ observaciones anuales [1].
2. **Evaluación del Índice de Calidad del Aire (AQI):** Clasificar la distribución del *Daily AQI Value* para categorizar el nivel de riesgo en la población [1], [2].
3. **Control de Calidad e Integridad de la Red:** Analizar el porcentaje de completitud (*% Completeness*) para verificar el acatamiento del criterio de suficiencia de datos del $75\%$ exigido por la EPA [1], [3].
4. **Diagnóstico Instrumental de Anomalías:** Investigar las causas operacionales detrás de los valores negativos (lecturas de $-0.5 \text{ ppb}$) asociadas al ruido de línea base en los fotómetros [1], [3].

---

## 2. METODOLOGÍA Y CONFIGURACIÓN INSTRUMENTAL

### 2.1 Ubicación Geográfica y Estaciones de Monitoreo

| Parámetro Geográfico / Administrativo | Detalle de Identificación |
| :--- | :--- |
| **Entidad Reguladora Superior** | US Environmental Protection Agency (EPA) - Región 4 [1] |
| **Estado / Condado** | Alabama (FIPS: 01) / Jefferson County (FIPS: 073) [1] |
| **Área Urbana (CBSA)** | Birmingham-Hoover, AL (13820) [1] |
| **Estación Principal (Site ID)** | `01-073-0023` (North Birmingham) [1] |
| **Estación Adyacente (Site ID)** | `01-073-1003` [1] |
| **Código de Parámetro (Parameter Code)** | `42401` ($SO_2$) [1] |
| **Frecuencia de Muestreo Original** | Lectura continua de 1 hora expresada como Máximo Diario [1] |

### 2.2 Métodos Instrumentales de Medición de la EPA
Los datos recolectados en la estación North Birmingham provienen de dos canales de monitoreo que operan mediante metodologías analíticas equivalentes (EQSA) autorizadas por la EPA [1], [3]:

1. **Método Código 100 (*Ultraviolet Fluorescence*):** El aire ambiente se bombea continuamente hacia una cámara de reacción donde las moléculas de $SO_2$ son excitadas mediante luz ultravioleta a una longitud de onda cercana a los $214 \text{ nm}$ [3], [5]. Al volver a su estado fundamental, el $SO_2$ emite fotones de luz fluorescente cuya intensidad es directamente proporcional a su concentración [5].
2. **Método Código 188 (*Advanced UV Fluorescence Monitoring*):** Evolución tecnológica del método 100 con corrección electrónica de interferencias ópticas por hidrocarburos aromáticos y compensación de temperatura [3], [5].

![Diagrama Instrumental de Fluorescencia UV](https://raw.githubusercontent.com/usuario/repositorio/main/imagenes/metodo_fluorescencia_uv.png)
*Figura 2: Esquema del principio de medición por fluorescencia ultravioleta utilizado por los métodos EPA 100 y 188 [3], [5].*

**Análisis e Interpretación de la Figura 2:** El esquema expone el funcionamiento interno del monitor de aire. La coexistencia de los métodos $100$ y $188$ en los canales POC (*Point of Control*) $1$ y $2$ de la estación demuestra que el sitio cuenta con redundancia instrumental [1], [3]. Esto garantiza que si un sensor entra en ciclo de mantenimiento o sufre una falla temporal, el canal secundario continúe capturando la calidad del aire sin interrupciones en los registros públicos [3].

### 2.3 Definición de Variables Técnicas y Filtros Estadísticos
* **Concentración Diaria Máxima de $SO_2$ (en ppb):** Corresponde al valor pico de concentración promedio registrado en un intervalo de $1 \text{ hora}$ durante el día ($24 \text{ horas}$), medido en partes por billón ($\text{ppb}$) [1].
* **Valor AQI Diario (Daily AQI Value):** Índice normalizado adimensional que convierte la concentración en un indicador de salud en escala de $0$ a $500$ [1], [2].
* **Completitud de Datos (% Completeness):** Porcentaje de horas del día que cuentan con mediciones válidas [1], [3].
* **POC (Parameter Occurrence Code):** Identificador del sensor físico que realizó la toma de muestra (POC 1 y POC 2) [1].

### 2.4 Fórmulas y Algoritmos Estadísticos Aplicados
Sobre el total de $N = 712$ observaciones se aplicaron las formulaciones estándar [1]:

$$\mu = \frac{1}{N} \sum_{i=1}^{N} x_i, \quad \sigma = \sqrt{\frac{1}{N-1} \sum_{i=1}^{N} (x_i - \mu)^2}$$

La mediana ($P_{50}$) y los percentiles $P_{25}$ y $P_{75}$ se evaluaron sobre la serie de datos ordenada incrementalmente [1].

---

## 3. RESULTADOS E INTERPRETACIÓN EXHAUSTIVA

### 3.1 Caracterización Estadística Global del Dataset
La siguiente tabla sintetiza la totalidad de los indicadores descriptivos calculados sobre la muestra de $712$ datos del año 2023 [1].

| Variable Analizada | Tamaño de Muestra ($N$) | Media ($\mu$) | Desviación Estándar ($\sigma$) | Valor Mínimo | Percentil 25 ($P_{25}$) | Mediana / $P_{50}$ | Percentil 75 ($P_{75}$) | Valor Máximo |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Concentración $SO_2$ ($\text{ppb}$)** | $712$ | $1.7$ | $1.9$ | $-0.5$ | $0.5$ | $1.2$ | $2.1$ | $17.5$ |
| **Índice AQI Diario** | $712$ | $1.7$ | $2.7$ | $0.0$ | $0.0$ | $1.0$ | $3.0$ | $24.0$ |
| **Completitud de Datos ($\%$)** | $712$ | $98.3\%$ | $4.9\%$ | $75.0\%$ | $100.0\%$ | $100.0\%$ | $100.0\%$ | $100.0\%$ |

![Histograma de Distribución de SO2](https://raw.githubusercontent.com/usuario/repositorio/main/imagenes/histograma_so2_2023.png)
*Figura 3: Histograma de frecuencia de las concentraciones diarias máximas de SO₂ en North Birmingham (2023) [1].*

**Análisis e Interpretación de la Figura 3:** La gráfica refleja una marcada asimetría positiva (sesgo a la derecha). La mayor parte de las observaciones se concentran entre $0.0$ y $2.5 \text{ ppb}$ [1]. Las concentraciones superiores a $5.0 \text{ ppb}$ aparecen con muy baja frecuencia, y el valor máximo de $17.5 \text{ ppb}$ actúa como una observación aislada en la cola de la distribución, demostrando que los eventos de mayor concentración fueron incidentes esporádicos y no un patrón continuo [1].

### 3.2 Interpretación de Distribución de Frecuencias y Cuantiles
* **Tendencia Central:** La concentración media anual se ubicó en $1.7 \text{ ppb}$, mientras que la mediana registró $1.2 \text{ ppb}$ [1]. En estudios de calidad del aire, la mediana refleja con mayor precisión el día habitual de una persona, dado que no resulta distorsionada por picos breves de contaminación [1], [3].
* **Comportamiento Cuantílico:**
  * El $25\%$ de las mediciones registradas ($P_{25}$) presentaron valores iguales o inferiores a $0.5 \text{ ppb}$ [1].
  * El $75\%$ de los registros del año ($P_{75}$) se mantuvieron por debajo de los $2.1 \text{ ppb}$ [1].
* **Dispersión:** La desviación estándar ($\sigma = 1.9 \text{ ppb}$) superó levemente al promedio, confirmando cuantitativamente la variabilidad generada por picos puntuales sobre una base de datos predominantemente baja [1].

### 3.3 Evaluación Técnica de Anomalías (Valores Negativos y Deriva del Cero)
El análisis identificó un valor mínimo registrado de **$-0.5 \text{ ppb}$** [1]. Desde un punto de vista estricto, no existen concentraciones de materia negativas en el aire. Sin embargo, este resultado es plenamente normal en la práctica analítica [3], [5].

Los monitores de fluorescencia UV se ajustan periódicamente con un gas cero (aire purificado sin $SO_2$) [3]. Cuando el aire del ambiente urbano está extremadamente limpio (cercano a $0.0 \text{ ppb}$), pequeñas fluctuaciones de temperatura en el equipo, pequeñas variaciones de voltaje o el envejecimiento normal de la lámpara UV hacen que la señal fotométrica marque valores ligeramente por debajo de la línea base calibrada [3], [5]. La EPA exige conservar estos datos en la base de datos AQS sin modificarlos para no alterar artificialmente los promedios ni sesgar las métricas anuales [3].

### 3.4 Análisis de Eficiencia Operativa y Completitud de Datos
Para considerar que un día de muestreo es válido en los balances regulatorios, la EPA exige capturar como mínimo el $75\%$ de las lecturas horarias de una jornada ($18$ de $24$ horas) [2], [3].

En North Birmingham, el nivel medio de completitud diaria alcanzó el **$98.3\%$**, registrando un mínimo de $75.0\%$ [1]. Asimismo, la presencia de $712$ filas en el dataset anual —en lugar de $365$— responde al funcionamiento paralelo de dos canales (POC 1 y POC 2) [1]. Al comparar los $712$ registros obtenidos con el máximo teórico de $730$ observaciones ($365 \text{ días} \times 2 \text{ canales}$), se obtiene una tasa global de disponibilidad de datos del **$97.5\%$**, lo cual respalda la validez técnica de las conclusiones [1], [3].

![Evolución Temporal del AQI](https://raw.githubusercontent.com/usuario/repositorio/main/imagenes/evolucion_aqi_2023.png)
*Figura 4: Serie temporal diaria del valor AQI registrado durante todo el año 2023 [1].*

**Análisis e Interpretación de la Figura 4:** La línea de tiempo evidencia que el valor de AQI se mantuvo durante todo el año muy por debajo del límite de $50$ puntos, el cual delimita la categoría de calidad de aire "Buena" [1], [2]. Las fluctuaciones superiores a $10$ puntos de AQI coinciden con momentos puntuales del año donde las condiciones atmosféricas o la actividad industrial local favorecieron la acumulación temporal del gas [1].

---

## 4. DISCUSIÓN

### 4.1 Evaluación Comparativa frente a la Normativa de Salud Pública
El estándar primario de la norma NAAQS (EPA) para dióxido de azufre busca proteger a la población general y sensible de efectos respiratorios, fijando un límite de **$75 \text{ ppb}$** para mediciones de $1\text{ hora}$ [2].

Al comparar los hallazgos de North Birmingham durante 2023 frente a la normativa vigente [1], [2]:

$$\text{Proporción de Exposición Máxima} = \left( \frac{17.5 \text{ ppb}}{75.0 \text{ ppb}} \right) \times 100 = 23.33\%$$

$$\text{Proporción de Exposición Promedio} = \left( \frac{1.7 \text{ ppb}}{75.0 \text{ ppb}} \right) \times 100 = 2.27\%$$
