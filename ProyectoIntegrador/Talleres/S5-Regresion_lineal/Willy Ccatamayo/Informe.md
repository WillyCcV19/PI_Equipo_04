# Análisis de regresión de la concentración de monóxido de carbono (CO) en el estado de Nueva York, 2022

**Curso:** Proyectos de Ingeniería 1 — Guía 1: Regresión
**Autor:** Ruben Andre Cabrera Cermeño
**Universidad Peruana Cayetano Heredia — Facultad de Ingeniería**
**Fecha:** 17 de septiembre de 2026

---

## 1. Introducción

El monóxido de carbono (CO) es un gas incoloro e inodoro que se produce por la
combustión incompleta de combustibles fósiles. En entornos urbanos, la fuente
predominante es el parque automotor. Su relevancia sanitaria radica en que
reduce la capacidad de la sangre para transportar oxígeno, por lo que la
Agencia de Protección Ambiental de los Estados Unidos (EPA) lo clasifica como
contaminante criterio y lo monitorea de forma continua, publicando los
registros en su portal de datos abiertos [1], [5].

El presente trabajo analiza la concentración diaria máxima de 8 horas de CO
registrada en el estado de Nueva York durante el año 2022, con tres objetivos:

1. Caracterizar la variabilidad temporal y espacial del contaminante en el
   periodo analizado.
2. Construir y comparar modelos de regresión lineal que expliquen la
   variabilidad diaria incorporando componentes de tendencia, estacionalidad
   anual, efecto de día de semana y persistencia temporal.
3. Verificar el cumplimiento de los supuestos del modelo lineal y evaluar la
   capacidad predictiva mediante validación temporal.

La hipótesis de partida es que, al tratarse de un contaminante de origen
mayoritariamente vehicular, la concentración diaria de CO debe presentar un
patrón estacional (mayores valores en meses fríos, cuando la dispersión
atmosférica es menor y aumenta el consumo energético), una reducción durante
los fines de semana por la caída del tráfico, y una fuerte dependencia del
valor observado el día anterior.

---

## 2. Metodología

### 2.1 Fuente y descripción de los datos

Los datos provienen del portal *Outdoor Air Quality Data* de la EPA, mediante
la herramienta **Download Daily Data** [1]. Los parámetros de consulta fueron:

| Parámetro | Valor |
|---|---|
| Contaminante | CO (Carbon monoxide) |
| Año | 2022 |
| Área geográfica | Nueva York (estado) |
| Estaciones | All Sites |
| Indicador | `Daily Max 8-hour CO Concentration` |
| Unidades | ppm (partes por millón) |
| Código AQS del parámetro | 42101 |

Se obtuvieron **3 596 registros** correspondientes a **10 estaciones de
monitoreo** distribuidas en 7 condados, todas con cobertura del año completo
(1 de enero al 31 de diciembre de 2022):

| Estación | Condado | Registros |
|---|---|---|
| Flax Pond | Suffolk | 365 |
| PFIZER LAB SITE | Bronx | 365 |
| QUEENS COLLEGE 2 | Queens | 365 |
| Queens College Near Road | Queens | 365 |
| ROCHESTER 2 | Monroe | 365 |
| CCNY | New York | 364 |
| BUFFALO | Erie | 359 |
| PINNACLE STATE PARK | Steuben | 355 |
| Buffalo Near-Road | Erie | 352 |
| Rochester Near-Road | Monroe | 341 |

### 2.2 Preprocesamiento

1. Normalización de los nombres de columna y conversión de la columna `Date` a
   tipo fecha (formato `%m/%d/%Y`).
2. Eliminación de registros con fecha o concentración nula.
3. Verificación de la cobertura temporal de cada estación.
4. Agregación por fecha mediante el promedio de las estaciones disponibles en
   cada día, obteniéndose una serie diaria de **365 observaciones** sin valores
   faltantes.

