typedef enum  {
  ROTATE, GRAB, EXTEND, ERROR
}Arm_Operation;

typedef struct  {
  Arm_Operation op;
  int value;
}Arm_Command;
void setup() {
  Serial.begin(115200);
  Serial.println("Success");
  Serial.println("Enter test input");
    Serial.println("Testing mode Activated");
}

void loop(){

    if(Serial.available() >0){
      String serialIn = Serial.readString();
     Arm_Command cmd =  parseSerial(serialIn);
     printExec(cmd);
    }
}


static Arm_Command parseSerial(String rawinput) {
   Arm_Command out;
  String buffer = rawinput;

  //This is what we expect in terms of input
  //Any commands related to rotation will start with an 'r' or 'R', then followed by a double indicating revolutions
  //Any commands related to gripping will start with a 'g' or 'G', then followed by a 0 or 1. Other values will trigger an exception
  //Any commands related to extending the arm will start with an 'e' or 'E', then followed by a double indicating motor rotation. We will assert that the value is between -1 and 1 for now
  //Any unrecognized letter will return the ERROR enum and 1 as the value. Serial should display an error message, or trigger an exception
  if (rawinput.charAt(0) == 'r' || rawinput.charAt(0) == 'R') {
    out.op = Arm_Operation::ROTATE;
    //Extract Value from command string
    out.value = atof(buffer.substring(1, buffer.length() - 1).c_str());
  } else if (rawinput.charAt(0) == 'g' || rawinput.charAt(0) == 'G') {
    out.op = Arm_Operation::GRAB;
    //Extract Value from command string
    out.value = atof(buffer.substring(1, buffer.length() - 1).c_str());
  } else if (rawinput.charAt(0) == 'e' || rawinput.charAt(0) == 'E') {
    out.op = Arm_Operation::EXTEND;
    //Extract Value from command string
    out.value = atof(buffer.substring(1, buffer.length() - 1).c_str());
  } else {
    out.op = Arm_Operation::ERROR;
    out.value = 1;
  }
  return out;
}

static void printExec( Arm_Command cmd) {
  Arm_Operation plsdo = cmd.op;
  switch (plsdo) {
  case Arm_Operation::ROTATE:
    Serial.println("Command: Rotate");
    Serial.println("Value: "+String(cmd.value));
    Serial.println("");
    break;
  case Arm_Operation::GRAB:
    Serial.println("Command: Grab");
    Serial.println("Value: "+String(cmd.value));
    Serial.println("");
    break;
  case Arm_Operation::EXTEND:
    Serial.println("Command: Extend");
    Serial.println("Value: "+String(cmd.value));
    Serial.println("");
    break;
  case Arm_Operation::ERROR:
    Serial.println("Command: Error");
    Serial.println("Value: "+String(cmd.value));
    Serial.println("");
    break;
  }
}
