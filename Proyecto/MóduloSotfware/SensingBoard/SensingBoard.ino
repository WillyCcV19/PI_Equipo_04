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
float temperatura;      // Temperatura


float read_cond(){                          // Leer una muestra de conductividad
  v_ref = 5.0 *  analogRead(ref) / adc;     // Leer voltaje de referencia 
  v_pou = 5.0 *  analogRead(signal) / adc;  // Leer voltaje de pulso
  v_out = 5.0 *  analogRead(cond) / adc;    // Leer voltaje de salida
  return ((150.0 * (v_pou - v_ref)) / ((v_out - v_ref) / 6)) - 150.0;    // Retornar el valor de la resistencia
}


float get_conductivity(){
  uint8_t counter = 0;
  float acc = 0;
  digitalWrite(relay, HIGH);      // Activar el relé
  delay(10);                      // Esperar a que los contactos peguen
  while(counter != 250){          // Repetir 250 veces (cada iteración dura ~ 2 milisegundos)
    digitalWrite(pulse, HIGH);    // Pulso de excitación
    delay(1);                     // Delay de pulso
    acc = acc + read_cond();      // Leer conductividad
    digitalWrite(pulse, LOW);
    delay(1);
    acc = acc + read_cond();
    counter ++;                   // Incrementar contador
  }
  digitalWrite(relay, LOW);       // Desactivar el relé
  return (acc / 500.0);           // Retornar valor promediado de conductividad
}

float get_turb(){
  float acc = 0;
  float temp = 0;
  uint8_t counter = 0;

  while(counter != 250){          // Repetir 250 veces (cada iteración dura ~ 1 milisegundo)
    temp = float(5.0 * analogRead(turb) / adc);  // Leer sensor de turbidez
    acc = acc + temp;             // Acumular valor de voltaje
    delay(1);                     // Delay de lectura
    counter ++;
  }

  return acc / 250;               // Retornar voltaje promediado del sensor de turbidez
}

float get_ph(){
  float acc = 0;
  uint8_t counter = 0;

  while(counter != 250){          // Repetir 250 veces (cada iteración dura ~ 1 milisegundo)
    acc = acc + (5.0*(analogRead(ph) - analogRead(ref)))/6.0;  // Leer sensor de ph
    delay(1);                     // Delay de lectura
    counter ++;
  }

  return acc / 250;               // Retornar voltaje promediado del sensor de ph
}

float get_temperature(){          // No tengo idea, para haber sido de chat GPT funciona bien
  sensors.requestTemperatures();
  float temperatura = sensors.getTempCByIndex(0);
  if(temperatura < -30){
    sensors.begin();
  }
  return temperatura;
}

void setup() {
  sensors.begin();               // Iniciar el sensor de temperatura
  pinMode(relay, OUTPUT);        // Asignar pin de salida para relé
  pinMode(pulse, OUTPUT);        // Asignar pin de salida para pulso de excitación
  Serial.begin(115200);          // Inicializar terminal serial a 11520 baudios
}

void loop() {
  resistencia = get_conductivity();  // Llamar la función de lectura de conductividad
  temperatura = get_temperature();   // Llamar la función de lectura de temperatura
  delay(1000);
  Serial.println();
  Serial.print("Resistencia: ");
  Serial.print(resistencia);
  Serial.println();
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println();
}

// Falta colocar una función para leer oxígeno disuelto
// Voltajes de ph y turbidez no calibrados
// Calibrar sensor de conductividad
// Ver Benson-Krause
