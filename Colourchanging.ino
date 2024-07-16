/*
  ———————————————————————————————————————————
  Programmer: Niyati Sharma
  Date: 8 Sept 2023
  ———————————————————————————————————————————
  Program: A toggle button that will turn a light on and off
  ———————————————————————————————————————————
  Description: When the button (acting as a toggle)
  will be clicked, the state of the LED will change.
  ———————————————————————————————————————————
  Connections: Pins 12, 11, 10, 9, 8, 6, 5
  ———————————————————————————————————————————
*/

//-----------------------------------------------------------------
// Global area - Everything in this section applies to all functions
//-----------------------------------------------------------------

int ledNum = 3; // Number of RGB LEDs
int potPin = A0;
int ledColors[3][3]; // Store the current color of each LED

int rgbPins[][3] = {
  {4, 5, 6},
  {7, 8, 9},
  {10, 11, 12}

};

//-----------------------------------------------------------------
// Setup area - All code in this section runs once
//-----------------------------------------------------------------

void setup() {
  // Initialize RGB pins as outputs
  for (int i = 0; i < ledNum; i++) {
    for (int n = 0; n < 3; n++) {
      pinMode(rgbPins[i][n], OUTPUT);
    }
  }

  // Initialize LED colors with random values
  for (int i = 0; i < ledNum; i++) {
    for (int n = 0; n < 3; n++) {
      ledColors[i][n] = random(256);
    }
    newLEDColour(i);
  }
}

//-----------------------------------------------------------------
// Loop area - All code in this section runs repeatedly
//-----------------------------------------------------------------

void loop() {
  // Read the potentiometer value
  int potValue = analogRead(potPin);

  // Update the colors of all LEDs based on the potentiometer value
  for (int i = 0; i < ledNum; i++) {
    for (int n = 0; n < 3; n++) {
      ledColors[i][n] = map(potValue, 0, 1023, 0, 256);
    }
    newLEDColour(i);
  }

  // Delay for a short time to avoid rapid updates
  delay(50);
}

//-----------------------------------------------------------------
// newLEDColour - All code in this section runs repeatedly
//-----------------------------------------------------------------

void newLEDColour(int ledIndex) {
  // Set the RGB LED to the current color
  analogWrite(rgbPins[ledIndex][0], ledColors[ledIndex][0]);
  analogWrite(rgbPins[ledIndex][1], ledColors[ledIndex][1]);
  analogWrite(rgbPins[ledIndex][2], ledColors[ledIndex][2]);
}
