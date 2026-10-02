# Actividad 01: Promediado del ADC y conversión a voltaje

## Procedimiento realizado

Se mejoró el código del ESP32 para tomar 20 lecturas del potenciómetro conectado al pin 34 y calcular su promedio, reduciendo las fluctuaciones de la medición. Luego, se convirtió el promedio del ADC a un voltaje aproximado mediante la fórmula `voltaje = promedio × 3.3 / 4095`. Ambos resultados se mostraron en el monitor serial a 115200 baudios.

## Interpretación de la captura

En el monitor serial se observa que el promedio del ADC aumenta desde 0 hasta 4095, mientras el voltaje calculado pasa de 0.00 a 3.30 V. Por ejemplo, un promedio de 1084.70 corresponde a 0.87 V y uno de 2515.90 corresponde a 2.03 V. Esta variación es consistente con el ajuste del potenciómetro. Las últimas lecturas permanecen en 4095 y 3.30 V, indicando que el ADC alcanzó su valor máximo.

El promediado ayuda a reducir las fluctuaciones entre lecturas. Los voltajes son aproximados, ya que se calculan mediante la fórmula utilizada en el programa.

## Código utilizado

```cpp
const int potPin = 34;       // Pata central del potenciómetro
const int numLecturas = 20;  // Lecturas para calcular el promedio

void setup() {
  Serial.begin(115200);
}

void loop() {
  long suma = 0;

  // Tomar 20 lecturas
  for (int i = 0; i < numLecturas; i++) {
    suma += analogRead(potPin);
    delay(10);
  }

  float promedio = suma / 20.0;
  float voltaje = promedio * 3.3 / 4095.0;  // Voltaje aproximado

  Serial.print("Promedio ADC: ");
  Serial.print(promedio, 1);
  Serial.print(" | Voltaje aproximado: ");
  Serial.print(voltaje, 2);
  Serial.println(" V");

  delay(500);
}
```
