int readPin = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int conductivity = analogRead(readPin);
  //Serial.println(conductivity);

  if(conductivity < 800) {
    digitalWrite(13, HIGH);
    Serial.println("FEED ME!");
  } else {
    digitalWrite(13, LOW);
  }
}
