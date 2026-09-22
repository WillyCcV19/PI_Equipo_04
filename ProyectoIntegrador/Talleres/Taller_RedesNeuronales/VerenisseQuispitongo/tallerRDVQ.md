# Redes Neuronales

En este taller se trabajaron diferentes conceptos relacionados con redes neuronales. Se utilizaron Redes Neuronales Convolucionales (CNN) para clasificación de imágenes, Keras para construir una red neuronal de clasificación binaria y finalmente se estudió el funcionamiento básico de un Perceptrón.

## Redes Neuronales Convencionales (CNN)

Las CNN (Convolutional Neural Networks) son redes neuronales especialmente utilizadas para trabajar con imágenes. Su principal característica es que pueden analizar grupos de píxeles cercanos y aprender automáticamente patrones presentes en una imagen.

Para ello utilizan pequeños filtros llamados kernels, los cuales recorren la imagen buscando características como bordes, formas, texturas y estructuras.

En una CNN se pueden identificar principalmente los siguientes componentes:

- **Conv2D:** aplica filtros sobre la imagen para extraer características.
- **ReLU:** transforma los valores negativos en cero y mantiene los valores positivos.
- **MaxPooling:** reduce el tamaño de la información manteniendo las características más importantes.
- **Capas densas:** utilizan las características encontradas para realizar finalmente la clasificación.

Para esta parte del taller se utilizó el dataset **TrashNet**, compuesto por imágenes de diferentes tipos de residuos.

En el ejercicio se trabajó específicamente con imágenes correspondientes a:

> **Glass (vidrio)**  
> **Plastic (plástico)**

Las imágenes fueron transformadas a escala de grises para utilizarlas como entrada del modelo.

<p align="center">
  <img src="/Imagenes/TallerRedesNeuronales/Screenshot 2026-09-22 153117.png" width="900"/>
</p>

### Construcción de la CNN

Se creó una CNN desde cero utilizando PyTorch.

El modelo está formado por varias capas convolucionales:

```python
self.features = nn.Sequential(
    nn.Conv2d(1, 16, kernel_size=3, padding=1),
    nn.ReLU(),
    nn.MaxPool2d(2),

    nn.Conv2d(16, 32, kernel_size=3, padding=1),
    nn.ReLU(),
    nn.MaxPool2d(2),

    nn.Conv2d(32, 64, kernel_size=3, padding=1),
    nn.ReLU(),
    nn.AdaptiveAvgPool2d((1, 1))
)
```

A medida que la imagen pasa por las diferentes capas, el modelo va aprendiendo características cada vez más específicas.

Las primeras capas pueden detectar características simples, mientras que las capas posteriores combinan esta información para distinguir entre vidrio y plástico.

### Entrenamiento del modelo

La CNN fue entrenada durante varias épocas utilizando los datos de entrenamiento.
<p align="center">
  <img src="/Imagenes/TallerRedesNeuronales/Screenshot 2026-09-22 154243.png" width="900"/>
</p>
En la gráfica se observa que la pérdida disminuye progresivamente. Esto indica que el modelo está aprendiendo durante el entrenamiento.
<p align="center">
  <img src="/Imagenes/TallerRedesNeuronales/Screenshot 2026-09-22 154420.png" width="900"/>
</p>
Durante las primeras épocas la exactitud se mantiene baja, pero posteriormente comienza a mejorar hasta alcanzar aproximadamente un 63.27 % de accuracy en validación.

El ROC-AUC se mantiene aproximadamente entre 0.67 y 0.69, por lo que el modelo logra diferenciar las clases, aunque todavía presenta dificultades.

### Data Augmentation

Posteriormente se utilizó Data Augmentation, realizando pequeñas modificaciones en las imágenes durante el entrenamiento, como rotaciones y desplazamientos.

El objetivo es evitar que el modelo memorice únicamente las imágenes originales y mejorar su capacidad para reconocer nuevos ejemplos.

Los resultados obtenidos fueron:

| Modelo | Accuracy | ROC-AUC |
|---|---:|---:|
| CNN sin augmentation | 55.03 % | 0.6191 |
| CNN con augmentation | 56.38 % | 0.6411 |

Se observa una pequeña mejora al utilizar aumento de datos.

### Transfer Learning

También se aplicó Transfer Learning utilizando una red ResNet18 previamente entrenada.

