#include "funciones.h"
#define TB1 2000
#define TB2 5000
#define TB3 7000
#define BAUDRATE 9600
bool T=true;
char dato;
char compra;
typedef enum
{
  Compra,
  Bebida1,
  Bebida2,
  Bebida3
}Maquina;
  Maquina estado = Compra;
void setup() 
{
  Serial.begin(BAUDRATE);
  Serial.println("ingrese un monto mayor a 2$");
}

void loop() 
{
  if(Serial.available()>0)
  {
    dato=Serial.read();
    compra=Serial.read();
  }
    if(dato=='1')
    {
      Serial.println("Monto Insuficiente, no se puede introducir a la maquina");
    }
    else if(dato=='2'||dato=='5'||dato=='7'||T==false)
    {
      switch(estado)
      {
        case Compra:
          Serial.println("Bienvenido que bebida deseas");
          Serial.println("500ml cuesta 2$(B),1000ml cuesta 5$(N), 1500ml cuesta 7$(M)");
          T=false;
      if(compra=='B')
        {
          estado=Bebida1;
        }
      else if(compra=='N')
        {
          estado=Bebida2;
        }
        else if(compra=='M')
        {
          compra=Bebida3;
        }
        break;
        case Bebida1:
            Serial.println("Haz Elegido la bebida de 500ml");
            mostrarBarraDeCarga(TB1);
        break;
        case Bebida2:
            Serial.println("Haz Elegido la bebida de 1000ml");
            mostrarBarraDeCarga(TB2);
        break;

        case Bebida3:
            Serial.println("Haz Elegido la bebida de 1500ml");
            mostrarBarraDeCarga(TB3);
        break;
      }
    }
}
