

#include "optionen.h"

void OptionenClass::init()
{

}

void OptionenClass::display()
{
	if (_pageAt == 0)
	{
		//Border
		tft.fillScreen(backgroundColor);
		tft.drawRect(0, 0, 320, 240, strokeColor);
		tft.drawRect(1, 1, 319, 239, strokeColor);
		tft.drawRect(2, 2, 318, 238, strokeColor);

		//Grad/Rad Selector
		tft.drawRect(45, 40, 65, 37, strokeColor);
		tft.drawRect(46, 41, 63, 35, strokeColor);
		tft.drawRect(47, 42, 61, 33, strokeColor);
		tft.setCursor(53 + (_settings._rad ? 5 : 0), 51);
		tft.setTextSize(2);
		tft.print(_settings._rad ? "Rad" : "Grad");

		if (_selection[0][0] == 0 && _selection[0][1] == 0)
		{
			tft.drawRect(45, 40, 65, 37, selectionColor);
			tft.drawRect(44, 39, 67, 39, selectionColor);
			tft.drawRect(43, 38, 69, 41, selectionColor);
		}


		//Brightness +
		tft.drawRect(64, 93, 26, 26, strokeColor);
		tft.drawRect(65, 94, 24, 24, strokeColor);
		tft.drawChar(72, 97, '+', textColor, backgroundColor, 2);

		if (_selection[0][0] == 0 && _selection[0][1] == 1)
		{
			tft.drawRect(64, 93, 26, 26, selectionColor);
			tft.drawRect(63, 92, 28, 28, selectionColor);
			tft.drawRect(62, 91, 30, 30, selectionColor);
		}


		//Brightness -
		tft.drawRect(64, 185, 26, 26, strokeColor);
		tft.drawRect(65, 186, 24, 24, strokeColor);
		tft.drawChar(72, 189, '-', textColor, backgroundColor, 2);

		if (_selection[0][0] == 0 && _selection[0][1] == 2)
		{
			tft.drawRect(64, 185, 26, 26, selectionColor);
			tft.drawRect(63, 184, 28, 28, selectionColor);
			tft.drawRect(62, 183, 30, 30, selectionColor);
		}


		//Brightness indikator
		if (_settings._brightness > 0)
			tft.fillRect(60, 168, 34, 13, lightColor);
		if (_settings._brightness > 1)
			tft.fillRect(60, 153, 34, 13, lightColor);
		if (_settings._brightness > 2)
			tft.fillRect(60, 138, 34, 13, lightColor);
		if (_settings._brightness > 3)
			tft.fillRect(60, 123, 34, 13, lightColor);

		//f1
		tft.drawRect(230, 15, 65, 37, strokeColor);
		tft.drawRect(231, 16, 63, 35, strokeColor);
		tft.drawRect(232, 17, 61, 33, strokeColor);
		tft.fillRect(235, 20, 55, 27, _settings._color[0]);
		tft.setCursor(180, 25);  // x-45  y+7
		tft.setTextSize(3);
		tft.print("f1:");

		if (_selection[0][0] == 1 && _selection[0][1] == 0)
		{
			tft.drawRect(230, 15, 65, 37, selectionColor);
			tft.drawRect(229, 14, 67, 39, selectionColor);
			tft.drawRect(228, 13, 69, 41, selectionColor);
		}


		//f2
		tft.drawRect(230, 58, 65, 37, strokeColor);
		tft.drawRect(231, 59, 63, 35, strokeColor);
		tft.drawRect(232, 60, 61, 33, strokeColor);
		tft.fillRect(235, 63, 55, 27, _settings._color[1]);
		tft.setCursor(180, 68);  // x-45  y+8
		tft.setTextSize(3);
		tft.print("f2:");

		if (_selection[0][0] == 1 && _selection[0][1] == 1)
		{
			tft.drawRect(230, 58, 65, 37, selectionColor);
			tft.drawRect(229, 57, 67, 39, selectionColor);
			tft.drawRect(228, 56, 69, 41, selectionColor);
		}


		//f3
		tft.drawRect(230, 101, 65, 37, strokeColor);
		tft.drawRect(231, 102, 63, 35, strokeColor);
		tft.drawRect(232, 103, 61, 33, strokeColor);
		tft.fillRect(235, 106, 55, 27, _settings._color[2]);
		tft.setCursor(180, 111);  // x-45  y+8
		tft.setTextSize(3);
		tft.print("f3:");

		if (_selection[0][0] == 1 && _selection[0][1] == 2)
		{
			tft.drawRect(230, 101, 65, 37, selectionColor);
			tft.drawRect(229, 100, 67, 39, selectionColor);
			tft.drawRect(228,  99, 69, 41, selectionColor);
		}


		//f4
		tft.drawRect(230, 144, 65, 37, strokeColor);
		tft.drawRect(231, 145, 63, 35, strokeColor);
		tft.drawRect(232, 146, 61, 33, strokeColor);
		tft.fillRect(235, 149, 55, 27, _settings._color[3]);
		tft.setCursor(180, 154);  // x-45  y+8
		tft.setTextSize(3);
		tft.print("f4:");

		if (_selection[0][0] == 1 && _selection[0][1] == 3)
		{
			tft.drawRect(230, 144, 65, 37, selectionColor);
			tft.drawRect(229, 143, 67, 39, selectionColor);
			tft.drawRect(228, 142, 69, 41, selectionColor);
		}


		//f5
		tft.drawRect(230, 187, 65, 37, strokeColor);
		tft.drawRect(231, 188, 63, 35, strokeColor);
		tft.drawRect(232, 189, 61, 33, strokeColor);
		tft.fillRect(235, 192, 55, 27, _settings._color[4]);
		tft.setCursor(180, 197);  // x-45  y+8
		tft.setTextSize(3);
		tft.print("f5:");

		if (_selection[0][0] == 1 && _selection[0][1] == 4)
		{
			tft.drawRect(230, 187, 65, 37, selectionColor);
			tft.drawRect(229, 186, 67, 39, selectionColor);
			tft.drawRect(228, 185, 69, 41, selectionColor);
		}

	}
	else if (_pageAt == 1)
	{
		tft.drawRect(79, 19, 180, 200, strokeColor);
		tft.drawRect(80, 20, 178, 198, strokeColor);
		tft.drawRect(81, 21, 176, 196, strokeColor);
		tft.fillRect(82, 22, 174, 194, backgroundColor);

		tft.drawRect(100, 80, 33, 130, strokeColor);
		tft.drawRect(101, 81, 31, 128, strokeColor);
		tft.drawRect(102, 82, 29, 126, strokeColor);
		tft.fillRect(103, 210 - (124 * (_settings._color[_selection[0][1]] >> 11) / 31), 27, (124 * (_settings._color[_selection[0][1]] >> 11) / 31), 0xF800);

		if (_selection[1][0] == 0)
		{
			tft.drawRect(100, 80, 33, 130, selectionColor);
			tft.drawRect( 99, 79, 35, 132, selectionColor);
			tft.drawRect( 98, 78, 37, 134, selectionColor);
		}


		tft.drawRect(151, 80, 33, 130, strokeColor);
		tft.drawRect(152, 81, 31, 129, strokeColor);
		tft.drawRect(153, 82, 29, 128, strokeColor);
		tft.fillRect(154, 210 - (124 * ((_settings._color[_selection[0][1]] >> 5) & 0b0111111) / 63), 27, ( 124 * ((_settings._color[_selection[0][1]] >> 5) & 0b0111111) / 63), 0x7E0);

		if (_selection[1][0] == 1)
		{
			tft.drawRect(151, 80, 33, 130, selectionColor);
			tft.drawRect(150, 79, 35, 132, selectionColor);
			tft.drawRect(149, 78, 37, 134, selectionColor);
		}


		tft.drawRect(202, 80, 33, 130, strokeColor);
		tft.drawRect(203, 81, 31, 129, strokeColor);
		tft.drawRect(204, 82, 29, 128, strokeColor);
		tft.fillRect(205, 210 - (124 * (_settings._color[_selection[0][1]] & 0b011111) / 31), 27, (124 * (_settings._color[_selection[0][1]] & 0b011111 ) / 31), 0x1F);

		if (_selection[1][0] == 2)
		{
			tft.drawRect(202, 80, 33, 130, selectionColor);
			tft.drawRect(201, 79, 35, 132, selectionColor);
			tft.drawRect(200, 78, 37, 134, selectionColor);
		}


		tft.drawRect(87, 27, 164, 40, strokeColor);
		tft.drawRect(88, 28, 162, 38, strokeColor);
		tft.drawRect(89, 29, 160, 36, strokeColor);
		tft.fillRect(90, 30, 158, 34, _settings._color[_selection[0][1]]);
	}
	else
	{
		tft.fillScreen(0x0000);
	}


}

