uint8_t signal = A0;    // Señal de excitación
uint8_t ref = A1;       // Referencia
uint8_t cond = A2;      // Lectura de conductividad
uint8_t ph = A3;        // Lectura de PH
uint8_t turb = A4;      // Lectura de Turbidez
uint8_t relay = 7;

uint8_t pulse = 13;     // Pulso de excitación

uint16_t adc = 1024;    // Precisión del ADC

float v_ref;
float v_pou;
float v_out;

float m_res = 150;      // Valor de resistencia para sensor de conductividad

float resistencia;
float turbidez;
float pothid;


void read_cond(){
  v_ref = 5 *  analogRead(ref) / adc;     // Leer voltaje de referencia 
  v_pou = 5 *  analogRead(signal) / adc;  // Leer voltaje de pulso
  v_out = 5 *  analogRead(cond) / adc;    // Leer voltaje de salida
  
  v_pou = v_pou - v_ref;                    // Relativizar los voltajes respecto a referencia
  v_out = v_out - v_ref;
}

float get_cond(){
  float acc = 0;
  float res = 0;
  uint8_t counter = 0;
  digitalWrite(relay, HIGH);
  pinMode(pulse, OUTPUT);
  
  while(counter != 250){
    digitalWrite(pulse, HIGH);
    delay(1);
    read_cond();
    res = ((m_res * v_pou)/(v_out / 6)) - m_res;  // Obtener una lectura de resistencia
    acc = acc + res;
    digitalWrite(pulse, LOW);
    delay(1);
    read_cond();
    res = ((m_res * v_pou)/(v_out / 6)) - m_res;  // Obtener una segunda lectura de resistencia
    acc = acc + res;
    counter ++;
  }
  digitalWrite(relay, LOW);
  pinMode(pulse, INPUT);
  return acc / 500;
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

void setup() {
  pinMode(relay, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  resistencia = get_cond();
  turbidez = get_turb();
  pothid = get_ph();

  Serial.println();
  Serial.print("Resistencia [ohms]: ");
  Serial.print(resistencia);
  Serial.println();
  Serial.print("Turbidez [volt]: ");
  Serial.print(turbidez);
  Serial.println();
  Serial.print("Ph [volt]: ");
  Serial.print(pothid);
  Serial.println();
  Serial.println();
}
