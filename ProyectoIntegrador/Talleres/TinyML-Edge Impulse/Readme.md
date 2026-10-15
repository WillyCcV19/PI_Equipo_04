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


