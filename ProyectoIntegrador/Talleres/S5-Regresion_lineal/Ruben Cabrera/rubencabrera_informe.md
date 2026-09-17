# Análisis de regresión de la concentración de NO₂ en el estado de Washington (2022–2023)

**Curso:** Proyectos de Ingeniería 1 — Guía 1: Regresión
**Autor:** Ruben Andre Cabrera Cermeño
**Universidad Peruana Cayetano Heredia — Facultad de Ingeniería**
**Fecha:** 17 de septiembre de 2026

---

## 1. Introducción

El dióxido de nitrógeno (NO₂) es un contaminante atmosférico asociado
principalmente a la combustión en motores de vehículos y a procesos
industriales. La exposición prolongada se vincula con la agravación de
enfermedades respiratorias, por lo que la Agencia de Protección Ambiental de
los Estados Unidos (EPA) lo incluye entre los contaminantes criterio que
monitorea de forma continua y publica en su portal de datos abiertos [1], [5].

El presente trabajo analiza la concentración diaria máxima horaria de NO₂
registrada en el estado de Washington durante los años 2022 y 2023, con dos
objetivos:

1. Determinar si existe una tendencia temporal estadísticamente significativa
   en la concentración de NO₂ durante el periodo analizado.
2. Construir y evaluar modelos de regresión lineal que expliquen la
   variabilidad diaria del contaminante incorporando componentes de tendencia,
   estacionalidad anual y persistencia temporal.

La hipótesis de partida es que la concentración diaria de NO₂ no depende
únicamente del tiempo transcurrido, sino que está dominada por un patrón
estacional anual y por una fuerte dependencia del valor observado el día
anterior.

---

## 2. Metodología

### 2.1 Fuente y descripción de los datos

Los datos provienen del portal *Outdoor Air Quality Data* de la EPA, mediante
la herramienta **Download Daily Data** [1]. Los parámetros de consulta fueron:

| Parámetro | Valor |
|---|---|
| Contaminante | NO₂ (Nitrogen dioxide) |
| Años | 2022 y 2023 (una descarga por año) |
| Área geográfica | Washington (estado) |
| Estaciones | All Sites |
| Indicador | `Daily Max 1-hour NO2 Concentration` (ppb) |

Se obtuvieron **2 098 registros** correspondientes a tres estaciones de
monitoreo:

| Estación | Inicio | Fin | Registros |
|---|---|---|---|
| Seattle – Beacon Hill | 2022-01-01 | 2023-12-31 | 710 |
| Seattle – 10th & Weller | 2022-01-01 | 2023-12-30 | 690 |
| Tacoma – S 36th St | 2022-01-01 | 2023-12-31 | 698 |

### 2.2 Preprocesamiento

1. Unión de los dos archivos CSV anuales en un único `DataFrame`.
2. Normalización de nombres de columna y conversión de la columna `Date` a
   tipo fecha (formato `%m/%d/%Y`).
3. Eliminación de registros con fecha o concentración nula.
4. Agregación por fecha mediante el promedio de las tres estaciones, con lo
   que se obtuvo una serie diaria de **730 observaciones** sin valores
   faltantes (cobertura del 100 % del periodo 2022-01-01 a 2023-12-31).

### 2.3 Variables del modelo

- **Variable dependiente:** `NO2`, concentración diaria máxima horaria
  promediada entre estaciones, en partes por billón (ppb). En el modelo
  logarítmico se emplea `ln(NO2)`.
- **Variables independientes:**

| Variable | Definición | Justificación |
|---|---|---|
| `t` | Días transcurridos desde el 2022-01-01 | Tendencia lineal |
| `sin_doy` | sen(2πd/365), con *d* = día del año | Estacionalidad anual |
| `cos_doy` | cos(2πd/365) | Estacionalidad anual |
| `lag1` | Concentración de NO₂ del día anterior | Persistencia (autorregresivo de orden 1) |

### 2.4 Modelos estimados

