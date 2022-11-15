#pragma GCC push_options
#pragma GCC optimize ("Os")

#include <core.h> // Required by cpu
#include <cpu.h>

#pragma GCC pop_options

CPU &cpu = Cpu;
unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 500;
int ledState = LOW;     
int led1=0;
int led2=2;
int led3=3;
int led4=4;
int led5=8;
int led6=9;
int led7=10;
int led8=11;


void setup () {
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(led5,OUTPUT);
pinMode(led6,OUTPUT);
pinMode(led7,OUTPUT);
pinMode(led8,OUTPUT);
}

void loop() {
unsigned long currentMillis = millis();
if (currentMillis - previousMillis >= interval) {
 // save the last time you blinked the LED
 previousMillis = currentMillis;

 // if the LED is off turn it on and vice-versa:
 if (ledState == LOW) {
   ledState = HIGH;
 } else {
   ledState = LOW;
 }

 // set the LED with the ledState of the variable:
 digitalWrite(led1, ledState);
 digitalWrite(led2, ledState);
 digitalWrite(led3, ledState);
 digitalWrite(led4, ledState);
 digitalWrite(led5, ledState);
 digitalWrite(led6, ledState);
 digitalWrite(led7, ledState);
 digitalWrite(led8, ledState);
}
}
