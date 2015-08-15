/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

const int a=1;
const int b=2;
const int c=3;
const int d=4;
const int e=5;
const int f=6;
const int g=7;
const int d1=A3;
const int d2=A2;
const int d3=A1;
const int d4=A0;

// the setup function runs once when you press reset or power the board
void setup() {
//  Serial.begin(9600);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);

}
int i = 1000;

// the loop function runs over and over again forever
void loop() {
  write(i--);
  delay(20);
}

void write(int num) {
  int n1 = num % 10;
  int n2 = (num /10) % 10;
  int n3 = (num /100) % 10;
  int n4 = (num /1000) % 10;

  onDigit(d1);
  writeSingleDigit(n4);
  delay(5);
  onDigit(d2);
  writeSingleDigit(n3);
  delay(5);
  onDigit(d3);
  writeSingleDigit(n2);
  delay(5);
  onDigit(d4);
  writeSingleDigit(n1);
  delay(5);
}

void writeSingleDigit(int n){
  switch(n) {
    case 0:
      up(a); up(b); up(c); up(d); up(e); up(f); down(g);
      break;
    case 1:
      down(a); up(b); up(c); down(d); down(e); down(f); down(g);
      break;
    case 2:
      up(a); up(b); down(c); up(d); up(e); down(f); up(g);
      break;
    case 3:
      up(a); up(b); up(c); up(d); down(e); down(f); up(g);
      break;
    case 4:
      down(a); up(b); up(c); down(d); down(e); up(f); up(g);
      break;
    case 5:
      up(a); down(b); up(c); up(d); down(e); up(f); up(g);
      break;
    case 6:
      down(a); down(b); up(c); up(d); up(e); up(f); up(g);
      break;
    case 7:
      up(a); up(b); up(c); down(d); down(e); down(f); down(g);
      break;
    case 8:
      up(a); up(b); up(c); up(d); up(e); up(f); up(g);
      break;
    case 9:
      up(a); up(b); up(c); up(d); down(e); up(f); up(g);
      break;
  }
}

void up(int segment) {
  digitalWrite(segment, HIGH);
}

void down(int segment) {
  digitalWrite(segment, LOW);
}

void onDigit(int digit)  {
  analogWrite(d1, 1023);
  analogWrite(d2, 1023);
  analogWrite(d3, 1023);
  analogWrite(d4, 1023);
  analogWrite(digit, 0);
}

void onAll(){
  digitalWrite(a, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(b, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(c, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(d, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(e, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(f, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(g, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void doCycle(){
  digitalWrite(g, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(a, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
  digitalWrite(a, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(b, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);
  digitalWrite(b, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(c, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(c, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(d, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(d, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(e, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(e, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(f, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(f, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(g, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);            
}

 
