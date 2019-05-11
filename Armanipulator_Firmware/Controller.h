/*
 * Controller.h
 *
 *  Created on: May 11, 2019
 *      Author: FaceF
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

//Includes
#include "Wstring.h"		//Arduino String Library (because C strings are not fun)

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
	static Arm_Command parseSerial(String rawinput);
	static void determineExec(Arm_Command cmd);
	static void printExec(Arm_Command cmd);
};

#endif /* CONTROLLER_H_ */