| Modelo | Especificación |
|---|---|
| M1 — Simple | NO₂ = β₀ + β₁·t + ε |
| M2 — Múltiple | NO₂ = β₀ + β₁·t + β₂·sin_doy + β₃·cos_doy + β₄·lag1 + ε |
| M3 — Log-lineal | ln(NO₂) = β₀ + β₁·t + β₂·sin_doy + β₃·cos_doy + β₄·lag1 + ε |

Los modelos se estimaron por mínimos cuadrados ordinarios (OLS). La
significancia individual de los coeficientes se evaluó con el estadístico *t* a
un nivel α = 0.05, y la del modelo en conjunto con el estadístico *F*. La
autocorrelación de los residuos se verificó con el estadístico de
Durbin-Watson.

### 2.5 Validación

Se realizó una partición **temporal** (no aleatoria, para no filtrar
información futura hacia el entrenamiento):

- Entrenamiento: 2022-01-02 a 2023-06-30 → 545 días.
- Prueba: 2023-07-01 a 2023-12-31 → 184 días.

Métricas de desempeño: coeficiente de determinación (R²), raíz del error
cuadrático medio (RMSE) y error absoluto medio (MAE).

### 2.6 Herramientas

Python 3 en Google Colab, con las librerías `pandas` [2], `numpy`,
`matplotlib`, `seaborn`, `scipy`, `scikit-learn` [3] y `statsmodels` [4].

---

## 3. Resultados

### 3.1 Estadística descriptiva

| Estadístico | NO₂ (ppb) |
|---|---|
| N | 730 |
| Media | 24.14 |
| Desviación estándar | 7.67 |
| Mínimo | 7.50 |
| Percentil 25 | 19.01 |
| Mediana | 23.42 |
| Percentil 75 | 28.39 |
| Máximo | 63.67 |

### 3.2 Patrón estacional

<img src="/Imagenes/TallerIA/Semana5_Tarea/Ruben/fig1_estacionalidad.png" width="900"/>

*Figura 1. Distribución mensual de la concentración diaria de NO₂.*

El diagrama de caja mensual evidencia un patrón estacional definido: los
valores mínimos se concentran en junio y julio, con una mediana cercana a
19 ppb, y los máximos entre agosto y octubre, con medianas próximas a 25 ppb.
Los meses de agosto a octubre presentan además la mayor dispersión y los
valores atípicos más extremos del periodo, incluido el máximo absoluto de
63.67 ppb.

### 3.3 Relación con el AQI

La correlación entre la concentración de NO₂ y el AQI diario es prácticamente
lineal y determinística, lo cual es esperable porque el AQI se calcula mediante
interpolación lineal por tramos a partir de la concentración [6]. Este
resultado se utilizó únicamente como verificación de consistencia interna de
los datos y se descartó como variable explicativa, por tratarse de una
transformación determinística de la variable dependiente.

### 3.4 Modelo M1 — Regresión lineal simple

Ecuación estimada:

```
NO₂ = 24.9076 − 0.00210 · t
```

| Coeficiente | Valor | Error est. | t | P>\|t\| |
|---|---|---|---|---|
| Constante | 24.9076 | 0.567 | 43.953 | 0.000 |
| t | −0.0021 | 0.001 | −1.563 | 0.119 |

| Métrica | Valor |
|---|---|
| R² | 0.0033 |
| R² ajustado | 0.0020 |
| F (1, 728) | 2.442 (p = 0.119) |
| RMSE | 7.653 ppb |
| MAE | 5.836 ppb |

<img src="/Imagenes/TallerIA/Semana5_Tarea/Ruben/fig3_regresion_simple.png" width="900"/>

*Figura 3. Serie diaria de NO₂ con la recta ajustada del modelo M1.*

La pendiente equivale a una disminución de **0.768 ppb por año**, pero **no es
estadísticamente significativa** (p = 0.119 > 0.05). El modelo explica apenas
el 0.33 % de la variabilidad observada, por lo que el tiempo, por sí solo, no
constituye un predictor útil de la concentración diaria de NO₂. La figura
muestra con claridad que la recta ajustada es prácticamente horizontal frente a
una nube de puntos de dispersión muy superior.

