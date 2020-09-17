
#pragma once

#ifndef _OPTIONEN_h
#define _OPTIONEN_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "global.h"
#include "settings.h"
#include "SPI.h"
#include "ILI9341_t3.h"

class OptionenClass
{
 protected:

	 int8_t _selection[2][2]
	 {
		 {0,0},
		 {0,0},
	 };

	 int8_t _pageAt = 0;

 public:
	void init();

	void display();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void select();
};

extern OptionenClass Optionen;

#endif

