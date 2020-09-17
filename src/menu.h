
#pragma once

#ifndef _MENU_h
#define _MENU_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "global.h"
#include "settings.h"
#include "grapher.h"
#include "rechner.h"
#include "optionen.h"
#include "menu.h"
#include "Keypad.h"
#include "SPI.h"
#include "ILI9341_t3.h"

class MenuClass
{
 protected:
	 signed char _pageAt = 0;
	 bool _change = true;
	 bool _secFunc = false;

 public:
	void init();
	void display();
	void input();
};

extern MenuClass Menu;

#endif

