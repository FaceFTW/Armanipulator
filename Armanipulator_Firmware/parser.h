/*
 * \file parser.h
 *
 * Prototype header for the parser.c file
 * Created: 4/26/2019 12:32:51 AM
 *  Author: Alex Westerman
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StepperDriver/src/DRV8825.h"
#include "StepperDriver/src/A4988.h"

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
