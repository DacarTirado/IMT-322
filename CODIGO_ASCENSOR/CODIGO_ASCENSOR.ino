String frase = "Piso al que desea ir: '1', '2' o '3' ";
String frase2 = "Te encuentras en el piso: ";
int Baudrate = 9600;
int x = 0;
typedef enum{
  t,
  uno,
  dos,
  tres
}lectura;
lectura F = t;
void setup()
{
Serial.begin(Baudrate);
}
void loop(){
  Serial.println(frase);
  while (Serial.available() == 0){
  }
  int mynumber = Serial.parseInt();
  if (mynumber == 1){
    F = uno;
  }
  if (mynumber == 2){
    F = dos;
  }
  if (mynumber == 3){
    F = tres;
  }
        switch (F){
          case uno:
          while (x<=9){
                x+=1;
                Serial.println(x);            
          }
          if (x=9){
                  Serial.print(frase2);
                Serial.println(mynumber);
              } 
          break;
          case dos:
          while (x<=9){
                x+=1;
                Serial.println(x);            
          }
          if (x=9){
                  Serial.print(frase2);
                Serial.println(mynumber);
              }
          break;
          case tres:
          while (x<=9){
                x+=1;
                Serial.println(x);            
          }
          if (x=9){
                  Serial.print(frase2);
                Serial.println(mynumber);
              }
          break;
      }
    
  }
