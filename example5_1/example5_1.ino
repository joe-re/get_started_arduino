const int LED = 9;
const int BUTTON = 7;

int i = 0;
int val = 0;
int old_val = 0;
int state = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  val = digitalRead(BUTTON);

  if ((val == HIGH) && (old_val == LOW)) {
    state = 1 - state;
    delay(10);
  }
  old_val = val;
  
  if (state == 1) {
    for (i = 0; i < 255; i++) {
      analogWrite(LED, i);
      delay(10);
    }
    for (i = 255; i > 0; i--) {
      analogWrite(LED, i);
      delay(10);
    }
  } else {
    digitalWrite(LED, LOW);
  }
}
