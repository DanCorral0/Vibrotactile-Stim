#include <Wire.h>
#include <LiquidCrystal.h>
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int pressureRead = A0;
const int buzzer = 9;
const int trigLED = 8;
int sensorReading = 0;
int buzzNum = 0;

int xVal[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
int Amp[] = {0,1,2,3,4,5,6,7,8,9,10,12,15,20,25,30,50};



void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(1,0);
  lcd.print("Pressure:");
  drv.begin();
  
  drv.selectLibrary(1);
  
  pinMode(buzzer, OUTPUT);
  pinMode(trigLED, OUTPUT);
  digitalWrite(trigLED, LOW);
  
  drv.begin();
  drv.setMode(DRV2605_MODE_REALTIME);
  drv.useLRA();
  Serial.begin(9600);
  
}



void loop() {
  for(int i = 0; i < 17; i++){ //loop through all values set in array
  delay(100);
  lcd.print("      ");
  sensorReading = analogRead(pressureRead);
    
  lcd.setCursor(2,1);
  lcd.print(sensorReading);//ouputs the pressure reading
  delay(100);

    drv.setRealtimeValue(Amp[i]);//vibrate at set amp
    digitalWrite(trigLED, HIGH);//send out ttl pulse
    delay(100);
    digitalWrite(trigLED,LOW);
    drv.setRealtimeValue(0);//turn off motor

    Serial.print(Amp[i]);//send amp value to serial monitor
    Serial.print("\n");
    buzzNum++;
    
    delay(1500);
    
     if(buzzNum == 100){
      tone(buzzer, 2000);
      delay(300);
      noTone(buzzer);
     
     }//end of buzzNum 
   
   }//end of for loop
    
}//end of void loop
