# Análisis de la relación entre PM2.5 y el Índice de Calidad del Aire mediante Regresión Lineal

## 1. Introducción

La contaminación atmosférica puede ser evaluada mediante diferentes contaminantes presentes en el aire. Entre ellos se encuentra el **material particulado PM2.5**, compuesto por partículas finas inhalables con diámetros generalmente iguales o menores a **2.5 µm** [1].

Para comunicar las condiciones de calidad del aire se utiliza el **Air Quality Index (AQI)** o Índice de Calidad del Aire. Este índice permite representar mediante una escala numérica el nivel de contaminación y el nivel de preocupación asociado a la calidad del aire. Valores más altos del AQI representan mayores niveles de contaminación [2].

En Estados Unidos, la Agencia de Protección Ambiental (EPA) recopila información de calidad del aire mediante el **Air Quality System (AQS)**. Dentro de los archivos diarios proporcionados por este sistema se incluyen mediciones de contaminantes como PM2.5 y sus respectivos valores de AQI [3].

En el presente trabajo se analizaron mediciones correspondientes al año **2022** del sitio de monitoreo ubicado en **Fairhope, Alabama**, utilizando principalmente la concentración media diaria de PM2.5 y el valor diario del AQI.

El objetivo del análisis fue estudiar la relación existente entre ambas variables mediante un modelo de **Regresión Lineal Simple**, evaluar su capacidad de ajuste y determinar mediante pruebas estadísticas si la relación lineal encontrada resulta significativa.

---

## 2. Metodología

### 2.1. Descripción y exploración del conjunto de datos

El conjunto de datos utilizado contiene **115 observaciones y 22 variables** relacionadas con mediciones de calidad del aire.

Durante la exploración inicial se observó que muchas de las columnas corresponden a información descriptiva del mismo sitio de monitoreo y mantienen valores constantes. La variable `Date` cambia entre registros, pero no fue utilizada como variable predictora en el modelo.

Para el análisis se seleccionaron:

- **Variable predictora (X):** `Daily Mean PM2.5 Concentration`
- **Variable objetivo (y):** `Daily AQI Value`

Las estadísticas descriptivas obtenidas fueron:

| Variable | Media | Desv. estándar | Mínimo | Máximo |
|---|---:|---:|---:|---:|
| PM2.5 | 7.32 | 3.76 | 2.60 | 33.60 |
| AQI | 38.27 | 13.92 | 14 | 97 |

La concentración de PM2.5 se encuentra expresada en **µg/m³**.

### 2.2. Análisis exploratorio

Antes de construir el modelo se realizó un gráfico de dispersión entre la concentración media diaria de **PM2.5** y el valor diario del **AQI**.

<p align="center">
  <img src="/Imagenes/TallerIA/Screenshot 2026-09-17 162529.png"/>
</p>

*Figura 1. Relación entre la concentración media diaria de PM2.5 y el AQI.*

A partir del gráfico puede observarse una tendencia positiva entre las variables: los valores de AQI tienden a aumentar conforme aumenta la concentración de PM2.5.

También se calculó el coeficiente de correlación entre ambas variables, obteniéndose:

> **r = 0.9349**

Este resultado muestra una asociación lineal positiva fuerte dentro del conjunto de datos analizado.

### 2.3. División de los datos

Para desarrollar el modelo se definió la concentración de PM2.5 como variable predictora y el AQI como variable objetivo.

```python
X = df[['Daily Mean PM2.5 Concentration']]
y = df['Daily AQI Value']
```

Posteriormente, los datos fueron divididos utilizando `train_test_split` en:

> **80 % para entrenamiento**  
> **20 % para prueba**

```python
X_train, X_test, y_train, y_test = train_test_split(
    X,
    y,
    test_size=0.2,
    random_state=123
)
```

El parámetro `random_state=123` permite reproducir la misma división de los datos al volver a ejecutar el código.

### 2.4. Construcción y entrenamiento del modelo

Para el desarrollo del modelo se utilizó `LinearRegression` de **Scikit-learn**, que implementa regresión lineal mediante el método de mínimos cuadrados [4].

```python
modelo = LinearRegression()
modelo.fit(X_train, y_train)
```

La instrucción `fit()` realiza el entrenamiento del modelo utilizando el conjunto de entrenamiento.

