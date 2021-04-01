void setup() {
  // put your setup code here, to run once:
  pinMode(16, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(17, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("test blink");
  digitalWrite(16, HIGH);
  delay(1000);
  //digitalWrite(16, LOW);
  digitalWrite(19, HIGH);
  delay(1000);
  //digitalWrite(19, LOW);
  digitalWrite(17, HIGH);
  delay(1000);
  digitalWrite(16, LOW);
  delay(1000);
  digitalWrite(19, LOW);
  delay(1000);
  digitalWrite(17, LOW);
  //digitalWrite(17, LOW);
  delay(1000);
}
