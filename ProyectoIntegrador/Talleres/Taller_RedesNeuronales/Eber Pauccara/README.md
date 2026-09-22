### Resumen de la sesión: CNN, Clasificación con Keras,  Perceptrón y aplicacion en Fishmon 365
---
> Taller de Redes Neuronales — Fundamentos de CNN, Keras y Perceptrón aplicados a un caso de clasificación de residuos, análisis de texto y compuertas lógicas.
---

## Parte 1: Redes Neuronales Convolucionales (CNN)

### Conceptos generales

Una CNN es un tipo de inteligencia artificial diseñada para analizar imágenes. A diferencia de otros métodos, no revisa los puntos de una foto de forma aislada, sino que analiza zonas cercanas entre sí, de manera similar a cómo el ojo humano reconoce formas y patrones.

### Proceso de funcionamiento

| Etapa | Qué ocurre |
|---|---|
| Convolución | Un filtro pequeño ("kernel") recorre la imagen detectando rasgos simples: bordes, cambios de color, texturas. En capas más profundas, estos rasgos se combinan para reconocer formas completas. |
| Activación (ReLU) | Se descartan los rasgos que no aportan información relevante y se conservan los que sí. Esto permite que el modelo aprenda relaciones más complejas que una simple suma de valores. |
| Reducción (Pooling) | La información se resume, conservando lo esencial y descartando detalles menores. Esto acelera el procesamiento y evita que el modelo dependa de detalles insignificantes. |
| Capas finales (densas) | Toda la información recolectada se combina para producir una decisión final: a qué categoría pertenece la imagen. |

### Aplicación práctica: clasificación de vidrio y plástico

Se entrenó una CNN desde cero para distinguir imágenes de vidrio y plástico, utilizando el dataset TrashNet (organizado mediante el script `trash_dataset.py`, que separa las imágenes en 70% para entrenamiento, 15% para validación y 15% para prueba final).

| Resultado obtenido | Descripción |
|---|---|
| Curvas de entrenamiento | Muestran la evolución del error y de la precisión del modelo a lo largo de las rondas de entrenamiento. |
| Matriz de confusión | Resume los aciertos y errores del modelo al clasificar las imágenes de prueba, evidenciando un desempeño limitado en esta primera versión. |

### Mejora mediante Transfer Learning

Se incorporó un modelo previamente entrenado con un gran volumen de imágenes generales, ajustando únicamente su parte final al problema específico de vidrio y plástico. Esta estrategia produjo mejores resultados que el entrenamiento desde cero, con menor esfuerzo y menos datos necesarios.

### Aumento de datos (Data Augmentation)

Se generaron variaciones artificiales de las imágenes existentes (giros, cambios de orientación) para evitar que el modelo memorizara posiciones específicas en lugar de aprender el patrón real de cada material.

### Interpretabilidad (Grad-CAM)

Se aplicó una técnica que genera un mapa de calor sobre la imagen, señalando qué zona utilizó el modelo para tomar su decisión. Esto permite verificar si el modelo está basando su clasificación en información relevante.

---

## Parte 2: Clasificación binaria con Keras

### Descripción del problema

Se trabajó con un conjunto de reseñas de películas, cada una etiquetada previamente como positiva o negativa, con el objetivo de que un modelo aprendiera a clasificar reseñas nuevas.

### Procesamiento de los datos

Cada reseña se transformó en una lista numérica de ceros y unos, donde cada posición indica la presencia o ausencia de una palabra determinada del vocabulario. Esta representación numérica es la que el modelo utiliza como entrada.

### Modelo y resultado

| Elemento | Detalle |
|---|---|
| Estructura | Conjunto de capas densas apiladas, que refinan progresivamente la clasificación. |
| Resultado de prueba | El modelo predijo una reseña de ejemplo como positiva con 99.4% de confianza. |

### Comparaciones y ajustes

| Prueba realizada | Propósito |
|---|---|
| Modelo más pequeño | Evaluar si un modelo con menos capacidad generaliza mejor o peor que el original. |
| Regularización | Penaliza al modelo cuando se vuelve demasiado complejo, evitando que memorice en exceso los datos de entrenamiento. |
| Dropout | Desactiva neuronas al azar durante el entrenamiento, distribuyendo el aprendizaje en toda la red en lugar de concentrarlo en unas pocas unidades. |

Ambas técnicas (regularización y Dropout) buscan el mismo objetivo: que el modelo mantenga un buen desempeño frente a datos nuevos, no solo frente a los datos ya vistos.

---

## Parte 3: Perceptrón

### Concepto

El perceptrón es la unidad más elemental de una red neuronal: una sola neurona artificial que recibe varias entradas, las pondera según su importancia y produce una salida.

### Funciones de decisión utilizadas

