// SIMPLE LIGHT SENSOR - By Mitchell Saremba
// Uses a photoresistor and voltage divider to detect light, and displays a colour on an RGB LED based on current state of my room light.
// The lamp next to my desk has three states - off, half on, full on. So the loop conditions are set to coordinate with the ranges of values observed during each separate state 

const int RED = 11;
const int GREEN = 10;
const int BLUE = 9;

const int PHOTORESISTOR = 0;
int val = 0; // to hold the changing value
int firstVal;

void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(PHOTORESISTOR);
  Serial.println(val);
  delay(500);

  if (val < 100) {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
  } else if (val >= 100 && val < 200) {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, HIGH);
  } else if (val >= 200) {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, LOW);
  }
}
