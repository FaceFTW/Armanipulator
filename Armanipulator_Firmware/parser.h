/*
 * \file parser.h
 *
 * Prototype header for the parser.c file
 * Created: 4/26/2019 12:32:51 AM
 *  Author: Alex Westerman
 */

#include <WString.h>
#ifndef PARSER_H
#define PARSER_H
class A4988;
class DRV8825;
namespace Parser{
typedef enum  {
	ROTATE, GRAB, EXTEND, ERROR
}Arm_Operation;

typedef struct  {
	Arm_Operation op;
	int value;
}Arm_Command;

/**
 * \fn
 *
 *
 */
 extern "C"{
static Arm_Command parseSerial(String rawinput);
//static void determineExec(Arm_Command cmd, DRV8825 *stepper);
//static void determineExec(Arm_Command cmd, A4988 *stepper);
static void printExec(Arm_Command cmd);
}
}
#endif