### 2.3 Variables del modelo

- **Variable dependiente:** `CO`, concentración diaria máxima de 8 horas
  promediada entre estaciones, en ppm. En los modelos logarítmicos se emplea
  `ln(CO)`.
- **Variables independientes:**

| Variable | Definición | Justificación |
|---|---|---|
| `t` | Días transcurridos desde el 2022-01-01 | Tendencia lineal |
| `sin_doy` | sen(2πd/365), con *d* = día del año | Estacionalidad anual |
| `cos_doy` | cos(2πd/365) | Estacionalidad anual |
| `finde` | 1 si sábado o domingo, 0 en caso contrario | Caída del tráfico vehicular |
| `lag1` | Concentración de CO del día anterior | Persistencia (autorregresivo de orden 1) |
| `log_lag1` | ln del valor del día anterior | Versión logarítmica del término anterior |

### 2.4 Modelos estimados

| Modelo | Especificación |
|---|---|
| M1 — Simple | CO = β₀ + β₁·t + ε |
| M2 — Múltiple en niveles | CO = β₀ + β₁·t + β₂·sin_doy + β₃·cos_doy + β₄·finde + β₅·lag1 + ε |
| M4 — Log-log parsimonioso | ln(CO) = β₀ + β₁·cos_doy + β₂·finde + β₃·ln(CO₍ₜ₋₁₎) + ε |

Los modelos se estimaron por mínimos cuadrados ordinarios (OLS). El modelo M4
retiene únicamente los regresores que resultaron significativos en M2 y
mantiene la coherencia de escala al rezagar `ln(CO)` en lugar de `CO`.

La significancia individual de los coeficientes se evaluó con el estadístico
*t* a un nivel α = 0.05, y la del modelo en conjunto con el estadístico *F*. La
autocorrelación residual se verificó con el estadístico de Durbin-Watson y la
normalidad con la prueba de Jarque-Bera y gráficos cuantil-cuantil.

### 2.5 Validación

La partición se realizó de forma **cronológica**, no aleatoria, para evitar que
información posterior se filtre hacia el conjunto de entrenamiento:

- Entrenamiento: 2022-01-02 a 2022-09-30 → 272 días.
- Prueba: 2022-10-01 a 2022-12-31 → 92 días.

Métricas: coeficiente de determinación (R²), raíz del error cuadrático medio
(RMSE) y error absoluto medio (MAE). En el modelo M4 las predicciones se
retransformaron con la función exponencial antes de calcular las métricas, de
modo que sean comparables con las de los modelos en niveles.

### 2.6 Herramientas

Python 3 en Google Colab, con las librerías `pandas` [2], `numpy`,
`matplotlib`, `seaborn`, `scipy`, `scikit-learn` [3] y `statsmodels` [4].

---

## 3. Resultados

### 3.1 Estadística descriptiva

| Estadístico | CO (ppm) | AQI |
|---|---|---|
| N | 365 | 365 |
| Media | 0.2974 | 3.2335 |
| Desviación estándar | 0.0976 | 1.2032 |
| Mínimo | 0.1300 | 1.3000 |
| Percentil 25 | 0.2333 | 2.4000 |
| Mediana | 0.2700 | 2.9000 |
| Percentil 75 | 0.3200 | 3.6000 |
| Máximo | 0.7500 | 8.6000 |

Todos los valores se ubican muy por debajo del estándar nacional de calidad del
aire para CO, fijado por la EPA en 9 ppm como máximo de 8 horas, lo que se
refleja en un AQI promedio de 3.2 sobre una escala de 500.

### 3.2 Patrón estacional

