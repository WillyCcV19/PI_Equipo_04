# TinyML con XIAO ESP32S3 Sense y Edge Impulse

## 1. Preparación de la cámara

### Descripción

En esta primera etapa del laboratorio realizamos la configuración de la cámara del **XIAO ESP32S3 Sense** utilizando Arduino IDE. El objetivo fue habilitar la captura y visualización de imágenes en tiempo real para posteriormente recopilar datos y entrenar un modelo de clasificación de imágenes mediante Edge Impulse.

### 1.1 Evidencia de la práctica

Durante el laboratorio realizamos pruebas de captura y visualización de imágenes utilizando la cámara conectada al XIAO ESP32S3 Sense.

<div align="center">
  
<img width="400" height="500" alt="image" src="https://github.com/user-attachments/assets/f4b34197-ca5d-459c-8ab9-0529a7f89775" />

*Figura 1. Prueba de funcionamiento de la cámara durante el laboratorio.*

</div>

## 2. Creación del proyecto en Edge Impulse

### 2.1 Creación del proyecto

Ingresamos a la plataforma **Edge Impulse Studio** y creamos un nuevo proyecto llamado **Taller**.

Este proyecto nos permitirá organizar las imágenes capturadas con la cámara XIAO ESP32S3 Sense y utilizarlas posteriormente para entrenar un modelo de clasificación mediante TinyML.

### 2.2 Resultado

Se creó correctamente el proyecto **Taller**, obteniendo acceso al panel principal de Edge Impulse, desde donde podremos cargar nuestro conjunto de imágenes (*dataset*), diseñar el modelo y realizar su entrenamiento.

**Evidencia:** 

<div align="center">
<img width="800" height="500" alt="image" src="https://github.com/user-attachments/assets/7c9bffcf-fa20-4e8c-9ffc-69306f558431" />
  
*Figura 2. Creación de proyecto.*
</div>

## 3. Adquisición de datos (Dataset)

### 3.1 Recopilación y carga de imágenes

En esta etapa recopilamos imágenes utilizando la cámara del **XIAO ESP32S3 Sense** y las incorporamos al proyecto de Edge Impulse. Las imágenes fueron organizadas y etiquetadas según los objetos que se buscaba reconocer, permitiendo construir un conjunto de datos para el entrenamiento del modelo de clasificación.

### 3.2 Distribución del dataset

Se registraron 150 imágenes, distribuidas de la siguiente manera:

| Conjunto | Porcentaje | Imágenes |
|---|---|---|
| Entrenamiento | 80 % | 120 |
| Prueba | 20 % | 30 |
| **Total** | **100 %** | **150** |

Esta distribución permite utilizar una parte de las imágenes para entrenar el modelo y otra para evaluar su capacidad de clasificación con datos separados del entrenamiento.

### 3.3 Organización de las imágenes

En la sección **Data Acquisition** se visualizaron las imágenes recopiladas junto con sus respectivas etiquetas. En la captura se observan muestras de la categoría Cepillo y una imagen seleccionada denominada Mouse_044.

### 3.4 Resultado

<div align="center">
<img width="800" height="500" alt="image" src="https://github.com/user-attachments/assets/cd84ef24-6bcb-4d30-8141-927d65d8e7d0" />
  
*Figura 3. Adquisición de datos.*
</div>

## 4. Diseño del modelo (Create Impulse)

En esta etapa configuramos el modelo de clasificación de imágenes utilizando **Edge Impulse**. Se estableció una resolución de 96 × 96 píxeles y se seleccionó Transfer Learning para entrenar el modelo con tres categorías: Celular, Cepillo y Mouse. Esta configuración permite preparar las imágenes para el entrenamiento y posterior reconocimiento de objetos.

<div align="center">
<img width="1600" height="848" alt="image" src="https://github.com/user-attachments/assets/a9df1f09-94a1-4cbe-b88a-4d33ff4a0da7" />
  
