#include <Wire.h> 
#include <Adafruit_L3GD20.h>
#define GYRO_CS 4 // labeled CS
#define GYRO_DO 5 // labeled SA0
#define GYRO_DI 6  // labeled SDA
#define GYRO_CLK 7 // labeled SCL
Adafruit_L3GD20 gyro(GYRO_CS, GYRO_DO, GYRO_DI, GYRO_CLK);

void setup(){
  Serial.begin(115200);
  if(!gyro.begin(gyro.L3DS20_RANGE_250DPS)){
    Serial.println("Oops ... unable to initialize the L3GD20. Check your wiring!");
    while(1);
  }
}

void loop(){
  gyro.read();
  Serial.print("X: ");
  Serial.print((int)gyro.data.x);
  Serial.print(" ");
  Serial.print("Y: ");
  Serial.print((int)gyro.data.y);
  Serial.print(" ");
  Serial.print("Z: ");
  Serial.print((int)gyro.data.z);
  Serial.print("\n");
  delay(500);
}
