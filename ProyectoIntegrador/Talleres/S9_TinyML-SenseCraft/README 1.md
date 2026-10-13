# Modelo de Distinción de Género con GPIO

## Descripción
En este taller se desarrolló un modelo de **distinción de género**, integrando sus resultados con el control de un LED mediante GPIO.
El objetivo fue demostrar cómo los datos procesados por un modelo pueden utilizarse para controlar dispositivos electrónicos mediante condiciones lógicas.

## Funcionamiento

1. **Procesamiento:** El modelo analiza los datos de entrada.
2. **Predicción:** Se obtiene un resultado numérico del modelo.
3. **Condición:** Se evalúa si el valor obtenido es mayor que 50.
4. **Activación GPIO:** Si se cumple la condición, el LED se enciende.
5. **Salida:** Si el valor es menor o igual a 50, el LED permanece apagado.


## Conclusión
El taller permitió comprender la integración de un modelo de distinción de género con el uso de **GPIO**, aplicando condiciones para activar una salida física según el resultado obtenido.

<div align="center">
  <img width="963" height="1280" alt="image" src="https://github.com/user-attachments/assets/dc689939-bbbc-44e6-88b5-0ebb6bc90865" />
</div>

<p align="center">
  <em>Modelo Detección de género (Female).</em>
</p>

<div align="center">
  <img width="963" height="1280" alt="image" src="https://github.com/user-attachments/assets/5169148d-a0d6-4288-a87f-2e06d3e16ca8" />
</div>

<p align="center">
  <em>Modelo Detección de género con valor > 50 (Male + LED PRENDIDO).</em>
</p>