*Figura 4.*
</div>

## 5. Entrenamiento y evaluación del modelo

En esta etapa entrenamos el modelo de clasificación de imágenes utilizando Transfer Learning con la arquitectura MobileNetV2 en Edge Impulse. Se configuraron 30 ciclos de entrenamiento, una tasa de aprendizaje de 0.0005 y el procesamiento mediante CPU.

### Resultados del entrenamiento

El modelo obtuvo una precisión de validación del 75 % y una pérdida (*loss*) de 0.51.
La matriz de confusión mostró los siguientes resultados:

- **Celular:** 100 % de clasificación correcta.
- **Cepillo:** 54.5 % de clasificación correcta.
- **Mouse:** 83.3 % de clasificación correcta.

Además, se visualizaron las muestras clasificadas mediante **Data Explorer**, permitiendo identificar los aciertos y errores del modelo.

### Evidencias

<div align="center">
<img width="1600" height="848" alt="image" src="https://github.com/user-attachments/assets/d1996ca7-f6ee-4348-978a-d74571a342c6" />
  
*Figura 5.Configuración y entrenamiento del modelo*
</div>

<div align="center">
<img width="751" height="776" alt="image" src="https://github.com/user-attachments/assets/2c0ee8b6-469e-4d08-9020-f9dc1da273c0" />
  
*Figura 6.Resultados y matriz de confusión*
</div>

<div align="center">
<img width="767" height="656" alt="image" src="https://github.com/user-attachments/assets/6eb7dfe9-4c4e-4be5-966b-a28206c3dc36" />
  
*Figura 7.Visualización de datos y rendimiento*
</div>

## 6. Prueba del modelo (Model Testing)

En esta etapa evaluamos el modelo entrenado utilizando las 30 imágenes reservadas para pruebas en Edge Impulse. Se utilizó la herramienta Model Testing para comprobar la capacidad del modelo de reconocer las tres categorías: **Celular, Cepillo y Mouse**.

### Resultados

- **Precisión general:** 96.67 %.
- **Celular:** 100 % de clasificación correcta.
- **Cepillo:** 90 % de clasificación correcta y 10 % de resultados inciertos.
- **Mouse:** 100 % de clasificación correcta.

Los resultados muestran un buen desempeño del modelo con las imágenes de prueba, aunque todavía presenta cierta incertidumbre al reconocer cepillos.

### Evidencia

<div align="center">
<img width="1600" height="848" alt="image" src="https://github.com/user-attachments/assets/7d69c7f1-6bdf-490f-b95e-bbe5cde68ab8" />
  
*Figura 8.Prueba del modelo en Edge Impulse*
</div>

Además, se utilizó la matriz de confusión para identificar los aciertos y el Feature Explorer para visualizar cómo el modelo diferencia las imágenes de cada categoría.

Estos resultados indican que el modelo logró un buen desempeño con las imágenes de prueba, aunque todavía presenta cierta incertidumbre al reconocer cepillos.

<div align="center">
<img width="1600" height="716" alt="image" src="https://github.com/user-attachments/assets/b9c0be0a-6ab9-4407-8f27-85cf1f8ce6c1" />
  
*Figura 9.*
</div>

<div align="center">
<img width="756" height="658" alt="image" src="https://github.com/user-attachments/assets/d1f587c1-d358-4708-b677-4e18ad07c677" />
  
*Figura 10.*
</div>

### 7. Implementación del modelo en ESP32

Se intentó implementar el modelo de reconocimiento de objetos entrenado en Edge Impulse utilizando Arduino IDE y la placa XIAO ESP32S3. Durante la ejecución se presentó un error de memoria (`LoadProhibited`), lo que provocó el reinicio del dispositivo e impidió completar las pruebas de reconocimiento en tiempo real.

<div align="center">
<img width="1600" height="856" alt="image" src="https://github.com/user-attachments/assets/a2ccf943-811b-4fc5-8f30-b5ac28fed21b" />
  
