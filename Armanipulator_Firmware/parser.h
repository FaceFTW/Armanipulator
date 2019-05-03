/*
 * \file parser.h
 *
 * Prototype header for the parser.c file
 * Created: 4/26/2019 12:32:51 AM
 *  Author: Alex Westerman
 */

class A4988;
class DRV8825;

typedef enum Operation {
	ROTATE, GRAB, EXTEND, ERROR
};

typedef struct Command {
	Operation op;
	int value;
};

/**
 * \fn
 *
 *
 */
static struct Command parse(char*);
static void determineExec(struct Command cmd, DRV8825 stepper);
static void determineExec(struct Command cmd, A4988 stepper);
static void printExec(struct Command cmd);
