## 🤖 Taller de Inteligencia Artificial – Semana 5 [Verenisse Quispitongo Leon]

En este taller se realizó un análisis de datos orientado a la **predicción del consumo de energía**, aplicando técnicas de análisis exploratorio, regresión lineal y evaluación de modelos de Machine Learning.

###  1. Exploración de los datos

Inicialmente se cargó el conjunto de datos utilizando **Pandas** y se realizó una exploración general mediante estadísticas descriptivas y visualizaciones.

Se analizaron variables como:

- 🌡️ Temperatura
- 💧 Humedad
- ⚡ Carga
- ⏱️ Horas de operación
- 🔋 Consumo de energía

Se utilizaron histogramas, gráficos de densidad, diagramas de dispersión y un mapa de calor para identificar posibles relaciones entre las variables.
<p align="center">
  <img src="/Imagenes/TallerIA/Screenshot 2026-09-15 164200.png" width="900"/>
</p>

###  2. Análisis de correlación

Se seleccionaron únicamente las variables numéricas del conjunto de datos y se utilizó el método `corr()` de **Pandas** para calcular la matriz de correlación. Esto permitió identificar qué variables presentan una mayor relación lineal con el **consumo de energía**.

```python
numeric_df = df.select_dtypes(include=np.number)

# Selecciona solo las columnas con valores numéricos
numeric_df.head()

# Cálculo de la matriz de correlación
numeric_df.corr().round(4)
```

Posteriormente, la matriz de correlación fue representada gráficamente mediante un **mapa de calor (heatmap)** utilizando la librería **Seaborn**.
<p align="center">
  <img src="/Imagenes/TallerIA/Screenshot 2026-09-15 164704.png" width="900"/>
</p>

###  3. Regresión Lineal Múltiple

Se implementó un modelo de **Regresión Lineal Múltiple**, utilizando el consumo de energía como variable objetivo y las demás características como variables predictoras.

Los datos fueron divididos en:
El parámetro `test_size=0.2` indica que el **20 % de los datos se utiliza para prueba**, mientras que el **80 % restante se utiliza para entrenamiento**.

> **80 % para entrenamiento**  
> **20 % para prueba**

Además, se utilizó `random_state=123` para que la división de los datos sea reproducible y se obtenga la misma separación cada vez que se ejecute el código

El modelo fue entrenado utilizando `LinearRegression` de **Scikit-learn**.

###  4. Análisis de los coeficientes

Después de entrenar el modelo de **Regresión Lineal Múltiple**, se analizaron los coeficientes obtenidos para conocer la influencia de cada variable sobre la predicción del consumo de energía.

Además, se representó gráficamente la relación entre cada variable predictora y el **consumo de energía** mediante diagramas de dispersión.

![Relación entre variables y consumo de energía](/Imagenes/TallerIA/variables_consumo.png)


En los gráficos se puede observar que las **horas de operación** presentan una relación positiva más clara con el consumo de energía, ya que conforme aumentan las horas de funcionamiento también tiende a aumentar el consumo.

La variable **carga** también muestra una tendencia positiva, aunque menos marcada. Por otro lado, la **temperatura** y la **humedad** presentan una relación visual mucho más débil con el consumo energético.

Este análisis permite comprender cuáles de las variables tienen una mayor influencia y relación con el comportamiento del consumo de energía.

###  5. Evaluación del modelo

Se realizaron predicciones utilizando los datos de prueba y se compararon los:

> **Valores reales vs. Valores predichos**
<p align="center">
  <img src="/Imagenes/TallerIA/Screenshot 2026-09-15 210025.png" width="900"/>
</p>

*La cercanía de los puntos a una tendencia lineal indica que las predicciones del modelo se aproximan a los valores reales.*

También se analizaron los **residuos**, es decir, las diferencias entre los valores reales y las predicciones del modelo, para evaluar su comportamiento.

###  6. Datos sintéticos y Árbol de Decisión

En la segunda parte del taller se generó un conjunto de datos artificial utilizando `make_regression`, compuesto por **100 muestras y 6 características**, de las cuales 3 fueron definidas como informativas.

Con estos datos se trabajó con un modelo de **Árbol de Decisión**, permitiendo comparar otra técnica de Machine Learning con el enfoque de regresión lineal.

###  Conclusión

El taller permitió comprender el proceso básico para desarrollar un modelo de Machine Learning:

**Explorar los datos → Analizar relaciones → Preparar los datos → Entrenar el modelo → Realizar predicciones → Evaluar resultados.**

Además, se reforzó el uso de herramientas como **Pandas, NumPy, Matplotlib, Seaborn y Scikit-learn** para el análisis y modelado de datos.
