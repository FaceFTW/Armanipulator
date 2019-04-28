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
	
	/*
	* \struct cmd
	* TODO Define struct stuff
	* 
	*/
	typedef struct cmd{
		double rot;
		double grip;
		double extend;
		int error;
	};
	
	/**
	* \fn static char[] removeNL(char[] in)
	* \brief Removes newline (\n) characters
	* \param char[] input
	*/
	static char[] removeNL(char[]);

	/**
	* \fn
	* 
	*
	*/
	static cmd{} parse(char[]);
	
	//Overloaded version of parse
	static cmd{} parse(int,int,int);
	
	
#endif