
#pragma once

#ifndef _GRAPH_h
#define _GRAPH_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "global.h"
#include "funktion.h"
#include <math.h>

class GraphClass
{
 protected:
	 __uint32_t _map[10][240] = { { 0 } };

	 void drawLine(__int16_t _x1, __int16_t _y1, __int16_t _x2, __int16_t _y2);
	 void drawPixel(__int16_t _x, __int16_t _y);
	 void drawLineAndDraw(__int16_t _x1, __int16_t _y1, __int16_t _x2, __int16_t _y2, __uint16_t _color);
	 void drawPixelAndDraw(__int16_t _x, __int16_t _y, __uint16_t _color);
	 bool getPixel(__int16_t _x, __int16_t _y);

 public:
	void init();
	void display( __uint16_t _color);
	void calculate(funktion* _funk, float _x, float _y, float _scaleX, float _scaleY, __int16_t _type);
	void calculateAndDisplay(funktion* _funk, float _x, float _y, float _scaleX, float _scaleY, __int16_t _type, __uint16_t _color);


};

extern GraphClass Graph[5];

#endif

