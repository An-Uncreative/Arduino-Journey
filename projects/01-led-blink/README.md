# Project 01: LED Blink 💡

## Overview
This is the classic "Hello World" project for Arduino. We'll make the built-in LED blink on and off repeatedly. This project teaches the fundamentals of digital output and timing in Arduino programming.

## What You'll Learn
- Basic Arduino sketch structure (`setup()` and `loop()`)
- Digital output using `digitalWrite()`
- Using delays with `delay()`
- Pin configuration with `pinMode()`
- Serial communication for debugging

## Components Required
- Arduino Uno/Nano (or compatible)
- USB cable
- No additional components needed (uses built-in LED)

## Circuit Diagram
```
Arduino Uno
┌─────────────┐
│             │
│         D13 ●───── Built-in LED
│             │
│             │
│         GND ●
│             │
└─────────────┘
```

## Code Explanation

### Setup Function
```cpp
void setup() {
  pinMode(LED_PIN, OUTPUT);  // Configure pin 13 as output
  Serial.begin(9600);        // Start serial communication
}
```
- `pinMode()` configures the pin mode (INPUT or OUTPUT)
- `Serial.begin()` initializes serial communication for debugging

### Loop Function
```cpp
void loop() {
  digitalWrite(LED_PIN, HIGH);  // Turn LED on
  delay(1000);                  // Wait 1 second
  digitalWrite(LED_PIN, LOW);   // Turn LED off
  delay(1000);                  // Wait 1 second
}
```
- `digitalWrite()` sets the pin to HIGH (5V) or LOW (0V)
- `delay()` pauses execution for specified milliseconds

## Upload Instructions
1. Connect your Arduino to your computer via USB
2. Open Arduino IDE
3. Select your board: Tools → Board → Arduino Uno
4. Select the correct port: Tools → Port → (your Arduino port)
5. Open `led_blink.ino`
6. Click the Upload button (→)

## Expected Behavior
- The built-in LED (usually near pin 13) will blink on and off
- Each state (on/off) lasts for 1 second
- Serial monitor will show "LED ON" and "LED OFF" messages

## Troubleshooting
- **LED not blinking**: Check if the correct board and port are selected
- **Upload error**: Ensure Arduino is properly connected and drivers are installed
- **No serial output**: Make sure serial monitor is set to 9600 baud rate

## Variations to Try
1. **Change timing**: Modify `delay(1000)` to different values
2. **External LED**: Connect an LED to a different pin with a 220Ω resistor
3. **Multiple LEDs**: Control several LEDs with different timing patterns
4. **Fade effect**: Use `analogWrite()` instead of `digitalWrite()` for PWM

## Next Steps
After mastering this project, move on to:
- [Project 02: Button Input](../02-button-input/) - Learn to read digital inputs
- Add external components and sensors