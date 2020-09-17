
#pragma once

#ifndef _RECHNER_h
#define _RECHNER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "global.h"
#include "settings.h"
#include "graph.h"
#include "funktion.h"
#include "SPI.h"
#include "ILI9341_t3.h"


class RechnerClass
{
 protected:
	 funktion _funktions[50];
	 char _strings[50][512];
	 __int16_t _stringSize[50];
	 __int16_t _displatStart[50];
	 __int16_t _pointAt = 0;
	 __int16_t _pointInString = 0;
	 __int16_t _amountSaved = -1;

 public:
	void init();

	void display();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void insertChar(char c);
	void enter();
	void delet();
	void deletAll();
	void outputMode();
};

extern RechnerClass Rechner;

#endif

