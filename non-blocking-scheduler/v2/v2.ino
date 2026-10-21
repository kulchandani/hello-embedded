// two leds blinking at different rates

#include<Arduino.h>

const int led1=8;
int state1=LOW;
const long int1=850;
unsigned long prevMillis1=0;


const int led2=12;
int state2=LOW;
const long int2=600;
unsigned long prevMillis2=0;

void setup(){
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop(){
  unsigned long currMillis = millis();

  if(currMillis - prevMillis1 >= int1){
    prevMillis1=currMillis;
    if(state1==LOW){state1=HIGH;}
    else{state1=LOW;}
    digitalWrite(led1,state1);
  }

  if(currMillis - prevMillis2 >= int2){
    prevMillis2=currMillis;
    if(state2==LOW){state2=HIGH;}
    else{state2=LOW;}
    digitalWrite(led2,state2);
  }
  
}