*Figura 11. Error de ejecución durante la implementación del modelo en ESP32.*

</div>

## Paso 8: Pruebas de reconocimiento de objetos

Se realizaron intentos de reconocimiento utilizando los tres objetos definidos durante el entrenamiento: **celular, cepillo y mouse**.

El objetivo era comprobar si la cámara podía capturar las imágenes y si el modelo podía identificar correctamente cada objeto.

Sin embargo, debido a los problemas encontrados durante la ejecución en el ESP32, no se logró confirmar el funcionamiento completo del reconocimiento en tiempo real.

### Evidencias de las pruebas

**Prueba 1: Reconocimiento de celular**

<div align="center">
<img width="460" height="600" alt="image" src="https://github.com/user-attachments/assets/4d4ce3d9-73cb-4ccc-af94-d44abc60624b" />
  
*Figura 12. Prueba con celular.*

</div>


**Prueba 2: Reconocimiento de cepillo**

<div align="center">
<img width="460" height="600" alt="image" src="https://github.com/user-attachments/assets/8e52c7f1-1d48-44f5-b4e5-51a162877ab3" />
  
*Figura 13. Prueba con cepillo.*

</div>

**Prueba 3: Reconocimiento de mouse**

<div align="center">
<img width="460" height="600" alt="image" src="https://github.com/user-attachments/assets/471899c7-8d10-4108-a464-4d778c7dc6ba" />

  
*Figura 14. Prueba con mouse.*

</div>

## Conclusión

El modelo desarrollado en Edge Impulse obtuvo una exactitud del **96.67 % en las pruebas realizadas en la plataforma**. No obstante, durante la implementación en el ESP32 se presentaron errores que impidieron validar completamente su funcionamiento en tiempo real.

Como mejora futura, se propone revisar el código, la configuración de la cámara y la memoria disponible para completar la implementación.

## 9. Despliegue y Pruebas en Tiempo Real (SenseCraft AI)
---
### Descripción
---
Una vez finalizadas las fases de entrenamiento y optimización en Edge Impulse, exportamos el modelo entrenado en formato comprimido para inferencia mediante **TensorFlow Lite con cuantización int8 (`TensorFlow Lite int8 quantized`)**. Este modelo ligero (`.lite`) fue cargado e implementado dentro de la plataforma web **SenseCraft AI** para interactuar directamente con la cámara del **XIAO ESP32S3 Sense** y validar las predicciones gráficas en un entorno real.

Durante el despliegue se configuraron las tres clases proyectadas (`0: Celular`, `1: Mouse`, `2: Cepillo`) y se ajustaron los parámetros operacionales del entorno: un umbral de **confianza del 50 %** y un **umbral IoU (Intersection over Union) del 60 %**, para garantizar que los objetos solo sean reconocidos cuando la confianza de la predicción supere el estándar establecido por el sistema.

### 9.1 Pruebas de Clasificación e Inferencias Obtenidas
---
#### A. Inferencia de la clase Mouse

En la primera prueba enfocamos el sensor directamente sobre el dispositivo ratón. El modelo TinyML respondió de forma inmediata al patrón geométrico y de color del objeto.

<div align="center">
<img width="500" height="600" alt="image" src="https://github.com/user-attachments/assets/91da04ea-7bf1-44b5-9cf7-42f0158482eb" />

*Figura 11. Inferencia en tiempo real del objeto Mouse.*
</div>

**Resultado:** Clasificación exitosa con un **86 % de confianza** asignado a la categoría **Mouse** y un 0 % de probabilidad asignada a las demás clases.
**Fundamentación técnica:** La forma ovalada, el contraste de su tonalidad blanca respecto a la superficie de la mesa de madera y los bordes continuos facilitaron que el bloque de extracción de características (*Transfer Learning / MobileNetV2*)  identificara el objeto sin ambigüedades, superando ampliamente el umbral mínimo del 50 %.

