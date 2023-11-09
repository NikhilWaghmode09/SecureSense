/*CODES FOR THE DEVICE "TEST BLYNK" #define BLYNK_TEMPLATE_ID "TMPL3TwzXJHWX"
#define BLYNK_TEMPLATE_NAME "TEST BLYNK"
#define BLYNK_AUTH_TOKEN "KL1nVMXMcmJSxDLfMNBPsNFZ9OVWtZBc"*/
// #include "DHT.h" //new
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN 2

// #define DHTPIN 2
// #define DHTTYPE DHT11

#define BLYNK_TEMPLATE_ID "TMPL3Re_Z3le2"
#define BLYNK_TEMPLATE_NAME "FireSafe"
#define BLYNK_AUTH_TOKEN "lhGhXAkHKMDUPe6TUaA5wxtL9R59AXJA"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#define APP_DEBUG

// DHT dht(DHTPIN, DHTTYPE);

// float dht11_temp;
// float dht11_humi;

const int mq2Pin = 32; // Analog pin connected to the MQ2 sensor
int buzz = 14;
int led = 27;
// int dht = 2;
void setup() {
  Serial.begin(115200);
  delay(100);
  WiFi.begin("Nikhil's A51", "");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  // dht.begin();
  // Initialize Blynk
  //  Blynk.begin(auth, WiFi.SSID().c_str(), WiFi.psk().c_str());
  Blynk.begin(BLYNK_AUTH_TOKEN, WiFi.SSID().c_str(), WiFi.psk().c_str());
  pinMode(led,OUTPUT);
  pinMode(buzz,OUTPUT);
}

void loop() {
  DHT.read(DHT11_PIN);
  int sensorValue = analogRead(mq2Pin);
  Blynk.virtualWrite(V4, sensorValue);
  Blynk.run();
  // double h = dht.readHumidity();
  // double t = dht.readTemperature();
  Blynk.virtualWrite(V2, DHT.temperature);
  Blynk.virtualWrite(V3, DHT.humidity);
  delay(1000);
  int threshold = 1000;
  if (sensorValue > threshold){
    Serial.println("ALERT!!! Smoke Detected.");
    Blynk.virtualWrite(V1, "ALERT!!! Smoke Detected :0");
    digitalWrite(buzz,HIGH);
    digitalWrite(led,HIGH);
    Blynk.logEvent("fire_risk","Smoke is detected! There might be risk of fire🔥");
  }
  else{
    Serial.println("No Smoke Detected.");
    Blynk.virtualWrite(V1, "No Smoke Detected :)");
    digitalWrite(buzz,LOW);
    digitalWrite(led,LOW);
  }
  delay(1000);
  Serial.println("Humidity =");
  Serial.println(DHT.humidity);
  Serial.println("Temperature = ");
  Serial.println(DHT.temperature);

  delay(1000);

}