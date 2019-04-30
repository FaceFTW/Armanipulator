/*
 * parser.c

 *
 * Created: 4/25/2019 2:30:08 PM
 *  Author: FaceF
 */
#include <Arduino.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Wstring.h>
#include "stringutils.h"
#include "parser.h"
#include "exec.h"
#include "StepperDriver/src/DRV8825.h"
#include "StepperDriver/src/A4988.h"

static struct Command parse(String rawinput[]) {
	struct Command out;
	String buffer = rawinput;

	//This is what we expect in terms of input
	//Any commands related to rotation will start with an 'r' or 'R', then followed by a double indicating revolutions
	//Any commands related to gripping will start with a 'g' or 'G', then followed by a 0 or 1. Other values will trigger an exception
	//Any commands related to extending the arm will start with an 'e' or 'E', then followed by a double indicating motor rotation. We will assert that the value is between -1 and 1 for now
	//Any unrecognized letter will return the ERROR enum and 1 as the value. Serial should display an error message, or trigger an exception
	if (rawinput[0] == 'r' || rawinput[0] == 'R') {
		out.op = operation::ROTATE;
		//Extract Value from command string
		out.value = atof(buffer.substring(1, buffer.length() - 1).c_str());
	} else if (rawinput[0] == 'g' || rawinput[0] == 'G') {
		out.op = operation::GRAB;
		//Extract Value from command string
		out.value = atof(buffer.substring(1, buffer.length() - 1).c_str());
	} else if (rawinput[0] == 'e' || rawinput[0] == 'E') {
		out.op = operation::EXTEND;
		//Extract Value from command string
		out.value = atof(buffer.substring(1, buffer.length() - 1).c_str());
	} else {
		out.op = operation::ERROR;
		out.value = 1;
	}
	return out;
}

//Now we move toward execution
static void determineExec(struct Command cmd, DRV8825 stepper) {
	operation cmdop = cmd.op;
	//TODO: Check efficiency of using a switch statement instead of an if/else chain
	//See Jump Tables and low-level intricacies produced by AVR
	switch (cmdop) {
	case operation::ROTATE:
		doRotate(cmd.value, stepper);
		break;
	case operation::GRAB:
		doGrip(cmd.value, stepper);
		break;
	case operation::EXTEND:
		doExtend(cmd.value, stepper);
		break;
	case ERROR:
		Serial.println("Error, Unrecognized Command");
		break;

	}
}
static void determineExec(struct Command cmd, A4988 stepper) {
	operation cmdop = cmd.op;
	//TODO: Check efficiency of using a switch statement instead of an if/else chain
	//See Jump Tables and low-level intricacies produced by AVR
	switch (cmdop) {
	case operation::ROTATE:
		doRotate(cmd.value, stepper);
		break;
	case operation::GRAB:
		doGrip(cmd.value, stepper);
		break;
	case operation::EXTEND:
		doExtend(cmd.value, stepper);
		break;
	case ERROR:
		Serial.println("Error, Unrecognized Command");
		break;

	}
}
