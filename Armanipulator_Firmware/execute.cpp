#include "StepperDriver/src/BasicStepperDriver.h"

//TODO: Add calculation relative to current microstep config
class BasicStepperDriver;
	//Rotate Execs
	static void Execute::doRotate(double& rotVal, BasicStepperDriver* stepper) {
		stepper->move(rotVal);
	}

	//Grip Execs
	static void Execute::doGrip(double& gripVal, BasicStepperDriver* stepper) {
		stepper->move(gripVal);
	}

	//Extend Execs
	static void Execute::doExtend(double& extendVal, BasicStepperDriver* stepper) {
		stepper->move(extendVal);
	}

	//static void Execute::changeMicrosteps(Parser::Microsteps steps, BasicStepperDriver* stepper) {

	//}

