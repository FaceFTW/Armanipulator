#include <HardwareSerial.h>
#include <WString.h>

#include "cpu_map.h"
#include "Controller.h"
#include "StepperDriver/src/BasicStepperDriver.h"

Controller *mainController;

void setup() {
	Serial.begin(115200);						//Begin Serial Communications
	Serial.println("Success");					//This shows if the connection is successful
	Serial.println("Enter command");			//Prompt user for command input
	mainController = new Controller();			//Create a new Controller object on the heap, then set the pointer to reference that object
}

void loop() {

	if (Serial.available() > 0) {				//Wait for serial input
		String serialIn = Serial.readString();	//Capture serial input
		mainController->parseSerial(serialIn);	//Parse serial input
		mainController->printExec();			//Print parsed serial input (debugging)
		mainController->executeCmd();			//Execute the parsed input
	}
}
