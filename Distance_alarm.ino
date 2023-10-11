#include <LiquidCrystal_I2C.h>

//define I2C address......
LiquidCrystal_I2C lcd(0x27, 16, 2);


//create veriables
int trig = 9;
int echo = 8;
long duretion, distance;

int LED = 3;
int Buzzer = 2;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);

  lcd.init();
  lcd.clear();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Distance:");

}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig, LOW);
  delayMicroseconds(10);
  digitalWrite(trig, HIGH);

  duretion = pulseIn(echo, HIGH);
  distance = (duretion * 0.034) / 2;

  lcd.setCursor(0, 1);
  lcd.print(distance);
  delay(500);
  lcd.clear();
  lcd.setCursor(5, 1);
  lcd.print("cm");
  lcd.setCursor(0, 0);
  lcd.print("Distance");


  if (distance < 10) {
    digitalWrite(LED, HIGH);
    digitalWrite(Buzzer, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
    digitalWrite(Buzzer, LOW);
  }

}
