
#pragma once

#ifndef _GRAPHER_h
#define _GRAPHER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "global.h"
#include "funktionBuffer.h"
#include "settings.h"
#include "graph.h"
#include "funktion.h"
#include "ILI9341_t3.h"
#include <math.h>

class GrapherClass
{
 protected:
	 __int8_t _pageAt = 0;

	 funktion _funktions[5];
	 char _strings[5][512];
	 __int16_t _stringSize[5] = { 0 };
	 __int16_t _displatStart[5] = { 0 };
	 __int16_t _pointAt = 0;
	 __int16_t _pointInString = 0;

	 __int16_t _scaleMode = 0;
	 __int8_t _selected = 0;

	 float _x = 0;
	 float _y = 0;
	 float _scaleX = 2;
	 float _scaleY = 2 * ASPECT_RATIO;
	 float _xw = 0;
	 float _yw = 0;
	 float _scaleXw = 2;
	 float _scaleYw = 2 * ASPECT_RATIO;
	 float _xSelect = 0;
	 float _ySelect = 0;
	 float _movement = 0.1;
	 bool _select = false;
	 bool _canidateForSeclect[5];


	 bool _graphChange = true;

 public:
	void init();
	void display();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void insertChar(char c);
	void enter();
	void funktions();
	void delet();
	void deletAll();

};

extern GrapherClass Grapher;

#endif

