/*
 * parser.c

 *
 * Created: 4/25/2019 2:30:08 PM
 *  Author: FaceF
 */
//TODO: Optimize for using native AVR-C strings
//See: https://hackingmajenkoblog.wordpress.com/2016/02/04/the-evils-of-arduino-strings/
//Possibility, flush buffer after each Arm_Operation?
//i.e, Serial.flush(), then invoke some form of garbage collection?
#include "parser.h"

#include <HardwareSerial.h>
#include "StepperDriver/src/A4988.h"
#include "StepperDriver/src/DRV8825.h"
#include <WString.h>

#include "exec.h"

class Exec;


	static Parser::Arm_Command Parser::parseSerial(String rawinput) {
		Arm_Command* out = new Arm_Command();
		String buffer = rawinput;

		//This is what we expect in terms of input
		//Any commands related to rotation will start with an 'r' or 'R', then followed by a double indicating revolutions
		//Any commands related to gripping will start with a 'g' or 'G', then followed by a 0 or 1. Other values will trigger an exception
		//Any commands related to extending the arm will start with an 'e' or 'E', then followed by a double indicating motor rotation. We will assert that the value is between -1 and 1 for now
		//Any unrecognized letter will return the ERROR enum and 1 as the value. Serial should display an error message, or trigger an exception
		if (rawinput.charAt(0) == 'r' || rawinput.charAt(0) == 'R') {
			out->op = Parser::Arm_Operation::ROTATE;
			//Extract Value from command string
			out->value = atof(buffer.substring(1, buffer.length() ).c_str());
		} else if (rawinput.charAt(0) == 'g' || rawinput.charAt(0) == 'G') {
			out->op = Parser::Arm_Operation::GRAB;
			//Extract Value from command string
			out->value = atof(buffer.substring(1, buffer.length() ).c_str());
		} else if (rawinput.charAt(0) == 'e' || rawinput.charAt(0) == 'E') {
			out->op = Parser::Arm_Operation::EXTEND;
			//Extract Value from command string
			out->value = atof(buffer.substring(1, buffer.length() ).c_str());
		} else if (rawinput.charAt(0) == 'm' || rawinput.charAt(0) == 'M') {
			out->op = Parser::Arm_Operation::MICROSTEPS;
			//Special Extract Value related to enum
			//Ev
		} else {

			out->op = Parser::Arm_Operation::ERROR;
			out->value = 1;
		}
		return* out;
	}


	//Now we move toward execution
	static void Parser::determineExec(Parser::Arm_Command cmd, BasicStepperDriver** stepper[]) {
		Parser::Arm_Operation cmdop = cmd.op;
		//TODO: Check efficiency of using a switch statement instead of an if/else chain
		//See Jump Tables and low-level intricacies produced by AVR
		switch (cmdop) {
		case Parser::Arm_Operation::ROTATE:
			Exec::doRotate(cmd.value,*(stepper)-stepper[0]);
			break;
		case Parser::Arm_Operation::GRAB:
			Exec::doGrip(cmd.value,*(stepper+1)-stepper[1]);
			break;
		case Parser::Arm_Operation::EXTEND:
			//Exec::doExtend(cmd.value, stepper);
			break;
		case Parser::Arm_Operation::ERROR:
			Serial.println("Error, Unrecognized Command");
			break;

		}
	}

	/*static void Parser::determineExec(Parser::Arm_Command cmd, A4988 stepper) {
		Parser::Arm_Operation cmdop = cmd.op;
		//TODO: Check efficiency of using a switch statement instead of an if/else chain
		//See Jump Tables and low-level intricacies produced by AVR
		switch (cmdop) {
		case Parser::Arm_Operation::ROTATE:
			Exec::doRotate(cmd.value, stepper);
			break;
		case Parser::Arm_Operation::GRAB:
			Exec::doGrip(cmd.value, stepper);
			break;
		case Parser::Arm_Operation::EXTEND:
			Exec::doExtend(cmd.value, stepper);
			break;
		case Parser::Arm_Operation::ERROR:
			Serial.println("Error, Unrecognized Command");
			break;
		}
	}
*/
	static void Parser::printExec(Parser::Arm_Command cmd) {
		Parser::Arm_Operation plsdo = cmd.op;
		switch (plsdo) {
		case Parser::Arm_Operation::ROTATE:
			Serial.println("Command: Rotate");
			Serial.println("Value: " + String(cmd.value));
			Serial.println("");
			break;
		case Parser::Arm_Operation::GRAB:
			Serial.println("Command: Grab");
			Serial.println("Value: " + String(cmd.value));
			Serial.println("");
			break;
		case Parser::Arm_Operation::EXTEND:
			Serial.println("Command: Extend");
			Serial.println("Value: " + String(cmd.value));
			Serial.println("");
			break;
		case Parser::Arm_Operation::MICROSTEPS:
			//Microsteps should be parsed diffenrently
			break;
		case Parser::Arm_Operation::ERROR:
			Serial.println("Command: Error");
			Serial.println("Value: " + String(cmd.value));
			Serial.println("");
			break;
		}
	}


