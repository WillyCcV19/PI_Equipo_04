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
