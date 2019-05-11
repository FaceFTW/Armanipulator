/*
 * MotorWrapper.h
 *
 *  Created on: May 10, 2019
 *      Author: FaceF
 */

#ifndef MOTORWRAPPER_H_
#define MOTORWRAPPER_H_

#include "parser.h"
#include "StepperDriver/src/BasicStepperDriver.h"
class MotorWrapper {
public:
	MotorWrapper(int steps, int dir_pin, int step_pin);
	virtual ~MotorWrapper();
	static void doMovement(double);
	static void setMicrosteps(Parser::Microsteps microstep);
private:
	BasicStepperDriver motor;
};

#endif /* MOTORWRAPPER_H_ */
