#include "FireBase.h"
#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

unsigned long count = 0;

// Define Firebase data object
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

void FireBase_Init(const char* wifi_ssid, const char* wifi_password) {
  Serial.begin(9600);
  // Firebase auth data
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;

  // Connect to Wi-Fi
  WiFi.begin(wifi_ssid, wifi_password);
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

void FireBase_SetInt(const char* path, int value){
  if (Firebase.RTDB.setInt(&fbdo, path, value)) {
    Serial.println("PASSED");
    Serial.println("PATH: " + fbdo.dataPath());
    Serial.println("TYPE: " + fbdo.dataType());
    count++;
  }
  else {
    Serial.println("FAILED");
    Serial.println("REASON: " + fbdo.errorReason());
  }
}