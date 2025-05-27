#include "DHT.h"

// Pin definities
#define DHTPIN 2          // DHT11 sensor pin
#define DHTTYPE DHT11     // DHT type

// Variabelen
DHT dht(DHTPIN, DHTTYPE);
unsigned long previousMillis = 0;
const long interval = 2000;  // Interval voor sensor metingen (2 seconden)

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 Test Start");
  Serial.println("Initializing sensor...");
  
  dht.begin();
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();
    
    Serial.println("-------------------");
    
    if (isnan(humidity) || isnan(temperature)) {
      Serial.println("ERROR: Failed to read sensor!");
      Serial.println("Please check connections and try again.");
    } else {
      Serial.print("Luchtvochtigheid: ");
      Serial.print(humidity);
      Serial.println("%");
      
      Serial.print("Temperatuur: ");
      Serial.print(temperature);
      Serial.println("°C");
    }
  }
} 