/*
 * exec.h
 *
 * Created: 4/26/2019 7:39:13 AM
 *  Author: FaceF
 */ 

//#include "parser.h"

//class A4988;/
//class DRV8825;
class BasicStepperDriver;


#ifndef EXEC_H_
#define EXEC_H_
class Execute{
public:
	//Rotate Execs
	static void doRotate(double& rotVal, BasicStepperDriver* stepper);
	//static void doRotate(double& rotVal, A4988& stepper);

	//Grip Execs
	static void doGrip(double& gripVal, BasicStepperDriver* stepper);
	//static void doGrip(double& gripVal, A4988& stepper);

	//Extend Execs
	static void doExtend(double& extendVal, BasicStepperDriver* stepper);
	//static void doExtend(double& extendVal, A4988& stepper);

	//Microstep Execs
	//TODO  A4988 does not support all microstep ratios that the DRV8825 supports
	//static void changeMicrosteps(Parser::Microsteps& steps, A4988& stepper);
	//static void changeMicrosteps(Parser::Microsteps& steps, BasicStepperDriver* stepper);


};


#endif /* EXEC_H_ */
