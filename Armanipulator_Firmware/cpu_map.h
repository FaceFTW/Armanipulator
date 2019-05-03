/*
 * cpu_map.h
 *
 * Created: 4/24/2019 9:38:26 PM
 *  Author: Alex Westerman
 *  Used to define pins in relation to the stepper motor drivers
 */ 


#ifndef CPU_MAP
#define CPU_MAP

//Define Wrist Driver Pins
#define WRIST_ROT_STEP		5
#define WRIST_ROT_DIR		2

//Define Grip Driver Pins
#define GRIP_STEP			6
#define GRIP_DIR			3

//Define Arm Motion Pins
#define EXTEND_STEP			7
#define EXTEND_DIR			4

//Define Microstep Control Pins
#define MICROSTEP_1			8
#define MICROSTEP_2			9
#define MICROSTEP_3			10



#endif
