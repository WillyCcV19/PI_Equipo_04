void setup() {
  Serial.begin(115200);  // Iniciar comunicación serial a 115200 baudios
}

void loop() {
  int16_t counter = 0;    // Contador
  float acc = 0;          // Acumulador = 0
  float temp = 0;         // Temporal = 0
  while(counter != 500){  // Repetir 500 veces
    counter = counter + 1;                  // Incrementar contador
    temp = (3.3 * analogRead(34)) / 4096;   // Leer voltaje
    acc = acc + temp;                       // Sumar voltaje al acumulador
    delayMicroseconds(500);
  }
  acc = acc / 500;                                        // Promediar voltaje
  Serial.print("Voltaje promediado de potenciómetro: ");  // Imprimir resultados
  Serial.print(acc);
  Serial.println();
}
