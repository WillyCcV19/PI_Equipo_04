# Clasificación de BreastMNIST con CNN y Transfer Learning

## 1. Dataset

Se utilizó **BreastMNIST**, compuesto por imágenes de ultrasonido mamario de 28 × 28 píxeles. El problema corresponde a una clasificación binaria entre la clase 0 y la clase 1.

El conjunto contiene 546 imágenes de entrenamiento, 78 de validación y 156 de prueba. Se identificó un desbalance en entrenamiento, con **147 muestras de clase 0 y 399 de clase 1**. Debido a ello, además del accuracy se consideró especialmente el ROC-AUC para evaluar el modelo.

## 2. CNN desde cero

Se utilizó una CNN con tres capas convolucionales de 16, 32 y 64 filtros. Inicialmente se probaron arquitecturas más complejas con 32-64-128 filtros, Batch Normalization y Dropout, pero se observaron mayores fluctuaciones en las métricas, por lo que se mantuvo una arquitectura más simple.

La CNN fue entrenada durante 8 épocas, utilizando Adam con un learning rate de 0.001. Debido al desbalance de clases, se aplicaron pesos en CrossEntropyLoss, dando mayor importancia a los errores de la clase minoritaria.

### Curvas de entrenamiento

<img width="1027" height="817" alt="image" src="https://github.com/user-attachments/assets/872fbcf4-af4a-48d1-8eab-f65113f1f2d5" />

La pérdida presentó una tendencia general descendente, indicando que el modelo fue aprendiendo durante las épocas. Sin embargo, el accuracy de validación mostró algunos picos.

Estas fluctuaciones no significan necesariamente overfitting. El conjunto de validación contiene solamente **78 imágenes**, por lo que cada imagen representa aproximadamente un **1.28 % del accuracy**. Un cambio de pocas predicciones puede generar variaciones visibles entre épocas.

También influyen el desbalance de clases y los componentes aleatorios del entrenamiento, como el orden de los datos y la formación de los mini-batches. Por ello, las curvas de una red neuronal no tienen que ser completamente lineales.

No se observa un deterioro sostenido de las métricas de validación mientras el entrenamiento continúa mejorando, por lo que **no se aprecia una señal clara de overfitting durante las épocas analizadas**. Sin embargo, para comprobarlo de manera más directa sería recomendable registrar también la pérdida de validación.

### Evaluación en Test

La CNN obtuvo:

- **Accuracy:** 0.6154
- **ROC-AUC:** 0.6713

La matriz de confusión mostró 27 aciertos para la clase 0 y 69 para la clase 1. Aunque el modelo consiguió predecir ambas clases, todavía presentó dificultades para diferenciarlas correctamente.
<img width="466" height="376" alt="image" src="https://github.com/user-attachments/assets/d47f2c52-8f87-4704-b6c7-abcb53beb73b" />

## 3. Data Augmentation

Se aplicaron pequeñas rotaciones de hasta 10° y traslaciones de hasta un 5 % únicamente sobre las imágenes de entrenamiento.

Durante este entrenamiento también aparecieron fluctuaciones. Esto se debe, en parte, a que las transformaciones son aleatorias y una misma imagen puede presentarse de forma ligeramente diferente entre épocas.

En test se obtuvo:

- **Sin augmentation:** Accuracy = 0.6154, ROC-AUC = 0.6713.
- **Con augmentation:** Accuracy = 0.5385, ROC-AUC = 0.6418.

Por lo tanto, en este experimento el aumento de datos utilizado **no mejoró el desempeño del modelo**. Esto no significa que Data Augmentation sea perjudicial, sino que las transformaciones seleccionadas no produjeron una mejora para esta configuración.

## 4. Transfer Learning con ResNet18

Se utilizó una **ResNet18 preentrenada**. Las imágenes de BreastMNIST fueron redimensionadas a 224 × 224 píxeles y replicadas a tres canales para adaptarlas a la entrada esperada por la red.

### Stage 1

Inicialmente se congeló la red y se entrenó únicamente la capa final. El accuracy permaneció en 0.7308, mientras que el ROC-AUC aumentó de 0.3893 a 0.6257.

El accuracy constante se relaciona con la tendencia inicial del modelo a favorecer la clase mayoritaria. Sin embargo, el aumento del ROC-AUC indica que las probabilidades generadas comenzaron progresivamente a separar mejor ambas clases.

### Stage 2: Fine-Tuning

Posteriormente se descongeló layer4 junto con la capa final y se utilizó un learning rate menor de 0.0001.

El fine-tuning produjo una mejora considerable. La pérdida disminuyó continuamente de 0.2344 a 0.1230 y el ROC-AUC alcanzó **0.9591** en validación.

El accuracy alcanzó 0.9231 y posteriormente disminuyó ligeramente a 0.9103. Esta variación corresponde aproximadamente a una sola imagen del conjunto de validación, por lo que no representa por sí misma una señal de overfitting.

## 5. Evaluación final

ResNet18 con fine-tuning obtuvo en test:

- **Accuracy:** 0.8846
- **ROC-AUC:** 0.9190

La comparación final fue:

| Modelo | Accuracy | ROC-AUC |
|---|---:|---:|
| CNN desde cero | 0.6154 | 0.6713 |
| CNN + Data Augmentation | 0.5385 | 0.6418 |
| ResNet18 + Fine-Tuning | **0.8846** | **0.9190** |

ResNet18 con fine-tuning presentó el mejor desempeño de las estrategias evaluadas, mostrando la utilidad de aprovechar características previamente aprendidas cuando se trabaja con un conjunto de imágenes reducido.

## 6. Grad-CAM

<img width="1211" height="420" alt="image" src="https://github.com/user-attachments/assets/5f5467e7-699b-46bd-91e2-22729e6e52b2" />

Finalmente, se utilizó **Grad-CAM** sobre ResNet18 para visualizar las regiones de las imágenes que tuvieron mayor influencia sobre las predicciones.

Esta técnica complementa las métricas obtenidas al proporcionar una interpretación visual del comportamiento del modelo. El mapa generado no demuestra por sí solo que la red haya identificado una estructura clínica específica, pero permite observar las zonas que tuvieron mayor influencia en su decisión.

## Conclusión

Los experimentos muestran que los **picos observados en las curvas no implican automáticamente overfitting**, ya que pueden estar relacionados con el pequeño conjunto de validación, el desbalance de clases y la aleatoriedad propia del entrenamiento.

La CNN desde cero obtuvo un desempeño moderado y Data Augmentation no produjo mejoras con las transformaciones utilizadas. En cambio, **Transfer Learning con ResNet18 y fine-tuning obtuvo los mejores resultados**, alcanzando un accuracy de 0.8846 y un ROC-AUC de 0.9190 en test.

Durante las épocas analizadas no se observa un deterioro sostenido de las métricas de validación que indique claramente sobreajuste, aunque incorporar la pérdida de validación permitiría realizar un análisis más directo en futuros experimentos.
