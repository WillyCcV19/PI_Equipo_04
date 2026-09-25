# CNN y Transfer Learning: interpretación de resultados

### OCTMNIST · Informe con capturas de la ejecución

**Fuente exclusiva:** `CNN_TransferLearning_corregido (1).ipynb`, adjuntado desde Descargas. Las seis imágenes de este informe se extrajeron directamente de sus salidas guardadas. Las cifras proceden de esa misma ejecución; no se reutilizan capturas ni métricas del archivo anterior.

## Resultados principales

| Modelo | Accuracy de prueba | ROC-AUC de prueba |
|---|---:|---:|
| CNN sin aumento de datos | 69.30 % | 0.9499 |
| CNN con aumento de datos | 67.80 % | 0.9474 |
| ResNet18 con fine-tuning | **71.00 %** | **0.9527** |

ResNet18 obtuvo los mejores valores globales en esta ejecución. La diferencia de accuracy frente a la CNN base es de **1.70 puntos porcentuales**. El aumento de datos utilizado no mejoró los resultados de la CNN. Una sola ejecución no permite asegurar que estas diferencias se mantengan con otras semillas o configuraciones.

---

## 1. Imágenes de ejemplo del dataset

![Ejemplos de imágenes de retina de OCTMNIST](graficas_ejecucion_corregida/01_ejemplos.png)

*Figura 1. Primeras 12 imágenes del conjunto de entrenamiento y sus etiquetas reales.*

Esta figura me permite revisar el aspecto de los datos antes de entrenar. Las imágenes corresponden a tomografía de coherencia óptica de retina y muestran bandas con diferentes formas e intensidades. Los títulos identifican las categorías CNV, DME, drusas y normal.

Las imágenes originales tienen una resolución de **28 × 28 píxeles**, por lo que se aprecia una estructura general con pocos detalles. Esta limitación debe tenerse en cuenta al interpretar los resultados y los mapas de calor.

**Interpretación:** esta figura es una revisión visual de los datos, no una evaluación del modelo. Las etiquetas son las clases reales y no predicciones. La cantidad de ejemplos de cada clase en estas 12 muestras tampoco representa necesariamente la distribución del dataset completo.

---

## 2. Pérdida de entrenamiento de la CNN

![Pérdida de entrenamiento de la CNN durante ocho épocas](graficas_ejecucion_corregida/02_perdida.png)

*Figura 2. Pérdida de entropía cruzada de la CNN sin aumento de datos.*

El eje horizontal representa las épocas y el vertical la pérdida, promediada por imagen. La pérdida disminuye de **0.5991 a 0.3420**, una reducción aproximada del **42.9 %** respecto al valor inicial.

La mayor caída se produce al comienzo: entre las épocas 1 y 2 pasa de 0.5991 a 0.4586. Después continúa disminuyendo, pero con mejoras más pequeñas. Esto indica que el modelo se ajusta cada vez mejor a las imágenes de entrenamiento.

**Interpretación:** el entrenamiento reduce su función de error, pero eso no garantiza un mejor desempeño con imágenes nuevas. De hecho, la pérdida sigue bajando en la última época mientras las métricas de validación empeoran. Por eso es necesario leer esta figura junto con la siguiente.

---

## 3. Accuracy y ROC-AUC de validación

![Accuracy y ROC-AUC de validación de la CNN](graficas_ejecucion_corregida/03_metricas.png)

*Figura 3. Métricas de la CNN sin aumento de datos en el conjunto de validación.*

El **accuracy** mide la proporción de predicciones correctas. El **ROC-AUC macro multiclase** evalúa la separación de cada clase frente al resto y promedia los resultados dando el mismo peso a las cuatro clases. Son métricas distintas: un AUC alto no implica que la clase elegida sea correcta en igual proporción de imágenes.

| Momento del entrenamiento | Accuracy | ROC-AUC |
|---|---:|---:|
| Época 1 | 83.40 % | 0.9243 |
| Época 2 | 61.88 % | 0.8796 |
| Época 7: mejor validación observada | **88.58 %** | **0.9572** |
| Época 8: modelo final | 83.41 % | 0.9457 |

La caída de la segunda época afecta a ambas métricas. Posteriormente se recuperan y alcanzan sus máximos en la séptima época. En la octava, el accuracy pierde **5.17 puntos porcentuales**, aunque la pérdida de entrenamiento continúa bajando.

**Interpretación:** la última época no fue la mejor según la validación. La caída final es compatible con fluctuaciones del entrenamiento o un deterioro de la generalización; un solo descenso no basta para afirmar sobreajuste. Sería útil guardar el modelo de la mejor época según validación. El código actual evalúa el modelo al terminar la octava época, por lo que no conocemos aquí el resultado de prueba del modelo de la séptima.

Esta gráfica muestra el **valor del AUC por época**, no una curva ROC. Tampoco permite evaluar la calibración de las probabilidades.

---

## 4. Tasa de aprendizaje

![Learning rate de la CNN durante ocho épocas](graficas_ejecucion_corregida/04_learning_rate.png)

*Figura 4. Tasa de aprendizaje utilizada por el optimizador de la CNN base.*

| Épocas | Learning rate |
|---|---:|
| 1–4 | 0.001 |
| 5–8 | 0.0005 |

La tasa se reduce a la mitad a partir de la quinta época. Esto coincide con la configuración del scheduler: `StepLR(step_size=4, gamma=0.5)`, actualizado al finalizar cada época.

**Interpretación:** en la segunda mitad del entrenamiento el optimizador utiliza una tasa menor para ajustar los pesos. Aunque la validación mejora hasta la séptima época, esta gráfica no demuestra que el cambio de tasa sea la causa de esa mejora. La reducción está programada y no depende de las métricas observadas.

