# Redes neuronales: CNN, Keras y Perceptrón

## CNN

Una CNN es una red neuronal diseñada principalmente para trabajar con imágenes. Su objetivo es aprender automáticamente a distinguir características visuales, como bordes, formas, texturas y patrones.

La forma de trabajo de una CNN normalmente es la siguiente:

1. Observa la imagen.
2. Mediante capas de convolución, detecta características importantes.
3. Combina esas características para reconocer patrones más complejos.
4. Finalmente, una capa de clasificación determina a qué clase pertenece la imagen.

### Imagen representativa

<img width="989" height="661" alt="cnn_ejemplos" src="https://github.com/user-attachments/assets/eb2030c0-70ac-4488-aad1-2df53735a41a" />

**Interpretación:** En esta imagen se observan ejemplos del conjunto de datos utilizado en el laboratorio. Las imágenes corresponden a las clases **glass** y **plastic**, que son las dos categorías que la CNN debe aprender a diferenciar a partir de sus características visuales.

<img width="863" height="395" alt="cnn_metricas" src="https://github.com/user-attachments/assets/dbdbaff0-4ae2-4953-9171-055403d8bdaa" />

**Interpretación:** La gráfica muestra la evolución de las métricas de validación de la CNN entrenada desde cero. De acuerdo con el análisis realizado en el notebook, a partir de la época 4 el modelo comienza a clasificar con mayor exactitud y alcanza aproximadamente un **63.27 % de accuracy**. El ROC-AUC se mantiene alrededor de **0.67 a 0.69**, lo que indica un aprendizaje moderado para diferenciar vidrio de plástico.

## Keras

Keras nos permite construir, entrenar y evaluar modelos de redes neuronales utilizando capas y funciones ya preparadas, sin tener que programar desde cero todo el funcionamiento matemático de una red neuronal.

Esta herramienta facilita la creación de modelos, ya que permite definir las capas de la red, configurar la forma en que el modelo aprenderá, entrenarlo utilizando datos y posteriormente evaluar su rendimiento.

Además, Keras permite realizar predicciones una vez que el modelo ha sido entrenado.

### Imagen representativa

![Pérdida de entrenamiento y validación en Keras](redes_neuronales_img/keras_sobreajuste.png)

**Interpretación:** La gráfica compara el error del modelo durante el entrenamiento con el error obtenido en los datos de validación. En el notebook se observa que la curva de validación deja de disminuir al final, mientras que el modelo continúa aprendiendo los datos de entrenamiento. Esto representa un caso de **sobreajuste**, donde el modelo aprende demasiado bien los datos de entrenamiento y pierde capacidad de generalización.

## Perceptrón

El perceptrón es un modelo de red neuronal que recibe varios datos de entrada y les asigna determinados pesos.

A partir de estas entradas, calcula una suma ponderada junto con un valor de sesgo o **bias**. Luego, el resultado pasa por una función de activación, la cual determina la salida del perceptrón.

En el laboratorio se utilizan funciones de activación como **escalón** y **tanh**, además de ejemplos de perceptrones aplicados a operaciones como AND, OR y XOR.

### Imagen representativa

![Fronteras de decisión del perceptrón](redes_neuronales_img/perceptron_fronteras.png)

**Interpretación:** La gráfica permite visualizar las fronteras de decisión de los perceptrones utilizados para representar las operaciones **AND** y **OR**. Para OR, la frontera separa el punto (0,0) del resto, mientras que para AND separa el punto (1,1) del resto. Esto muestra cómo un perceptrón puede separar diferentes grupos de datos mediante una frontera de decisión.

## ¿Cuál usaría en mi proyecto?

Para el proyecto FISHMON 365, la opción que consideraría más recomendable de las estudiadas es el perceptrón, debido a que el sistema trabaja principalmente con datos obtenidos mediante sensores de calidad del agua, como oxígeno disuelto, temperatura, pH y turbidez.

Estos valores pueden utilizarse como datos de entrada para que el modelo determine una salida o clasificación relacionada con el estado del agua. Por ejemplo, podría ayudar a identificar si las condiciones medidas se encuentran dentro o fuera de un rango adecuado para la crianza de truchas.

Keras también podría utilizarse en FISHMON 365, pero no como un modelo equivalente al perceptrón o a una CNN. Keras es una herramienta que facilita la construcción, entrenamiento y evaluación de redes neuronales, por lo que podría servir para desarrollar modelos más complejos en futuras mejoras del proyecto.

En el caso de una CNN, no sería la opción principal para la versión actual de FISHMON 365, debido a que el proyecto se basa principalmente en datos obtenidos por sensores y no en el procesamiento de imágenes. Sin embargo, podría ser útil en una futura implementación si se incorpora una cámara para analizar visualmente a los peces o alguna condición observable del entorno acuático.

Por ello, de las tres opciones revisadas, el perceptrón sería el más directamente aplicable a la versión actual de FISHMON 365, Keras podría utilizarse como herramienta para construir y entrenar modelos, y la CNN quedaría como una alternativa para futuras funciones basadas en imágenes.
