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
  
  // Test eerste meting
  float testHumidity = dht.readHumidity();
  float testTemp = dht.readTemperature();
  
  if (isnan(testHumidity) || isnan(testTemp)) {
    Serial.println("ERROR: Sensor not responding properly!");
    Serial.println("Please check:");
    Serial.println("1. Sensor connections (VCC, DATA, GND)");
    Serial.println("2. 10kΩ pull-up resistor between VCC and DATA");
    Serial.println("3. Power supply (should be 5V)");
  } else {
    Serial.println("Sensor initialized successfully!");
  }
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Meet en toon waarden op interval
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    // Lees sensor
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();
    
    // Debug informatie
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