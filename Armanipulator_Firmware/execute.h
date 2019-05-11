/*
 * exec.h
 *
 * Created: 4/26/2019 7:39:13 AM
 *  Author: FaceF
 */ 


//class A4988;/
//class DRV8825;



#ifndef EXECUTE_H_
#define EXECUTE	_H_
class BasicStepperDriver;
class Execute{
	//Rotate Execs
	static void doRotate(double& rotVal, BasicStepperDriver* stepper);

	//Grip Execs
	static void doGrip(double& gripVal, BasicStepperDriver* stepper);

	//Extend Execs
	static void doExtend(double& extendVal, BasicStepperDriver* stepper);


	//Microstep Execs
	//TODO  A4988 does not support all microstep ratios that the DRV8825 supports
	//static void changeMicrosteps(Parser::Microsteps& steps, A4988& stepper);
	//static void changeMicrosteps(Parser::Microsteps& steps, BasicStepperDriver* stepper);
};



#endif /* EXEC_H_ */
