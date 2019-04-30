#include "parser.h"
#include "stringutils.h"
#include "StepperDriver/src/DRV8825.h"

	//TODO: Add calculation relative to current microstep config

	//Rotate Execs
	static void doRotate(int rotVal, DRV8825 stepper){
		stepper.move(rotVal);
	}

	static void doRotate(int rotVal, A4988 stepper){
		stepper.move(rotVal);
	}


	//Grip Execs
	static void doGrip(int gripVal, DRV8825 stepper){
		stepper.move(gripVal);
	}
	static void doGrip(int gripVal, A4988 stepper){
		stepper.move(gripVal);
	}


	//Extend Execs
	static void doExtend(int extendVal, DRV8825 stepper){
		stepper.move(extendVal);
	}

	static void doExtend(int extendVal, A4988 stepper){
		stepper.move(extendVal);
	}
