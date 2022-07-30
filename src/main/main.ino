-#include <Hash.h> //using sha1 hash
#include <SPI.h> // SPI library- Serial Peripheral Interface Protocol
#include <NTPClient.h>
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#define FIREBASE_HOST "https://nodemcu-1206.firebaseio.comx /"      
#define FIREBASE_AUTH "YtEadYbnayiO7jIrytZo1z7eWaBJ3EjuQ8uUcFEk"           
#define WIFI_SSID "motog"                                  
#define WIFI_PASSWORD "zanespectre"


WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

FirebaseData firebaseData;
FirebaseJson json;
long randNumber;
void setup() {
  Serial.begin(9600); // open serial connection
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                  
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
 
  Serial.println();
  Serial.print("Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());                               //prints local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);  // connect to the firebase
  timeClient.begin();
 
}
 
void loop() {

      String resultid = sha1(random(10000););//Encrypting id using SHA1 Algorithm
      Serial.println(" " + resultid); // Print out of encrypted id is complete.
      delay(2000);
      timeClient.update();
      json.set("chipid",resultid);
      json.set("ecg",Ecg_data);
      json.set("readerid","H101");
      json.set("timestamp",timeClient.getFormattedTime());
      if (Firebase.pushJSON(firebaseData, "/rfid", json)){

  Serial.println(firebaseData.dataPath());

  Serial.println(firebaseData.pushName());

  Serial.println(firebaseData.dataPath() + "/"+ firebaseData.pushName());

} else {
  Serial.println(firebaseData.errorReason());
}

//  }
    }
  }
}
