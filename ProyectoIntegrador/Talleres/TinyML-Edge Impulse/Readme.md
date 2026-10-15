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


