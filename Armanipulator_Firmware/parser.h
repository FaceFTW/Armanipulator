/*
 * \file parser.h
 *
 * Prototype header for the parser.c file
 * Created: 4/26/2019 12:32:51 AM
 *  Author: Alex Westerman
 */

class A4988;
class DRV8825;

typedef enum operation {
	ROTATE, GRAB, EXTEND, ERROR
};

typedef struct Command {
	operation op;
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
