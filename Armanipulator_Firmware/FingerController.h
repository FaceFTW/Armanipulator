/** @file FingerController.h
 *  @brief Contains the definitions for the FingerController class used for jointed finger control
 * 	This class is purely theroretical at the moment, but it may actually work in theory
 */

#ifndef FINGERCONTROLLER_H_
#define FINGERCONTROLLER_H_
class BasicStepperDriver;

/**@class FingerController
 * @brief Used to serve as the interface between the finger and the MCU
 * Has only finger specific commands unlike the Controller and Controller_Multifinger class
 *
 */
class FingerController{

	//Unlike other controller classes, this class does not need to have any struct to transit a command and data
	//With this class we assume that the finger has no partial movement capabilities
public:

	/** @typedef FingerController::FingerOp
	 *  @brief Defines finger movement directions
	 */
	typedef enum {
		EXTEND,			/**< Extend the finger *///!< EXTEND
		CURL			/**< Curl the finger */     //!< CURL
	} Finger_Op;

	/** @fn FingerController::FingerController
	 * 	@brief Constructor for the Finger Controller
	 *
	 */
	FingerController(BasicStepperDriver* _joint1, BasicStepperDriver* _joint2, BasicStepperDriver* _joint3);

	/**@fn virtual FingerController::~FingerController
	 * @brief obligatory destructor for this class
	 */

	//This code is tenative. It is not good code due to the number of pointer refs and jump operations it would cause

	void doOperation(Finger_Op _op){
		//Change the executed method dependent on _op
		switch(_op){
		case Finger_Op::EXTEND:
			//Placeholder
			break;
		case Finger_Op::CURL:
			//Placeholder
			break;
		}
	}

	void extendFinger(){
		//Used for finger extenstion
	}

	void curlFinger(){
		//Used for finger curling
	}

private:
	//We asssume stepper motors here to prevent increasing size by adding the servo library
	BasicStepperDriver* joint1Driver;
	BasicStepperDriver* joint2Driver;
	BasicStepperDriver* joint3Driver;

};




#endif /* FINGERCONTROLLER_H_ */
