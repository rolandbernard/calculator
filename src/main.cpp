


#include "global.h"
#include "funktionBuffer.h"
#include "settings.h"
#include "grapher.h"
#include "optionen.h"
#include "rechner.h"
#include "graph.h"
#include "funktion.h"
#include "menu.h"
#include "Keypad.h"
#include "SPI.h"
#include "ILI9341_t3.h"
#include <math.h>


#ifdef DEBUG_OUT

IntervalTimer outRamTimer;

#endif // DEBUG_OUT

void setup()
{
#ifdef DEBUG_OUT
	Serial.begin(9600);

	outRamTimer.begin(printFreeRam, 250000);
#endif // DEBUG_OUT


	tft.begin();
	tft.setRotation(1);
	tft.setTextColor(textColor);

	_settings._rad = false;
	_settings._brightness = 3;
	_settings._base = 0;

	//RRGGBB
	_settings._color[0] = ILI9341_BLUE;
	_settings._color[1] = ILI9341_BLACK;
	_settings._color[2] = ILI9341_RED;
	_settings._color[3] = ILI9341_YELLOW;
	_settings._color[4] = ILI9341_ORANGE;
	analogWriteDAC0(100 * pow(_settings._brightness, 1.6) + 3100);
}

void loop()
{
	Menu.input();
	Menu.display();
}

int main()
{
	setup();
	while (1)
	{
		loop();
	}
}