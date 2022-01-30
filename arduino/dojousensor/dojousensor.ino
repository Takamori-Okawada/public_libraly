const int sensorPin = A1;
const int lightPin1 =  9;
const int lightPin2 =  8;
int sensorValue = 0;
int lightcnt = 0;

void setup() {
  pinMode(lightPin1, OUTPUT);
  pinMode(lightPin2, OUTPUT);
  Serial.begin(115200);
}
void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  if(sensorValue < 350){
    Serial.println("*WET*");
    digitalWrite(lightPin1,LOW);
    digitalWrite(lightPin2,LOW);
    lightcnt = 0;
    delay(600000);
  }
  else if( (sensorValue >= 350) && (sensorValue < 450) ){
    Serial.println("*WET*");
    digitalWrite(lightPin1,HIGH);
    digitalWrite(lightPin2,LOW);
    lightcnt = 0;
    delay(300000);
  }
  else if( (sensorValue >= 450) && (sensorValue < 500) ){
    Serial.println("*WET*");
    digitalWrite(lightPin1,HIGH);
    digitalWrite(lightPin2,HIGH);
    lightcnt = 0;
    delay(180000);
  }
  else{
    Serial.println("*DRY.NEED WATER.*");
    if(lightcnt % 2 == 0){
      digitalWrite(lightPin1,LOW);
      digitalWrite(lightPin2,HIGH);
    }
    else{
      digitalWrite(lightPin1,HIGH);
      digitalWrite(lightPin2,LOW);
    }
    lightcnt += 1;
    if(lightcnt > 99){
      lightcnt = 0;
    }
    delay(500);
  }
}
