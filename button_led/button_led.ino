const int LED = 9;
const int BUTTON = 2;
// store previous / current button state
int prevState = LOW;
int currentState = LOW;
// keep track of LED state
bool ledOn = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT); // default
}

void loop() {
  currentState = debounce(prevState);
  if (prevState == LOW && currentState == HIGH) ledOn != ledOn;
  prevState = currentState;
}

bool debounce (bool prev) {
  bool current = digitalRead(BUTTON);
  if (prev != current) {
    delay(5);
    current = digitalRead(BUTTON);
  } return current;
}
