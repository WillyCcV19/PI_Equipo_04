# Introducción

El siguiente documento detalla el análisis de la calidad de aire para predecir la concentración diaria máxima de monóxido de carbono utilizando regresión lineal, con datos obtenidos de la Agencia de Protección Ambiental (EPA por sus siglas en inglés) [1]. El análisis exploratorio fue utilizado para identificar relaciones entre variables y evaluar la capacidad predictiva.

# Metodología

El conjunto de datos presenta mediciones diarias desde el 1/1/2022 hasta 31/12/2023 de distintos lugares dentro del estado de Iowa como Birmingham del norte, FairField y Arkadelfia [1].

El objetivo fue estudiar la relación existente entre variables y observar el poder predictivo cuando al modelo de regresión lineal se le presentan variables que pueden dar lugar a fugas de información y cuando se remueven dichas variables.

Para el caso 1 se seleccionaron las siguientes variables:

Predictores:
- POC
- Índice de calidad de aire diario
- número de observaciones
- Porcentaje completo
- Latitud
- Longitud
- Elevación
- Longitud de sensor
- Función seno del año
- Función coseno del año

Objetivo:
- Concentración máxima de monóxido de carbono

Para el caso 2 se removió el Índice de calidad de aire diario.

La "Concentración diaria máxima de monóxido de carbono" y el "Índice diario de calidad de aire (AQI)" presentan una muy fuerte relación (0.99), debido a que la concentración de Monóxido de Carbono es una de las variables utilizadas para el cálculo del índice AQI. Ver página 18 de [2]

# Análisis exploratorio

A partir del gráfico se observa la relación entre el Índice diario de calidad de aire (Daily AQI Value) y la concentración diaria máxima de monóxido de carbono (Daily Max CO Concentration):
<img src="/Imagenes/TallerIA/SaturdayNightSpecial.png" width=1000/>

# División de los datos y construcción del modelo de regresión

70% fue utilizado de entrenamiento.
30% fue utilizado de prueba.

Se utilizó un modelo de regresión lineal proveniente de la librería scikit learn.

# Resultados

## Caso 1: Con AQI (Índice de calidad de aire)
| Curva de regresión | Residuales | Distribución de residuales |
| --- | --- | --- |
| <img src="/Imagenes/TallerIA/regresion1.png" width=500/> | <img src="/Imagenes/TallerIA/residual1.png" width=500/> | <img src="/Imagenes/TallerIA/distribucion1.png" width=500/> |

## Caso 2: Sin AQI como una de las variables predictoras
| Curva de regresión | Residuales | Distribución de residuales |
| --- | --- | --- |
| <img src="/Imagenes/TallerIA/regresion2.png" width=500/> | <img src="/Imagenes/TallerIA/residual2.png" width=500/> | <img src="/Imagenes/TallerIA/distribucion2.png" width=500/> |

- En el caso 1 se puede observar que la predicción sigue a los valores actuales, pero en el caso 2 la relación lineal entre los valores reales y las predicciones se debilita considerablemente.

- En los residuales se puede observar que el rango aumenta considerablemente, pasando de (-0.125 a 0.075) a (-0.4 a 0.6).

# Conclusiones

El modelo con AQI presenta un mejor desempeño y menor rango de residuales. Al eliminar dicha variable, los errores aumentan considerablemente, evidenciando que aporta información muy relacionada con la concentración máxima de CO. Por otra parte, el segundo modelo permite evaluar mejor el poder predictivo de las demás variables.

# Referencias
[1] U.S. Environmental Protection Agency, U.S. E.P.A. Air data. [En línea]. Disponible en: https://rconnect-public.epa.gov/AirData/
[2] U.S. Environmental Protection Agency, "Technical Assistance Document for the Reporting of Daily Air Quality", U.S. E.P.A. [En línea]. Disponible en: https://document.airnow.gov/technical-assistance-document-for-the-reporting-of-daily-air-quailty.pdf
