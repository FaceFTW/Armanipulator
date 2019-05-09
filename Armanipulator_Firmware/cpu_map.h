/*
 * cpu_map.h
 *
 * Created: 4/24/2019 9:38:26 PM
 *  Author: Alex Westerman
 *  Used to define pins in relation to the stepper motor drivers
 */

#ifndef CPU_MAP
#define CPU_MAP
class Pinout {
public:
//Define Wrist Driver Pins
	const static int WRIST_ROT_STEP = 2;
	const static int WRIST_ROT_DIR = 3;
//Define Grip Driver Pins
	const static int GRIP_STEP = 4;
	const static int GRIP_DIR = 5;

//Define Arm Motion Pins
	const static int EXTEND_STEP = 6;
	const static int EXTEND_DIR = 7;

//Define Microstep Control Pins
	const static int MICROSTEP_1 = 8;
	const static int MICROSTEP_2 = 9;
	const static int MICROSTEP_3 = 10;
};

class MotorConfig {
public:
	const static int MOTOR_STEPS = 200;
	const static int MICROSTEPS = 1;
	const static int MOTOR_RPM = 120;
};

#endif