| Mes | Media (ppm) | Mediana | Desv. est. |
|---|---|---|---|
| Enero | 0.336 | 0.310 | 0.084 |
| Febrero | 0.325 | 0.300 | 0.085 |
| Marzo | 0.300 | 0.290 | 0.091 |
| Abril | 0.276 | 0.255 | 0.067 |
| Mayo | 0.258 | 0.270 | 0.052 |
| Junio | 0.264 | 0.270 | 0.059 |
| Julio | 0.250 | 0.250 | 0.031 |
| Agosto | 0.241 | 0.233 | 0.036 |
| Septiembre | 0.261 | 0.256 | 0.048 |
| Octubre | 0.363 | 0.340 | 0.134 |
| Noviembre | 0.347 | 0.300 | 0.131 |
| Diciembre | 0.349 | 0.300 | 0.149 |

<img src="/Imagenes/TallerIA/Semana 5_Tarea/fig1_estacionalidad.png" width="700"/>

*Figura 1. Distribución mensual de la concentración diaria de CO.*

Se observa un patrón estacional claro: los valores mínimos se concentran en
agosto (0.241 ppm) y los máximos en octubre (0.363 ppm), una diferencia del
51 %. Los meses fríos presentan además una dispersión notablemente mayor
(desviación estándar de 0.149 en diciembre frente a 0.031 en julio), lo que
anticipa la heterocedasticidad detectada posteriormente en los residuos.

### 3.3 Gradiente espacial

| Estación | CO medio (ppm) | Máximo |
|---|---|---|
| Queens College Near Road | 0.434 | 1.7 |
| CCNY | 0.369 | 1.2 |
| PFIZER LAB SITE | 0.358 | 1.7 |
| QUEENS COLLEGE 2 | 0.350 | 1.3 |
| Rochester Near-Road | 0.314 | 0.6 |
| BUFFALO | 0.284 | 0.8 |
| Buffalo Near-Road | 0.284 | 0.8 |
| ROCHESTER 2 | 0.251 | 0.7 |
| Flax Pond | 0.204 | 0.4 |
| PINNACLE STATE PARK | 0.125 | 0.3 |

![CO promedio por estación](figuras/fig2_por_estacion.png)

*Figura 2. Concentración media anual de CO por estación de monitoreo.*

El contraste espacial es pronunciado: la estación Queens College Near Road,
situada junto a una vía de alto tráfico, registra un promedio 3.5 veces
superior al de Pinnacle State Park, estación rural de fondo. Este gradiente
respalda la atribución del CO al tráfico vehicular y constituye evidencia
descriptiva consistente con la hipótesis planteada.

### 3.4 Relación con el AQI

La correlación de Pearson entre la concentración de CO y el AQI diario es de
**0.9968**, prácticamente perfecta. Este resultado es esperable, ya que el AQI
se calcula mediante interpolación lineal por tramos a partir de la
concentración [6]. Por tanto, se utilizó únicamente como verificación de
consistencia interna de los datos y se descartó como variable explicativa, por
tratarse de una transformación determinística de la variable dependiente.

### 3.5 Modelo M1 — Regresión lineal simple

Ecuación estimada:

```
CO = 0.2828 + 0.0000799 · t
```

| Coeficiente | Valor | Error est. | t | P>\|t\| |
|---|---|---|---|---|
| Constante | 0.2828 | 0.010 | 27.817 | 0.000 |
| t | 7.988 × 10⁻⁵ | 4.83 × 10⁻⁵ | 1.652 | 0.099 |

| Métrica | Valor |
|---|---|
| R² | 0.0075 |
| R² ajustado | 0.0047 |
| F (1, 363) | 2.730 (p = 0.0994) |
| RMSE (ajuste) | 0.0971 ppm |
| MAE (ajuste) | 0.0689 ppm |

![Serie diaria y recta de regresión](figuras/fig3_regresion_simple.png)

*Figura 3. Serie diaria de CO con la recta ajustada del modelo M1.*