---

## 5. Matriz de confusión de la CNN

![Matriz de confusión de la CNN sobre las cuatro clases de OCTMNIST](graficas_ejecucion_corregida/05_matriz_confusion.png)

*Figura 5. Resultados de la CNN sin aumento de datos sobre 1000 imágenes de prueba.*

Las **filas indican la clase real** y las **columnas la predicción**. Los valores de la diagonal representan aciertos; los demás indican confusiones. En esta prueba hay 250 imágenes por clase.

| Clase real | Aciertos / total | Recall | Lectura |
|---|---:|---:|---|
| CNV | 211 / 250 | 84.40 % | La confusión más frecuente es con DME: 32 imágenes. |
| DME | 237 / 250 | 94.80 % | Es la clase con mayor proporción de aciertos. |
| Drusas | 16 / 250 | **6.40 %** | Es la principal debilidad del modelo. |
| Normal | 229 / 250 | 91.60 % | La mayor confusión es con DME: 18 imágenes. |

El total de aciertos es **693 de 1000**, coherente con el accuracy de **69.30 %**. De las 250 imágenes de drusas, el modelo clasifica 107 como normales, 76 como CNV y 51 como DME. Solo identifica correctamente 16.

El reporte asigna a drusas una precision de **1.0000**, pero esto no significa que reconozca bien esa clase: las 16 predicciones de drusas son correctas, aunque deja sin detectar las otras 234 muestras. Por eso su recall es de solo 6.40 % y su F1-score de 0.1203.

**Interpretación:** el rendimiento es desigual entre categorías. El AUC de prueba de **0.9499** no elimina el problema que muestra la matriz: con la decisión por clase de mayor probabilidad, la CNN casi nunca elige drusas. Es necesario revisar las métricas por clase además de las globales.

El accuracy de prueba también queda **14.11 puntos porcentuales** por debajo del de validación de la última época. Esta diferencia merece revisión, pero las figuras no permiten determinar por sí solas su causa.

---

## 6. Grad-CAM de ResNet18

![Imagen OCT normal, mapa Grad-CAM y superposición de ResNet18](graficas_ejecucion_corregida/06_grad_cam.png)

*Figura 6. Primera imagen de prueba: etiqueta real 3 y predicción 3, ambas correspondientes a la clase normal.*

| Panel | Qué muestra |
|---|---|
| Izquierda | Imagen de retina, después de deshacer la normalización para visualizarla. |
| Centro | Mapa Grad-CAM para la clase predicha. |
| Derecha | Mapa superpuesto sobre la imagen de entrada. |

En esta muestra, la predicción coincide con la etiqueta real: **normal**. La mayor intensidad del mapa se concentra en la zona superior central y derecha, cerca de las bandas claras que se observan en la imagen. La parte inferior presenta valores menores.

Los tonos rojos y amarillos representan contribuciones positivas más altas a la puntuación de la clase predicha, según Grad-CAM. Los tonos azules representan valores menores. La superposición permite relacionar estas contribuciones con la posición de las estructuras visibles.

**Interpretación:** el modelo acertó en este ejemplo y el mapa permite explorar las zonas que contribuyen a esa decisión. No demuestra que el modelo haya aprendido criterios clínicos correctos ni delimita una lesión. En particular, una zona roja en una imagen clasificada como normal no significa enfermedad.

El mapa está normalizado para esta imagen y sus colores no representan probabilidades. Además, se obtiene a baja resolución y se amplía para alinearlo con la entrada. Redimensionar las imágenes originales de 28 × 28 a 224 × 224 no recupera detalles que no estaban presentes. Para evaluar el comportamiento de forma más amplia habría que observar varias muestras correctas e incorrectas de cada clase.

---

## 7. Comparación final y conclusiones

Las curvas de las figuras 2–4 corresponden únicamente a la **CNN sin aumento de datos**. La siguiente interpretación de los otros modelos se apoya en los registros y reportes de texto guardados en el mismo notebook.

**Aumento de datos.** La CNN con las transformaciones utilizadas obtuvo 67.80 % de accuracy y 0.9474 de AUC, frente a 69.30 % y 0.9499 de la CNN base. En esta ejecución no hubo mejora; esto no demuestra que cualquier aumento de datos sea perjudicial.

**Fine-tuning.** En ResNet18, la validación pasa de 76.98 % de accuracy al final de la etapa que entrena el clasificador a 90.03 % al final del fine-tuning. El AUC pasa de 0.8796 a 0.9634. Esto muestra una mejora de validación al ajustar también la última sección del extractor. No se guardó una evaluación de prueba intermedia para comparar ambas etapas en test.

**Prueba de ResNet18.** El resultado final es 71.00 % de accuracy y 0.9527 de AUC. Aunque mejora a la CNN base en las métricas globales, el recall de drusas sigue siendo bajo: **20.80 %**, equivalente a 52 de 250 imágenes. Su F1 macro es 0.6699, frente a 0.6157 de la CNN base. La diferencia entre accuracy de validación final y prueba es de 19.03 puntos porcentuales.

**Conclusión del trabajo.** En esta ejecución, ResNet18 con fine-tuning consigue el mejor resultado global de los tres modelos. Sin embargo, el desempeño por clase revela una dificultad persistente con drusas. La prioridad para continuar sería seleccionar el modelo con validación, revisar sus errores por clase y repetir los experimentos antes de atribuir una ventaja general a una configuración.

---

### Cómo conservar las imágenes

El ZIP contiene este archivo Markdown y la carpeta `graficas_ejecucion_corregida` con las seis capturas originales. Extrae ambos en la misma ubicación para que se muestren las imágenes al abrir el documento en un visor Markdown.
