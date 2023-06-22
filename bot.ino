//www.elegoo.com
//2016.12.08
#include "SR04.h"

#define TRIG_PIN 12
#define ECHO_PIN 11
#define LEFT_MOTOR_PIN 13
#define RIGHT_MOTOR_PIN 14
#define BOOST_LED_PIN 15

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

void setup() {
   Serial.begin(9600);
   
}

void loop() {
  lcd.clear();
  lcd.home(); // Replace le curseur en haut a gauche
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
   delay(1000);
}