La pendiente equivale a un incremento de 0.0292 ppm anuales, pero **no es
estadísticamente significativa** (p = 0.099 > 0.05). El modelo explica apenas
el 0.75 % de la variabilidad. Es importante señalar una limitación estructural:
con un único año de datos, el término de tendencia no es separable de la
estacionalidad, ya que ambos recorren un solo ciclo. La pendiente positiva
observada refleja en realidad que el año comienza en enero (mes frío, valores
altos), desciende en verano y vuelve a subir entre octubre y diciembre, no una
tendencia estructural creciente.

### 3.6 Modelo M2 — Regresión lineal múltiple en niveles

Ecuación estimada:

```
CO = 0.1333 + 0.0000626·t + 0.0027·sin_doy + 0.0273·cos_doy − 0.0148·finde + 0.5297·lag1
```

| Coeficiente | Valor | Error est. | t | P>\|t\| | Significativo (α = 0.05) |
|---|---|---|---|---|---|
| Constante | 0.1333 | 0.018 | 7.378 | 0.000 | Sí |
| t | 6.261 × 10⁻⁵ | 6.14 × 10⁻⁵ | 1.019 | 0.309 | No |
| sin_doy | 0.0027 | 0.009 | 0.299 | 0.765 | No |
| cos_doy | 0.0273 | 0.006 | 4.395 | 0.000 | Sí |
| finde | −0.0148 | 0.009 | −1.670 | 0.096 | No (marginal) |
| lag1 | 0.5297 | 0.046 | 11.399 | 0.000 | Sí |

| Métrica | Valor |
|---|---|
| R² | 0.3935 |
| R² ajustado | 0.3850 |
| F (5, 358) | 46.449 (p = 6.14 × 10⁻³⁷) |
| Durbin-Watson | 1.684 |

El modelo es globalmente significativo y multiplica por 52 la capacidad
explicativa de M1. Sin embargo, tres de los cinco regresores no alcanzan
significancia individual, lo que sugiere sobreparametrización. Los dos
predictores relevantes son el armónico coseno de la estacionalidad y,
especialmente, la persistencia diaria.

### 3.7 Modelo M4 — Especificación log-log parsimoniosa

Ecuación estimada:

```
ln(CO) = −0.5714 + 0.0809·cos_doy − 0.0513·finde + 0.5324·ln(CO₍ₜ₋₁₎)
```

| Coeficiente | Valor | Error est. | t | P>\|t\| | Significativo (α = 0.05) |
|---|---|---|---|---|---|
| Constante | −0.5714 | 0.059 | −9.686 | 0.000 | Sí |
| cos_doy | 0.0809 | 0.018 | 4.560 | 0.000 | Sí |
| finde | −0.0513 | 0.025 | −2.039 | 0.042 | Sí |
| log_lag1 | 0.5324 | 0.045 | 11.722 | 0.000 | Sí |

| Métrica | Valor |
|---|---|
| R² | 0.4090 |
| R² ajustado | 0.4040 |
| F (3, 360) | 83.036 (p = 7.55 × 10⁻⁴¹) |
| Durbin-Watson | 1.714 |

Este modelo mejora a M2 en todos los criterios relevantes pese a emplear dos
regresores menos: mayor R² ajustado (0.404 frente a 0.385), estadístico F casi
duplicado y **todos los coeficientes significativos al 5 %**. La interpretación
de los coeficientes en escala logarítmica es directa:

- `log_lag1` = 0.5324: elasticidad de la persistencia. Un aumento del 1 % en la
  concentración del día previo se asocia a un aumento del 0.53 % en el día
  actual.
- `finde` = −0.0513: los fines de semana la concentración es aproximadamente un
  **5.0 % menor** que en días hábiles, a igualdad de las demás condiciones.
- `cos_doy` = 0.0809: amplitud del ciclo estacional anual, con máximo en enero
  (cos = 1) y mínimo a inicios de julio (cos = −1).

### 3.8 Comparación de modelos y validación temporal

