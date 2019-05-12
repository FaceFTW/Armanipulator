/** @file Controller.h
 * 	@brief Contains methods for controlling the motors and parsing input
 *
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

//Includes

#include <WString.h>		//Arduino String Library (because C strings are not fun)

#include "StepperDriver/src/BasicStepperDriver.h"
#include "cpu_map.h"

/** @class Controller
 * 	@brief The class-object used to interface between the serial interface and
 *
 */
class Controller {

public:

	/**	@typedef Controller::Arm_Operation
	 * 	@brief Used to define common commands parsed by the arm
	 */
	typedef enum {
		ROTATE, 	/**< Run the Wrist Rotation Motor */
		GRAB, 		/**< Run the Grab motor			  */
		EXTEND, 	/**< Run the Arm Extender Motor	  */
		MICROSTEPS, /**< Change the Microsteps for the driver */
		ERROR		/**< Default Error Placeholder	  */
	} Arm_Operation;

	/** @typedef Controller::Microsteps
	 *	@brief	Used to placehold common Microstep configs for the motor drivers
	 */
	typedef enum microsteps {
		HALF,			/**< 1/2 Microstep Ratio		  */       //!< HALF
		QUARTER,	 	/**< 1/4 Microstep Ratio		  */    //!< QUARTER
		EIGTH, 			/**< 1/8 Microstep Ratio		  */     //!< EIGTH
		SIXTEENTH, 		/**< 1/16 Microstep Ratio		  */ //!< SIXTEENTH
		THIRTY_SECOND	/**< 1/32 Microstep Ratio		  *///!< THIRTY_SECOND
	} Microsteps;

	/**
	 *
	 */
	typedef struct arm_command {
		Controller::Arm_Operation op;
		double value;
	} Arm_Command;

	//Constructor/Destructor
	/**
	 *
	 */
	Controller();
	/**
	 *
	 */
	virtual ~Controller();

	//Parser Related Methods
	/**
	 *
	 * @param rawinput
	 */
	void parseSerial(String rawinput);
	/**
	 *
	 */
	void printExec();

	//Motor Init
	/**
	 *
	 */
	void initMotors();

	//Do stuff methods
	/**
	 *
	 */
	void executeCmd();

	//Getter & Setter for variables
	//Arm_Command cmd
	/**
	 *
	 * @return
	 */
	Arm_Command* getCommand();
	/**
	 *
	 * @param cmd
	 */
	void setCommand(Arm_Command* cmd);

	//Private Vars
private:
	/**
	 *
	 */
	Arm_Command* currentCmd;

	/**
	 *
	 */
	BasicStepperDriver* rotateDriver;

	/**
	 *
	 */
	BasicStepperDriver* grabDriver;

	/**
	 *
	 */
	BasicStepperDriver* extendDriver;
};

#endif /* CONTROLLER_H_ */
