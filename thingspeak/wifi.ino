//#include <ESP8266WiFi.h>

//int led = D0;

char ssid[] = "NGTI-SPECIAL";

char pass[] = "FolgvKr6";

int status = WL_IDLE_STATUS; // the Wifi radio's status

//void loop() { 
// checkWifi();
// Serial.println("Connected"); 
// delay(1000);
//} 

void printMac() { 
 byte mac[6]; 
 WiFi.macAddress(mac);
 Serial.print("MAC: "); 
 for (int i = 0; i <= 4; i++) { 
  Serial.print(mac[i], HEX); 
  Serial.print(":"); 
 } 

 Serial.println(mac[5], HEX); 
}

void checkWifi() { 
 if (WiFi.status() == WL_CONNECTED) { 
  return; 
 } 

 digitalWrite(led, LOW); // not connected, turn off LED
 delay(10); 
 Serial.print("Connecting to "); 
 Serial.println(ssid);
 WiFi.begin(ssid, pass);
 
 while (WiFi.status() != WL_CONNECTED) { // blink LED while connecting
  digitalWrite(led, HIGH); 
  delay(200); 
  digitalWrite(led, LOW); 
  delay(300); 
  Serial.print("."); 
 } 

 digitalWrite(led, HIGH); // LED burns when connected

 Serial.println("WiFi connected"); 
 Serial.print("IP address: "); 
 Serial.println(WiFi.localIP()); 
 Serial.print("SSID: "); 
 Serial.println(WiFi.SSID()); 
 Serial.print("signal strength (RSSI):"); 

 Serial.println(WiFi.RSSI()); 

}