| Modelo | R² ajuste | R² ajustado | F | p (F) | Durbin-Watson | R² prueba | RMSE prueba | MAE prueba |
|---|---|---|---|---|---|---|---|---|
| M1 — Simple | 0.0075 | 0.0047 | 2.730 | 0.0994 | 0.794 | −1.0872 | 0.1967 | 0.1433 |
| M2 — Múltiple (niveles) | 0.3935 | 0.3850 | 46.449 | < 0.001 | 1.684 | 0.0950 | 0.1295 | 0.0926 |
| **M4 — Log-log parsimonioso** | **0.4090** | **0.4040** | **83.036** | **< 0.001** | **1.714** | **0.2407** | **0.1186** | **0.0885** |

Entrenamiento: 272 días. Prueba: 92 días (octubre–diciembre de 2022).

![Real vs predicho M4](figuras/fig4_m4_prueba.png)

*Figura 4. Valores reales y predichos por el modelo M4 en el conjunto de prueba.*

Hallazgos de la validación:

- El modelo M1 presenta un **R² negativo (−1.087)** en el conjunto de prueba,
  es decir, predice peor que la simple media histórica. Su pendiente positiva,
  extrapolada al último trimestre, se aleja de los valores reales.
- El modelo M4 es el de mejor desempeño predictivo: reduce el RMSE en un
  **39.7 %** respecto a M1 y en un **8.4 %** respecto a M2, con un MAE de
  0.0885 ppm frente a una media de la serie de 0.2974 ppm.
- El estadístico de Durbin-Watson mejora progresivamente de 0.794 (M1) a 1.714
  (M4), aunque permanece por debajo de 2, lo que indica **autocorrelación
  residual positiva remanente**.

### 3.9 Verificación de supuestos

**Linealidad y homocedasticidad.** El análisis de los residuos del modelo M2
muestra una distribución centrada en cero sin patrón curvilíneo, lo que
respalda la especificación lineal. Se aprecia, no obstante, un aumento de la
dispersión asociado a los valores predichos más altos, coherente con la mayor
desviación estándar observada en los meses fríos (0.149 en diciembre frente a
0.031 en julio). En el modelo M4
esta heterocedasticidad se atenúa, dado que la transformación logarítmica
estabiliza la varianza de variables estrictamente positivas y de distribución
asimétrica.

**Normalidad de los residuos.**

| Modelo | Asimetría | Curtosis | Jarque-Bera | p |
|---|---|---|---|---|
| M2 (niveles) | 0.939 | 3.300 | 218.636 | < 0.0001 |
| M4 (log-log) | 0.284 | 0.535 | 9.256 | 0.0098 |

![Q-Q comparativo](figuras/fig5_qq.png)

*Figura 5. Gráficos cuantil-cuantil de los residuos de M2 y M4.*

El modelo en niveles presenta una fuerte asimetría positiva y colas pesadas: el
gráfico Q-Q muestra que la cola derecha se desvía marcadamente de la diagonal,
señal de que el modelo no reproduce los episodios de concentración elevada. La
transformación logarítmica reduce la asimetría en un 70 % y la curtosis en un
84 %, y el ajuste a la diagonal es visiblemente mejor. Aunque la prueba de
Jarque-Bera sigue rechazando la normalidad estricta (p = 0.0098), con 364
observaciones el teorema central del límite respalda la validez asintótica de
la inferencia sobre los coeficientes.

**Independencia.** Los valores de Durbin-Watson inferiores a 2 revelan
autocorrelación positiva residual en todos los modelos. La inclusión del
término rezagado la reduce sustancialmente, pero no la elimina, lo que se
discute en la sección siguiente.

---

## 4. Discusión

Los resultados permiten responder a los tres objetivos planteados y presentan
además dos hallazgos metodológicos de interés.

