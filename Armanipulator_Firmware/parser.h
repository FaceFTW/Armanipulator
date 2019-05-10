/*
 * \file parser.h
 *
 * Prototype header for the parser.c file
 * Created: 4/26/2019 12:32:51 AM
 *  Author: Alex Westerman
 */
#pragma once
#include <WString.h>
#ifndef PARSER_H
#define PARSER_H
//class A4988;
//class DRV8825;
#include "StepperDriver/src/BasicStepperDriver.h"

class Parser {
public:
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
		Parser::Arm_Operation op;
		double value;
	} Arm_Command;

	/**
	 * \fn
	 *
	 *
	 */
	static Arm_Command parseSerial(String rawinput);
	static void determineExec(Arm_Command cmd, BasicStepperDriver* stepper[]);
	//static void determineExec(Arm_Command cmd, A4988 stepper);
	static void printExec(Arm_Command cmd);
};

#endif
