#define ROJO      2
#define AMARILLO   3
#define VERDE     4
#define TIEMPO 3000

enum Estado {
  ESTADO_VERDE,
  ESTADO_AMARILLO,
  ESTADO_ROJO
};

Estado estado = ESTADO_VERDE;

void setup() {
  pinMode(ROJO, OUTPUT);
  pinMode(AMARILLO, OUTPUT);
  pinMode(VERDE, OUTPUT);
}

void loop() {
  switch (estado) {
    case ESTADO_VERDE:  
      digitalWrite(ROJO, LOW);
      digitalWrite(AMARILLO, LOW);
      digitalWrite(VERDE, HIGH);
      delay(TIEMPO);
      estado = ESTADO_AMARILLO;
      break;
    case ESTADO_AMARILLO:  
      digitalWrite(ROJO, LOW);
      digitalWrite(AMARILLO, HIGH);
      digitalWrite(VERDE, LOW);
      delay(1000);
      estado = ESTADO_ROJO;
      break;
    case ESTADO_ROJO:  
      digitalWrite(ROJO, HIGH);
      digitalWrite(AMARILLO, LOW);
      digitalWrite(VERDE, LOW);
      delay(TIEMPO);
      estado = ESTADO_VERDE;
      break;
  }
}
