# Armanipulator
This project is created by Alex Westerman, Dalton Yu, Felix Xu, and Alexander Luu as a final project for the Project Lead the Way Engineering Design and Development Capstone course.

## Licensing
Armanipulator is licensed under the GNU GPL v3 License

    Copyright (C) 2019  Alex Westerman, Felix Xu, Dalton Yu, and Alexander Luu

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

## Project resources
- Documentation for the firmware code is available on the [Github Pages](https://faceftw.github.io/Armanipulator)  website Other forms of the documentation (PDF, RTF) can be found in the [docs](https://github.com/FaceFTW/Armanipulator/tree/master/docs) folder of the repository
- The firmware source is found in the [Armanipulator_Firmware](https://github.com/FaceFTW/Armanipulator/tree/master/Armanipulator_Firmware) folder.
- The source for the client program running on a computer is in the [Client](https://github.com/FaceFTW/Armanipulator/tree/master/Client) folder. Documentation for this is not complete due to time constraints


## Building the firmware
The firmware was written in the [Sloeber IDE](http://eclipse.baeyens.it/), a derivative of the Eclipse CDT IDE with tools specifically for working with Arduino. Compiling with the Arduino IDE is also possible.
### Using Sloeber
*Please note that Sloeber still requires a copy of the Arduino IDE, as the Arduino toolchain differs from the stantart AVR toolchain the Arduino processors are based off of.*

Once you have obtained a copy of the IDE, clone the repository by clicking "Clone or Download" button, or running these commands in a shell.

    git clone --recurse-submodules https://github.com/FaceFTW/Armanipulator
    
Since we do reference the [StepperDriver library](https://github.com/laurb9/StepperDriver/tree/589298541ae5f51816e11a6a6302776a16177b75) froum laurb9, ensure that the submodule is initialized. Use commands like `git submodule status` in the repository's directory to determine if it is properly initialized. 
Now, just import the project into Sloeber:

 1. Goto **File** > **Import Projects from File System**
 2. Open the directory of `Armanipulator_Firmware` on your system
 3. Hit finish

Then building it requires the code to be "verified" (compiled). Clicking the blue button with the check mark on the toolbar is the verify command, or clicking **Arduino** >  **Verify**

### Using the Arduino IDE
The [Arduino IDE](https://www.arduino.cc/en/Main/Software) is the standard software for writing and compiling code for Arduino boards. While the entire project is written in Sloeber, The project can simply be opened in the Arduino IDE by using **File** > **Open Sketch**, then opening the `Armanipulator_Firmware.ino` file in the `Armanipulator_Firmware` folder.
Similar to Sloeber, the "verify" button is a circular button on the toolbar with a checkmark. It can also be invoked by hitting **CTRL**+**R** or clicking **Sketch** > **Verify/Compile**

## Uploading
Coming soon to a repository near you...

## Future plans
I need to sleep man, finishing this later
