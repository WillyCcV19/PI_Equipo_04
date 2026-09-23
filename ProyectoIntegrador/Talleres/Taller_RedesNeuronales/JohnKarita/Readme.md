## Lo aprendido:

### CNN [Convolutional Neural Network]
- Trabaja principalmente con imágenes y estas pueden aumentarse mediante transformaciones (data augmentation), salvo que dichas modificaciones puedan alterar información importante.
- Menor tiempo de ejecución cuando se utiliza GPU.
- Extrae características de las imágenes para identificar regiones relevantes, que pueden visualizarse posteriormente.

  
<img src="/Imagenes/TallerRedesNeuronales/s6i2.png" width="1000"/>
<img src="/Imagenes/TallerRedesNeuronales/s6i3.png" width="1000"/>
<img src="/Imagenes/TallerRedesNeuronales/s6i4.png" width="1000"/>
- Se puede observar de las imágenes que las áreas de los cuellos de las botellas/frascos tienen bastante influencia para la clasificación
  
### Keras
- Permite construir redes neuronales por capas de manera sencilla.
- Permite utilizar funciones de activación como tangente hiperbólica, ReLU y sigmoide.
- Puede reducir el sobreajuste mediante dropout, desactivando aleatoriamente algunas neuronas durante el entrenamiento.
  
### Perceptrón
- Realiza el producto punto entre las entradas y los pesos, y suma un sesgo (bias).
- Puede realizar operaciones como AND y OR, pero no XOR con un solo perceptrón.
- Utiliza una función de activación.


<img src="/Imagenes/TallerRedesNeuronales/s6i1.png" width="386"/>
- Para que realice la discriminación tipo XOR requiere ambos perceptrones y definir una región entre ellos dos, como se detalla arriba.

## ¿Cuál utilizaría para el proyecto?
- Utilizaría perceptrones para obtener los parámetros (Tiempo, PH, DO, Temperatura, Turbidez y conductividad) y simplemente una salida que decida advertir o no, sería un punto inicial.
- Para características más refinadas o con variables más difíciles de pesar utilizaría Keras para construir una red más compleja. Solo tendría que recopilar un buen dataset y evitar el sobreajuste.
