/*
  Button Input - Arduino Journey Project 02
  
  This project demonstrates how to read digital input from a push button.
  When the button is pressed, the LED turns on. When released, it turns off.
  This introduces concepts of digital input and pull-up resistors.
  
  Circuit:
  - LED connected to digital pin 13 (built-in LED)
  - Push button connected to digital pin 2
  - 10kΩ pull-up resistor from pin 2 to 5V (or use internal pull-up)
  
  Created: 2024
  By: Arduino Journey
*/

// Pin definitions
const int LED_PIN = 13;    // Built-in LED pin
const int BUTTON_PIN = 2;  // Button input pin

// Variables to store button state
int buttonState = 0;       // Current button state
int lastButtonState = 0;   // Previous button state
bool ledState = false;     // Current LED state (for toggle mode)

void setup() {
  // Initialize pins
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Use internal pull-up resistor
  
  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("Button Input Project Started!");
  Serial.println("Press the button to control the LED");
}

void loop() {
  // Read the button state
  buttonState = digitalRead(BUTTON_PIN);
  
  // Check if button state has changed
  if (buttonState != lastButtonState) {
    // Small delay to debounce the button
    delay(50);
    
    // Read the button state again
    buttonState = digitalRead(BUTTON_PIN);
    
    // If button is pressed (LOW because of pull-up resistor)
    if (buttonState == LOW) {
      // Toggle LED state
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
      
      // Print status to serial monitor
      if (ledState) {
        Serial.println("Button pressed - LED ON");
      } else {
        Serial.println("Button pressed - LED OFF");
      }
    }
  }
  
  // Save the current state as the last state for next time
  lastButtonState = buttonState;
}