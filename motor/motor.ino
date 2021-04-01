
// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;


void setup() {
  Serial.begin(115200);
  ledcSetup(pwmChannel, freq, resolution);
  ledcAttachPin(14, pwmChannel);
  Serial.println("mise en marche moteur");
}

void loop(){
  
  ledcWrite(pwmChannel, 255);
}
