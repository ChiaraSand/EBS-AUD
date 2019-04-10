* EINGEBETTETE SYSTEME WiSe 18/19 
  * HOCHSCHULE RUHR WEST
  * 
  * CHIARA SANDFUEHR 
  * MATR: 10009436
  * 
  * made for Arduino UNO
  * 
  * datasheet for ultrasonic sensor: 
  * https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
  * 
  * datasheet for lcd-display:
  * 
*/////////////////////////////////////////////////////////////////////////////

//library for lcd-display
#include <LiquidCrystal.h>

//ultrasonic sensor 
#define trigger 18
#define echo 19

//RGB-LED, common gnd
#define LED_R 10
#define LED_G 11
#define LED_B 9
 
float time=0,distance=0;

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
//LiquidCrystal lcd(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7);
 
void setup(){
 //declare I/O

pinMode(trigger,OUTPUT);
pinMode(echo,INPUT);
pinMode(LED_R,OUTPUT);
pinMode(LED_G,OUTPUT);
pinMode(LED_B,OUTPUT);
 
lcd.begin(16, 2);

//print message on boot
lcd.clear();
lcd.setCursor(0, 0);           //sets Cursor to column 0 & row 0..
lcd.print(" Ultra sonic");
lcd.setCursor(0, 1);
lcd.print("Distance Meter");
delay(1500);
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("by Chiara");
lcd.setCursor(0, 2);
lcd.print("Sandfuehr");
delay(1500);
}

//declare looping function
void loop(){
 digitalWrite(trigger,LOW);     //make sure trigger is set to "off"    (delay from datasheet)
 delayMicroseconds(2);
 
 digitalWrite(trigger,HIGH);   //turn trigger on  -> generate signal   (delay from datasheet)
 delayMicroseconds(10);
 
 digitalWrite(trigger,LOW);    //turn trigger off -> stop signal       (delay from datasheet)
 delayMicroseconds(2);
 
 time=pulseIn(echo,HIGH);
 distance=time*340/20000;

   //close range <= 10cm - green light/ everything ok
   if (distance <= 10){
   analogWrite(LED_R, 0);
   analogWrite(LED_G, 255);
   analogWrite(LED_B, 0);
   }  //medium range <= 20cm - yellow light/ caution
      else if(distance <= 20){
      analogWrite(LED_R, 255);
      analogWrite(LED_G, 255);
      analogWrite(LED_B, 0);
      }   //far range >= 20cm - red light/ danger
          else {
          analogWrite(LED_R, 255);
          analogWrite(LED_G, 0);
          analogWrite(LED_B, 0);
          }
          
if(distance > 50){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("     ERROR     ");
lcd.setCursor(0,1);
lcd.print("  get closer!  ");
delay(200);  
}
else {
int dist = distance; //well, does it make a difference if you drop 11cm or 11,4123cm ?..
lcd.clear();
lcd.print("Distance:");
lcd.setCursor(0,1);
lcd.print(dist);
lcd.print("cm");
delay(200);
}
//distance in meters, if that's a feature that you're interested in

//lcd.setCursor(0,1);
//lcd.print("Distance:");
//lcd.print(distance/100);
//lcd.print("m");
//delay(1000);
          
}
