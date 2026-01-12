const byte encoderA = 2;  // input pin that the interruption will be attached to
const byte encoderB = 7;  // input pin that the interruption will be attached to

static uint8_t prevA = 0;
static uint8_t currentA = 0;
static uint8_t currentB = 0;

void setup() {
  Serial.begin(115200);
  pinMode(encoderA, INPUT);
  pinMode(encoderB, INPUT);
  attachInterrupt(digitalPinToInterrupt(encoderA), checkState, CHANGE);
  // attachInterrupt(digitalPinToInterrupt(encoderB), checkState, CHANGE);
}

void loop() {

}

void checkState() {
  currentA = digitalRead(encoderA);
  currentB = digitalRead(encoderB);
  if (currentA == 0){
    if (prevA == 0){
      if (currentB == 1){
        Serial.println("Clockwise");
      } else{
        Serial.println("Counter clockwise");
      }
    }
    if (prevA == 1){
      if (currentB == 0){
        Serial.println("Clockwise");
      } else{
        Serial.println("Counter clockwise");
      }
    }
  }
  
  if(currentA == 1) {
    if (prevA == 1){
      if (currentB == 0){
        Serial.println("Clockwise");
      }else{
        Serial.println("Counter clockwise");
      }
    }
    if (prevA == 0){
      if (currentB == 1){
        Serial.println("Clockwise");
      }else{
        Serial.println("Counter clockwise");
      }
    }
  }

  prevA = currentA;
}