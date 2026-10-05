/*
 * Footstep Power Generation & Energy Harvesting System
 * Controller: Arduino Nano
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int piezoPin = A0;      // Analog input from piezo bridge & capacitor filter
const int ledPin = 13;        // Status LED / Transistor control output

int stepCount = 0;            
float voltage = 0.0;          
const float threshold = 0.2;  // Voltage detection threshold in Volts

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("FOOTSTEP POWER");
  lcd.setCursor(0, 1);
  lcd.print("GENERATOR MODEL");
  delay(2000);
  lcd.clear();
}

void loop() {
  int rawValue = analogRead(piezoPin);
  voltage = (rawValue * 5.0) / 1023.0;

  if (voltage > threshold) { 
    stepCount++;
    
    digitalWrite(ledPin, HIGH);
    delay(150);
    digitalWrite(ledPin, LOW);

    lcd.setCursor(0, 0);
    lcd.print("Steps: ");
    lcd.print(stepCount);
    lcd.print("    ");

    lcd.setCursor(0, 1);
    lcd.print("Volt: ");
    lcd.print(voltage, 2);
    lcd.print("V   ");

    delay(300); 
  }
}
