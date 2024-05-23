
const int ledbloqueo = 9;
const int ledacceso = 10;
const int botonenvio = 2;
const int botonReset = 3;
const String contraseña = "ucb.2024";
String introducir = "";

unsigned long tiempo = 0;
const unsigned long tiempoMaximo = 3000; 


 void setup() {
  Serial.begin(9600);
  pinMode(ledbloqueo, OUTPUT);
  pinMode(ledacceso, OUTPUT);
  pinMode(botonenvio, INPUT_PULLUP);
  pinMode(botonReset, INPUT_PULLUP);

  digitalWrite(ledbloqueo, HIGH);  
  digitalWrite(ledacceso, LOW);   

  attachInterrupt(digitalPinToInterrupt(botonenvio),  botonenvio, FALLING);
  attachInterrupt(digitalPinToInterrupt(botonReset), botonReset, FALLING);
  }
void loop() {
  if (Serial.available() > 0) {
    char incomingChar = Serial.read();
    enter += incomingChar;
    tiempo = millis();
  }
    if (enter.length() > 0 && millis() - tiempo > tiempoMaximo) {
    resetSystem();
  }

  // Ahorro de energía
 // LowPower.idle(SLEEP_FOREVER, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF, SPI_OFF, USART0_OFF, TWI_OFF);
}

void sendPassword() {
   if (enter == contraseña) {
    digitalWrite(ledbloqueo, LOW);   
    digitalWrite(ledacceso, HIGH);   
  } else {
   resetSystem();  
  }
}

void resetSystem() {
  enter = "";
  digitalWrite(ledbloqueo, HIGH);   
  digitalWrite(ledacceso, LOW);    
  Serial.flush();                 
}