**Sobre la variabilidad temporal.** La concentración de CO en Nueva York exhibe
un ciclo anual bien definido, con un contraste del 51 % entre el mes de menor
(agosto) y mayor concentración (octubre). Este patrón es consistente con la
literatura sobre contaminantes primarios: en invierno la capa de mezcla
atmosférica es más baja y la dispersión vertical menor, de modo que una misma
tasa de emisión produce concentraciones más altas. El término de tendencia, en
cambio, carece de interpretación válida en este diseño: con un único año de
datos, tendencia y estacionalidad no son identificables por separado, y el
modelo M1 ilustra de forma didáctica el riesgo de interpretar una pendiente
como evidencia de cambio estructural. Extender el análisis a varios años es la
condición necesaria para estimar una tendencia real.

**Sobre el efecto de fin de semana.** Este es el hallazgo metodológicamente más
interesante del trabajo. La comparación directa de medias no detecta diferencia
alguna: 0.3004 ppm en días hábiles frente a 0.2899 ppm en fines de semana, con
una prueba t no significativa (t = 0.919; p = 0.359). Sin embargo, al controlar
por estacionalidad y persistencia en el modelo M4, el efecto emerge como
significativo (−5.0 %; p = 0.042). La explicación es que la variabilidad
estacional y meteorológica es de magnitud muy superior al efecto semanal y lo
enmascara por completo en el análisis bivariado. Este resultado ilustra un
principio central del análisis de regresión: un efecto real puede permanecer
oculto si el modelo no controla adecuadamente las fuentes dominantes de
variación.

**Sobre la capacidad predictiva.** El modelo M4 explica el 40.9 % de la
variabilidad diaria, un valor razonable para un contaminante atmosférico
modelado sin covariables meteorológicas. La persistencia resulta el predictor
dominante, con una elasticidad de 0.53, lo que refleja que las condiciones de
dispersión atmosférica cambian de forma gradual y presentan memoria de varios
días. El 59 % de variabilidad no explicada corresponde presumiblemente a
factores meteorológicos no incorporados: velocidad y dirección del viento,
altura de la capa de mezcla, temperatura, precipitación y estabilidad
atmosférica.

Las principales limitaciones del estudio son:

1. **Un único año de datos.** Impide estimar tendencias interanuales y hace que
   el término `t` sea no interpretable. Es la limitación más relevante del
   diseño.
2. **Ausencia de covariables meteorológicas**, el principal factor omitido y la
   vía de mejora más directa del modelo.
3. **Promediado espacial.** La agregación de diez estaciones de naturaleza
   heterogénea —desde una estación rural de fondo hasta una adyacente a una vía
   de alto tráfico, con un rango de 0.125 a 0.434 ppm— atenúa los máximos
   locales y descarta la variabilidad entre sitios, que los resultados muestran
   como sustancial. Un modelo de datos de panel con efectos fijos por estación
   aprovecharía esta dimensión.
4. **Autocorrelación residual remanente** (Durbin-Watson = 1.714), que sesga a
   la baja los errores estándar y, en consecuencia, sobreestima la
   significancia de los coeficientes. Un término rezagado de orden superior o un
   modelo ARIMA/SARIMA trataría explícitamente esta estructura.
5. **Normalidad no estricta de los residuos** incluso tras la transformación
   logarítmica (Jarque-Bera p = 0.0098), atribuible a episodios de
   concentración elevada que un modelo lineal no está diseñado para capturar.
6. **Cobertura incompleta en tres estaciones** (Rochester Near-Road con 341 de
   365 días, Buffalo Near-Road con 352 y Pinnacle State Park con 355), lo que
   introduce una leve inconsistencia en la composición del promedio diario a lo
   largo del año.

Como líneas de mejora se proponen: incorporar datos meteorológicos diarios de
la NOAA para las mismas localidades; estimar un modelo de panel con efectos
fijos por estación en lugar de promediar; ampliar el periodo a cinco o más años
para estimar la tendencia con potencia estadística suficiente; y evaluar
especificaciones SARIMA que modelen de forma explícita la estructura
autorregresiva y estacional de la serie.

