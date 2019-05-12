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
	/**
	 *
	 */
	const static short WRIST_ROT_STEP = 2;

	/**
	 *
	 */
	const static short WRIST_ROT_DIR = 3;
//Define Grip Driver Pins
	/**
	 *
	 */
	const static short GRIP_STEP = 4;

	/**
	 *
	 */
	const static short GRIP_DIR = 5;

//Define Arm Motion Pins

	const static short EXTEND_STEP = 6;	/**< */


	/**
	 *
	 */
	const static short EXTEND_DIR = 7;

};

class MotorConfig {
public:
	/**
	 *
	 */
	const static short MOTOR_STEPS = 200;

	/**
	 *
	 */
	const static short MICROSTEPS = 1;

	/**
	 *
	 */
	const static short MOTOR_RPM = 120;
};

#endif
