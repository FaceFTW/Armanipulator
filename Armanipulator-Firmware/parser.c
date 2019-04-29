/*
 * parser.c

 *
 * Created: 4/25/2019 2:30:08 PM
 *  Author: FaceF
 */ 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "stringutils.h"

    
 static Command parse(char[] rawinput){
    Command out = Command{0,0,0,0};
    char[] buffer = rawinput;
    
    //This is what we expect in terms of input
    //Any commands related to rotation will start with an 'r' or 'R', then followed by a double indicating revolutions
    //Any commands related to gripping will start with a 'g' or 'G', then followed by a 0 or 1. Other values will trigger an exception
    //Any commands releted to extending the arm will start with an 'e' or 'E', then followed by a double indicating motor rotation. We will assert that the value is between -1 and 1 for now
    //Any unrecognized letter will return

    if (strcmp(rawinput[0],'r') == 0 || strcmp(rawinput[0],'R') == 0){
        out.operation = ROTATE;
        //Extract Value from command string
        out.value = 
    } else if (strcmp(rawinput[0],'g') == 0 || strcmp(rawinput[0],'G') == 0){
        
    } else if (strcmp(rawinput[0],'e') == 0 || strcmp(rawinput[0],'E') == 0){
        
    } else{
        out.operation = ERROR;

    }
    

    
    };
 }