#include "parser.h"
#include "Arduino.h"
void setup(){
	Serial.begin(115200);
	Serial.println("Success");
	Serial.println("Enter test input");
	Serial.println("Testing mode Activated");
}

void loop(){

		if(Serial.available() >0){
			String serialIn = Serial.readString();
			Parser::Arm_Command cmd = Parser::parseSerial(serialIn);
			Parser::printExec(cmd);
		}
}
