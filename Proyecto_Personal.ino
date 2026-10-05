#include <Wire.h>//dibreria
#include <LiquidCrystal_I2C.h>//dibreria
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);//definicion
//LiquidCrystal_I2C lcd(0x3F,16,2);//comentario
const int Trigger = 2;//variables
const int Echo = 3;
int pinaltavoz=13;
int frecuencia=220;
int contador;
int to,tt,ttt,dpwm;

void setup() //configuracion
{
  
  lcd.begin(16,2);   //define columnas filas lcd
  lcd.home ();      // go home
  lcd.print("3 metros");//presenta en pantalla
  pinMode(Trigger,OUTPUT);//define como salida 
  pinMode(Echo, INPUT);//define como entrada
  digitalWrite(Trigger,LOW);//define estado de salida
  pinMode(9,OUTPUT);//define pin 9 como salida
}

void loop() //bucle
{
  long t;
  long int d;
  ttt=ttt+1;//suma un 1
  if (ttt>=10)//rutina para medir distancia
  {
    ttt=0;//pone a 0
    digitalWrite(Trigger,HIGH);//escribe nivel alto
    delayMicroseconds(10);// espera
    digitalWrite(Trigger,LOW);//estribe nivel bajo
    t=pulseIn(Echo,HIGH);//cuenta tiempo hasta recibir el eco
    d=t/59;//calcula distancia
    //distancia=( velocidada del sonido * tiempo ) / 2
    //medida en centimetros 
    //tiempo en us
    //entre 2 por ser de ida y vuelta
    //distancia = ( 340m/s * 1/1000000 s/us * 100 cm/m * tiempo ) / 2
    //distancia = tiempo * 0.017 
    //distancia = tiempo / 59
    delay(100);//tiempo
    lcd.setCursor ( 0, 1 ); //pone a posicion 0,1       
    lcd.print("      ");//escribe espacio en blanco
    lcd.setCursor ( 0, 1 );//pone en posicion 0,1
    lcd.print (d);//visualiza en pantalla la variable d
    dpwm=d;
    if (dpwm>=250) dpwm=251;//combierte a pwm para visualizar en voltaje
    analogWrite(9,dpwm);//sale por pin9 salida analogica voltaje
  }
  
  tt=tt+1;
  if (tt>=d) //rutina para generar pulso variable con la distancia
  {
    tt=0;
    for (int i=0; i<5; i++)//precuencia del pulso
    {
      digitalWrite(pinaltavoz,HIGH); 
      delay(5);
      digitalWrite(pinaltavoz,LOW);
      delay(6);  
    
  }
    
}