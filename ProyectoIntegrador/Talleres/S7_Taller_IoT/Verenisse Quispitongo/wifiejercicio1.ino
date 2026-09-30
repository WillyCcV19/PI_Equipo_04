int potPin = 34;          // pin del potenciómetro
int valores[10];          // array para guardar 10 lecturas
int cantidad = 10;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int suma = 0;
  //10 lecturas
  for (int i = 0; i < cantidad; i++) {
    valores[i] = analogRead(potPin);
    suma = suma + valores[i];
    delay(50);  // pequeña pausa entre lecturas
  }

  float promedio = suma / 10.0;
  //promedio ADC a voltaje
  float voltaje = (promedio * 3.3) / 4095.0;
  // Mostrar resultados
  Serial.print("ADC promedio: ");
  Serial.print(promedio);
  Serial.print(" | Voltaje aproximado: ");
  Serial.print(voltaje, 2);
  Serial.println(" V");
  delay(500);
}