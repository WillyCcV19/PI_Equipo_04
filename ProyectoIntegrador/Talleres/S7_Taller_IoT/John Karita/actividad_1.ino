void setup() {
  Serial.begin(115200);
}

void loop() {
  int16_t counter = 0;
  float acc = 0;
  float temp = 0;
  while(counter != 500){
    counter = counter + 1;
    temp = (3.3 * analogRead(34)) / 4096;
    acc = acc + temp;
    delayMicroseconds(500);
  }
  acc = acc / 500;
  Serial.print("Voltaje promediado de potenciómetro: ");
  Serial.print(acc);
  Serial.println();
}
