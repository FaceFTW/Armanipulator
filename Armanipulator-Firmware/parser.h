/*
 * \file parser.h
 *
 * Prototype header for the parser.c file
 * Created: 4/26/2019 12:32:51 AM
 *  Author: Alex Westerman
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef parser_H_
#define parser_H_
	enum CMD{ROTATE, GRAB, EXTEND, ERROR};
	/**
	 * @brief 
	 * 
	 */
	typedef struct Command{
		CMD operation;
		int value;
	};
	
	/**
	* \fn static char[] removeNL(char[] in)
	* \brief Removes newline (\n) characters
	* \param char[] input
	*/

	/**
	* \fn
	* 
	*
	*/
	static Command parse(char[])
	
	//Overloaded version of parse
	static Command parse(char[] op, int val);
	
	
#endif