Después de este proceso se obtuvieron los siguientes parámetros:

| Parámetro | Valor |
|---|---:|
| Intercepto | 13.5774 |
| Coeficiente de PM2.5 | 3.3481 |
<p align="center">
  <img src="/Imagenes/TallerIA/Screenshot 2026-09-17 163441.png"/>
</p>

Por lo tanto, el modelo obtenido con los datos de entrenamiento puede representarse aproximadamente mediante:

> **AQI = 13.58 + 3.35 × PM2.5**

El coeficiente positivo indica que, dentro del modelo ajustado, un incremento de una unidad en la concentración de PM2.5 está asociado con un incremento aproximado de **3.35 unidades en el AQI predicho**.

Posteriormente se realizaron predicciones utilizando únicamente el conjunto de prueba:

```python
predicciones = modelo.predict(X_test)
```

### 2.5. Predicciones y análisis de residuos

Después de entrenar el modelo se realizaron predicciones utilizando los datos de prueba:

```python
predicciones = modelo.predict(X_test)

### 2.6. Prueba estadística mediante OLS

Además del modelo predictivo desarrollado con Scikit-learn, se realizó un análisis estadístico mediante **Ordinary Least Squares (OLS)** o Mínimos Cuadrados Ordinarios utilizando la biblioteca **Statsmodels** [5].

```python
Xs = sm.add_constant(X)

stat_model = sm.OLS(y, Xs)

stat_result = stat_model.fit()

