int inputPin = 2;
int outputPin = 13;
int del = 100;
int counter = 0;

void setup()
{
    pinMode( inputPin, INPUT );
    pinMode( outputPin, OUTPUT );
    noTone(outputPin);
}

void loop()
{
  int   inputVal = digitalRead(inputPin);
  if(inputVal == HIGH) {
    counter++;
  } else {
    counter = 0;
  }
  
  if(counter > 50){
    tone(outputPin, 440);
  } else if(counter == 0 ){
    noTone(outputPin);
  }
  
  delay(del);
}
