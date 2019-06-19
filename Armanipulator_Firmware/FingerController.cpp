/*
 * FingerController.cpp
 *
 *  Created on: Jun 19, 2019
 *      Author: FaceF
 */

#include "FingerController.h"

BasicStepperDriver* joint1Driver;
BasicStepperDriver* joint2Driver;
BasicStepperDriver* joint3Driver;

FingerController::FingerController(BasicStepperDriver* _joint1,
	BasicStepperDriver* _joint2, BasicStepperDriver* _joint3) {
	joint1Driver = _joint1;
	joint2Driver = _joint2;
	joint3Driver = _joint3;
}

//DESTROY THE CHILD. CORRUPT THEM ALL
FingerController::~FingerController() {
	//GC is a pain
}

void FingerController::doOperation(Finger_Op _op) {
	//Change the executed method dependent on _op
	switch (_op) {
	case Finger_Op::EXTEND:
		this->extendFinger();
		break;
	case Finger_Op::CURL:
		this->curlFinger();
		break;
	}
}

void FingerController::extendFinger(){
	//Placeholder
}

void FingerController::curlFinger(){
	//placeholder
}

