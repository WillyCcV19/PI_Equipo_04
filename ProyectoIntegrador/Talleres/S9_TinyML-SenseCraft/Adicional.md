# Modelo 1 (adicional) - Detección de gestos

## Descripción
Se entrenó un modelo de detección de gestos para distinguir tres diferentes: Piedra, Papel y Tijera. No se controló un LED mediante GPIO
El objetivo principal es demostrar el funcionamiento del modelo y ver qué inconvenientes puede presentar.

## Funcionamiento

1. **Procesamiento:** El modelo analiza los datos de entrada
2. **Predicción:** Se obtiene un resultado numérico del modelo
3. **Condición:** No se colocó ningún umbral
4. **Activación GPIO:** No se configuró GPIO
5. **Salida:** Clasificación del modelo

<div align="center">
  <img width="800" alt="image" src="/Imagenes/TinyML-Hand/img7.jpeg" />
</div>

<p align="center">
  <em>Datos de entrenamiento</em>
</p>

<table>
  <tr>
    <td align="center">
      <img src="/Imagenes/TinyML-Hand/img1.jpeg" width="100%">
      <br>
      <em>Papel</em>
    </td>
    <td align="center">
      <img src="/Imagenes/TinyML-Hand/img2.jpeg" width="100%">
      <br>
      <em>Tijera</em>
    </td>
  </tr>
</table>

<table>
  <tr>
    <td align="center">
      <img src="/Imagenes/TinyML-Hand/img3.jpeg" width="100%">
      <br>
      <em>Piedra</em>
    </td>
    <td align="center">
      <img src="/Imagenes/TinyML-Hand/img4.jpeg" width="100%">
      <br>
      <em>Papel</em>
    </td>
  </tr>
</table>

<table>
  <tr>
    <td align="center">
      <img src="/Imagenes/TinyML-Hand/img7.jpeg" width="100%">
      <br>
      <em> - </em>
    </td>
    <td align="center">
      <img src="/Imagenes/TinyML-Hand/img8.jpeg" width="100%">
      <br>
      <em> - </em>
    </td>
  </tr>
</table>


# Modelo 2 (adicional) - Clasificación de objetos

## Descripción
Se entrenó un modelo de clasificación para distinguir tres objetos: Osciloscopio, Multímetro y Calculadora. No se colocó un control de LED mediante GPIO
El objetivo principal es demostrar el funcionamiento del modelo y ver qué inconvenientes puede presentar.
- Archivos de entrenamiento en la carpeta "Recursos"

## Funcionamiento

1. **Procesamiento:** El modelo analiza los datos de entrada
2. **Predicción:** Se obtiene un resultado numérico del modelo
3. **Condición:** No se colocó ningún umbral
4. **Activación GPIO:** No se configuró GPIO
5. **Salida:** Clasificación del modelo

<div align="center">
  <img width="800" alt="image" src="/Imagenes/TinyML-MOC/img7.png" />
</div>

<p align="center">
  <em>Datos de entrenamiento</em>
</p>

<table>
  <tr>
    <td align="center">
      <img src="/Imagenes/TinyML-MOC/img3.jpeg" width="100%">
      <br>
      <em>Clasificación multímetro 84%</em>
    </td>
    <td align="center">
      <img src="/Imagenes/TinyML-MOC/img2.jpeg" width="100%">
      <br>
      <em>Clasificación multímetro 61%, calculadora 38%</em>
    </td>
  </tr>
</table>

<table>
  <tr>
    <td align="center">
      <img src="/Imagenes/TinyML-MOC/img4.jpeg" width="100%">
      <br>
      <em>Clasificación calculadora 64%</em>
    </td>
    <td align="center">
      <img src="/Imagenes/TinyML-MOC/img1.jpeg" width="100%">
      <br>
      <em>Clasificación calculadora 61%, multímetro 38%</em>
    </td>
  </tr>
</table>

<table>
  <tr>
    <td align="center">
      <img src="/Imagenes/TinyML-MOC/img6.jpeg" width="100%">
      <br>
      <em>Clasificación osciloscopio 54%, calculadora 39%</em>
    </td>
    <td align="center">
      <img src="/Imagenes/TinyML-MOC/img5.jpeg" width="100%">
      <br>
      <em>Clasificación osciloscopio 47% multímetro 36%</em>
    </td>
  </tr>
</table>

## Conclusión
- El alto error se debe a pocos datos de entrenamiento
- Las imágenes, desde la perspectiva del modelo, son similares. Por ejemplo: La parte trasera del multímetro y calculadora. Puede que el modelo esté confundiendo eso
