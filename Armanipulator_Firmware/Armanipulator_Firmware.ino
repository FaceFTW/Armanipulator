#include <HardwareSerial.h>
#include <WString.h>

#include "cpu_map.h"
#include "parser.h"
#include "StepperDriver/src/BasicStepperDriver.h"


BasicStepperDriver wrist(MotorConfig::MOTOR_STEPS,Pinout::WRIST_ROT_DIR,Pinout::WRIST_ROT_STEP);
BasicStepperDriver grip(MotorConfig::MOTOR_STEPS,Pinout::GRIP_DIR,Pinout::GRIP_STEP);
BasicStepperDriver motorlist[] = {wrist,grip};
BasicStepperDriver *motorPointer[2] = {&motorlist[0], &motorlist[1]};
void setup() {
	Serial.begin(115200);
	Serial.println("Success");
	Serial.println("Enter command");
	wrist.begin(MotorConfig::MOTOR_RPM, MotorConfig::MICROSTEPS);
	grip.begin(MotorConfig::MOTOR_RPM, MotorConfig::MICROSTEPS);
}

void loop() {

	if (Serial.available() > 0) {
		String serialIn = Serial.readString();
		Parser::Arm_Command cmd = Parser::parseSerial(serialIn);
		Parser::determineExec(cmd, motorPointer);
}
}
