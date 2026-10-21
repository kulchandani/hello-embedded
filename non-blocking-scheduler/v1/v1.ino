// inbuilt led blink and serial print at different rates

#include<Arduino.h>

const int ledPin=13;
const long ledInterval = 350;
int ledState = LOW;
unsigned long previousLedMillis=0; //last time led was updated

const long serialInterval= 1000;
unsigned long previousSerialMillis=0; //last time serial printed
int secondsPassed=0;

void setup(){
    pinMode(ledPin,OUTPUT);
    Serial.begin(9600);
}

void loop(){
    unsigned long currentMillis = millis(); //get curr time

    if(currentMillis-previousLedMillis>=ledInterval){ //task1
      previousLedMillis=currentMillis;

      if(ledState==LOW){
        ledState=HIGH;
      } else{
        ledState=LOW;
      }

      digitalWrite(ledPin,ledState);
    }

    if(currentMillis-previousSerialMillis>=serialInterval){ //task2
      previousSerialMillis=currentMillis;
      secondsPassed++;
      Serial.print("Uptime: ");
      Serial.print(secondsPassed);
      Serial.println(" seconds");
    }


}
