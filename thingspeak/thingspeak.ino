#include <ESP8266WiFi.h>
// 3KXHUIP2QP3UEATO

// ThingSpeak Settings

int led = D0;

const char* thingSpeakHost = "api.thingspeak.com";
String writeAPIKey = "3KXHUIP2QP3UEATO";
const int updateThingSpeakInterval = 15 * 1000;
const int windowSize = 10;
const int valueReadInterval = updateThingSpeakInterval / windowSize;

float movingAvg = 0;

void setup() { 
 pinMode(led, OUTPUT); 
 Serial.begin(115200); 
 checkWifi();
 printMac();
} 

void loop() {  
  checkWifi();

  for(int i = 0; i< windowSize; i++) { 
    readTemperature();
    delay(valueReadInterval);
  }
  sendUpdate("field1=" + String(movingAvg/windowSize));
}

boolean sendUpdate(String data) {
  Serial.println("sending: " + data);
  WiFiClient client; // Use WiFiClient class to create TCP connections
  if (!client.connect(thingSpeakHost, 80)) {
    Serial.println("connection failed");
    return false;
  }

  client.print("POST /update HTTP/1.1\n");
  client.print("Host: api.thingspeak.com\n");
  client.print("Connection: close\n");
  client.print("X-THINGSPEAKAPIKEY: " + writeAPIKey + "\n");
  client.print("Content-Type: application/x-www-form-urlencoded\n");
  client.print("Content-Length: ");
  client.print(data.length());
  client.print("\n\n");
  client.print(data);
  
  delay(10);

  Serial.println("closing connection");
  return true;

}

void readTemperature() {
  int val = analogRead(A0);
  delay(3);
  float volts = (val/1024.0) * 3.3;
  int centigrades= volts * 100 -50;
  movingAvg = movingAvg + centigrades - movingAvg / windowSize;
}

