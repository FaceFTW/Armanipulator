#include <HardwareSerial.h>
#include <WString.h>

#include "cpu_map.h"
#include "Controller.h"
#include "StepperDriver/src/BasicStepperDriver.h"

Controller *mainController;

void setup() {
	Serial.begin(115200);
	Serial.println("Success");
	Serial.println("Enter command");
	mainController = new Controller();
}

void loop() {

	if (Serial.available() > 0) {
		String serialIn = Serial.readString();
		mainController->parseSerial(serialIn);
		mainController->printExec();
		mainController->executeCmd();
	}
}
