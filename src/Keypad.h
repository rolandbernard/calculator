#pragma once

#include "WProgram.h"
#include "ILI9341_t3.h"
extern ILI9341_t3 tft;

class Keypad
{
public:
	Keypad();
	Keypad(int, byte*, byte*, int, int);
	~Keypad();

	char getKey()
	{
		return tft.getInput();
	}
};

extern int makeKeymap(char*[]);