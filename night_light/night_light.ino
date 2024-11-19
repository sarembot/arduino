// Night Light - A simple program that cycles through colors on button presses. Uses an RGB LED. 

// From Chapter 2 of Exploring Arduino by Jeremy Blum.
// Author: Mitchell Saremba

const int BLUE = 9;
const int GREEN = 10;
const int RED = 11;
const int BUTTON = 2;

int ledMode = 0;

int currentState = LOW;
int prevState = LOW;


void setup() {
  // put your setup code here, to run once:
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

// for debugging bouncing voltage in button
bool debounce (bool prev) {
  bool current = digitalRead(BUTTON);
  if (prev != current) { // if btn bounces check again
    delay(5);
    current = digitalRead(BUTTON);
  } 
  return current;
}

void setMode(int mode) {
  // RED
  if (mode == 1) {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
  }
  // GREEN
  else if (mode == 2) {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, LOW);
  }
  // BLUE
  else if (mode == 3) {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, HIGH);
  }
  //PURPLE (RED+BLUE)
  else if (mode == 4) {
    analogWrite(RED, 127);
    analogWrite(GREEN, 0);
    analogWrite(BLUE, 127);
  }
  //TEAL (BLUE+GREEN)
  else if (mode == 5) {
    analogWrite(RED, 0);
    analogWrite(GREEN, 127);
    analogWrite(BLUE, 127);
  }
  //ORANGE (GREEN+RED)
  else if (mode == 6) {
    analogWrite(RED, 127);
    analogWrite(GREEN, 127);
    analogWrite(BLUE, 0);
  }
  //WHITE (GREEN+RED+BLUE)
  else if (mode == 7) {
    analogWrite(RED, 85);
    analogWrite(GREEN, 85);
    analogWrite(BLUE, 85);
  }
  //OFF (mode = 0)
  else {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
  }
}

void loop() {
  currentState = debounce(BUTTON);
  if (prevState == LOW && currentState == HIGH) { // if button clicked
    ledMode += 1;
  }
  prevState = currentState;
  if (ledMode == 8) ledMode = 0; // reset at end of cycle
  setMode(ledMode);
}