print(stat_result.summary())
```

`sm.add_constant(X)` permite incorporar el intercepto dentro del modelo estadístico, mientras que `OLS()` realiza el ajuste mediante mínimos cuadrados.

Esta prueba permite obtener información adicional como:

- Coeficientes.
- Error estándar.
- Estadístico t.
- p-value.
- Estadístico F.
- R².
- Intervalos de confianza.

Para analizar la significancia del coeficiente de PM2.5 se plantearon las siguientes hipótesis:

> **H₀:** β₁ = 0. La concentración de PM2.5 no presenta una relación lineal estadísticamente significativa con el AQI.

> **H₁:** β₁ ≠ 0. La concentración de PM2.5 presenta una relación lineal estadísticamente significativa con el AQI.

Se trabajó con un nivel de significancia:

> **α = 0.05**

---

## 3. Resultados

### 3.1. Correlación entre PM2.5 y AQI

La matriz de correlación mostró un coeficiente de:

> **r = 0.934874**

Este valor cercano a 1 evidencia una **asociación lineal positiva fuerte** entre las variables analizadas.

Esto también puede apreciarse en el diagrama de dispersión, donde los puntos siguen una tendencia ascendente.


### 3.2. Valores reales frente a valores predichos

Se compararon gráficamente los valores reales del AQI con los valores estimados por el modelo.

![AQI real vs. AQI predicho](Imagenes/TallerIA/real_predicho.png)

*Figura 2. Comparación entre los valores reales y predichos del AQI.*

Los puntos presentan una tendencia aproximadamente lineal, mostrando que gran parte de las predicciones se aproximan a los valores observados.

### 3.3. Análisis de residuos

También se analizó la diferencia entre cada observación real y su respectiva predicción.

![Valores residuales vs predichos](Imagenes/TallerIA/residuos_predichos.png)

*Figura 3. Residuos obtenidos por el modelo frente a los valores predichos.*

El análisis de residuos permite observar el comportamiento de los errores y detectar posibles desviaciones o patrones que no hayan sido explicados por el modelo lineal.

### 3.4. Resultados de la prueba estadística OLS

El análisis mediante Statsmodels se realizó utilizando las **115 observaciones** disponibles en el conjunto de datos.

Los principales resultados fueron:

| Estadístico | Resultado |
|---|---:|
| R² | **0.874** |
| R² ajustado | **0.873** |
| Intercepto | **12.9202** |
| Coeficiente PM2.5 | **3.4643** |
| Error estándar del coeficiente | **0.124** |
| Estadístico t | **27.996** |
| p-value | **< 0.001** |
| F-statistic | **783.8** |
| Prob. F-statistic | **1.19 × 10⁻⁵²** |

El coeficiente estimado para PM2.5 fue positivo:

> **β₁ = 3.4643**

Además, el estadístico t obtenido fue:

> **t = 27.996**

con un:

> **p-value < 0.001**

Debido a que:

> **p-value < α = 0.05**

se rechaza la hipótesis nula **H₀**.

Por lo tanto, existe evidencia estadística de una **asociación lineal significativa entre la concentración media diaria de PM2.5 y el AQI** en el conjunto de datos analizado.

La prueba F también presentó una probabilidad extremadamente pequeña:

> **Prob(F) = 1.19 × 10⁻⁵²**

lo cual indica que el modelo lineal considerado en su conjunto resulta estadísticamente significativo.

---

## 4. Discusión
Los resultados obtenidos muestran una asociación positiva fuerte entre la concentración media diaria de **PM2.5** y el **AQI**.

El coeficiente de correlación obtenido fue de aproximadamente **0.935**, mientras que el modelo estadístico mediante OLS presentó un **R² de 0.874**. Estos resultados muestran que existe una relación lineal importante entre ambas variables.

Además, la prueba estadística presentó un **p-value menor a 0.001**, proporcionando evidencia suficiente para considerar estadísticamente significativo el coeficiente lineal asociado a PM2.5.

El análisis gráfico de los valores reales frente a los predichos permitió observar el comportamiento de las estimaciones realizadas por el modelo. Asimismo, mediante el gráfico de residuos se analizaron visualmente los errores generados durante la predicción.

Sin embargo, esta relación debe interpretarse considerando la naturaleza de las variables. El AQI es un índice utilizado por la EPA para comunicar la calidad del aire y puede calcularse a partir de concentraciones de contaminantes, entre ellos PM2.5 [2], [3]. Por ello, la fuerte asociación encontrada entre ambas variables es esperable y el presente análisis debe entenderse principalmente como una aplicación de técnicas de regresión lineal y análisis estadístico.

Otra limitación es que los datos analizados pertenecen a **un único sitio de monitoreo** y a un periodo específico del año 2022. Por lo tanto, los resultados no deben generalizarse automáticamente a otras ubicaciones o periodos.

---
## 5. Conclusiones

El análisis permitió estudiar la relación entre la concentración media diaria de **PM2.5** y el **Índice de Calidad del Aire (AQI)** mediante un modelo de Regresión Lineal Simple.

Se encontró una correlación positiva fuerte de aproximadamente **0.935** entre ambas variables, indicando que los valores de AQI tienden a aumentar conforme aumenta la concentración de PM2.5.

Mediante la comparación entre los valores reales y los valores predichos se pudo observar el comportamiento de las estimaciones realizadas por el modelo. Asimismo, el análisis de residuos permitió estudiar visualmente los errores generados durante la predicción.

La prueba estadística realizada mediante **OLS** presentó un **R² de 0.874** y confirmó que el coeficiente correspondiente a PM2.5 es estadísticamente significativo, debido a que presentó un **p-value inferior a 0.05**.

Por lo tanto, se concluye que existe una asociación lineal positiva y estadísticamente significativa entre la concentración media diaria de PM2.5 y el AQI dentro del conjunto de datos analizado.

Finalmente, el trabajo permitió aplicar las principales etapas de un análisis de regresión:

> **Exploración de datos → Selección de variables → Entrenamiento → Predicción → Análisis de residuos → Análisis estadístico**

---

## 6. Referencias

[1] U.S. Environmental Protection Agency, “Particulate Matter (PM) Basics,” *U.S. EPA*. [En línea]. Disponible en: https://www.epa.gov/pm-pollution/particulate-matter-pm-basics.

[2] U.S. Environmental Protection Agency, “AQI Basics,” *AirNow.gov*. [En línea]. Disponible en: https://www.airnow.gov/aqi/aqi-basics/.

[3] U.S. Environmental Protection Agency, “Download Files,” *AirData*. [En línea]. Disponible en: https://aqs.epa.gov/aqsweb/airdata/download_files.html.

[4] Scikit-learn Developers, “LinearRegression,” *Scikit-learn Documentation*. [En línea]. Disponible en: https://scikit-learn.org/stable/modules/generated/sklearn.linear_model.LinearRegression.html.

[5] Statsmodels Developers, “statsmodels.regression.linear_model.OLS,” *Statsmodels Documentation*. [En línea]. Disponible en: https://www.statsmodels.org/stable/generated/statsmodels.regression.linear_model.OLS.html.
