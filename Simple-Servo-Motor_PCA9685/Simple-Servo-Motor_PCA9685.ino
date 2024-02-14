#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Initialize the PCA9685 using the default address (0x40).
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Servo pulse constants for 1ms and 2ms in terms of the 0-4095 scale
#define SERVOMIN  150 // This value corresponds to a 1ms pulse length
#define SERVOMAX  600 // This value corresponds to a 2ms pulse length

void setup() {
  // put your setup code here, to run once:
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
}

void setPostion(int Angle, int ServoNum) {
    // Map the angle to a pulse length
    int pulseWidth = map(Angle, 0, 180, SERVOMIN, SERVOMAX);
    // Command the servo to go to the angle
    pwm.setPWM(ServoNum, 0, pulseWidth);
}

void loop() {
  // put your main code here, to run repeatedly:
  setPostion(0, 0);
  delay(2000);
  setPostion(180, 0);
  delay(2000);
}
