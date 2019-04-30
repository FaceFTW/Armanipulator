/*
 * exec.h
 *
 * Created: 4/26/2019 7:39:13 AM
 *  Author: FaceF
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StepperDriver/src/DRV8825.h"
#include "StepperDriver/src/A4988.h"

#ifndef EXEC_H_
#define EXEC_H_
	//Rotate Execs
	static void doRotate(int rotVal, DRV8825 stepper);
	static void doRotate(int rotVal, A4988 stepper);

	//Grip Execs
	static void doGrip(int gripVal, DRV8825 stepper);
	static void doGrip(int gripVal, A4988 stepper);


	static void doExtend(int extendVal, DRV8825 stepper);
	static void doExtend(int extendVal, A4988 stepper);





#endif /* EXEC_H_ */
