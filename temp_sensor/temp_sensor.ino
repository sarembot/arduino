// SIMPLE TEMPERATURE SENSOR - By Mitchell Saremba
// Uses a thermistor and voltage divider to detect the temperature in the room, and displays a colour on an RGB LED based on current temp.

const int RED = 11;
const int GREEN = 10;
const int BLUE = 9;

const int THERMISTOR = 0;
int val = 0; // to hold the changing value

void setup() {
  // put your s, aetup code here, to run once:
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(THERMISTOR);
  Serial.println(val);
  delay(500);

  if (val == 460) { // temp is normal - green
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, LOW);
  } else if (val < 460) { // temp is low - blue
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, HIGH);
  } else if (val > 460) { // temp is high - red
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
}
}
