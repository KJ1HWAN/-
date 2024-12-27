const int ldrPin = A0;
const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

float colorPhase = 0;
float phaseIncrement = 0.05;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);

  int baseBrightness = map(ldrValue, 0, 1000, 1, 255);
  baseBrightness = constrain(baseBrightness, 1, 255);

  int redValue = baseBrightness * (sin(colorPhase) * 0.5 + 0.5);
  int greenValue = baseBrightness * (sin(colorPhase + 2.0) * 0.5 + 0.5);
  int blueValue = baseBrightness * (sin(colorPhase + 4.0) * 0.5 + 0.5);

  analogWrite(redPin, 255 - redValue);
  analogWrite(greenPin, 255 - greenValue);
  analogWrite(bluePin, 255 - blueValue);

  Serial.print("LDR Value: ");
  Serial.print(ldrValue);
  Serial.print(" | Base Brightness: ");
  Serial.print(baseBrightness);
  Serial.print(" | R: ");
  Serial.print(255 - redValue);
  Serial.print(" G: ");
  Serial.print(255 - greenValue);
  Serial.print(" B: ");
  Serial.println(255 - blueValue);

  colorPhase += phaseIncrement;
  if (colorPhase >= 6.28) {
    colorPhase = 0;
  }

  delay(100); 
}
