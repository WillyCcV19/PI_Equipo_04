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

| N° | Sección correspondiente | Qué muestra y qué significa |
|---|---|---|
| 1 |  <img src="/Imagenes/TallerRedesNeuronales/110.png" width="500"/> | Son las fotos de vidrio y plástico usadas para entrenar el modelo. No mide ningún resultado, solo confirma con qué datos se trabajó. Las fotos están claras y bien etiquetadas, lo cual es necesario para que el modelo tenga una base decente de aprendizaje. |
| 2 | <img src="/Imagenes/TallerRedesNeuronales/111.png" width="500"/> | La curva de error casi no baja y la precisión se mantiene plana durante varias rondas, subiendo recién al final. El modelo entrenado desde cero no aprendió bien, el resultado no es bueno. |
| 3 |<img src="/Imagenes/TallerRedesNeuronales/112.png" width="500"/> | La matriz muestra 38 aciertos y 38 errores en vidrio, 44 aciertos y 29 errores en plástico. Los aciertos y los errores están muy parejos, el modelo casi no logra diferenciar mejor que adivinando al azar. |
| 4 | <img src="/Imagenes/TallerRedesNeuronales/113.png" width="500"/> | El mapa de calor marca el cuerpo central de la botella como la zona que usó el modelo para decidir que era vidrio. Esa zona tiene sentido para un ojo humano también, es una señal de que el modelo miró algo razonable y no algo irrelevante como el fondo. |
| 5 | <img src="/Imagenes/TallerRedesNeuronales/114.png" width="500"/> | El error de entrenamiento baja todo el tiempo, pero el error de validación empieza a subir cerca de la ronda 5. El modelo empieza a memorizar las reseñas que ya vio en vez de aprender el patrón general. |
| 6 |<img src="/Imagenes/TallerRedesNeuronales/115.png" width="500"/> | El modelo más pequeño llega a su punto más bajo de error antes y se mantiene un poco más estable que el original. Con menos neuronas el modelo generaliza mejor en este caso, no peor. |
| 7 | <img src="/Imagenes/TallerRedesNeuronales/116.png" width="500"/> | El modelo con regularización sigue subiendo su error con el tiempo, aunque de forma menos brusca que el original. Ayuda, pero no resuelve el problema por completo. |
| 8 | <img src="/Imagenes/TallerRedesNeuronales/117.png" width="500"/> | El modelo con dropout arranca peor pero su curva sube de forma más pareja, sin el salto brusco que tiene la regularización. Es más estable, aunque también termina subiendo con el tiempo. |
| 9 |<img src="/Imagenes/TallerRedesNeuronales/118.png" width="500"/> | La línea verde separa los casos de AND, la línea roja separa los casos de OR. Ambas compuertas quedan resueltas porque una sola línea recta logra dejar los casos verdaderos de un lado y los falsos del otro. |
| 10 | <img src="/Imagenes/TallerRedesNeuronales/119.png" width="500"/> | Las líneas azules intentan separar los casos de XOR. Los puntos verdaderos (0,1) y (1,0) quedan en esquinas opuestas, y los falsos (0,0) y (1,1) también en esquinas opuestas entre sí. Ninguna línea recta logra dejar todos los verdaderos de un lado, por eso XOR no se resuelve con un solo perceptrón. |

---

## Aplicación al proyecto FISHMON 365

FISHMON 365 es una boya flotante autónoma, los sensores están selladas herméticamente en un recipiente cilíndrico, con los sensores de pH, temperatura, oxígeno disuelto y turbidez expuestos al agua en y a  distintas alturas. No tiene cámara ni conexión constante a internet porque trabaja en el campo.

| Herramienta | ¿Aplica? | Justificación |
|---|---|---|
| Perceptrón | Sí | El perceptrón recibe varias entradas numéricas, las pondera y da una salida de alerta o no alerta, exactamente el mismo caso que la alarma de sobrecalentamiento del equipo industrial ya trabajada. Aquí las entradas serían las lecturas de pH, temperatura, oxígeno disuelto y turbidez, y la salida sería agua en condición normal. Es simple, no necesita imágenes ni grandes volúmenes de datos, y puede correr en un microcontrolador dentro de la caja sellada. |
| Clasificación con Keras (tipo reseñas) | No | Ese modelo está pensado para textos largos con miles de palabras posibles como entrada, un problema mucho más grande que decidir con cuatro o cinco lecturas de sensores. Usar una red así sería más complejidad de la necesaria para este caso, el perceptrón ya cubre lo que se necesita. |
| CNN | No | La CNN necesita imágenes para funcionar, y la boya no tiene cámara, solo sensores. Tampoco tiene sentido depender de ella porque el dispositivo trabaja en campo sin conexión constante a internet, y este tipo de modelo suele necesitar más capacidad de procesamiento de la que tendría un dispositivo sellado y autónomo como este. |

---

## Conclusiones

- De las tres herramientas del taller, solo el perceptrón encaja de forma directa con FISHMON 365, porque el proyecto trabaja con unas pocas lecturas numéricas de sensores y necesita una decisión simple: alerta o no alerta.
- La clasificación con Keras usada en el taller (reseñas de texto) no aplica, ese problema maneja un volumen de datos mucho mayor al que maneja la boya con sus sensores.
- La CNN tampoco aplica, la boya no cuenta con cámara y su condición de trabajo en campo sin internet constante hace que un modelo de ese tamaño no sea viable.
- El caso de la alarma de sobrecalentamiento resuelto con perceptrón en el taller es, en la práctica, el mismo tipo de problema que FISHMON 365 necesita resolver con sus lecturas de pH, temperatura, oxígeno disuelto y turbidez.
