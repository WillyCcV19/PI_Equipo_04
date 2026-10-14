# Modelo 2


# Tiny Machine Learning con SenseCraft y Detección de Objetos

## Descripción

En este taller se desarrolló un modelo de **Tiny Machine Learning (TinyML)** utilizando la plataforma SenseCraft en combinación con un sensor de visión artificial y hardware conectado mediante cables USB. El objetivo fue demostrar cómo un modelo de inteligencia artificial liviano puede entrenarse para reconocer diferentes objetos cotidianos en tiempo real y activar una respuesta lógica o física al superar un rango de confianza determinado.

## Funcionamiento

1. **Configuración de Hardware:** Se conecta el sensor a la computadora mediante cables y puerto USB para habilitar la transmisión de video y datos.
2. **Captura de Muestras:** Se toman múltiples muestras fotográficas de los objetos a clasificar (como pilas, celulares, calculadoras y lentes) para definir las categorías del modelo.
3. **Entrenamiento:** Se procesan las imágenes dentro de la plataforma SenseCraft utilizando el modelo correspondiente (porergic, Grove Vision AI V2).
4. **Evaluación e Inferencia:** Al colocar un objeto frente al sensor, la interfaz calcula la probabilidad en tiempo real.
5. **Activación de Salida:** Si el valor de inferencia supera el rango establecido (por ejemplo, mayor al 70%), el sistema activa una respuesta física —como encender un pequeño foquito— confirmando la detección exitosa.

## Descripción detallada de las imágenes

- **<img src="/Imagenes/Imagenes/TinyML/200.png" width="1000"/>** Se muestra la configuración inicial y el espacio de trabajo en la laptop utilizando la interfaz de SenseCraft. Aquí se aprecia el sensor conectado mediante el cable USB junto con los materiales preparados (como el teléfono celular y el entorno de pruebas) listos para iniciar con la digitalización y el reconocimiento.
- **<img src="/Imagenes/Imagenes/TinyML/201.png" width="1000"/>** Se observa la prueba de detección utilizando una calculadora. Al sostener la calculadora frente al sensor, la interfaz de SenseCraft procesa la imagen en tiempo real y genera los registros de inferencia correspondientes en el panel lateral de la pantalla.
- **<img src="/Imagenes/Imagenes/TinyML/202.png" width="1000"/>** Muestra el proceso de prueba con una pila cilíndrica. Sostenemos el módulo del sensor apuntando hacia el objeto situado en la mesa; en la laptop se visualiza cómo la cámara captura la pila y el modelo comienza a reconocer sus características visuales asociadas. Además, se configuró el GPIO para activar un LED cuando el nivel de detección superaba el 40 %. En la prueba se observa que, al alcanzar ese umbral, se encendió correctamente el LED amarillo como señal de detección.
- **<img src="/Imagenes/Imagenes/TinyML/203.png" width="1000"/>** Corresponde al panel general de entrenamiento dentro de la plataforma, enfocado en la categoría de "Lentes" con sus respectivas muestras de imágenes capturadas. Se visualiza el botón para iniciar el entrenamiento y la barra de confianza de resultados en la esquina inferior derecha (alcanzando un 97% de acierto), la cual activa una respuesta física como encender un foquito al superar el rango establecido del 70%.

## Conclusión

El taller permitió comprender la integración de modelos de TinyML con hardware de bajo consumo, aplicando condiciones lógicas y rangos de confianza para activar salidas físicas según el reconocimiento exitoso de objetos en tiempo real.
