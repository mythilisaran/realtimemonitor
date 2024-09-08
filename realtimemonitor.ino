//https://github.com/mathworks/thingspeak-arduino/blob/master/README.md
//https://docs.espressif.com/projects/esp-idf/en/stable/esp32/hw-reference/esp32/get-started-devkitc.html
//https://thingspeak.com/channels/2642618
//Write a Channel Feed
 //GET https://api.thingspeak.com/update?api_key=VRM9PPSF02IOGENV&field1=0
 //Read a Channel Feed
 //GET https://api.thingspeak.com/channels/2642618/feeds.json?results=2




#include <WiFi.h>
#include "ThingSpeak.h"
//box1
const char* WIFI_NAME = "Wokwi-GUEST";
const char* WIFI_PASSWORD = "";
const int myChannelNumber = 2642618;
const char* myApiKey = "Z8PU8CJTQIPD6KMI";
const char* server = "api.thingspeak.com";




long duration; 

WiFiClient client;

void setup() {
  Serial.begin(115200); // Starts the serial communication


  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.println("Wifi not connected");
  }
  Serial.println("Wifi connected !");
  Serial.println("Local IP: " + String(WiFi.localIP()));
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);


}

void loop() {


  // Clears the trigPin
 
  //float r1 = ThingSpeak.readFloatField(myChannelNumber, 1);  
  long count1 = ThingSpeak.readLongField(myChannelNumber, 1, myApiKey);  
 long count2 = ThingSpeak.readLongField(myChannelNumber, 2, myApiKey);  

  // Convert to inches
  
  // Prints the distance in the Serial Monitor

  Serial.print("Distance (inch): ");
  Serial.println(count1); 
  Serial.print("Distance (inch): ");
  Serial.println(count2);
  
  delay(1000);
}


//https://github.com/mathworks/thingspeak-arduino/blob/master/README.md