void OptionenClass::moveUp()
{
	if (_pageAt == 0)
	{
		if (--_selection[0][1] < 0)
			_selection[0][1] = 0;
	}
	else //if (_pageAt == 1)
	{
		if (((_settings._color[_selection[0][1]] >> (_selection[1][0] == 0 ? 11 : (_selection[1][0] == 1 ? 5 : 0))) & (_selection[1][0] == 1 ? 0b0111111 : 0b011111)) < (_selection[1][0] == 1 ? 60 : 30))
			_settings._color[_selection[0][1]] += (_selection[1][0] == 0 ? 0b01000000000000 : (_selection[1][0] == 1 ? 0b010000000 : 0b010));
	}
}

void OptionenClass::moveDown()
{
	if (_pageAt == 0)
	{
		if (++_selection[0][1] > (_selection[0][0] == 0 ? 2 : 4))
			_selection[0][1] = (_selection[0][0] == 0 ? 2 : 4);
	}
	else //if (_pageAt == 1)
	{
		if (((_settings._color[_selection[0][1]] >> (_selection[1][0] == 0 ? 11 : (_selection[1][0] == 1 ? 5 : 0))) & (_selection[1][0] == 1 ? 0b0111111 : 0b011111)) > (_selection[1][0] == 1 ? 3 : 1))
			_settings._color[_selection[0][1]] -= (_selection[1][0] == 0 ? 0b01000000000000 : (_selection[1][0] == 1 ? 0b010000000 : 0b010));
	}
}

