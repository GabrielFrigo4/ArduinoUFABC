//https://www.robocore.net/tutoriais/programando-o-esp8266-pela-arduino-ide
#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>

#define WIFI_SSID "Wi-Fé"
#define WIFI_PASSWORD "manoelgomes"

#define DATABASE_URL "https://flutter-temperatura-arduino-default-rtdb.firebaseio.com/"
#define API_KEY "AIzaSyBl5TymsKLfMySzBm1DB5ue_oA2KcsdMco"
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"
unsigned long count = 0;

// Define Firebase data object
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

void setup() {
  Serial.begin(9600);
  // Firebase auth data
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;

  // Connect to Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi!");

  // Initialize Firebase
  if (Firebase.signUp(&config, &auth, "", "")){
    Serial.println("ok");
  }
  else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void loop() {
  /*
  if (Firebase.RTDB.setInt(&fbdo, "sensors/sensor_01/humidity", count)) {
  Serial.println("PASSED");
  Serial.println("PATH: " + fbdo.dataPath());
  Serial.println("TYPE: " + fbdo.dataType());
  count++;
  }
  else {
    Serial.println("FAILED");
    Serial.println("REASON: " + fbdo.errorReason());
  }*/
}
