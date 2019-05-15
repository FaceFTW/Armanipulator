/*
 * Controller.cpp
 *
 *  Created on: May 11, 2019
 *      Author: FaceF
 */

//Include Me pls
#include "Controller.h"
#include "cpu_map.h"

Controller::Arm_Command* currentCmd;
BasicStepperDriver* rotateDriver;
BasicStepperDriver* grabDriver;
BasicStepperDriver* extendDriver;
//Bob the builder
Controller::Controller() {
	//Init the motors
	//Declare Motor Pinouts
	rotateDriver = new BasicStepperDriver(MotorConfig::MOTOR_STEPS, Pinout::WRIST_ROT_DIR, Pinout::WRIST_ROT_STEP);
	grabDriver = new BasicStepperDriver(MotorConfig::MOTOR_STEPS, Pinout::GRIP_DIR, Pinout::GRIP_STEP);
	extendDriver = new BasicStepperDriver(MotorConfig::MOTOR_STEPS,	Pinout::EXTEND_DIR, Pinout::EXTEND_STEP);

	//Start the motors
	rotateDriver->begin(MotorConfig::MOTOR_RPM, MotorConfig::MICROSTEPS);
	grabDriver->begin(MotorConfig::MOTOR_RPM, MotorConfig::MICROSTEPS);
	extendDriver->begin(MotorConfig::MOTOR_RPM, MotorConfig::MICROSTEPS);

	//Init the struct as an error struct (If executeCMD is called before parseSerial, error is returned intentionally)
	currentCmd = new Arm_Command{Controller::Arm_Operation::ERROR, 1};
}

//DESTROY THE CHILD. CORRUPT THEM ALL
Controller::~Controller() {

}

//Getters and Setters
//Arm_Command
Controller::Arm_Command* Controller::getCommand() {
	return currentCmd;
}

void Controller::setCommand(Controller::Arm_Command* cmd) {
	currentCmd = cmd;
}

void Controller::parseSerial(String rawinput) {
	Arm_Command* out = new Arm_Command();

	//This is what we expect in terms of input
	//Any commands related to rotation will start with an 'r' or 'R', then followed by a double indicating revolutions
	//Any commands related to gripping will start with a 'g' or 'G', then followed by a 0 or 1. Other values will trigger an exception
	//Any commands related to extending the arm will start with an 'e' or 'E', then followed by a double indicating motor rotation. We will assert that the value is between -1 and 1 for now
	//Any unrecognized letter will return the ERROR enum and 1 as the value. Serial should display an error message, or trigger an exception
	if (rawinput.charAt(0) == 'r' || rawinput.charAt(0) == 'R') {
		out->op = Controller::Arm_Operation::ROTATE;
		out->value = atof(rawinput.substring(1, rawinput.length()).c_str());						//Extract Value from command string
	} else if (rawinput.charAt(0) == 'g' || rawinput.charAt(0) == 'G') {
		out->op = Controller::Arm_Operation::GRAB;
		out->value = atof(rawinput.substring(1, rawinput.length()).c_str());						//Extract Value from command string
	} else if (rawinput.charAt(0) == 'e' || rawinput.charAt(0) == 'E') {
		out->op = Controller::Arm_Operation::EXTEND;
		out->value = atof(rawinput.substring(1, rawinput.length()).c_str());						//Extract Value from command string
	} else if (rawinput.charAt(0) == 'm' || rawinput.charAt(0) == 'M') {
		out->op = Controller::Arm_Operation::MICROSTEPS;
		//Special Extract Value related to enum

	} else {
		out->op = Controller::Arm_Operation::ERROR;
		out->value = 1;
	}
	currentCmd = out;
}

void Controller::printExec() {
	Controller::Arm_Operation plsdo = this->getCommand()->op;										//Get the Arm_Operation enum from the
	switch (plsdo) {																				//Figure out which command was extracted
	case Controller::Arm_Operation::ROTATE:															//The command is to rotate the wrist
		Serial.println("Command: Rotate");															//Print out the command name
		Serial.println("Value: " + String(this->getCommand()->value));								//Print out the command value
		Serial.println("");																			//Newline to seperate output
		break;
	case Controller::Arm_Operation::GRAB:															//The command is to do the grabby hand
		Serial.println("Command: Grab");															//Print out the command name
		Serial.println("Value: " + String(this->getCommand()->value));								//Print out the command value
		Serial.println("");																			//Newline to seperate output
		break;
	case Controller::Arm_Operation::EXTEND:															//The Command is to extend the arm
		Serial.println("Command: Extend");															//Print out the command name
		Serial.println("Value: " + String(this->getCommand()->value));								//Print out the command value
		Serial.println("");																			//Newline to seperate output
		break;
	case Controller::Arm_Operation::MICROSTEPS:
		//Microsteps should be parsed diffenrently
		break;
	case Controller::Arm_Operation::ERROR:															//The command is an error
		Serial.println("Command: Error");															//Print out the command name
		Serial.println("Value: " + String(this->getCommand()->value));								//Print out the command value
		Serial.println("");																			//Newline to seperate output
		break;
	}
}

//Execute Order 66
void Controller::executeCmd() {
	Controller::Arm_Operation cmdop = this->getCommand()->op;										//Extract the Arm_Operation enum stored in this controller object
	//TODO: Check efficiency of using a switch statement instead of an if/else chain
	//See Jump Tables and low-level intricacies produced by AVR
	switch (cmdop) {																				//What is the command
	case Controller::Arm_Operation::ROTATE:															//Rotate the wrist
		if (this->getCommand()->value > 1 || this->getCommand()->value < -1) {						//Check the bounds of the value
			Serial.println("Error: Value for Wrist Rotation commands should be between -1 and 1");	//Print an error message and give explanation
			return;																					//Exits to the main loop if bounds are not met
		}
		rotateDriver->move(currentCmd->value * 200);												//Otherwise, perform the movement
		break;
	case Controller::Arm_Operation::GRAB:															//Do the grabby hand
		if (this->getCommand()->value != 1 || this->getCommand()->value != -1) {					//Bounds checking, but stricter (Decimal values indicate a partial oepning of the hand, which us not the best practice
			Serial.println("Error: Value for Grab commands should be either -1 or 1");				//Print an error message and give explanation
			return;																					//Exits to the main loop if bounds are not met
		}
		grabDriver->move(currentCmd->value * 60);													//Do the grab (set value, motion depends on sign))
		break;
	case Controller::Arm_Operation::EXTEND:															//Extend the arm!
		if (this->getCommand()->value > 1 || this->getCommand()->value < -1) {						//Bounds checking, but not strict (arm should extend to variable lengths
			Serial.println("Error: Value for Arm Extension commands should be between -1 and 1");	//Print an error message and give explanation
			return;																					//Exits to the main loop if bounds are not met
		}
		extendDriver->move(currentCmd->value);														//Extend the arm
		break;
	case Controller::Arm_Operation::MICROSTEPS:
		//Empty for now
		break;
	case Controller::Arm_Operation::ERROR:															//He's Dead, Jim!
		Serial.println("Error, Unrecognized Command");												//Print out an error message
		break;

	}
}
