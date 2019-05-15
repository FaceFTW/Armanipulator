/** @file Armanipulator_Firmware.ino
 *  @brief Base file for the arduino sketch
 */

#include <HardwareSerial.h>
#include <WString.h>

#include "cpu_map.h"
#include "Controller.h"
#include "StepperDriver/src/BasicStepperDriver.h"


Controller* mainController;						/**< Pointer to the Controller Object */

	/** @fn Main::setup
	 *  @brief One-time initalization function
	 *  The setup function is one of the required functions in an arduino sketch in order for it to work.
	 *  This function serves as a "container" for all functions and operations that is to be run once, unless the RESET button is activated.
	 */
void setup() {
	Serial.begin(115200);							//Open serial comms
	Serial.println("Success");						//This implies the serial connection opened successfully
	Serial.println("Enter command");				//Prompt user to enter commands for parsing
	mainController = new Controller();				//Create a new Controller object on the heap, initialize it, then have mainController point to it
}


	/** @fn Main::loop
	 *  @brief Main firmware loop
	 *  The loop function is the other requried function in an arduino sketch in order for it to compile.
	 *  This function serves as a contianer for all functions and operations that is to be repeated until the MCU receives no power or the RESET button is activated.
	 */
void loop() {
	if (Serial.available() > 0) {				//Wait for serial input
		String serialIn = Serial.readString();	//Capture serial input
		mainController->parseSerial(serialIn);	//Parse serial input
		mainController->printExec();			//Print parsed serial input (debugging)
		mainController->executeCmd();			//Execute the parsed input
	}
}