#### B. Inferencia de la clase Celular

Posteriormente, se posicionó el teléfono móvil frente al lente del XIAO ESP32S3 para verificar la capacidad del algoritmo frente a las condiciones de reflexión de la luz.

<div align="center">
<img width="500" height="600" alt="image" src="https://github.com/user-attachments/assets/a368c4cb-e50e-4253-a952-98773af37a87" />

*Figura 12. Inferencia en tiempo real del objeto Celular.*
</div>

**Resultado:** El sistema logró clasificar correctamente el objeto, alcanzando un **88 % de confianza** para la categoría **Celular**, mientras que las demás clases obtuvieron un 0 %.
 **Fundamentación técnica:** A pesar de los destellos generados por la luz ambiental sobre la pantalla del teléfono, la disposición visual del módulo de cámaras posterior y la geometría rectangular con esquinas redondeadas proporcionaron características visuales distintivas para la red neuronal, permitiendo una clasificación firme y precisa.

#### C. Disposición del Entorno de Laboratorio y Análisis de la clase Cepillo (Peine)

Para evaluar el comportamiento del sistema en un entorno completo, se colocaron sobre la mesa de trabajo los componentes de desarrollo junto a los tres objetos físicos seleccionados para el laboratorio.


<div align="center">
<img width="800" height="500" alt="image" src="https://github.com/user-attachments/assets/5b28f2c3-0e86-46c3-83f0-264eae1c220c" />

*Figura 13. Montaje del entorno de prueba con el XIAO ESP32S3 Sense, laptop y los objetos de prueba.*
</div>

#### Sustento y Justificación Técnica de la Falla en la Detección del Cepillo

Durante la prueba física con el **cepillo/peine azul**, observamos que el módulo XIAO ESP32S3 no lograba clasificarlo correctamente o lo asociaba de manera errónea con la categoría *Celular*. Las principales causas que podrían explicar este comportamiento técnico son las siguientes:

1. **Similitud cromática entre el objeto y el teléfono celular:** El mango del cepillo tiene un tono azul muy parecido al color de la carcasa trasera del teléfono celular utilizado. Al reducir las imágenes a una resolución de \(96 \times 96\) píxeles para el procesamiento TinyML, la red puede perder detalles finos de textura, como las cerdas blancas, y dar mayor importancia a las regiones de color azul, confundiendo ambas clases.

2. **Deficiencia de muestreo en el dataset:** Según las métricas obtenidas durante la fase de entrenamiento, la clase Cepillo alcanzó solamente un **54.5 % de precisión de validación**. Este resultado sugiere que podrían faltar muestras con mayor variación de ángulos, perspectivas laterales y condiciones de iluminación para mejorar la capacidad de reconocimiento del modelo.

3. **Pérdida de información espacial por compresión:** La cuantización a **int8** permite reducir el tamaño del modelo y su consumo de memoria, facilitando su implementación en dispositivos con recursos limitados. Sin embargo, la cuantización por sí sola no implica necesariamente una pérdida de resolución espacial. La dificultad para reconocer las cerdas pequeñas del peine puede estar relacionada principalmente con la resolución de entrada, la calidad de las imágenes y las características aprendidas durante el entrenamiento.

**Conclusión operacional:** Aunque el cepillo no alcanzó el umbral del 50 % necesario para ser validado, el experimento permite identificar tanto los aciertos como las limitaciones del sistema. **Dos de los tres objetos evaluados (Mouse y Celular) obtuvieron porcentajes de confianza superiores al 85 %**, lo que demuestra un resultado favorable en estas dos clases y evidencia la viabilidad de la tecnología TinyML en el microcontrolador XIAO ESP32S3 Sense. No obstante, será necesario ampliar y diversificar las muestras de la clase Cepillo para mejorar su reconocimiento y conseguir un desempeño más uniforme en las tres categorías.