---

## 5. Conclusiones

1. La concentración diaria máxima de 8 horas de CO en Nueva York durante 2022
   promedió 0.2974 ppm (desviación estándar de 0.0976; rango de 0.13 a
   0.75 ppm), muy por debajo del estándar nacional de 9 ppm establecido por la
   EPA.
2. El modelo de tendencia simple no es significativo (p = 0.099) y en
   validación temporal produce un R² negativo (−1.087), es decir, predice peor
   que la media del periodo. Con un solo año de datos la tendencia lineal no es
   separable de la estacionalidad.
3. El modelo log-log parsimonioso (M4) es el de mejor desempeño: R² ajustado de
   0.404, todos sus coeficientes significativos al 5 % y un RMSE de validación
   de 0.1186 ppm, un 39.7 % inferior al del modelo simple.
4. La persistencia diaria es el predictor dominante, con una elasticidad de
   0.532: un aumento del 1 % en la concentración del día previo se asocia a un
   aumento del 0.53 % en el día actual.
5. Se confirma el patrón estacional esperable para un contaminante de origen
   vehicular, con máximos en los meses fríos (octubre a febrero) y mínimos en
   agosto, con una diferencia del 51 % entre ambos extremos.
6. El efecto de fin de semana no es detectable mediante comparación de medias
   (prueba t: p = 0.359), pero resulta significativo al controlar por
   estacionalidad y persistencia (−5.0 %; p = 0.042), lo que evidencia la
   importancia de una especificación adecuada del modelo.
7. El gradiente espacial es marcado: la estación Queens College Near Road
   (0.434 ppm) registra un promedio 3.5 veces superior al de Pinnacle State
   Park (0.125 ppm), estación rural de fondo, lo que respalda la atribución del
   CO al tráfico vehicular.

---

## 6. Referencias

[1] U.S. Environmental Protection Agency, "Outdoor Air Quality Data — Download
Daily Data," *EPA.gov*. [En línea]. Disponible en:
https://www.epa.gov/outdoor-air-quality-data. [Accedido: 17-sep-2026].

[2] W. McKinney, "Data structures for statistical computing in Python," en
*Proc. 9th Python in Science Conf. (SciPy)*, Austin, TX, EE. UU., 2010,
pp. 56–61.

[3] F. Pedregosa et al., "Scikit-learn: Machine learning in Python," *J. Mach.
Learn. Res.*, vol. 12, pp. 2825–2830, 2011.

[4] S. Seabold y J. Perktold, "Statsmodels: Econometric and statistical
modeling with Python," en *Proc. 9th Python in Science Conf. (SciPy)*, Austin,
TX, EE. UU., 2010, pp. 92–96.

[5] U.S. Environmental Protection Agency, "Carbon Monoxide (CO) Pollution in
Outdoor Air," *EPA.gov*. [En línea]. Disponible en:
https://www.epa.gov/co-pollution. [Accedido: 17-sep-2026].

[6] U.S. Environmental Protection Agency, "Technical Assistance Document for
the Reporting of Daily Air Quality — the Air Quality Index (AQI),"
EPA 454/B-18-007, Research Triangle Park, NC, EE. UU., 2018.

---

## Anexo — Estructura del repositorio

```
.
├── README.md                          # Este informe
├── regresion_CO_NuevaYork.ipynb       # Notebook de Google Colab
├── datos/
│   └── Data1_CO_New_York.csv          # CO, Nueva York, 2022 (EPA)
└── figuras/
    ├── fig1_estacionalidad.png
    ├── fig2_por_estacion.png
    ├── fig3_regresion_simple.png
    ├── fig4_m4_prueba.png
    └── fig5_qq.png
```

Para reproducir el análisis: abrir el notebook en Google Colab, subir el archivo
`Data1_CO_New_York.csv` al entorno y ejecutar todas las celdas.
