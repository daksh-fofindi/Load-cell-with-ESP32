#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "HX711.h"

// HX711 Pins
#define DT 34
#define SCK 18

// ESP32 inbuilt LED
#define LED_PIN 2

HX711 scale;

// LCD Address
LiquidCrystal_I2C lcd(0x27, 16, 2);

// CHANGE THIS AFTER CALIBRATION
float calibration_factor = -1000.0;

unsigned long previousMillis = 0;
bool ledState = false;

void setup() {

  Serial.begin(115200);

  // LED setup
  pinMode(LED_PIN, OUTPUT);

  // LCD setup
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Weighing Scale");

  // HX711 setup
  scale.begin(DT, SCK);

  delay(500);

  // Reset scale
  scale.set_scale();
  scale.tare();

  lcd.setCursor(0,1);
  lcd.print("Tare Done");

  delay(1500);

  lcd.clear();
}

void loop() {

  // AIRPLANE STYLE DOUBLE BLINK
  unsigned long currentMillis = millis();

  static int blinkStep = 0;

  if(blinkStep == 0 && currentMillis - previousMillis >= 1200) {
    digitalWrite(LED_PIN, HIGH);
    previousMillis = currentMillis;
    blinkStep = 1;
  }

  else if(blinkStep == 1 && currentMillis - previousMillis >= 80) {
    digitalWrite(LED_PIN, LOW);
    previousMillis = currentMillis;
    blinkStep = 2;
  }

  else if(blinkStep == 2 && currentMillis - previousMillis >= 120) {
    digitalWrite(LED_PIN, HIGH);
    previousMillis = currentMillis;
    blinkStep = 3;
  }

  else if(blinkStep == 3 && currentMillis - previousMillis >= 80) {
    digitalWrite(LED_PIN, LOW);
    previousMillis = currentMillis;
    blinkStep = 0;
  }

  // Read weight
  float weight = scale.get_units(1);

  // Remove negative noise
  if(weight < 0)
    weight = 0;

  // Serial Monitor
  Serial.print("Weight: ");
  Serial.print(weight, 1);
  Serial.println(" g");

  // LCD Display
  lcd.setCursor(0,0);
  lcd.print("Weight:");

  lcd.setCursor(0,1);
  lcd.print(weight,1);
  lcd.print(" g      ");

  delay(500);
}