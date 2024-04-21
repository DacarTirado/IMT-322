const int triggerPin = 2;
const int echoPin = 3;
const int buttonPin = 4;


unsigned long tiempoInicio = 0;

const unsigned long tiempoEspera = 5000;  // 5 segundos

enum EstadoMedicion {
  INACTIVO,
  ESPERANDO,
  MEDICION_ACTIVA
};

EstadoMedicion estado = INACTIVO;

void setup() {
  
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  
  Serial.begin(9600);
}

void loop() {
  switch (estado) {
    case INACTIVO:
      
      if (digitalRead(buttonPin) == LOW) {
       
        tiempoInicio = millis();
        
        estado = ESPERANDO;
      }
      break;

    case ESPERANDO:
      
      if (millis() - tiempoInicio >= tiempoEspera) {
        estado = MEDICION_ACTIVA;
      }
      break;

    case MEDICION_ACTIVA:
      
      float distancia = medirDistancia();
     
      Serial.print("Distancia: ");
      Serial.print(distancia);
      Serial.println(" cm");
      
      estado = INACTIVO;
      break;
  }
} 

float medirDistancia() {
 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  
  unsigned long duracionPulso = pulseIn(echoPin, HIGH);

  
  float distancia = duracionPulso * 0.034 / 2;

  return distancia;
}
