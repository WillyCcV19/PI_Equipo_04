# Introducción

En siguiente documento detalla el análisis de la calidad de aire para predecir la concentración máxima de monóxido de carbono utilizando regresión lineal, con datos obtenidos de la Agencia de Protección Ambiental (EPA por sus siglas en inglés). El análisis exploratorio fue itilizado para identificar relaciones entre variables y evaluar la capacidad predictiva.

# Metodología

EL conjunto de datos presenta mediciones diarias desde el 1/1/2022 hasta 31/12/2023 de distintos lugares dentro del estado de Iowa como Birmingham del norte, FairField y Arkadelfia.

El objetivo fue estudiar la relación existente entre variables y observar el poder predictivo cuando al modelo de regresión lineal se le presentan variables que pueden dar lugar a fugas y cuando se remueven dichas variables.

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
- Año función seno
- Año función coseno

Objetivo:
- Concentración máxima de monóxido de carbono

Para el caso 2 se removió el Índice de calidad de aire diario.

# Análisis exploratorio

A partir de siguientes gráficos se puede confirmar la relación entre el Índice de calidad de aire y la concentración máxima de monóxido de carbono.

# División de los datos y construcción del modelo de regresión

70% fue utilizado de entrenamiento.
30% fue utilizado de prueba.

Se utilizó un modelo de regresión lineal proveniente de la librería scikit learn.

# Resultados

## Con AQI (Índice de calidad de aire)
| Curva de regresión | Residuales | Distribución de residuales |
| --- | --- | --- |
| <img src="/Imagenes/TallerIA/regresion1.png" width=500/> | <img src="/Imagenes/TallerIA/residual1.png" width=500/> | <img src="/Imagenes/TallerIA/distribucion1.png" width=500/> |

## Sin AQI como una de las variables predictoras
| Curva de regresión | Residuales | Distribución de residuales |
| --- | --- | --- |
| <img src="/Imagenes/TallerIA/regresion2.png" width=500/> | <img src="/Imagenes/TallerIA/residual2.png" width=500/> | <img src="/Imagenes/TallerIA/distribucion2.png" width=500/> |

...
