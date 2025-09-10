/*
  RGB LED Control - Arduino Journey Project 03
  
  This project demonstrates PWM (Pulse Width Modulation) by controlling
  an RGB LED to create different colors. The LED will cycle through
  various colors automatically, showcasing analog output capabilities.
  
  Circuit:
  - RGB LED (common cathode) connected to pins 9, 10, 11
  - 220Ω resistors for each color channel
  - Common cathode connected to GND
  
  Created: 2024
  By: Arduino Journey
*/

// Pin definitions for RGB LED
const int RED_PIN = 11;    // Red channel
const int GREEN_PIN = 10;  // Green channel  
const int BLUE_PIN = 9;    // Blue channel

// Variables for color cycling
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

void setup() {
  // Initialize PWM pins as outputs
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("RGB LED Control Project Started!");
  Serial.println("Watch the LED cycle through different colors");
}

void loop() {
  // Demonstrate different colors
  demonstrateBasicColors();
  
  // Smooth color transitions
  rainbowCycle();
}

void demonstrateBasicColors() {
  Serial.println("Demonstrating basic colors...");
  
  // Red
  setColor(255, 0, 0);
  Serial.println("Red");
  delay(1000);
  
  // Green
  setColor(0, 255, 0);
  Serial.println("Green");
  delay(1000);
  
  // Blue
  setColor(0, 0, 255);
  Serial.println("Blue");
  delay(1000);
  
  // Yellow (Red + Green)
  setColor(255, 255, 0);
  Serial.println("Yellow");
  delay(1000);
  
  // Cyan (Green + Blue)
  setColor(0, 255, 255);
  Serial.println("Cyan");
  delay(1000);
  
  // Magenta (Red + Blue)
  setColor(255, 0, 255);
  Serial.println("Magenta");
  delay(1000);
  
  // White (All colors)
  setColor(255, 255, 255);
  Serial.println("White");
  delay(1000);
  
  // Off
  setColor(0, 0, 0);
  Serial.println("Off");
  delay(1000);
}

void rainbowCycle() {
  Serial.println("Rainbow color cycle...");
  
  for (int i = 0; i < 256; i++) {
    // Create rainbow effect using sine waves
    redValue = (sin(i * 0.024) * 127) + 128;
    greenValue = (sin(i * 0.024 + 2.094) * 127) + 128;
    blueValue = (sin(i * 0.024 + 4.188) * 127) + 128;
    
    setColor(redValue, greenValue, blueValue);
    delay(20);
  }
}

// Function to set RGB LED color
void setColor(int red, int green, int blue) {
  // Constrain values to 0-255 range
  red = constrain(red, 0, 255);
  green = constrain(green, 0, 255);
  blue = constrain(blue, 0, 255);
  
  // Write PWM values to pins
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}