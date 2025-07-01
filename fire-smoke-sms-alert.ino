#include "WiFiS3.h"
#include "Arduino_LED_Matrix.h"

// Pin Definitions
#define SMOKE_SENSOR   A0
#define FLAME_SENSOR   6
#define GREEN_LED      3
#define RED_LED        5
#define BUZZER         4

// Wi-Fi & SMS Setup
const char* ssid     = "<Your_SSID>";
const char* password = "<Your_WIFI_Password>";
const String apiKey  = "<Your_SMS_API_Key>";
const String phoneNo = "<Recipient_Phone_Number>";
const int templateID = 101;
String var1 = "House";
String var2 = "FIRE EMERGENCY!";

// Setup
void setup() {
  pinMode(SMOKE_SENSOR, INPUT);
  pinMode(FLAME_SENSOR, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);
  noTone(BUZZER);

  Serial.begin(9600);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected.");
}

// Main loop
void loop() {
  int smokeValue = analogRead(SMOKE_SENSOR);
  int flameValue = digitalRead(FLAME_SENSOR);

  Serial.print("Smoke: ");
  Serial.print(smokeValue);
  Serial.print(" | Flame: ");
  Serial.println(flameValue);

  if (smokeValue > 400 || flameValue == HIGH) {
    triggerAlarm();
    sendSMSAlert();
    delay(10000);  // Avoid spamming SMS
  } else {
    resetAlarm();
  }

  delay(500);
}

// Alarm ON
void triggerAlarm() {
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  tone(BUZZER, 1000);
}

// Alarm OFF
void resetAlarm() {
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  noTone(BUZZER);
}

// Send SMS Alert
void sendSMSAlert() {
  WiFiClient client;
  String url = "/send?apikey=" + apiKey + "&template=" + String(templateID) +
               "&var1=" + var1 + "&var2=" + var2 + "&to=" + phoneNo;

  if (client.connect("api.circuitdigest.com", 80)) {
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: api.circuitdigest.com\r\n" +
                 "Connection: close\r\n\r\n");
    delay(500);
    while (client.available()) {
      char c = client.read();
      Serial.write(c);
    }
    client.stop();
  } else {
    Serial.println("Connection to SMS API failed.");
  }
}
