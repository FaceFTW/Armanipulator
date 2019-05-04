/*
 * exec.h
 *
 * Created: 4/26/2019 7:39:13 AM
 *  Author: FaceF
 */ 

#include "parser.h"

class A4988;
class DRV8825;

typedef enum Parser::Microsteps Microsteps;

#ifndef EXEC_H_
#define EXEC_H_
	//Rotate Execs
	static void doRotate(int rotVal, DRV8825 stepper);
	static void doRotate(int rotVal, A4988 stepper);

	//Grip Execs
	static void doGrip(int gripVal, DRV8825 stepper);
	static void doGrip(int gripVal, A4988 stepper);

	//Extend Execs
	static void doExtend(int extendVal, DRV8825 stepper);
	static void doExtend(int extendVal, A4988 stepper);

	//Microstep Execs
	//TODO  A4988 does not support all microstep ratios that the DRV8825 supports
	static void changeMicrosteps(enum Microsteps steps, A4988 stepper)
	static void changeMicrosteps(enum Microsteps steps, DRV8825 stepper);





#endif /* EXEC_H_ */
