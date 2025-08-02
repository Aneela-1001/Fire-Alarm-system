const int mq2Pin     = A0;  
const int buzzerPin  = 8;   
const int redLedPin  = 9;    
const int greenLedPin = 10; 
const int powerSwitchPin = 2;  
const int testSwitchPin  = 3;   
const int resetSwitchPin = 4;  
const int smokeThreshold = 400;
bool alarmTriggered = false;
bool systemPowered = false;
void setup() {
  pinMode(mq2Pin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(powerSwitchPin, INPUT_PULLUP);
  pinMode(testSwitchPin, INPUT_PULLUP);
  pinMode(resetSwitchPin, INPUT_PULLUP);
  Serial.begin(9600);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
}
void loop() {
  bool powerSwitchState = digitalRead(powerSwitchPin) == LOW;
  bool testSwitchState  = digitalRead(testSwitchPin)  == LOW;
  bool resetSwitchState = digitalRead(resetSwitchPin) == LOW;
  if (powerSwitchState) {
    systemPowered = !systemPowered;
    delay(500); // debounce
  }
  if (!systemPowered) {
    turnOffSystem();
    return;
  }
  int smokeLevel = analogRead(mq2Pin);
  Serial.print("Smoke level: ");
  Serial.println(smokeLevel);
  if (smokeLevel > smokeThreshold || testSwitchState) {
    triggerAlarm();
  }
  if (resetSwitchState) {
    resetAlarm();
  }
  delay(200);
}
void triggerAlarm() {
  alarmTriggered = true;
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(redLedPin, HIGH);
  digitalWrite(greenLedPin, LOW);
}
void resetAlarm() {
  alarmTriggered = false;
  digitalWrite(buzzerPin, LOW);
  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, HIGH);
}
void turnOffSystem() {
  alarmTriggered = false;
  digitalWrite(buzzerPin, LOW);
  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
}