### 3.5 Modelo M2 — Regresión lineal múltiple

Ecuación estimada:

```
NO₂ = 15.2260 − 0.00260·t − 1.0473·sin_doy + 0.7217·cos_doy + 0.4089·lag1
```

| Coeficiente | Valor | Error est. | t | P>\|t\| | Significativo (α = 0.05) |
|---|---|---|---|---|---|
| Constante | 15.2260 | 1.030 | 14.787 | 0.000 | Sí |
| t | −0.0026 | 0.001 | −1.972 | 0.049 | Sí |
| sin_doy | −1.0473 | 0.396 | −2.644 | 0.008 | Sí |
| cos_doy | 0.7217 | 0.364 | 1.985 | 0.047 | Sí |
| lag1 | 0.4089 | 0.034 | 12.054 | 0.000 | Sí |

| Métrica | Ajuste global (N = 729) | Validación hold-out (184 días) |
|---|---|---|
| R² | 0.199 | 0.0671 |
| R² ajustado | 0.195 | — |
| F (4, 724) | 45.00 (p = 9.03 × 10⁻³⁴) | — |
| RMSE | — | 6.668 ppb |
| MAE | — | 5.059 ppb |
| Durbin-Watson | 1.983 | — |

<img src="/Imagenes/TallerIA/Semana5_Tarea/Ruben/fig4_m2_prueba.png" width="900"/>

*Figura 4. Valores reales y predichos por el modelo M2 en el conjunto de prueba
(julio–diciembre de 2023).*

Resultados principales:

- El modelo es globalmente significativo y **todos los coeficientes resultan
  significativos** al 5 %.
- Al controlar por estacionalidad y persistencia, la tendencia temporal pasa a
  ser significativa (p = 0.049) con una disminución estimada de **0.95 ppb por
  año**.
- El coeficiente de `lag1` (0.4089) indica que un incremento de 1 ppb en el día
  previo se asocia a un aumento de 0.41 ppb en el día actual: la persistencia
  es el factor explicativo dominante.
- El estadístico de Durbin-Watson de 1.983, muy cercano a 2, indica ausencia de
  autocorrelación de primer orden en los residuos, lo que valida la inclusión
  del término rezagado.
- Frente al modelo M1, el RMSE de validación se reduce de 7.653 a 6.668 ppb
  (mejora del 12.9 %) y el MAE de 5.836 a 5.059 ppb (mejora del 13.3 %).
- La Figura 4 muestra que el modelo reproduce correctamente el nivel general de
  la serie pero **suaviza los picos**: predice valores cercanos a 32 ppb en días
  en que se observaron hasta 45 ppb.

El R² del conjunto de prueba (0.0671) no es directamente comparable con el R²
de ajuste global, ya que se calcula sobre la varianza del subperiodo
julio–diciembre de 2023. La comparación válida entre modelos es la del RMSE y
el MAE sobre el mismo conjunto.

### 3.6 Modelo M3 — Especificación logarítmica

Ecuación estimada:

```
ln(NO₂) = 2.7858 − 0.0001·t − 0.0381·sin_doy + 0.0534·cos_doy + 0.0160·lag1
```

| Coeficiente | Valor | Error est. | t | P>\|t\| | Significativo (α = 0.05) |
|---|---|---|---|---|---|
| Constante | 2.7858 | 0.043 | 64.145 | 0.000 | Sí |
| t | −0.0001 | 5.59 × 10⁻⁵ | −1.841 | 0.066 | No |
| sin_doy | −0.0381 | 0.017 | −2.282 | 0.023 | Sí |
| cos_doy | 0.0534 | 0.015 | 3.485 | 0.001 | Sí |
| lag1 | 0.0160 | 0.001 | 11.164 | 0.000 | Sí |

