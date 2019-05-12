/*
 * Controller.h
 *
 *  Created on: May 11, 2019
 *      Author: FaceF
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

//Includes

#include <WString.h>		//Arduino String Library (because C strings are not fun)

#include "StepperDriver/src/BasicStepperDriver.h"
#include "cpu_map.h"

class Controller {

public:
	//structs and types
	typedef enum {
		ROTATE, GRAB, EXTEND, MICROSTEPS, ERROR
	} Arm_Operation;

	typedef enum microsteps {
		HALF,			//value = 1
		QUARTER,	 	//value = 2
		EIGTH, 			//value = 3
		SIXTEENTH, 		//value = 4
		THIRTY_SECOND	//value = 5
	} Microsteps;

	typedef struct arm_command {
		Controller::Arm_Operation op;
		double value;
	} Arm_Command;

	//Constructor/Destructor
	Controller();
	virtual ~Controller();

	//Parser Related Methods
	void parseSerial(String rawinput);
	void printExec();

	//Motor Init
	void initMotors();

	//Do stuff methods
	void executeCmd();

	//Getter & Setter for variables
	//Arm_Command cmd
	Arm_Command* getCommand();
	void setCommand(Arm_Command* cmd);



	//Private Vars
private:
	Arm_Command* currentCmd;
	BasicStepperDriver* rotateDriver;
	BasicStepperDriver* grabDriver;
	BasicStepperDriver* extendDriver;
};

#endif /* CONTROLLER_H_ */
