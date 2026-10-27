byte datos[5];
byte contador = 0;

void setup() {
  Serial.begin(115200);  // Monitor serie USB

  // UART2: RX = GPIO 16, TX = GPIO 17
  Serial2.begin(9600, SERIAL_8N1, 16, 17);

  Serial.println("Esperando datos del Nano...");
}

void loop() {
  while (Serial2.available() > 0) {
    datos[contador] = Serial2.read();
    contador++;

    if (contador == 5) {
      Serial.print("Datos recibidos: ");

      for (int i = 0; i < 5; i++) {
        Serial.print(datos[i]);
        Serial.print(" ");
      }

      Serial.println();
      contador = 0;
    }
  }
}
