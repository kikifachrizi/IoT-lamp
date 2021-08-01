#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include <WiFiClient.h>


int ledd = 16;//D4
int led = 2;
String key = "1";

WiFiClient wifiClient;


void setup() {
  pinMode(led, OUTPUT);
  pinMode(ledd, OUTPUT);
  const char* ssid = "ISINAMAWIFIKALIAN"; //Nama WiFi
  const char* password = "ISIPASSSWIFIKALIAN"; //Password WiFi
//    const char* ssid = "Redmi Note 10"; //Nama WiFi
//  const char* password = "12345678"; //Password WiFi
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting..");
  }
  Serial.println("Connection OK");
}

void loop() {

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
http.begin(wifiClient, "ISI URL YANG AKAN KALIAN AKSES (YANG SUDAH DITEST PADA POSTMAN)");
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    int httpResponseCode = http.POST("token="+key); 
    delay(100);
    if (httpResponseCode > 0) {
      char json[500];
      String response = http.getString();
      response.toCharArray(json, 500);
      StaticJsonDocument<200> doc;
      deserializeJson(doc, json);
      int light = doc["lampu"];
      Serial.print("light = ");
      Serial.println(light);
//      Serial.println(response); //menampilkan respon dari website
      if(light == 1){
        digitalWrite(led, HIGH);
      } else{
        digitalWrite(led, LOW);
      }
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }
    http.end();  //Free resources
  } else {
    Serial.println("Error in WiFi connection");
  }
  delay(100);
}
