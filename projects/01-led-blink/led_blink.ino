/*
  LED Blink - Arduino Journey Project 01
  
  This is the "Hello World" of Arduino programming.
  The built-in LED on pin 13 will blink on and off repeatedly.
  
  Circuit:
  - LED connected to digital pin 13 (built-in LED on most Arduino boards)
  - No external components needed for this basic version
  
  Created: 2024
  By: Arduino Journey
*/

// Pin definitions
const int LED_PIN = 13;  // Built-in LED pin on most Arduino boards

void setup() {
  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  
  // Initialize serial communication for debugging (optional)
  Serial.begin(9600);
  Serial.println("LED Blink Project Started!");
}

void loop() {
  // Turn the LED on
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED ON");
  
  // Wait for 1 second
  delay(1000);
  
  // Turn the LED off
  digitalWrite(LED_PIN, LOW);
  Serial.println("LED OFF");
  
  // Wait for 1 second
  delay(1000);
}