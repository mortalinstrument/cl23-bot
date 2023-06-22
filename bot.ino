//www.elegoo.com
//2016.12.08
#include "SR04.h"

#define TRIG_PIN 12 // 
#define ECHO_PIN 9 // 
#define LEFT_MOTOR_FORWARD 3
#define LEFT_MOTOR_BACKWARD 5

#define RIGHT_MOTOR_FORWARD 6
#define RIGHT_MOTOR_BACKWARD 7

//#define BOOST_LED_PIN 15
//#define BOOST_RELAIS_PIN

//#define BOOST_LED_PIN 15  
//#define BOOST_LED_PIN 15 
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long distance_cm;

void meow(int fwd, int bwd, bool i) {
   int a = LOW;
   int b = HIGH;
   if (i) {
    int tmp = a;
    a = b;
    b = tmp;
   }
   digitalWrite(fwd, b);
   digitalWrite(bwd, a);
}

void set_left(bool i) {
  meow(LEFT_MOTOR_FORWARD, LEFT_MOTOR_BACKWARD, i);
}


void set_right(bool i) {
  meow(RIGHT_MOTOR_FORWARD, RIGHT_MOTOR_BACKWARD, i);
}

void setup() {
   Serial.begin(9600);
   pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
   pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);

   pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
   pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT);

   digitalWrite(LEFT_MOTOR_FORWARD, LOW);
   digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
   digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
   digitalWrite(RIGHT_MOTOR_BACKWARD, HIGH);
}

void loop() {
   set_left(false);
   set_right(false);
   distance_cm=sr04.Distance();

   Serial.print(distance_cm);
   Serial.println("cm");
}
