/*
 * parsertest.cpp
 *
 *  Created on: May 2, 2019
 *      Author: FaceF
 */

#include "parser.h"
#include "Arduino.h"
#include "WString.h"

static void testParser(){
	Serial.println("Testing mode Activated");
	if(Serial.available() >0){
		String serialIn = Serial.readString();
	}

}


