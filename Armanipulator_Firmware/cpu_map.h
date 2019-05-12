/** @file cpu_map.h
 *
 * Created: 4/24/2019 9:38:26 PM
 *  Author: Alex Westerman
 *  Used to define pins in relation to the stepper motor drivers
 */

#ifndef CPU_MAP
#define CPU_MAP

/** @class Pinout
 * 	Contains the pin definitions of the motor drivers and any other relevant pins
 */
class Pinout {
public:
//Define Wrist Driver Pins
	const static short WRIST_ROT_STEP = 2;		/**< The pin definition for the STEP pin on the motor driver responsible for wrist rotation */
	const static short WRIST_ROT_DIR = 3;		/**< The pin definition for the DIR pin on the motor driver responsible for wrist rotation */

//Define Grip Driver Pins
	const static short GRIP_STEP = 4;			/**< The pin definition for the STEP pin on the motor driver responsible for the grabbing motion */
	const static short GRIP_DIR = 5;			/**< The pin definition for the DIR pin on the motor driver responsible for the grabbing motion */

//Define Arm Motion Pins

	const static short EXTEND_STEP = 6;			/**< The pin definition for the STEP pin on the motor driver responsible for arm extension motions */
	const static short EXTEND_DIR = 7;			/**< The pin definition for the DIR pin on the motor driver responsible for arm extension motions */

};

/** @class MotorConfig
 * 	Contains constants related to motor configuration
 */
class MotorConfig {
public:
	const static short MOTOR_STEPS = 200;		/**< Constant used for defining the number of motor steps per revolution of the stepper motor */
	const static short MICROSTEPS = 1;			/**< Constant used for defining the current microstep resolution */
	const static short MOTOR_RPM = 120;			/**< Constant used for defining the RPM of the stepper motor (essentially speed) */
};

#endif
