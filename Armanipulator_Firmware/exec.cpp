#include "StepperDriver/src/DRV8825.h"
#include "parser.h"
//TODO: Add calculation relative to current microstep config
class Exec {
public:
	//Rotate Execs
	static void doRotate(double rotVal, DRV8825& stepper) {
		stepper.move(rotVal);
	}

	static void doRotate(double rotVal, A4988& stepper) {
		stepper.move(rotVal);
	}

	//Grip Execs
	static void doGrip(double gripVal, DRV8825& stepper) {
		stepper.move(gripVal);
	}
	static void doGrip(double gripVal, A4988& stepper) {
		stepper.move(gripVal);
	}

	//Extend Execs
	static void doExtend(double extendVal, DRV8825& stepper) {
		stepper.move(extendVal);
	}

	static void doExtend(double extendVal, A4988& stepper) {
		stepper.move(extendVal);
	}

	static void changeMicrosteps(Parser::Microsteps steps, A4988& stepper) {

	}

	static void changeMicrosteps(Parser::Microsteps steps, DRV8825& stepper) {

	}
};
