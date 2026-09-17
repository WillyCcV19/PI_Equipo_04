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

![Relación entre PM2.5 y AQI](Imagenes/TallerIA/pm25_aqi.png)

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

Por lo tanto, el modelo obtenido con los datos de entrenamiento puede representarse aproximadamente mediante:

> **AQI = 13.58 + 3.35 × PM2.5**

El coeficiente positivo indica que, dentro del modelo ajustado, un incremento de una unidad en la concentración de PM2.5 está asociado con un incremento aproximado de **3.35 unidades en el AQI predicho**.

Posteriormente se realizaron predicciones utilizando únicamente el conjunto de prueba:

```python
predicciones = modelo.predict(X_test)
```

### 2.5. Evaluación del modelo

Para evaluar el desempeño predictivo se utilizaron tres métricas:

- **R²:** mide la proporción de variabilidad de la variable objetivo explicada por el modelo.
- **MAE:** representa el error absoluto promedio entre los valores reales y predichos.
- **RMSE:** mide el error cuadrático medio y penaliza en mayor medida los errores grandes.

Los residuos se calcularon mediante:

```python
residuos = y_test - predicciones
```

Estos representan la diferencia entre los valores reales y los valores estimados por el modelo.

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

### 3.2. Evaluación predictiva

Al realizar las predicciones sobre el **20 % de los datos reservado para prueba**, se obtuvieron los siguientes resultados:

| Métrica | Resultado |
|---|---:|
| R² | **0.8992** |
| MAE | **3.4520** |
| RMSE | **4.0779** |

El valor de **R² = 0.8992** indica que, para el conjunto de prueba utilizado, aproximadamente el **89.9 % de la variabilidad observada en el AQI fue explicada por el modelo lineal**.

El MAE obtenido indica una diferencia absoluta promedio de aproximadamente **3.45 unidades de AQI** entre los valores reales y las predicciones.

### 3.3. Valores reales frente a valores predichos

Se compararon gráficamente los valores reales del AQI con los valores estimados por el modelo.

![AQI real vs. AQI predicho](Imagenes/TallerIA/real_predicho.png)

*Figura 2. Comparación entre los valores reales y predichos del AQI.*

Los puntos presentan una tendencia aproximadamente lineal, mostrando que gran parte de las predicciones se aproximan a los valores observados.

### 3.4. Análisis de residuos

También se analizó la diferencia entre cada observación real y su respectiva predicción.

![Valores residuales vs predichos](Imagenes/TallerIA/residuos_predichos.png)

*Figura 3. Residuos obtenidos por el modelo frente a los valores predichos.*

El análisis de residuos permite observar el comportamiento de los errores y detectar posibles desviaciones o patrones que no hayan sido explicados por el modelo lineal.

### 3.5. Resultados de la prueba estadística OLS

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

Los resultados obtenidos mediante diferentes métodos muestran una asociación positiva fuerte entre la concentración media diaria de **PM2.5** y el **AQI**.

El coeficiente de correlación obtenido fue de aproximadamente **0.935**, mientras que el modelo estadístico OLS presentó un **R² de 0.874**. En una regresión lineal simple con intercepto, estos resultados son coherentes entre sí, ya que el cuadrado de la correlación se encuentra muy próximo al coeficiente de determinación obtenido.

Por otro lado, el modelo entrenado con Scikit-learn obtuvo un **R² de 0.8992 sobre el conjunto de prueba**, acompañado de un MAE de aproximadamente **3.45** y un RMSE de aproximadamente **4.08**.

Debe considerarse que el R² obtenido mediante Scikit-learn y el R² mostrado por Statsmodels no corresponden exactamente al mismo procedimiento. El primero evalúa las predicciones sobre el **20 % reservado para prueba**, mientras que el modelo OLS fue ajustado utilizando las **115 observaciones** del conjunto completo.

La prueba estadística mostró además un **p-value menor a 0.001**, proporcionando evidencia suficiente para considerar significativo el coeficiente lineal asociado a PM2.5.

Sin embargo, esta relación debe interpretarse considerando la naturaleza de las variables. El AQI es un índice utilizado por la EPA para comunicar la calidad del aire y puede calcularse a partir de concentraciones de contaminantes, entre ellos PM2.5 [2], [3]. Por ello, la fuerte asociación encontrada entre ambas variables es esperable y el presente análisis debe entenderse principalmente como una aplicación de técnicas de regresión lineal y análisis estadístico, no como evidencia de una relación causal independiente.

Otra limitación es que los datos analizados pertenecen a **un único sitio de monitoreo** y a un periodo específico del año 2022. Por lo tanto, los resultados no deben generalizarse automáticamente a otras ubicaciones o periodos.

Asimismo, la división de entrenamiento y prueba fue realizada aleatoriamente. Al tratarse de observaciones fechadas, un análisis futuro podría considerar una separación cronológica para evaluar el comportamiento predictivo sobre periodos posteriores.

---

## 5. Conclusiones

El análisis permitió estudiar la relación entre la concentración media diaria de **PM2.5** y el **Índice de Calidad del Aire (AQI)** utilizando técnicas de Regresión Lineal Simple.

Se encontró una correlación positiva fuerte de aproximadamente **0.935** entre ambas variables.

El modelo desarrollado con Scikit-learn obtuvo un **R² de 0.8992** sobre los datos de prueba, indicando un alto nivel de ajuste para las observaciones utilizadas. Asimismo, se obtuvo un MAE de **3.45** y un RMSE de **4.08**.

La prueba estadística mediante OLS confirmó que el coeficiente correspondiente a PM2.5 es estadísticamente significativo, debido a que presentó un **p-value inferior a 0.05**.

Por lo tanto, se concluye que existe una asociación lineal positiva y estadísticamente significativa entre las variables dentro del conjunto de datos analizado.

Finalmente, el trabajo permitió aplicar las principales etapas de un análisis de regresión:

> **Exploración de datos → Selección de variables → Entrenamiento → Predicción → Evaluación → Análisis estadístico**

---

## 6. Referencias

[1] U.S. Environmental Protection Agency, “Particulate Matter (PM) Basics,” *U.S. EPA*. [En línea]. Disponible en: https://www.epa.gov/pm-pollution/particulate-matter-pm-basics.

[2] U.S. Environmental Protection Agency, “AQI Basics,” *AirNow.gov*. [En línea]. Disponible en: https://www.airnow.gov/aqi/aqi-basics/.

[3] U.S. Environmental Protection Agency, “Download Files,” *AirData*. [En línea]. Disponible en: https://aqs.epa.gov/aqsweb/airdata/download_files.html.

[4] Scikit-learn Developers, “LinearRegression,” *Scikit-learn Documentation*. [En línea]. Disponible en: https://scikit-learn.org/stable/modules/generated/sklearn.linear_model.LinearRegression.html.

[5] Statsmodels Developers, “statsmodels.regression.linear_model.OLS,” *Statsmodels Documentation*. [En línea]. Disponible en: https://www.statsmodels.org/stable/generated/statsmodels.regression.linear_model.OLS.html.
