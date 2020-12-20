int readPin = A0;
int fedFlag = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

//This function check if the fedFlag is checked and if so returns 0, if not then 1
int fedPrint(int currentResult) {
  if(fedFlag == 0 && currentResult == 1) {
    fedFlag = 1;
    return 1;
  } else if(fedFlag == 1) {
    return 0;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int conductivity = analogRead(readPin);
  //Serial.println(conductivity);

  if(conductivity < 200) {
    digitalWrite(13, LOW);
    delay(200);
    digitalWrite(13, HIGH);
    delay(200);
    fedFlag = 0;
    Serial.println("PLEASE!! FEED ME!");
  } else if(conductivity < 800) {
    digitalWrite(13, HIGH);
    Serial.println("FEED ME!");
    fedFlag = 0;
  } else {
    digitalWrite(13, LOW);
    if(fedPrint(1)) { // Prints message only once when change occurs
      Serial.println("Thank you, Seymour!");
    }
  }
}