| Métrica | Valor |
|---|---|
| R² | 0.187 |
| R² ajustado | 0.182 |
| F (4, 724) | 41.61 (p = 2.01 × 10⁻³¹) |
| Durbin-Watson | 1.955 |

Esta especificación se estimó para corregir la asimetría de los residuos
detectada en M2. Su ventaja no está en el ajuste (R² ligeramente inferior),
sino en el cumplimiento del supuesto de normalidad, como se detalla en la
sección siguiente.

### 3.7 Comparación de modelos

| Modelo | R² ajuste | R² ajustado | F | p (F) | Durbin-Watson | RMSE prueba | MAE prueba |
|---|---|---|---|---|---|---|---|
| M1 — Simple | 0.0033 | 0.0020 | 2.442 | 0.119 | — | 7.653 | 5.836 |
| **M2 — Múltiple** | **0.199** | **0.195** | **45.00** | **9.03 × 10⁻³⁴** | **1.983** | **6.668** | **5.059** |
| M3 — Log-lineal | 0.187 | 0.182 | 41.61 | 2.01 × 10⁻³¹ | 1.955 | — |

### 3.8 Verificación de supuestos

<img src="/Imagenes/TallerIA/Semana5_Tarea/Ruben/fig2_residuos.png" width="900"/>

*Figura 2. Residuos frente a valores predichos en ambas especificaciones.*

**Linealidad y homocedasticidad.** El gráfico de residuos contra valores
predichos del modelo M2 muestra una nube centrada en cero y sin patrón
curvilíneo, lo que respalda la especificación lineal. Se observa, sin embargo,
un ligero aumento de la dispersión hacia los valores predichos más altos
(heterocedasticidad leve), con residuos extremos de hasta +35 y −25 ppb en los
días del episodio de 2022. En la especificación logarítmica esta dispersión se
estabiliza.


<img src="/Imagenes/TallerIA/Semana5_Tarea/Ruben/figuras/fig5_qq.png" width="900"/>


*Figura 5. Gráficos cuantil-cuantil de los residuos de M2 y M3.*

**Normalidad de los residuos.** El gráfico Q-Q del modelo M2 se ajusta a la
diagonal en el centro de la distribución, pero la cola derecha se desvía
claramente hacia arriba, indicando asimetría positiva y colas más pesadas que
la normal: el modelo no reproduce los episodios de concentración elevada. Al
aplicar la transformación logarítmica (M3), la cola derecha se alinea con la
diagonal y solo persiste una desviación en la cola izquierda, atribuible a un
número reducido de días con concentraciones muy bajas. La especificación
log-lineal cumple por tanto mejor el supuesto de normalidad.

**Independencia.** Los estadísticos de Durbin-Watson de 1.983 (M2) y 1.955
(M3), ambos muy próximos al valor de referencia de 2, no evidencian
autocorrelación residual de primer orden.

---

## 4. Discusión

Los resultados permiten responder a los dos objetivos planteados.

Respecto a la tendencia, el modelo simple no detecta un cambio significativo
(p = 0.119). Solo al controlar por estacionalidad y persistencia aparece una
disminución significativa de aproximadamente 0.95 ppb por año. Esto ilustra un
punto metodológico relevante: en series ambientales con alta variabilidad
diaria, una regresión únicamente temporal carece de potencia estadística para
identificar tendencias de magnitud moderada. Aun así, dos años de datos son un
horizonte corto para afirmar una tendencia estructural de la calidad del aire;
el hallazgo debe interpretarse como descriptivo del periodo y no extrapolarse.

Respecto a la capacidad explicativa, el modelo múltiple alcanza un R² de 0.199.
Es un valor bajo en términos absolutos, pero coherente con la literatura sobre
contaminantes atmosféricos diarios, cuya variabilidad depende en gran medida de
variables meteorológicas no incluidas en este análisis: velocidad y dirección
del viento, altura de la capa de mezcla, temperatura, precipitación y
radiación solar. La inspección visual del conjunto de prueba (Figura 4)
confirma esta limitación: el modelo reproduce correctamente el nivel general de
la serie pero suaviza los picos. Este comportamiento es característico de los
modelos con término rezagado, que reaccionan con un día de retardo frente a los
cambios abruptos.

