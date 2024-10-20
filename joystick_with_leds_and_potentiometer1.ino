// Define pins for the potentiometers
int xAxisPin = A0;
int yAxisPin = A1;

// Define pins for LEDs
int ledUp = 2;
int ledDown = 3;
int ledLeft = 4;
int ledRight = 5;
int ledUpRight = 6;
int ledUpLeft = 7;
int ledDownRight = 8;
int ledDownLeft = 9;

void setup() {
  // Set LED pins as OUTPUT
  pinMode(ledUp, OUTPUT);
  pinMode(ledDown, OUTPUT);
  pinMode(ledLeft, OUTPUT);
  pinMode(ledRight, OUTPUT);
  pinMode(ledUpRight, OUTPUT);
  pinMode(ledUpLeft, OUTPUT);
  pinMode(ledDownRight, OUTPUT);
  pinMode(ledDownLeft, OUTPUT);

  Serial.begin(9600);  // For debugging if needed
}

void loop() {
  int xValue = analogRead(xAxisPin);  // Read X-axis value
  int yValue = analogRead(yAxisPin);  // Read Y-axis value

  // Map potentiometer values (0-1023) to a simpler range (-1, 0, 1)
  int xMapped = map(xValue, 0, 1023, -1, 1);
  int yMapped = map(yValue, 0, 1023, -1, 1);

  // Turn off all LEDs initially
  turnOffAllLeds();

  // Check joystick position and light up corresponding LEDs
  if (xMapped == 0 && yMapped == 1) {
    digitalWrite(ledUp, HIGH);  // Up
  }
  else if (xMapped == 0 && yMapped == -1) {
    digitalWrite(ledDown, HIGH);  // Down
  }
  else if (xMapped == -1 && yMapped == 0) {
    digitalWrite(ledLeft, HIGH);  // Left
  }
  else if (xMapped == 1 && yMapped == 0) {
    digitalWrite(ledRight, HIGH);  // Right
  }
  else if (xMapped == 1 && yMapped == 1) {
    digitalWrite(ledUpRight, HIGH);  // Up-Right
  }
  else if (xMapped == -1 && yMapped == 1) {
    digitalWrite(ledUpLeft, HIGH);  // Up-Left
  }
  else if (xMapped == 1 && yMapped == -1) {
    digitalWrite(ledDownRight, HIGH);  // Down-Right
  }
  else if (xMapped == -1 && yMapped == -1) {
    digitalWrite(ledDownLeft, HIGH);  // Down-Left
  }

  // Short delay for stability
  delay(100);
}

// Function to turn off all LEDs
void turnOffAllLeds() {
  digitalWrite(ledUp, LOW);
  digitalWrite(ledDown, LOW);
  digitalWrite(ledLeft, LOW);
  digitalWrite(ledRight, LOW);
  digitalWrite(ledUpRight, LOW);
  digitalWrite(ledUpLeft, LOW);
  digitalWrite(ledDownRight, LOW);
  digitalWrite(ledDownLeft, LOW);
}
