#include "funciones.h"
#define TB1 2000
#define TB2 5000
#define TB3 7000
#define BAUDRATE 9600
#define PULSADOR 3
//Definimos las variables
int dato=0;
int compra=0;
int precioBebida;
int vuelto;
bool T=false;
bool S=false;
int contador = 0;

typedef enum
{
  Inicio,
  Compra,
  Bebida1,
  Bebida2,
  Bebida3,
  Reinicio
} Maquina;

Maquina estado = Inicio;

void setup() 
{
  Serial.begin(BAUDRATE);
  pinMode(PULSADOR, INPUT_PULLUP);
}

void loop() 
{
  switch (estado)
  {
  case Inicio:
  Serial.println("Ingrese un monto mayor a $2");
    while (!Serial.available()||dato==0)
    {
      dato = Serial.parseInt();
      T=true;
    }
    
    Serial.print("El monto de dinero ingresado fue: ");
    Serial.println(dato);
    
    if (dato < 2) 
    {
      Serial.println("Monto Insuficiente, no se puede introducir a la maquina");
    }
    Serial.println("Bienvenido, ¿qué bebida deseas?");
    Serial.println("500ml cuesta $2 (1), 1000ml cuesta $5 (2), 1500ml cuesta $7 (3)");  
    
    while (T==true)
    {
      if(Serial.available() > 1)
      {
      S=true;
        if(compra==0)
        {
          compra = Serial.parseInt();
        }
        if(compra==1||compra==2||compra==3)
        {
          estado=Compra;
          T=false;
        }
      }
    }
  break;

    case Compra:
    if(compra==1)
    {
      estado = Bebida1;
    }
    if(compra==2)
    {
      estado = Bebida2;
    }
    if(compra==3)
    {
      estado = Bebida3;
    }
    break;

    case Bebida1:
      precioBebida = 2;
      Serial.println("La bebida elegida fue 500ml");
      cambio(TB1);
    break;

    case Bebida2:
      precioBebida = 5;
      Serial.println("La bebida elegida fue 1000ml");
      cambio(TB2);
    break;

    case Bebida3:
      precioBebida = 7;
      Serial.println("La bebida elegida fue 1500ml");
      cambio(TB3);
    break;
      
    case Reinicio:
    Serial.println("Oprime el boton para el reinicio del sistema");
    Boton();
    break;

    default:
      Serial.println("Bebida no válida. Reiniciando el ciclo.");
      return;
  }
}
void cambio(int n) 
{
  vuelto = dato - precioBebida;
  mostrarBarraDeCarga(n);
  if (vuelto >= 0) 
  {
    Serial.print("Su vuelto es de $");
    Serial.println(vuelto);
  }
  else if (vuelto < 0) 
  {
    Serial.println("Error: monto insuficiente para comprar la bebida.");
    dato=0;
    compra=0;
    estado=Inicio;
  }
  estado = Reinicio;
}
void Boton()
{
  delay(2000);
  if (digitalRead(PULSADOR) == LOW) 
  {
    dato=0;
    compra=0;
    Serial.println("Botón presionado. Reiniciando el sistema");
    estado=Inicio;
  }
}