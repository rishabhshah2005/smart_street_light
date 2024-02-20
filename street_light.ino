int led1 = 9;
int led2 = 10;
int led3 = 11;
int led4 = 12;
int led5 = 13;

int ir1 = 2;
int ir2 = 4;
int ir3 = 5;
int ir4 = 6;
int ir5 = 7;

int ldr = A5;

long cur_time;
const int interval = 5000;

long restime, res2time, res3time, res4time, res5time;

void setup() {
  // put your setup code here, to run once:
  // Serial.begin(9600);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);

  pinMode(ldr, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int res = digitalRead(ir1);
  int res2 = digitalRead(ir2);
  int res3 = digitalRead(ir3);
  int res4 = digitalRead(ir4);
  int res5 = digitalRead(ir5);

  int ldrres = analogRead(ldr);
  // Serial.println(ldrres);

  cur_time = millis();

  if (ldrres > 790) {

    if (res == LOW) {
      digitalWrite(led1, HIGH);
      restime = millis();
    }

    if (res2 == LOW) {
      digitalWrite(led2, HIGH);
      res2time = millis();
    }

    if (res3 == LOW) {
      digitalWrite(led3, HIGH);
      res3time = millis();
    }

    if (res4 == LOW) {
      digitalWrite(led4, HIGH);
      res4time = millis();
    }

    if (res5 == LOW) {
      digitalWrite(led5, HIGH);
      res5time = millis();
    }

    if (cur_time-restime>interval){
      digitalWrite(led1, LOW);
    }
    if (cur_time-res2time>interval){
      digitalWrite(led2, LOW);
    }
    if (cur_time-res3time>interval){
      digitalWrite(led3, LOW);
    }
    if (cur_time-res4time>interval){
      digitalWrite(led4, LOW);
    }
    if (cur_time-res5time>interval){
      digitalWrite(led5, LOW);
    }

  } else {
    digitalWrite(led3, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led4, LOW);
  }
}
