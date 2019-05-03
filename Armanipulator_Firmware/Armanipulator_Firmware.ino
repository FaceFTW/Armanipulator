#include "parser.h"
using namespace Parser;
void setup(){
	Serial.begin(115200);
	Serial.println("Success");
	Serial.println("Enter test input");
}

void loop(){
	Serial.println("Testing mode Activated");
		if(Serial.available() >0){
			String serialIn = Serial.readString();
			Parser::Arm_Command cmd = Parser::parseSerial(serialIn);
			Parser::printExec(cmd);
		}
}
