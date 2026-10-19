#include <OneWire.h>
#include <DallasTemperature.h>
#define SENSOR_PIN 9
OneWire oneWire(SENSOR_PIN);
DallasTemperature sensors(&oneWire);

uint8_t signal = A0;    // Señal de excitación
uint8_t ref = A1;       // Referencia
uint8_t cond = A2;      // Lectura de conductividad
uint8_t ph = A3;        // Lectura de PH
uint8_t turb = A4;      // Lectura de Turbidez
uint8_t relay = 7;      // Pin de desactivación de sensor de conductividad
float m_res = 150;      // Valor de resistencia para sensor de conductividad
uint8_t pulse = 13;     // Pin para pulso de excitación
uint16_t adc = 1023;    // Precisión del ADC

float v_ref;            // Voltaje de referencia
float v_pou;            // Voltaje de pulso
float v_out;            // Voltaje de salida de sensor de conductividad
float resistencia;      // Resistencia leída del sensor de conductividad
float turbidez;         // Voltaje del sensor de turbidez
float pothid;           // Voltaje del sensor de PH


float read_cond(){                         // Leer una muestra de conductividad
  v_ref = 5.0 *  analogRead(ref) / adc;     // Leer voltaje de referencia 
  v_pou = 5.0 *  analogRead(signal) / adc;  // Leer voltaje de pulso
  v_out = 5.0 *  analogRead(cond) / adc;    // Leer voltaje de salida
  return ((150.0 * (v_pou - v_ref)) / ((v_out - v_ref) / 6)) - 150.0;
}


float get_conductivity(){
  uint8_t counter = 0;
  float acc = 0;
  digitalWrite(relay, HIGH);
  delay(10);
  while(counter != 250){
    digitalWrite(pulse, HIGH);
    delay(1);
    acc = acc + read_cond();
    digitalWrite(pulse, LOW);
    delay(1);
    acc = acc + read_cond();
    counter ++;
  }
  digitalWrite(relay, LOW);
  return (acc / 500.0);
}

float get_turb(){
  float acc = 0;
  float temp = 0;
  uint8_t counter = 0;

  while(counter != 250){
    temp = float(5.0 * analogRead(turb) / adc);
    acc = acc + temp;
    delay(1);
    counter ++;
  }

  return acc / 250;
}

float get_ph(){
  float acc = 0;
  uint8_t counter = 0;

  while(counter != 250){
    acc = acc + (5.0*(analogRead(ph) - analogRead(ref)))/6.0;
    delay(1);
    counter ++;
  }

  return acc / 250;
}

float get_temperature(){
  sensors.requestTemperatures();
  float temperatura = sensors.getTempCByIndex(0);
  if(temperatura < -30){
    sensors.begin();
  }
  return temperatura;
}

void setup() {
  sensors.begin();
  pinMode(relay, OUTPUT);
  pinMode(pulse, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  resistencia = get_conductivity();
  delay(1000);
  Serial.println();
  Serial.print("Resistencia: ");
  Serial.print(resistencia);
  Serial.println();
  Serial.print("Temperatura: ");
  Serial.print(get_temperature());
  Serial.println();
}
