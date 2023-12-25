#include <LiquidCrystal.h>
#include <Servo.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Servo myservo;

int trigPin = 8;
int echoPin = 7;
long duration;
int distance;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16, 2);
  myservo.attach(13);
  Serial.begin(9600);

}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0344 / 2;

  if (distance < 20) {
    lcd.setCursor(0, 0);
    lcd.print("Welcome.");
    myservo.write(180);
    delay(5000);
    lcd.clear();
    myservo.write(0);
  }
  else {
    lcd.setCursor(0, 0);
    lcd.print("Try Again.");
    myservo.write(0);
    delay(5000);
    lcd.clear();
  }
  delay(1000);

}
