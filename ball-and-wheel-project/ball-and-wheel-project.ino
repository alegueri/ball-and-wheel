const byte encoderA = 2;  // input pin that the interruption will be attached to
const byte encoderB = 7;  // input pin that the interruption will be attached to

static uint8_t prevA = 0;
static uint8_t currentA = 0;
static uint8_t currentB = 0;

static uint8_t prevDir = 2;
static uint8_t direction = 2; // 0 -> Clockwise 1 -> CC
volatile long count = 0;
// long lastPrintCount = 0;

void setup() {
  Serial.begin(115200);
  pinMode(encoderA, INPUT_PULLUP);
  pinMode(encoderB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderA), checkState, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderB), checkState, CHANGE);
}

void loop() {
  if (prevDir != direction){
    prevDir = direction;
    if (direction == 0){
      Serial.println("Clockwise");
    }else{
      Serial.println("Counter clockwise");
    }
  }

}

void checkState() {
  currentA = digitalRead(encoderA);
  currentB = digitalRead(encoderB);
  if (currentA == 0){
    if (prevA == 0){
      if (currentB == 1){
        direction = 0;
        
      } else{
        direction = 1;
      }
    }
    if (prevA == 1){
      if (currentB == 0){
        direction=0;
      } else{
        direction=1;
      }
    }
  }
  
  if(currentA == 1) {
    if (prevA == 1){
      if (currentB == 0){
        direction=0;
      }else{
        direction=1;
      }
    }
    if (prevA == 0){
      if (currentB == 1){
        direction=0;
      }else{
        direction=1;
      }
    }
  }

  prevA = currentA;
  count++;
}