#define ADC_VREF_mV    3100.0 
#define ADC_RESOLUTION 4096.0
#define PIN_LM35       35 


#include <WiFi.h>
#include <String.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"


#define WLAN_SSID       "POCOM2"      
#define WLAN_PASS       "computer"      

#define AIO_SERVER      "io.adafruit.com" 
#define AIO_SERVERPORT   1883           
       
#define IO_USERNAME  "SrujanS"
#define IO_KEY       "aio_BjuV97X4tBatwk8IBdaoP0JE8m7m"



WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, IO_USERNAME, IO_KEY);
Adafruit_MQTT_Publish temp = Adafruit_MQTT_Publish(&mqtt, IO_USERNAME "/feeds/temperature");

void wifiConnect() {
    Serial.println(F("Adafruit MQTT demo"));
    Serial.println(); Serial.println();
    Serial.print("Connecting to ");
    Serial.println(WLAN_SSID);
    WiFi.begin(WLAN_SSID, WLAN_PASS);
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("IP address: "); 
  Serial.println(WiFi.localIP());
  delay(3000);
}


int inHeat = 32;
int inCold = 33;

int buzzer = 18;
int fan = 19;
int led = 2;

float tempC = 0;

void setup() {
  
  Serial.begin(9600);
  pinMode(inHeat,OUTPUT);
  pinMode(inCold,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(fan,OUTPUT);
  pinMode(led,OUTPUT);
  initialize();
  wifiConnect();
  
}

void initialize()
{
  digitalWrite(inHeat,LOW);
  digitalWrite(inCold,LOW);
  digitalWrite(buzzer,LOW);
  digitalWrite(fan,LOW);
  digitalWrite(led,LOW);  
}

void ReadTemperature()
{
  int adcVal = analogRead(PIN_LM35);
  float milliVolt = adcVal * (ADC_VREF_mV / ADC_RESOLUTION);
  tempC = milliVolt / 8;
  float tempF = tempC * 9 / 5 + 32;
  Serial.print("Temperature: ");
  Serial.print(tempC);   
  Serial.print("°C");
  Serial.print("  ~  "); 
  Serial.print(tempF);   
  Serial.println("°F");
  temp.publish(tempC);
  delay(2000);
}

void operation()
{
  if ( tempC > 28 )
  {
    digitalWrite(fan,HIGH);
    digitalWrite(inHeat,LOW);
    digitalWrite(inCold,HIGH);
    digitalWrite(buzzer,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
    digitalWrite(led,LOW);
  }
  else if ( tempC < 15 )
  {
    digitalWrite(fan,HIGH);
    digitalWrite(inHeat,HIGH);
    digitalWrite(inCold,LOW);
    digitalWrite(buzzer,LOW);
    digitalWrite(led,LOW);

  }
  else if ( 15 > tempC < 28 )
  {
    digitalWrite(fan,LOW);
    digitalWrite(inHeat,LOW);
    digitalWrite(inCold,LOW);
    digitalWrite(buzzer,LOW);
    digitalWrite(led,HIGH);
    
  }
}

void loop() {
  MQTT_connect();
  ReadTemperature(); 
  operation();
}

void MQTT_connect() {
  
  int8_t ret;
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { 
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying MQTT connection in 5 seconds...");
    mqtt.disconnect();
    delay(5000);  
    retries--;
    if (retries == 0) {
      while (1);
    }
  }
  Serial.println("MQTT Connected!");
}