| Función | Comportamiento |
|---|---|
| Escalón | Respuesta binaria estricta: 0 o 1, sin valores intermedios. |
| Tanh | Respuesta entre -1 y 1, permitiendo expresar distintos niveles de certeza. |

### Caso aplicado

Se utilizó un perceptrón para simular una alerta de sobrecalentamiento en un equipo industrial, a partir de ciertos factores de entrada. En las pruebas realizadas, el resultado indicó ausencia de alerta con ambas funciones de activación.

### Compuertas lógicas

| Compuerta | Resultado con el perceptrón simple |
|---|---|
| AND | Resuelta correctamente. |
| OR | Resuelta correctamente. |
| XOR | No pudo resolverse; no existe una única línea recta capaz de separar correctamente los casos. |

Esta limitación es la razón histórica por la cual se desarrollaron las redes con múltiples capas: conectando varias neuronas es posible combinar distintas líneas de separación y resolver problemas que una sola neurona no puede resolver por sí sola.

---

## Imágenes del documento

| N° | Sección correspondiente | Contenido |
|---|---|---|
| 1 |  <img src="/Imagenes/TallerRedesNeuronales/110.png" width="500"/> | Cuadrícula de 12 imágenes de ejemplo, etiquetadas "glass" y "plastic". |
| 2 | <img src="/Imagenes/TallerRedesNeuronales/111.png" width="500"/> | Curvas de pérdida y de métricas de validación a lo largo de las rondas de entrenamiento. |
| 3 |<img src="/Imagenes/TallerRedesNeuronales/112.png" width="500"/> | Matriz de confusión con los aciertos y errores de clasificación en el conjunto de prueba. |
| 4 | <img src="/Imagenes/TallerRedesNeuronales/113.png" width="500"/> | Comparación entre imagen original, mapa de calor Grad-CAM y superposición de ambos. |
| 5 | <img src="/Imagenes/TallerRedesNeuronales/114.png" width="500"/> | Curva de pérdida en entrenamiento y validación. |
| 6 |<img src="/Imagenes/TallerRedesNeuronales/115.png" width="500"/> | Curva comparativa entre el modelo original y una versión reducida. |
| 7 | <img src="/Imagenes/TallerRedesNeuronales/116.png" width="500"/> | Curva comparativa incorporando el modelo con regularización. |
| 8 | <img src="/Imagenes/TallerRedesNeuronales/117.png" width="500"/> | Curva comparativa incorporando el modelo con Dropout. |
| 9 |<img src="/Imagenes/TallerRedesNeuronales/118.png" width="500"/> | Líneas de separación encontradas para ambos casos. |
| 10 | <img src="/Imagenes/TallerRedesNeuronales/119.png" width="500"/> | Representación visual de la imposibilidad de separar los casos con una línea recta. |

---

## Aplicación al proyecto FISHMON 365

| Herramienta | Aplicación en el monitoreo de calidad de agua para truchicultura |
|---|---|
| Perceptrón / red densa | Clasificación de lecturas de sensores (oxígeno, temperatura, pH) en "condición normal" o "condición de alerta". |
| CNN | Análisis de imágenes captadas por una eventual cámara sumergible, para detectar turbidez o señales visuales relevantes. |
| Grad-CAM | Justificación visual de las alertas generadas, indicando qué dato o zona de imagen influyó en la decisión. |
| Transfer Learning | Aprovechamiento de modelos previamente entrenados en contextos acuícolas similares, reduciendo la necesidad de grandes volúmenes de datos propios. |
| Regularización / Dropout | Mejora de la confiabilidad del modelo ante condiciones distintas a las registradas en el sitio de prueba. |
| Aumento de datos | Generación de variaciones sobre datos limitados, para fortalecer el entrenamiento del modelo. |

---

## Conclusiones

- El perceptrón y la CNN abordan el mismo tipo de problema (clasificación entre categorías), pero en escalas distintas: uno es la unidad mínima de decisión, la otra es una arquitectura compleja orientada al análisis de imágenes.
- El uso de un modelo previamente entrenado (transfer learning) resultó más eficiente que entrenar una CNN desde cero, tanto en precisión como en cantidad de datos requeridos.
- Un modelo de mayor tamaño no garantiza mejores resultados; técnicas como la regularización y el Dropout existen para mantener el aprendizaje generalizable y evitar la memorización excesiva.
- La interpretabilidad, mediante herramientas como Grad-CAM, permite verificar y explicar las decisiones de un modelo, un aspecto relevante en sistemas donde la confianza del usuario final es importante.
- El perceptrón simple tiene una limitación estructural (no resuelve XOR), lo cual constituye el fundamento histórico del desarrollo de redes neuronales con múltiples capas.
- Los conceptos abordados tienen aplicación directa en el proyecto FISHMON 365, tanto en su etapa actual basada en sensores como en una eventual incorporación de visión por cámara.
