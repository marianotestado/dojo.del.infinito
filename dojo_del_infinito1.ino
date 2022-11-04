// Testado Mariano, 1G
// -Comentario:
//       El Buzzer lo tuve que desconectar 
//           por que se bugeaba todo,
//              mil disculpas.


// C++ code
//
#include <LiquidCrystal.h>
#include "string.h"

#define RC 2
#define E 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
#define POT A0
#define LED1 13
#define LED2 12
#define LED3 11
#define LED4 10
#define LED5 9
#define LED6 8
#define PULS 1
#define BUZ 0

void apagarLeds();
void prenderLeds();
void titilarLeds();

LiquidCrystal lcd(RC,E,D4,D5,D6,D7);
char mensaje[40];
char nombreHeroe[20];




void setup()
{
  lcd.begin(16,2);
  
  pinMode(LED1,OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(PULS, INPUT_PULLUP);
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
}


int flagAlma = 0;
int flagEspacio = 0;
int flagRealidad = 0;
int flagPoder = 0;
int flagTiempo = 0;
int flagMente = 0;
int contadorGema = 0;
int flagEncendido = 0;
int flagPrimera = 0;
int poderHeroe;




void loop()
{
  

  
  int potenciometro = analogRead(POT);
  int poderThanos = map(potenciometro, 0 , 1028, 90, 191);
  
  
  lcd.clear();
  sprintf(mensaje, "A LUCHAR!");
  lcd.setCursor(0,0);
  lcd.print(mensaje);
  
  
  if(digitalRead(PULS) == LOW)
  {
    flagEncendido = 1;
    
  }
  
  if(flagEncendido == 1)
  {    
    switch(contadorGema)
    {
      case 0:
      	poderHeroe = random(100, 200);
        lcd.clear();
        delay(2500);      
        strcpy(nombreHeroe, "Gamora");
        Serial.println(poderHeroe);

        sprintf(mensaje, "Thanos : %d", poderThanos);
          lcd.setCursor(0,0);
          lcd.print(mensaje);
          sprintf(mensaje, "Gamora : %d.",poderHeroe);
          lcd.setCursor(0,1);
          lcd.print(mensaje);

        delay(2500);

        lcd.clear();
        sprintf(mensaje, "Por la");
        lcd.setCursor(0,0);
        lcd.print(mensaje);
        sprintf(mensaje, "gema de Alma.");
        lcd.setCursor(0,1);
        lcd.print(mensaje);
      	delay(2500);
      
      	if(poderThanos > poderHeroe)
        {
          lcd.clear();
          delay(2500);
          sprintf(mensaje, "Has ganado");
          lcd.setCursor(0,0);
          lcd.print(mensaje);
          sprintf(mensaje, "la pelea.");
          lcd.setCursor(0,1);
          lcd.print(mensaje);


          flagAlma = 1; 
          contadorGema++;
          flagEncendido = 0;
          delay(1000);
          flagEncendido = 0;

          lcd.clear();
          sprintf(mensaje, "Tienes");
          lcd.setCursor(0,0);
          lcd.print(mensaje);
          sprintf(mensaje, "%d gema.", contadorGema);
          lcd.setCursor(0,1);
          lcd.print(mensaje);
          delay(2500);


        }
        else
        {
          lcd.clear();
          delay(2500);
          sprintf(mensaje, "Derrotado");
          lcd.setCursor(0,2);
          lcd.print(mensaje);

        }
      break;
      
      case 1:
      	if(flagEncendido = 1)
        {
          poderHeroe = random(100, 200);
          lcd.clear();
          delay(2500);      
          strcpy(nombreHeroe, "Loki");
          Serial.println(poderHeroe);

          sprintf(mensaje, "Thanos : %d", poderThanos);
          lcd.setCursor(0,0);
          lcd.print(mensaje);
          sprintf(mensaje, "Loki : %d.",poderHeroe);
          lcd.setCursor(0,1);
          lcd.print(mensaje);

          delay(2500);

          lcd.clear();
          sprintf(mensaje, "Por la");
          lcd.setCursor(0,0);
          lcd.print(mensaje);
          sprintf(mensaje, "gema de Espacio.");
          lcd.setCursor(0,1);
          lcd.print(mensaje);
          delay(2500);


          if(poderThanos > poderHeroe)
          {
            lcd.clear();
            delay(2500);
            sprintf(mensaje, "Has ganado");
            lcd.setCursor(0,0);
            lcd.print(mensaje);
            sprintf(mensaje, "la pelea.");
            lcd.setCursor(0,1);
            lcd.print(mensaje);

            flagEspacio = 1;
            contadorGema++;
            flagEncendido = 0;

            delay(1000);

            lcd.clear();
            sprintf(mensaje, "Tienes");
            lcd.setCursor(0,0);
            lcd.print(mensaje);
            sprintf(mensaje, "%d gemas.", contadorGema);
            lcd.setCursor(0,1);
            lcd.print(mensaje);
            delay(2500);

          }
          else
          {
            lcd.clear();
            delay(2500);
            sprintf(mensaje, "Derrotado");
            lcd.setCursor(0,2);
            lcd.print(mensaje);
            flagAlma = 0;
            contadorGema = 0;

          }
          
        }
      
      
      	break;
      
      case 2:
      	if(flagEncendido == 1)
        {
          poderHeroe = random(100, 200);
          lcd.clear();
          delay(2500);      
          strcpy(nombreHeroe, "El Coleccionista");
          Serial.println(poderHeroe);

          sprintf(mensaje, "Thanos : %d", poderThanos);
          lcd.setCursor(0,0);
          lcd.print(mensaje);
          sprintf(mensaje, "Colec. : %d.",poderHeroe);
          lcd.setCursor(0,1);
          lcd.print(mensaje);

          delay(2500);

          lcd.clear();
          sprintf(mensaje, "Por la");
          lcd.setCursor(0,0);
          lcd.print(mensaje);
          sprintf(mensaje, "gema de Realidad.");
          lcd.setCursor(0,1);
          lcd.print(mensaje);
          delay(2500);

          if(poderThanos > poderHeroe)
          {

            lcd.clear();
            delay(2500);
            sprintf(mensaje, "Has ganado");
            lcd.setCursor(0,0);
            lcd.print(mensaje);
            sprintf(mensaje, "la pelea.");
            lcd.setCursor(0,1);
            lcd.print(mensaje);

            flagRealidad = 1;
            contadorGema++;
            flagEncendido = 0;

            delay(1000);

            lcd.clear();
            sprintf(mensaje, "Tienes");
            lcd.setCursor(0,0);
            lcd.print(mensaje);
            sprintf(mensaje, "%d gemas.", contadorGema);
            lcd.setCursor(0,1);
            lcd.print(mensaje);
            delay(2500);

          }
          else
          {
            lcd.clear();
            delay(2500);
            sprintf(mensaje, "Derrotado");
            lcd.setCursor(0,2);
            lcd.print(mensaje);
            flagAlma = 0;
            flagEspacio = 0;
            contadorGema = 0;

          }
          
          
          
        }
      
      	break;
      
      case 3:
      	if(flagEncendido == 1)
        {
          poderHeroe = random(100, 200);
          lcd.clear();
          delay(2500);      
          strcpy(nombreHeroe, "Star Lord");
          Serial.println(poderHeroe);

          sprintf(mensaje, "Thanos : %d", poderThanos);
          lcd.setCursor(0,0);
          lcd.print(mensaje);
          sprintf(mensaje, "Star Lord : %d.",poderHeroe);
          lcd.setCursor(0,1);
          lcd.print(mensaje);

          delay(2500);

          lcd.clear();
          sprintf(mensaje, "Por la");
          lcd.setCursor(0,0);
          lcd.print(mensaje);
          sprintf(mensaje, "gema de Poder.");
          lcd.setCursor(0,1);
          lcd.print(mensaje);
          delay(2500);
          
          if(poderThanos > poderHeroe)
          {

            lcd.clear();
            delay(2500);
            sprintf(mensaje, "Has ganado");
            lcd.setCursor(0,0);
            lcd.print(mensaje);
            sprintf(mensaje, "la pelea.");
            lcd.setCursor(0,1);
            lcd.print(mensaje);

            flagRealidad = 1;
            contadorGema++;
            flagEncendido = 0;

            delay(1000);

            lcd.clear();
            sprintf(mensaje, "Tienes");
            lcd.setCursor(0,0);
            lcd.print(mensaje);
            sprintf(mensaje, "%d gemas.", contadorGema);
            lcd.setCursor(0,1);
            lcd.print(mensaje);
            delay(2500);

          }
          else
          {
            lcd.clear();
            delay(2500);
            sprintf(mensaje, "Derrotado");
            lcd.setCursor(0,2);
            lcd.print(mensaje);
            flagAlma = 0;
            flagEspacio = 0;
            contadorGema = 0;

          }
          
        }
      	break;
      case 4:
      	if(flagEncendido == 1)
        {
          poderHeroe = random(100, 200);
          lcd.clear();
          delay(2500);      
          strcpy(nombreHeroe, "Dr Strange");
          Serial.println(poderHeroe);

          sprintf(mensaje, "Thanos : %d", poderThanos);
          lcd.setCursor(0,0);
          lcd.print(mensaje);
          sprintf(mensaje, "Dr Strange : %d.",poderHeroe);
          lcd.setCursor(0,1);
          lcd.print(mensaje);

          delay(2500);

          lcd.clear();
          sprintf(mensaje, "Por la");
          lcd.setCursor(0,0);
          lcd.print(mensaje);
          sprintf(mensaje, "gema de Tiempo.");
          lcd.setCursor(0,1);
          lcd.print(mensaje);
          delay(2500);
          if(poderThanos > poderHeroe)
          {
            lcd.clear();
            delay(2500);
            sprintf(mensaje, "Has ganado");
            lcd.setCursor(0,0);
            lcd.print(mensaje);
            sprintf(mensaje, "la pelea.");
            lcd.setCursor(0,1);
            lcd.print(mensaje);

            flagTiempo = 1;
            contadorGema++;
            flagEncendido = 0;

            delay(1000);

            lcd.clear();
            sprintf(mensaje, "Tienes");
            lcd.setCursor(0,0);
            lcd.print(mensaje);
            sprintf(mensaje, "%d gemas.", contadorGema);
            lcd.setCursor(0,1);
            lcd.print(mensaje);
            delay(2500);

          }
          else
          {
            lcd.clear();
            delay(2500);
            sprintf(mensaje, "Derrotado");
            lcd.setCursor(0,2);
            lcd.print(mensaje);
            flagAlma = 0;
            flagEspacio = 0;
            flagRealidad - 0;
            flagPoder = 0;
            contadorGema = 0;

          }
          
          
          
        }
       break;
      
      case 5:
      	if(flagEncendido == 1)
        {
          poderHeroe = random(100, 200);
          lcd.clear();
          delay(2500);      
          strcpy(nombreHeroe, "Vision");
          Serial.println(poderHeroe);

          sprintf(mensaje, "Thanos : %d", poderThanos);
          lcd.setCursor(0,0);
          lcd.print(mensaje);
          sprintf(mensaje, "Vision : %d.",poderHeroe);
          lcd.setCursor(0,1);
          lcd.print(mensaje);

          delay(2500);

          lcd.clear();
          sprintf(mensaje, "Por la");
          lcd.setCursor(0,0);
          lcd.print(mensaje);
          sprintf(mensaje, "gema de Mente.");
          lcd.setCursor(0,1);
          lcd.print(mensaje); 
          delay(2500);
          
          if(poderThanos > poderHeroe)
          {
                
            lcd.clear();
            delay(2500);
            sprintf(mensaje, "Has ganado");
            lcd.setCursor(0,0);
            lcd.print(mensaje);
            sprintf(mensaje, "la pelea.");
            lcd.setCursor(0,1);
            lcd.print(mensaje);


            flagMente = 1;
            contadorGema++;

            delay(1000);

            lcd.clear();
            sprintf(mensaje, "Tienes");
            lcd.setCursor(0,0);
            lcd.print(mensaje);
            sprintf(mensaje, "%d gemas.", contadorGema);
            lcd.setCursor(0,1);
            lcd.print(mensaje);
            delay(2500);



          }
          else
          {
            lcd.clear();
            delay(2500);
            sprintf(mensaje, "Derrotado");
            lcd.setCursor(0,2);
            lcd.print(mensaje);
            flagAlma = 0;
            flagEspacio = 0;
            flagRealidad - 0;
            flagPoder = 0;
            flagTiempo = 0;
            contadorGema = 0;

          }
          
          if(contadorGema == 6)
          {


            lcd.clear();
            delay(2500);
            sprintf(mensaje, "No me quiero");
            lcd.setCursor(0,0);
            lcd.print(mensaje);
            sprintf(mensaje, "ir Sr Stark...");
            lcd.setCursor(0,2);
            lcd.print(mensaje);
            titilarLeds();
            flagAlma = 0;
            flagEspacio = 0;
            flagRealidad - 0;
            flagPoder = 0;
            flagTiempo = 0;
            flagEncendido = 0;
            flagMente = 0;
            contadorGema = 0; 

          }
          
          
        }
      
      
      	break;
 
    }
  }
  delay(500);
}
    
  
  




void apagarLeds()
{
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);   
}

void prenderLeds()
{
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH);
  digitalWrite(LED6, HIGH);
  
}

void titilarLeds()
{
  prenderLeds();
  delay(1000);
  apagarLeds();
  delay(1000);
  prenderLeds();
  delay(1000);
  apagarLeds();
  delay(1000);
  prenderLeds();
  delay(1000);
  apagarLeds();
  
  
}