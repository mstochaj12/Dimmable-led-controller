// Pin configuration
int whiteLedPin = 3;
int blueLedPin = 5;
int potentiometerPin = A4;
int buttonPin = 9;

// Variables for potentiometer and brightness
int potValue;       // Raw value from potentiometer (0-1023)
int brightness;     // Mapped brightness value (0-255)

// Button handling (edge detection)
bool buttonState;                       // Current state of the button
bool ledEnabled = false;                // Whether LEDs are ON or OFF
bool previousButtonState = HIGH;        // Previous button state (for the edge detection)

// Store last printed brightness to avoid spamming Serial Monitor
int previousBrightness = -1;

void setup() {
  Serial.begin(9600);

  // Set up pin modes
  pinMode(whiteLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(potentiometerPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);   // Internal pull-up resistor
}

void loop() {
  // Read potentiometer and map to brightness (0-255)
  potValue = analogRead(potentiometerPin);
  brightness = map(potValue, 0, 1023, 0, 255);

  // Detect button press (tansition from HIGH to LOW)
  buttonState = digitalRead(buttonPin);
  if (previousButtonState == HIGH && buttonState == LOW) {
  ledEnabled = !ledEnabled;       // Toggle LED state
  }

  // Update previous button state
  previousButtonState = buttonState;

  // If LEDs are enabled
  if (ledEnabled) {

    // Set LED brightness using PWM
    analogWrite(whiteLedPin, brightness);
    analogWrite(blueLedPin, brightness);

    // Print brightness only if it changed
    if (previousBrightness != brightness) {

      Serial.print("Brightness: ");
      Serial.println(brightness);
      previousBrightness = brightness;
    }
  } else {

    // Turn off LEDs
    analogWrite(whiteLedPin, 0);
    analogWrite(blueLedPin, 0);

    // Print 0 only once when LEDs turn off
    if(previousBrightness != 0) {
      Serial.println("Brightness: 0");
      previousBrightness = 0;
    }
  }
}