En este caso no se comienza completamente desde cero, sino que se aprovechan características que la red ya había aprendido anteriormente sobre otras imágenes.

Después del entrenamiento y Fine-Tuning se obtuvo:

> **Accuracy: 86.58 %**  
> **ROC-AUC: 0.9562**

El resultado es considerablemente superior al obtenido con la CNN creada desde cero, mostrando la utilidad del Transfer Learning cuando se dispone de una cantidad limitada de imágenes.


### Interpretabilidad mediante Grad-CAM

Finalmente se utilizó Grad-CAM para visualizar qué regiones de una imagen fueron más importantes para que la red realizara una predicción.
<p align="center">
  <img src="/Imagenes/TallerRedesNeuronales/Screenshot 2026-09-22 154939.png" width="900"/>
</p>

Las regiones más claras o amarillas representan las zonas que tuvieron mayor influencia en la decisión del modelo.
Las regiones más oscuras representan zonas que tuvieron una menor participación en la predicción.
Esto permite tener una idea de qué partes de la imagen está utilizando la CNN para distinguir entre los diferentes residuos.


# 2. Clasificación binaria utilizando Keras

En la segunda parte se utilizó Keras, una librería que facilita la creación y entrenamiento de redes neuronales.

En este ejercicio se trabajó con el dataset IMDB, que contiene reseñas de películas. El objetivo fue clasificar cada reseña en una de dos categorías:
> **0 → Reseña negativa**  
> **1 → Reseña positiva**

## Preparación de los datos

Las palabras de las reseñas se encuentran inicialmente representadas mediante números. Posteriormente se realizó una transformación de los datos mediante una representación tipo One-Hot Encoding**, generando vectores de 10 000 posiciones.De esta manera, la red neuronal puede trabajar con la información de las reseñas en forma numérica.

## Construcción del modelo

La red fue construida utilizando `Sequential` de Keras. El modelo posee dos capas ocultas de **16 neuronas** y una capa final con una sola neurona. La función `ReLU` se utiliza en las capas internas, mientras que `sigmoid` se utiliza en la salida porque el problema tiene únicamente dos posibles resultados. La salida de `sigmoid` puede interpretarse como una probabilidad entre 0 y 1.

## Entrenamiento y sobreajuste

El modelo fue entrenado durante 20 épocas.

<img width="876" height="840" alt="image" src="https://github.com/user-attachments/assets/e00a6448-70b8-4e03-ba5b-15a443507cda" />

En la gráfica se observa que el error de entrenamiento disminuye a medida que avanzan las épocas. Sin embargo, aproximadamente desde la época 4 o 5, el error de validación comienza a aumentar. Este comportamiento indica un caso de **sobreajuste**, ya que el modelo continúa aprendiendo los datos de entrenamiento, pero comienza a perder capacidad para generalizar correctamente a otros datos.

## Comparación con una red más pequeña

También se creó un modelo más pequeño utilizando únicamente cuatro neuronas en la capa oculta.
<img width="855" height="787" alt="image" src="https://github.com/user-attachments/assets/1dd8d222-e8bb-4fca-bdfc-996427d2ad2e" />
El modelo pequeño mantiene durante más épocas un valor de pérdida de validación relativamente estable.
Esto permite observar que reducir la complejidad de una red puede ayudar a disminuir el sobreajuste.

## Regularización

Posteriormente se aplicó regularización **L2**. La regularización penaliza los pesos demasiado grandes y busca que el modelo aprenda una solución menos dependiente de los datos de entrenamiento. Esto puede producir inicialmente un error mayor, pero busca mejorar la capacidad de generalización.

## Dropout

También se utilizó **Dropout**. Durante el entrenamiento se desactiva aleatoriamente aproximadamente el 50 % de las neuronasde esa capa.bEsto obliga a la red a no depender siempre de las mismas neuronas y permite reducir el riesgo de sobreajuste.

## Predicción

Finalmente se realizaron predicciones utilizando:

```python
predictions = model.predict(x_test)
```

Por ejemplo, para uno de los elementos del conjunto de prueba se obtuvo:

```python
array([0.99375147])
```

Este valor equivale aproximadamente a una probabilidad de:

> **99.4 %**

Por lo tanto, el modelo interpreta esa reseña como **positiva** con una probabilidad elevada.