void OptionenClass::moveRight()
{
	if (_pageAt == 0)
	{
		if (++_selection[0][0] > 1)
			_selection[0][0] = 1;

		if (_selection[0][1] > (_selection[0][0] == 0 ? 2 : 4))
			_selection[0][1] = (_selection[0][0] == 0 ? 2 : 4);
	}
	else //if (_pageAt == 1)
		if (++_selection[1][0] > 2)
			_selection[1][0] = 2;

}

void OptionenClass::moveLeft()
{
	if (_pageAt == 0)
	{
		if (--_selection[0][0] < 0)
			_selection[0][0] = 0;

		if (_selection[0][1] > (_selection[0][0] == 0 ? 2 : 4))
			_selection[0][1] = (_selection[0][0] == 0 ? 2 : 4);
	}
	else //if (_pageAt == 1)
		if (--_selection[1][0] < 0)
			_selection[1][0] = 0;
	
}

void OptionenClass::select()
{
	if (_pageAt == 0)
	{

		if (_selection[0][0] == 1)
		{
			_pageAt = 1;
		}
		else if (_selection[0][0] == 0)
		{
			if (_selection[0][1] == 0)
				_settings._rad = !_settings._rad;

			if (_selection[0][1] == 1)
				if (++_settings._brightness > 4)
					_settings._brightness = 4;

			if (_selection[0][1] == 2)
				if (_settings._brightness > 0)
					_settings._brightness--;
			

			analogWriteDAC0(100 * pow(_settings._brightness, 1.6) + 3100);
		}
	}
	else //if (_pageAt == 1)
		_pageAt = 0;
}


OptionenClass Optionen;

