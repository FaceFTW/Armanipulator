/*
 * MotorWrapper.cpp
 *
 *  Created on: May 10, 2019
 *      Author: FaceF
 */

#include "MotorWrapper.h"

#include "StepperDriver/src/BasicStepperDriver.h"

BasicStepperDriver motor;

MotorWrapper::MotorWrapper(int steps, int dir_pin, int step_pin) {
	motor = new BasicStepperDriver::BasicStepperDriver(steps, dir_pin, step_pin);

}

MotorWrapper::~MotorWrapper() {
	// TODO Auto-generated destructor stub
}

