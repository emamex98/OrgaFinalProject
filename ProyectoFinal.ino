// Emanuel Estrada Larios
// Maximo Bautista Aguirre

#include <NewPing.h>
#include <NewTone.h>

// Declaracion de pines de ultrasonicos
#define TRIGGER_PIN1  31
#define ECHO_PIN1     30
#define MAX_DISTANCE1 200

#define TRIGGER_PIN_2  33
#define ECHO_PIN_2     32
#define MAX_DISTANCE_2 200

#define TRIGGER_PIN_3  35
#define ECHO_PIN_3     34
#define MAX_DISTANCE_3 200

#define TRIGGER_PIN_44  39
#define ECHO_PIN_44     38
#define MAX_DISTANCE_44 200

#define TRIGGER_PIN_6  37
#define ECHO_PIN_6     36
#define MAX_DISTANCE_6 200

// Declaracion de pines de movimiento y laser
int escalon7 = 50; // INPUT
int escalon8 = 51; // INPUT
int receptor = 42;
int laser = 43;

/*int ledDo = 50;
int ledRe = 0;
int ledMi = 0;
int ledFa = 0;
int ledSol = 0;
int ledLa = 0;
int ledSi = 0;

int fqDo[5]={131,262,523,1046,2093};      // Do
int fqRe[5]={147,294,587,1175,2349};      // Re
int fqMi[5]={165,330,659,1319,2637};      // Mi
int fqFa[5]={175,349,698,1397,2794};      // Fa
int fqSol[5]={196,392,784,1568,3136};     // Sol
int fqLa[5]={220,440,880,1760,3520};      // La
int fqSi[5]={247,494,988,1976,3951};      // Si */

// Configuracion pines ultrasonicos
NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE1);
NewPing escalon2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE_2);
NewPing escalon3(TRIGGER_PIN_3, ECHO_PIN_3, MAX_DISTANCE_3);
NewPing escalon44(TRIGGER_PIN_44, ECHO_PIN_44, MAX_DISTANCE_44);
NewPing escalon6(TRIGGER_PIN_6, ECHO_PIN_6, MAX_DISTANCE_6);

  

void setup() {
  Serial.begin(9600);
  
  // Configuraciones pines de movimiento y laser
  pinMode(escalon7,INPUT);
  pinMode(escalon8,INPUT);
  pinMode(receptor,INPUT);
  pinMode(laser,OUTPUT);

  /*pinMode(ledDo,OUTPUT);
  pinMode(ledRe,OUTPUT);
  pinMode(ledMi,OUTPUT);
  pinMode(ledFa,OUTPUT);
  pinMode(ledSol,OUTPUT);
  pinMode(ledLa,OUTPUT);
  pinMode(ledSi,OUTPUT);*/

}

void loop() {
  delay(2000);

  // Obtener distancia ultrasonicos
  int es1 = sonar1.ping_median();
  int es2 = escalon2.ping_median();
  int es3 = escalon3.ping_median();
  int es44 = escalon44.ping_median();
  int es6 = escalon6.ping_median();
  

  Serial.println("Escalones activados: ");
  Serial.println(es1/US_ROUNDTRIP_CM); //Arreglar
  Serial.println(es2/US_ROUNDTRIP_CM); //arr
  Serial.println(es3/US_ROUNDTRIP_CM); //arr
  Serial.println(es44/US_ROUNDTRIP_CM); //arr
  Serial.println(digitalRead(receptor));
  Serial.println(es6/US_ROUNDTRIP_CM); //arr
  Serial.println(digitalRead(escalon7));
  Serial.println(digitalRead(escalon8));

  if((es1/US_ROUNDTRIP_CM)>0 && (es1/US_ROUNDTRIP_CM) <20) {
    NewTone(53, 262);
    delay(1000);
    noNewTone(53);
  }
  else if((es2/US_ROUNDTRIP_CM)>0 && (es2/US_ROUNDTRIP_CM) <20) {
    NewTone(53, 294);
    delay(1000);
    noNewTone(53);
  }
  else if((es3/US_ROUNDTRIP_CM)>0 && (es3/US_ROUNDTRIP_CM) <20) {
    NewTone(53, 330);
    delay(1000);
    noNewTone(53);
  }
  else if((es44/US_ROUNDTRIP_CM)>0 && (es44/US_ROUNDTRIP_CM) <20) {
    NewTone(53, 349);
    delay(1000);
    noNewTone(53);
  }
  else if(digitalRead(receptor) == 0) {
    NewTone(53, 392);
    delay(1000);
    noNewTone(53);
  }
  else if((es6/US_ROUNDTRIP_CM)>0 && (es6/US_ROUNDTRIP_CM) <20) {
    NewTone(53, 440);
    delay(1000);
    noNewTone(53);
  }
  else if (digitalRead(escalon7) == 1) {
    NewTone(53, 494);
    delay(1000);
    noNewTone(53);
  }
  else if (digitalRead(escalon8) == 1) {
    NewTone(53, 523);
    delay(1000);
    noNewTone(53);
  }
  

}
