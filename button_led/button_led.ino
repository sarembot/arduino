// Light Switcher Onner/Offer
// Author: Mitchell Saremba

// This is a program that allows someone to click a physical button to toggle an LED light. I wrote the program in conjunction with a simple circuit that I prototyped with a breadboard. It reads input from the button, and sends output to the LED. 

const int LED = 9;
const int BUTTON = 2;
int prevState = LOW; // store previous / current button state to debug bouncing voltage
int currentState = LOW;
bool ledOn = false; // keep track of LED state for toggle

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT); // default

  Serial.begin(9600);
}

void loop() {
  currentState = debounce(prevState);
  if (prevState == LOW && currentState == HIGH) ledOn = !ledOn;
  prevState = currentState;
  digitalWrite(LED, ledOn);
}

// for debugging bouncing voltage in button
bool debounce (bool prev) {
  bool current = digitalRead(BUTTON);
    if (prev != current) {
      delay(5);
      current = digitalRead(BUTTON);
    } 
    return current;
}

void toggleLed() {
  if (ledOn) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
