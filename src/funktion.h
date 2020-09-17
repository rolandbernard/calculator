
#pragma once

#ifndef _FUNKTION_h
#define _FUNKTION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "funktionBuffer.h"
#include "settings.h"
#include "global.h"

class funktion
{
 protected:
	 __int16_t _funktionStart = -1;
	 __int16_t _overWrite = -1;

 public:
	void init();

	bool reProgram(char * _input, __int16_t _start, __int16_t _end, __int16_t preFunk);
	bool checkExistance();
	scalar calculate();
	scalar calculate(scalar _x, scalar _y);
	__int16_t getStart();
};

#endif

