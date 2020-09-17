
#pragma once

#ifndef _FUNKTIONBUFFER_h
#define _FUNKTIONBUFFER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define E 2.7182818284590452353602874713526
#define BUFFER_SIZE 4096

#include "global.h"
#include <math.h>

struct space
{
	__int16_t _pointer;
	__int16_t _overWrite;
};

class funktionNode
{
protected:
	

public:

	__int16_t _leftNode = -1;
	__int16_t _rightNode = -1;
	signed char _type = -1;
	scalar _value = 0;


	bool reProgram(char * _input, __int16_t _start, __int16_t _end, char  _strings[50][512], __int16_t * sizes, __int16_t preFunk);
	scalar calculate();
	float calculate(float _x, float _y);
	bool containsX();
	bool containsY();
};


class FunktionBufferClass
{
 public:

	__uint16_t _used = 0;
	__uint16_t _overWrite[BUFFER_SIZE] = { 0 };
	funktionNode _buffer[BUFFER_SIZE];
	__int16_t _sizes[50] = { 0 };
	char _strings[50][512];

	void init();

	space requestSpaceObject();
	__int16_t requestSpace();
};


extern FunktionBufferClass FunktionBuffer;

#endif

