# Resumen Técnico del Análisis Exploratorio de Datos (EDA) y Proyecto de Regresión

Este documento sintetiza la estructura, el comportamiento y los hallazgos fundamentales del conjunto de datos analizado en el proyecto. Su objetivo es explicar de manera clara y rigurosa la relación entre las variables de operación y el consumo energético obtenido.

## 1. Visión General del Dataset

El análisis se basa en un conjunto de datos industrial (**Data_PI_regresion.csv**) que cuenta con **5,000 registros y 5 variables numéricas continuas**. No presenta valores nulos, lo que proporciona una base sólida para el modelado mediante Regresión Lineal Múltiple.

El objetivo principal es entender qué variables influyen de manera directa en el **Consumo de Energía** (variable dependiente o *target*) a partir de cuatro variables independientes o predictoras (variables operativas y ambientales).

## 2. Descripción de Componentes y Variables

A continuación se detalla la caracterización estadística de cada variable analizada:

| Variable            | Tipo de Variable       |     Media (Promedio) |                         Rango (Mín - Máx) | Descripción y Comportamiento                                                                          |
| ------------------- | ---------------------- | -------------------: | ----------------------------------------: | ----------------------------------------------------------------------------------------------------- |
| **Temperatura**     | Predictora (Ambiental) | $26.5^\circ\text{C}$ | $18.0^\circ\text{C} - 35.0^\circ\text{C}$ | Registra la temperatura ambiente del entorno operativo. Muestra una distribución simétrica.           |
| **Horas_Operacion** | Predictora (Operativa) |     $7.0\text{ hrs}$ |        $2.0\text{ hrs} - 12.0\text{ hrs}$ | Representa el tiempo activo de trabajo. Es el factor directo de mayor impacto sobre el consumo.       |
| **Carga**           | Predictora (Operativa) |              $65.0%$ |                          $30.0% - 100.0%$ | Mide el porcentaje de capacidad/exigencia a la que trabaja el equipo. Presenta impacto moderado-alto. |
| **Humedad**         | Predictora (Ambiental) |              $65.1%$ |                           $40.0% - 90.0%$ | Refleja el porcentaje de humedad relativa. Muestra muy bajo impacto directo en el consumo energético. |
| **Consumo_Energia** | Objetivo (Target)      |    $26.0\text{ kWh}$ |        $9.1\text{ kWh} - 42.6\text{ kWh}$ | Variable dependiente a predecir. Su distribución es Gaussiana (Normal) centrada en $26.0\text{ kWh}$. |

## 3. Principales Hallazgos y Patrones Encontrados

| Aspecto Analizado              | Hallazgo Clave                | Explicación Técnica y Práctica                                                                                                                 |
| ------------------------------ | ----------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------- |
| **Calidad de Datos**           | Completitud del $100%$        | Las $5,000$ filas están completas, lo que elimina la necesidad de imputación de datos.                                                         |
| **Relación Principal**         | Correlación Lineal Alta       | Horas_Operacion muestra una fuerte pendiente positiva con Consumo_Energia. A más horas de uso, el consumo aumenta de forma lineal y constante. |
| **Relación Secundaria**        | Correlación Lineal Moderada   | Carga incrementa proporcionalmente la exigencia eléctrica del sistema.                                                                         |
| **Independencia de Variables** | Ausencia de Multicolinealidad | Las variables predictoras no están fuertemente correlacionadas entre sí, lo que favorece la estabilidad de un modelo de regresión.             |

## 4. Visualizaciones y Fotografías Referenciales

Para facilitar la interpretación del análisis exploratorio, se incluyen las visualizaciones clave generadas en el entorno del notebook.

### [Cuadro para Foto 50: Matriz de Dispersión / Pairplot]

**Identificador:** Foto 50

**Descripción:** Visión global de las relaciones cruzadas entre todas las variables del dataset (sns.pairplot). En la diagonal principal se observan las distribuciones individuales (histogramas) y en los paneles fuera de la diagonal las nubes de puntos de dispersión.

### [Cuadro para Foto 51: Matriz de Correlación / Heatmap]

**Identificador:** Foto 51

**Descripción:** Mapa de calor de correlación de Pearson. Cuantifica en una escala de $-1$ a $+1$ la fuerza de la relación lineal entre cada par de variables.

### [Cuadro para Foto 52: Dispersión Específica de Consumo vs. Horas de Operación]

**Identificador:** Foto 52

**Descripción:** Gráfico de dispersión (scatterplot) que detalla cómo evoluciona el Consumo_Energia conforme aumentan las Horas_Operacion, discriminando los datos mediante la variable Temperatura.

## 5. Conclusión del Proyecto

El análisis exploratorio confirma que el dataset es adecuado para la implementación de algoritmos de aprendizaje supervisado, específicamente la Regresión Lineal Múltiple. Las variables operativas (**Horas_Operacion** y **Carga**) explican la mayor parte de la varianza observada en el **Consumo_Energia**, mientras que las variables ambientales (**Temperatura** y **Humedad**) aportan matices secundarios pero útiles para ajustar la precisión de las predicciones.
