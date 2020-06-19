#include <LiquidCrystal.h> 
int Contrast=75;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int sensorMin = 0; 
const int sensorMax = 1024; 
int buzzer = 13;
int sensor = 8;
int val;
int val1;
void setup() 
{
  // put your setup code here, to run once:
  pinMode(9,INPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(8, INPUT);
  analogWrite(6,Contrast);
  lcd.begin(16, 2);
  }

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(8);
  Serial.print("Hello");
  int sensorReading = analogRead(A0);
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
  if(range == 0 || range == 1)
  {
    digitalWrite(13,HIGH);
    Serial.print("\nSensed Wet");
    lcd.setCursor(0,0);
    lcd.print("Motor Status");
    lcd.setCursor(0, 1);
    lcd.print("OFF");
    //Motor OFF
    digitalWrite(7,1);  // turn off relay 1
    Serial.print("OFF");
  }
  else
  {
  if(val == LOW)
  {
    digitalWrite(13,HIGH);
    Serial.print("\nSensed Wet");
    lcd.setCursor(0,0);
    lcd.print("Motor Status");
    lcd.setCursor(0, 1);
    lcd.print("OFF");
    //Motor OFF
    digitalWrite(7,1);  // turn off relay 1
    Serial.print("OFF");
   
  }
  else
  {
    digitalWrite(13,LOW);
    Serial.print("\nSensed Drys");
    lcd.setCursor(0,0);
    lcd.print("Motor Status");
    lcd.setCursor(0, 1);
    lcd.print("ON ");
    //Motor ON
    digitalWrite(7,0);    // turn on relay 1
    Serial.print("ON");
  }
 }
  delay(200);
  lcd.clear();
}
