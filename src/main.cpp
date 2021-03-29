
/*
 Name:		M5_inverted_pendulum.ino
 Created:	2020/07/12 22:56:25
*/
#define M5STACK_MPU6886
#define BLYNK_PRINT Serial
#define BLYNK_USE_DIRECT_CONNECT 

#include <M5Stack.h>
#include <Encoder.h>
#include <BlynkSimpleEsp32_BLE.h>
#include <BLEDevice.h>
#include <BLEServer.h>

#include "M5graph.h"
#include "MotorDriver.h"
#include "PID.h"

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "GOJ6lVdiblnMlQtdLZyfwuu8e-st2ogG";

//pinNumber
const int motor1A = 16;
const int motor1B = 17;
const int motor2A = 2;
const int motor2B = 3;
const int encRA = 26;
const int encRB = 25;
const int encLA = 35;
const int encLB = 36;

const int Kp = 25.5;
const int Ki = 0;
const int Kd = 0.8;
const int Kx = 0.15;
const int Kv = 0;

float pitch = 0.0F;
float roll = 0.0F;
float yaw = 0.0F;
float preL = 0;
float preR = 0;
long newL = 0;
long newR = 0;
float preTime = 0;
long positionLeft  = -999;
long positionRight = -999;
float vL,vR,resultL,resultR,dt; 

MotorDriver motorL(motor1A, motor1B);
MotorDriver motorR(motor2A, motor2B);
Encoder encR(encRA, encRB);
Encoder encL(encLA, encLB);
PID pL(Kp,Ki,Kd);
PID pR(Kp,Ki,Kd);
M5view::M5graph rollGraph;

void task1(void *pvParameters){
    while (1) {
      M5.IMU.getAhrsData(&pitch, &roll, &yaw);

      dt = (micros() - preTime) / 1000000;
      vL = (newL - preL)/dt;
      vR = (newR - preR)/dt;
      preTime = micros();
      preL = newL;
      preR = newR; 

      resultL = pL.pid( 6, roll) + Kx*newL + Kv*vL;
      resultR = pR.pid( 6, roll) + Kx*newR + Kv*vR;
  
      motorL.setSpeed(resultL*0.05);
      motorR.setSpeed(resultR);

      rollGraph.graph(roll);
      
    delay(1);
  }
}

void task2(void *pvParameters){
    while (1) {
        newL = encL.read();
        newR = encR.read();
        if (newL != positionLeft || newR != positionRight) {
          Serial.print("Left = ");
          Serial.print(newL);
          Serial.print(", Right = ");
          Serial.print(newR);
          Serial.println();
          positionLeft = newL;
          positionRight = newR;
  }
        if (M5.BtnA.isPressed()) {
        encL.readAndReset();
        encR.readAndReset();
        pL.resetI();
        pR.resetI();
    }
        delay(1);
    }
}

// the setup function runs once when you press reset or power the board
void setup() {
	M5.begin();
	M5.Power.begin();
	M5.IMU.Init();

	//pinMode(encRA, INPUT);
	//pinMode(encRB, INPUT);
	//pinMode(encLA, INPUT);
	//pinMode(encLB, INPUT);

  
	motorL.setSpeed(0);
	motorR.setSpeed(0);

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(GREEN , BLACK);
  M5.Lcd.setTextSize(2);
  
  Serial.begin(9600);
  xTaskCreatePinnedToCore(
    task1,
    "task1",
    8192,
    NULL,
    0,
    NULL,
    0
  );

  xTaskCreatePinnedToCore(
    task2,
    "task2",
    8192,
    NULL,
    1,
    NULL,
    1
  );
}

// the loop function runs over and over again until power down or reset
void loop() {
  //delay(1);
	
}