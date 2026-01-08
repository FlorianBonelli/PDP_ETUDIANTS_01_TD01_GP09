#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// Define the pins that we will use
#define CAPTEUR 33
#define LED 26

// Define the DHT sensor type and pin
#define DHTTYPE DHT11
DHT dht(CAPTEUR, DHTTYPE);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize the DHT sensor
  dht.begin();

  // Set up the LED pin
  pinMode(LED, OUTPUT);
}

void loop() {
  // Wait 5 seconds between measurements
  delay(5000);

  // Read humidity
  float humidity = dht.readHumidity();

  // Read temperature as Celsius
  float temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again next loop)
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print the results to the Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
}