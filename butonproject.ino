#define YELLOWLED 7
#define REDLED 6
#define GREENLED 5
#define YELLOWLED2 8
#define BUTTON1 9
#define BUTTON2 10
int read1 = 0;
int read2 = 0;

void setup() {

  pinMode(YELLOWLED, OUTPUT);
  pinMode(REDLED, OUTPUT);
  pinMode(GREENLED, OUTPUT);
  pinMode(YELLOWLED2, OUTPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
}

void loop() {

  read1 = digitalRead(BUTTON1);
  read2 = digitalRead(BUTTON2);

  if (read1 == 1) { button1_func(read1); }

  if (read2 == 1) { button2_func(read2); }
}

void button1_func(int read) {

  while (read1 == 1) {

    digitalWrite(YELLOWLED, HIGH);
    digitalWrite(REDLED, HIGH);
    digitalWrite(GREENLED, HIGH);
    digitalWrite(YELLOWLED2, HIGH);
    read1 = digitalRead(BUTTON1);
  }

  digitalWrite(YELLOWLED, LOW);
  digitalWrite(REDLED, LOW);
  digitalWrite(GREENLED, LOW);
  digitalWrite(YELLOWLED2, LOW);
}

void button2_func(int read) {
  delay(500);
  read2 = digitalRead(BUTTON2);
  while (read2 == 0) {
    digitalWrite(YELLOWLED, HIGH);
    digitalWrite(REDLED, HIGH);
    digitalWrite(GREENLED, HIGH);
    digitalWrite(YELLOWLED2, HIGH);
    read2 = digitalRead(BUTTON2);
    delay(250);
    if (read2 == 1) {
      digitalWrite(YELLOWLED, LOW);
      digitalWrite(REDLED, LOW);
      digitalWrite(GREENLED, LOW);
      digitalWrite(YELLOWLED2, LOW);
      break;
    }
  }
}