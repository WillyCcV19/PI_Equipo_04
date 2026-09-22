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
