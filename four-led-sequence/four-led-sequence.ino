int red = 3;
int blue = 9;
int yellow = 5;
int green = 10;
int delayPeriod = 15;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  }

void brighten(int colour, int step) {
  for (int i = 0; i < 125; i+=step) {
      analogWrite(colour, i);
      delay(delayPeriod);
    }
}

void dampen(int colour, int step) {
  for (int i = 125; i >= 0; i -=step){
      analogWrite(colour, i);
      delay(delayPeriod);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  brighten(red, 5);
  dampen(red, 5);
  brighten(blue, 5);
  dampen(blue, 5);
  brighten(yellow, 5);
  dampen(yellow, 5);
  brighten(green, 5);
  dampen(green, 5);
  
  brighten(yellow, 5);
  dampen(yellow, 5);
  brighten(blue, 5);
  dampen(blue, 5);
}
