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
 * 	@brief The class-object used to interface between the serial interface and the stepper motor drivers
 *
 */
class Controller {

public:

	/**	@typedef Controller::Arm_Operation
	 * 	@brief Used to define common commands parsed by the arm
	 */

	typedef enum {
		ROTATE, /**< Run the Wrist Rotation Motor */
		GRAB, /**< Run the Grab motor			  */
		EXTEND, /**< Run the Arm Extender Motor	  */
		MICROSTEPS, /**< Change the Microsteps for the driver */
		ERROR /**< Default Error Placeholder	  */
	} Arm_Operation;

	/** @typedef Controller::Microsteps
	 *	@brief	Used to placehold common Microstep configs for the motor drivers
	 */
	/** @enum Controller::microsteps
	 * @brief Enum for the Microsteps typedef
	 */
	typedef enum microsteps {
		HALF, /**< 1/2 Microstep Ratio		  */         //!< HALF
		QUARTER, /**< 1/4 Microstep Ratio		  */      //!< QUARTER
		EIGTH, /**< 1/8 Microstep Ratio		  */        //!< EIGTH
		SIXTEENTH, /**< 1/16 Microstep Ratio		  */   //!< SIXTEENTH
		THIRTY_SECOND /**< 1/32 Microstep Ratio		  *///!< THIRTY_SECOND
	} Microsteps;

	/** @typedef Controller::Arm_Command
	 * 	@brief Type for the Arm_Command Struct to allow easy definition
	 * 	@sa Controller::arm_command
	 */

	/** @struct Controller::arm_command
	 *	@brief The structure used to define the overall instruction parsed from serial input
	 */
	typedef struct arm_command {
		Controller::Arm_Operation op; /**< The operation used in the command Structure */
		double value; /**< The value associated with the operation. If the command in op is ERROR, the value is 1 by default*/
	} Arm_Command;

	//Constructor/Destructor
	/** @fn Controller::Controller
	 * 	@brief Constructor for the controller object
	 * 	In this constructor, the motors are created on the heap, and then the motor pointer vars now point to the motors on the heap.
	 * 	currentCmd is not initialized, because it does not need to be pointed to at the minute
	 */
	Controller();

	/** @fn virtual Controller::~Controller
	 *	@brief Destructor for the controller object
	 *	Has no purpose, therefore does nothing
	 */
	virtual ~Controller();

	//Parser Related Methods
	/** @fn Controller::parseSerial
	 *	@brief Translates Serial or Other Input into an Arm_Command struct object
	 *	This function will take the string input, and then parse based on the first character of the string. Parsing goes as follows:
	 *	-Any commands related to rotation will start with an 'r' or 'R', then followed by a double indicating revolutions
	 * 	-Any commands related to gripping will start with a 'g' or 'G', then followed by a 0 or 1. Other values will trigger an exception
	 *	-Any commands related to extending the arm will start with an 'e' or 'E', then followed by a double indicating motor rotation. We will assert that the value is between -1 and 1 for now
	 *	-Any unrecognized letter will return the ERROR enum and 1 as the value. Serial should display an error message, or trigger an exception
	 *  Once the command is selected, the remaining value is parsed as a double, and then pointed to in the Arm_Command Pointer
	 *
	 *  @param rawinput The input from Serial or other communication method
	 */
	void parseSerial(String rawinput);
	/** @fn Controller::printExec
	 *	@brief Debug Function to test the parser
	 *	Prints output in the serial connection based on the values in currentCmd
	 *	@sa Controller::parseSerial
	 */
	void printExec();

	//Do stuff methods
	/** @fn Controller::executeCmd
	 *	@brief Runs Commands based on data pointed to by currentCmd
	 *	Uses the parsing rules defined by parseSerial and then do the respective action
	 *	@sa Controller::parseSerial
	 */
	void executeCmd();

	//Getter & Setter for variables
	//Arm_Command cmd
	/** @fn Controller::getCommand
	 *	@brief Getter method for the currentCmd pointer
	 *  @return Pointer to the Arm_Command object of the pointer
	 */
	Arm_Command* getCommand();

	/** @fn Controller::setCommand
	 *	@brief Setter method for the currentCmd pointer
	 *  @param cmd The pointer to overwrite the current pointer of currentCmd
	 */
	void setCommand(Arm_Command* cmd);

	//Private Vars
private:
	/** @var Arm_Command* currentCmd
	 * 	Serves as a pointer to an Arm_Command structure. This explicitly points to the memory address that holds the Arm_Command struct, but never holds any of the values
	 */
	Arm_Command* currentCmd;

	/** @var BasicStepperDriver* rotateDriver
	 *	Serves as a pointer to the motor driver for the wrist rotation. This cannot be an actual object given how the heap works, and therefore the pointer serves as the access point for the actual driver object.
	 *	Similar any other pointers, this explicitly holds the memory address for the driver object, not the object itself.
	 */
	BasicStepperDriver* rotateDriver;

	/** @var BasicStepperDriver* grabDriver
	 *	Serves as a pointer to the motor driver for the hand grip. This cannot be an actual object given how the heap works, and therefore the pointer serves as the access point for the actual driver object.
	 *	Similar any other pointers, this explicitly holds the memory address for the driver object, not the object itself.
	 */
	BasicStepperDriver* grabDriver;

	/** @var BasicStepperDriver* extendDriver
	 *	Serves as a pointer to the motor driver for the arm extension motor. This cannot be an actual object given how the heap works, and therefore the pointer serves as the access point for the actual driver object.
	 *	Similar any other pointers, this explicitly holds the memory address for the driver object, not the object itself.
	 */
	BasicStepperDriver* extendDriver;
};

#endif /* CONTROLLER_H_ */
