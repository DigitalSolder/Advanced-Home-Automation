#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <DHT.h>
#include <RTClib.h>
#include <EEPROM.h>

// Pin Definitions
#define DHTPIN 15
#define DHTTYPE DHT22
#define PIRPIN 4
#define LDR_AO 34
#define LDR_DO 32
#define RELAY_LIGHT 26
#define RELAY_FAN 27
#define STATUS_LED 2  // New LED indicator pin

// EEPROM addresses
#define TEMP_THRESHOLD_ADDR 0
#define LIGHT_THRESHOLD_ADDR 10

// Object instances
DHT dht(DHTPIN, DHTTYPE);
RTC_DS1307 rtc;
Adafruit_SSD1306 display(128, 64, &Wire, -1);

// Threshold defaults
float TEMP_THRESHOLD = 30.0;
int LIGHT_THRESHOLD = 500;

void setup() {
  Serial.begin(115200);
  dht.begin();
  Wire.begin(21, 22);
  EEPROM.begin(64);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
  }
  display.clearDisplay();
  display.display();

  if (!rtc.begin()) {
    Serial.println("RTC not found!");
    while (1);
  }
  if (!rtc.isrunning()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  pinMode(PIRPIN, INPUT);
  pinMode(LDR_DO, INPUT);
  pinMode(RELAY_LIGHT, OUTPUT);
  pinMode(RELAY_FAN, OUTPUT);
  pinMode(STATUS_LED, OUTPUT);

  EEPROM.get(TEMP_THRESHOLD_ADDR, TEMP_THRESHOLD);
  EEPROM.get(LIGHT_THRESHOLD_ADDR, LIGHT_THRESHOLD);
  if (isnan(TEMP_THRESHOLD) || TEMP_THRESHOLD < 10 || TEMP_THRESHOLD > 50) TEMP_THRESHOLD = 30.0;
  if (LIGHT_THRESHOLD < 100 || LIGHT_THRESHOLD > 2000) LIGHT_THRESHOLD = 500;

  Serial.println("System Initialized");
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  int ldrAnalog = analogRead(LDR_AO);
  int ldrDigital = digitalRead(LDR_DO);
  int motion = digitalRead(PIRPIN);
  delay(100);
  DateTime now = rtc.now();

  Serial.printf("[%02d:%02d] Temp: %.1f C, Hum: %.1f%%, LDR: %d, Motion: %d\n",
                now.hour(), now.minute(), temperature, humidity, ldrAnalog, motion);

  if (ldrAnalog < LIGHT_THRESHOLD && motion == HIGH) {
    digitalWrite(RELAY_LIGHT, HIGH);
  } else {
    digitalWrite(RELAY_LIGHT, LOW);
  }

  if (temperature > TEMP_THRESHOLD && motion == HIGH) {
    digitalWrite(RELAY_FAN, HIGH);
  } else {
    digitalWrite(RELAY_FAN, LOW);
  }

  // New: LED indicator based on LDR DO digital output
  if (ldrDigital == LOW) {
    digitalWrite(STATUS_LED, HIGH); // LED ON if light intensity below preset threshold (via DO comparator)
  } else {
    digitalWrite(STATUS_LED, LOW); // LED OFF if sufficient light
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.printf("Time: %02d:%02d\n", now.hour(), now.minute());
  display.printf("Temp: %.1fC Hum: %.1f%%\n", temperature, humidity);
  display.printf("LDR (AO): %d\n", ldrAnalog);
  display.printf("LDR (DO): %d\n", ldrDigital);
  display.printf("Motion: %d\n", motion);
  display.display();

  updateThresholds();
  delay(2000);
}

void updateThresholds() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    if (input.startsWith("TEMP:")) {
      float newTemp = input.substring(5).toFloat();
      if (newTemp >= 10 && newTemp <= 50) {
        if (TEMP_THRESHOLD != newTemp) {
          TEMP_THRESHOLD = newTemp;
          EEPROM.put(TEMP_THRESHOLD_ADDR, TEMP_THRESHOLD);
          EEPROM.commit();
        }
        Serial.printf("Updated TEMP_THRESHOLD to %.1f\n", TEMP_THRESHOLD);
      }
    } else if (input.startsWith("LIGHT:")) {
      int newLight = input.substring(6).toInt();
      if (newLight >= 100 && newLight <= 2000) {
        if (LIGHT_THRESHOLD != newLight) {
          LIGHT_THRESHOLD = newLight;
          EEPROM.put(LIGHT_THRESHOLD_ADDR, LIGHT_THRESHOLD);
          EEPROM.commit();
        }
        Serial.printf("Updated LIGHT_THRESHOLD to %d\n", LIGHT_THRESHOLD);
      }
    }
  }
}
