/*
 * parser.c

 *
 * Created: 4/25/2019 2:30:08 PM
 *  Author: FaceF
 */
//TODO: Optimize for using native AVR-C strings
//See: https://hackingmajenkoblog.wordpress.com/2016/02/04/the-evils-of-arduino-strings/
//Possibility, flush buffer after each operation?
//i.e, Serial.flush(), then invoke some form of garbage collection?

#include "parser.h"

#include <HardwareSerial.h>
#include <WString.h>

#include "exec.h"

static struct Command parse(String rawinput[]) {
	struct Command out;
	String buffer = rawinput;

	//This is what we expect in terms of input
	//Any commands related to rotation will start with an 'r' or 'R', then followed by a double indicating revolutions
	//Any commands related to gripping will start with a 'g' or 'G', then followed by a 0 or 1. Other values will trigger an exception
	//Any commands related to extending the arm will start with an 'e' or 'E', then followed by a double indicating motor rotation. We will assert that the value is between -1 and 1 for now
	//Any unrecognized letter will return the ERROR enum and 1 as the value. Serial should display an error message, or trigger an exception
	if (rawinput[0] == 'r' || rawinput[0] == 'R') {
		out.op = Operation::ROTATE;
		//Extract Value from command string
		out.value = atof(buffer.substring(1, buffer.length() - 1).c_str());
	} else if (rawinput[0] == 'g' || rawinput[0] == 'G') {
		out.op = Operation::GRAB;
		//Extract Value from command string
		out.value = atof(buffer.substring(1, buffer.length() - 1).c_str());
	} else if (rawinput[0] == 'e' || rawinput[0] == 'E') {
		out.op = Operation::EXTEND;
		//Extract Value from command string
		out.value = atof(buffer.substring(1, buffer.length() - 1).c_str());
	} else {
		out.op = Operation::ERROR;
		out.value = 1;
	}
	return out;
}

//Now we move toward execution
static void determineExec(struct Command cmd, DRV8825 stepper) {
	Operation cmdop = cmd.op;
	//TODO: Check efficiency of using a switch statement instead of an if/else chain
	//See Jump Tables and low-level intricacies produced by AVR
	switch (cmdop) {
	case Operation::ROTATE:
		doRotate(cmd.value, stepper);
		break;
	case Operation::GRAB:
		doGrip(cmd.value, stepper);
		break;
	case Operation::EXTEND:
		doExtend(cmd.value, stepper);
		break;
	case ERROR:
		Serial.println("Error, Unrecognized Command");
		break;

	}
}

static void determineExec(struct Command cmd, A4988 stepper) {
	Operation cmdop = cmd.op;
	//TODO: Check efficiency of using a switch statement instead of an if/else chain
	//See Jump Tables and low-level intricacies produced by AVR
	switch (cmdop) {
	case Operation::ROTATE:
		doRotate(cmd.value, stepper);
		break;
	case Operation::GRAB:
		doGrip(cmd.value, stepper);
		break;
	case Operation::EXTEND:
		doExtend(cmd.value, stepper);
		break;
	case ERROR:
		Serial.println("Error, Unrecognized Command");
		break;
	}
}

static void printExec(struct Command cmd) {
	Operation plsdo = cmd.op;
	switch (plsdo) {
	case Operation::ROTATE:
		Serial.println("Command: Rotate");
		Serial.println("Value: "+cmd.value);
		Serial.println("");
		break;
	case Operation::GRAB:
		Serial.println("Command: Grab");
		Serial.println("Value: "+cmd.value);
		Serial.println("");
		break;
	case Operation::EXTEND:
		Serial.println("Command: Extend");
		Serial.println("Value: "+cmd.value);
		Serial.println("");
		break;
	case Operation::ERROR:
		Serial.println("Command: Error");
		Serial.println("Value: "+cmd.value);
		Serial.println("");
		break;
	}
}
