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

int duration = 100;//the duration of the vibration

int threshold = 5;

//total of 300 stimulus where 1 is standard amplitude and 2 is deviant amplitude
byte stim[6][50] = {
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,2,1,1,2,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,1,2,1,1,1,2,1,1,1,1}, 
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,1,1,1,1,2,1,2,1,1,2,1,1,1,1,2,1,1,1,1,1,2,1,1,1,1,1,1,1,2,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,1,2,1,1,1,1,1,1,1,2,1,1,2,1,2,1,1,1,1,1,1,1,1,2,1,1,2,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,2,1,2,1,1,1,1,1,1,1,2,1,1,1,1,1,2,1,2},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,1,1,1,2,1,1,1,1,1,2,1,1,1,2,1,1,1,1,1,2,1,1,2,1,1,1,1,2,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,2,1,1,1,2,1,1,1,1,1,2,1,1,1,2,1,1,1,2,1,1,1,2,1,2,1,1,1,1,1}
};


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
  
  for(int i = 0; i < 6; i ++){
    for(int j = 0; j < 50; j ++){

      delay(100);
      lcd.print("      ");
      sensorReading = analogRead(pressureRead);
    
      lcd.setCursor(2,1);
      lcd.print(sensorReading);//ouputs the pressure reading
      delay(100);
      
      int st = stim[i][j];//temp variable to check for 1 or 2

      if (st == 1){
        drv.setRealtimeValue(threshold);//vibrate at set amp
        digitalWrite(trigLED, HIGH);//send out ttl pulse
        delay(duration);
        digitalWrite(trigLED,LOW);
        drv.setRealtimeValue(0);//turn off motor
      }

      if (st == 2){
        drv.setRealtimeValue(20);//vibrate at set amp
        digitalWrite(trigLED, HIGH);//send out ttl pulse
        delay((duration/3));
        digitalWrite(trigLED,LOW);
        delay(35);//short delay so the higher stimulation can be distinguished on the waveform
        digitalWrite(trigLED, HIGH);//send out ttl pulse
        delay((duration/3));
        digitalWrite(trigLED,LOW);
        drv.setRealtimeValue(0);//turn off motor
      }
      
      delay(400 + random(100,200));//random delay before we loop back
      buzzNum++;
      if(buzzNum == 300){
        tone(buzzer, 2000);
        delay(500);
        noTone(buzzer);
     
      }//end of buzzNum 
      
    }//end of nested for loop
  }//end of outer for loop
      
}//end of void loop