Las principales limitaciones del estudio son:

1. **Ausencia de covariables meteorológicas**, que constituyen el principal
   factor omitido y la vía de mejora más directa del modelo.
2. **Promediado espacial.** Agregar tres estaciones de características
   distintas (dos urbanas en Seattle, una en Tacoma) atenúa los máximos locales
   y puede enmascarar comportamientos específicos de cada sitio.
3. **Heterocedasticidad y colas pesadas** en los residuos del modelo en
   niveles, que afectan la precisión de los intervalos de confianza. La
   transformación logarítmica mitiga este problema.
4. **Inconsistencia de escala en el modelo M3**, donde la variable dependiente
   está en logaritmos mientras que `lag1` se mantiene en ppb. Una
   especificación estrictamente log-log requeriría rezagar ln(NO₂), lo que se
   deja como mejora inmediata.
5. **Episodios extremos.** El pico de agosto–octubre de 2022 sugiere la
   influencia de eventos puntuales, como incendios forestales o episodios de
   inversión térmica, que un modelo lineal no está diseñado para capturar.

Como líneas de mejora se proponen: incorporar datos meteorológicos horarios,
ajustar el modelo por estación de monitoreo en lugar de promediar, evaluar
especificaciones autorregresivas (ARIMA o SARIMA) que traten la serie de forma
explícita, y ampliar el periodo de análisis a cinco o más años para estimar la
tendencia con mayor potencia estadística.

---

## 5. Conclusiones

1. La concentración diaria máxima horaria de NO₂ en Washington durante
   2022–2023 promedió 24.14 ppb, con un rango de 7.50 a 63.67 ppb.
2. No se detecta una tendencia temporal significativa mediante regresión simple
   (p = 0.119); al controlar por estacionalidad y persistencia, se estima una
   disminución significativa de 0.95 ppb por año (p = 0.049).
3. El modelo múltiple es globalmente significativo (F = 45.00,
   p = 9.03 × 10⁻³⁴), explica el 19.9 % de la variabilidad y reduce el RMSE de
   validación en un 12.9 % frente al modelo simple.
4. La persistencia diaria es el predictor dominante: el valor del día anterior
   pesa más que la tendencia y la estacionalidad en conjunto.
5. Se identifica un patrón estacional con mínimos en junio y julio y máximos
   entre agosto y octubre, periodo que concentra además los valores extremos.
6. La especificación logarítmica cumple mejor el supuesto de normalidad de los
   residuos y es preferible para la inferencia estadística sobre los
   coeficientes.

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

[5] U.S. Environmental Protection Agency, "Nitrogen Dioxide (NO2) Pollution —
Basic Information," *EPA.gov*. [En línea]. Disponible en:
https://www.epa.gov/no2-pollution. [Accedido: 17-sep-2026].

[6] U.S. Environmental Protection Agency, "Technical Assistance Document for
the Reporting of Daily Air Quality — the Air Quality Index (AQI),"
EPA 454/B-18-007, Research Triangle Park, NC, EE. UU., 2018.

---

## Anexo — Estructura del repositorio

```
.
├── README.md                            # Este informe
├── regresion_NO2_Washington.ipynb       # Notebook de Google Colab
├── datos/
│   ├── ad_viz_plotval_data.csv          # NO2, Washington, 2022 (EPA)
│   └── ad_viz_plotval_data-2.csv        # NO2, Washington, 2023 (EPA)
└── figuras/
    ├── fig1_estacionalidad.png
    ├── fig2_residuos.png
    ├── fig3_regresion_simple.png
    ├── fig4_m2_prueba.png
    └── fig5_qq.png
```

Para reproducir el análisis: abrir el notebook en Google Colab, subir los dos
archivos CSV al entorno y ejecutar todas las celdas.
