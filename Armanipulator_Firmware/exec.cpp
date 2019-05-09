#include "StepperDriver/src/BasicStepperDriver.h"
#include "parser.h"
//TODO: Add calculation relative to current microstep config
class Exec {
public:

	//Rotate Execs
	static void doRotate(double rotVal, BasicStepperDriver& stepper) {
		stepper.move(rotVal);
	}
/*
	static void doRotate(double rotVal, A4988& stepper) {
		stepper.move(rotVal);
	}*/

	//Grip Execs
	static void doGrip(double gripVal, BasicStepperDriver& stepper) {
		stepper.move(gripVal);
	}
	/*
	static void doGrip(double gripVal, A4988& stepper) {
		stepper.move(gripVal);
	}
*/
	//Extend Execs
	static void doExtend(double extendVal, BasicStepperDriver* stepper) {
		stepper->move(extendVal);
	}
/*
	static void doExtend(double extendVal, A4988& stepper) {
		stepper.move(extendVal);
	}
	*/
/*
	static void changeMicrosteps(Parser::Microsteps steps, A4988& stepper) {

	}
*/
	static void changeMicrosteps(Parser::Microsteps steps, BasicStepperDriver& stepper) {

	}
};
