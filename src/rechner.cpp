

#include "rechner.h"

void RechnerClass::init()
{


}

void RechnerClass::display()
{
	for (__int16_t i = 0; i < 50; i++)
		_funktions[i].checkExistance();

	//Border
	tft.fillScreen(backgroundColor);
	tft.drawRect(0, 0, 320, 240, strokeColor);
	tft.drawRect(1, 1, 319, 239, strokeColor);
	tft.drawRect(2, 2, 318, 238, strokeColor);

	//Writing
	tft.drawRect(10, 62, 294, 60, strokeColor);
	tft.drawRect(11, 63, 292, 58, strokeColor);
	tft.drawRect(12, 64, 290, 56, strokeColor);

	for (int i = _displatStart[_pointAt]; i < _displatStart[_pointAt] + 16 && i < _stringSize[_pointAt]; i++)
	{
		if (_strings[_pointAt][i] == '\\')
		{
			tft.drawLine(14 + 18 * (i - _displatStart[_pointAt]), 90, 19 + 18 * (i - _displatStart[_pointAt]), 90, textColor);
			tft.drawLine(19 + 18 * (i - _displatStart[_pointAt]), 90, 22 + 18 * (i - _displatStart[_pointAt]), 103, textColor);
			tft.drawLine(22 + 18 * (i - _displatStart[_pointAt]), 103, 26 + 18 * (i - _displatStart[_pointAt]), 79, textColor);
			tft.drawLine(26 + 18 * (i - _displatStart[_pointAt]), 79, 31 + 18 * (i - _displatStart[_pointAt]), 79, textColor);

			tft.drawLine(14 + 18 * (i - _displatStart[_pointAt]), 91, 19 + 18 * (i - _displatStart[_pointAt]), 91, textColor);
			tft.drawLine(19 + 18 * (i - _displatStart[_pointAt]), 91, 22 + 18 * (i - _displatStart[_pointAt]), 102, textColor);
			tft.drawLine(22 + 18 * (i - _displatStart[_pointAt]), 102, 26 + 18 * (i - _displatStart[_pointAt]), 78, textColor);
			tft.drawLine(26 + 18 * (i - _displatStart[_pointAt]), 78, 31 + 18 * (i - _displatStart[_pointAt]), 78, textColor);

			tft.drawLine(14 + 18 * (i - _displatStart[_pointAt]), 92, 19 + 18 * (i - _displatStart[_pointAt]), 92, textColor);
			tft.drawLine(19 + 18 * (i - _displatStart[_pointAt]), 92, 22 + 18 * (i - _displatStart[_pointAt]), 101, textColor);
			tft.drawLine(22 + 18 * (i - _displatStart[_pointAt]), 101, 26 + 18 * (i - _displatStart[_pointAt]), 77, textColor);
			tft.drawLine(26 + 18 * (i - _displatStart[_pointAt]), 77, 31 + 18 * (i - _displatStart[_pointAt]), 77, textColor);
		}
		else if (_strings[_pointAt][i] == '$')
		{
			tft.drawLine(14 + 18 * (i - _displatStart[_pointAt]), 90, 19 + 18 * (i - _displatStart[_pointAt]), 90, textColor);
			tft.drawLine(19 + 18 * (i - _displatStart[_pointAt]), 90, 22 + 18 * (i - _displatStart[_pointAt]), 103, textColor);
			tft.drawLine(22 + 18 * (i - _displatStart[_pointAt]), 103, 26 + 18 * (i - _displatStart[_pointAt]), 79, textColor);
			tft.drawLine(26 + 18 * (i - _displatStart[_pointAt]), 79, 31 + 18 * (i - _displatStart[_pointAt]), 79, textColor);

			tft.drawLine(14 + 18 * (i - _displatStart[_pointAt]), 91, 19 + 18 * (i - _displatStart[_pointAt]), 91, textColor);
			tft.drawLine(19 + 18 * (i - _displatStart[_pointAt]), 91, 22 + 18 * (i - _displatStart[_pointAt]), 102, textColor);
			tft.drawLine(22 + 18 * (i - _displatStart[_pointAt]), 102, 26 + 18 * (i - _displatStart[_pointAt]), 78, textColor);
			tft.drawLine(26 + 18 * (i - _displatStart[_pointAt]), 78, 31 + 18 * (i - _displatStart[_pointAt]), 78, textColor);

			tft.drawLine(14 + 18 * (i - _displatStart[_pointAt]), 92, 19 + 18 * (i - _displatStart[_pointAt]), 92, textColor);
			tft.drawLine(19 + 18 * (i - _displatStart[_pointAt]), 92, 22 + 18 * (i - _displatStart[_pointAt]), 101, textColor);
			tft.drawLine(22 + 18 * (i - _displatStart[_pointAt]), 101, 26 + 18 * (i - _displatStart[_pointAt]), 77, textColor);
			tft.drawLine(26 + 18 * (i - _displatStart[_pointAt]), 77, 31 + 18 * (i - _displatStart[_pointAt]), 77, textColor);

			tft.drawChar(14 + 18 * (i - _displatStart[_pointAt]), 82, '2', textColor, backgroundColor, 1);
		}
		else if (_strings[_pointAt][i] == '#')
		{
			tft.drawLine(14 + 18 * (i - _displatStart[_pointAt]), 90, 19 + 18 * (i - _displatStart[_pointAt]), 90, textColor);
			tft.drawLine(19 + 18 * (i - _displatStart[_pointAt]), 90, 22 + 18 * (i - _displatStart[_pointAt]), 103, textColor);
			tft.drawLine(22 + 18 * (i - _displatStart[_pointAt]), 103, 26 + 18 * (i - _displatStart[_pointAt]), 79, textColor);
			tft.drawLine(26 + 18 * (i - _displatStart[_pointAt]), 79, 31 + 18 * (i - _displatStart[_pointAt]), 79, textColor);

			tft.drawLine(14 + 18 * (i - _displatStart[_pointAt]), 91, 19 + 18 * (i - _displatStart[_pointAt]), 91, textColor);
			tft.drawLine(19 + 18 * (i - _displatStart[_pointAt]), 91, 22 + 18 * (i - _displatStart[_pointAt]), 102, textColor);
			tft.drawLine(22 + 18 * (i - _displatStart[_pointAt]), 102, 26 + 18 * (i - _displatStart[_pointAt]), 78, textColor);
			tft.drawLine(26 + 18 * (i - _displatStart[_pointAt]), 78, 31 + 18 * (i - _displatStart[_pointAt]), 78, textColor);

			tft.drawLine(14 + 18 * (i - _displatStart[_pointAt]), 92, 19 + 18 * (i - _displatStart[_pointAt]), 92, textColor);
			tft.drawLine(19 + 18 * (i - _displatStart[_pointAt]), 92, 22 + 18 * (i - _displatStart[_pointAt]), 101, textColor);
			tft.drawLine(22 + 18 * (i - _displatStart[_pointAt]), 101, 26 + 18 * (i - _displatStart[_pointAt]), 77, textColor);
			tft.drawLine(26 + 18 * (i - _displatStart[_pointAt]), 77, 31 + 18 * (i - _displatStart[_pointAt]), 77, textColor);

			tft.drawChar(14 + 18 * (i - _displatStart[_pointAt]), 82, '3', textColor, backgroundColor, 1);
		}
		else
			tft.drawChar(14 + 18*(i - _displatStart[_pointAt]), 80, _strings[_pointAt][i], textColor, backgroundColor, 3);

	}

	tft.fillRect(14 + 18 * (_pointInString - _displatStart[_pointAt]), 102, 15, 3, textColor);

	//Calculated
	if (_funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].checkExistance())
	{
		int index = (_pointAt - 1) < 0 ? 49 : _pointAt - 1;

		tft.drawRect(13, 28, 196, 33, strokeColor);
		tft.drawRect(14, 29, 194, 31, strokeColor);

		for (int i = _displatStart[index]; i < _displatStart[index] + 16 && i < _stringSize[index]; i++)
		{
			if (_strings[index][i] == '\\')
			{
				tft.drawLine(16 + 12 * (i - _displatStart[index]), 44, 19 + 12 * (i - _displatStart[index]), 44, textColor);
				tft.drawLine(19 + 12 * (i - _displatStart[index]), 44, 21 + 12 * (i - _displatStart[index]), 51, textColor);
				tft.drawLine(21 + 12 * (i - _displatStart[index]), 51, 24 + 12 * (i - _displatStart[index]), 35, textColor);
				tft.drawLine(24 + 12 * (i - _displatStart[index]), 35, 27 + 12 * (i - _displatStart[index]), 35, textColor);

				tft.drawLine(16 + 12 * (i - _displatStart[index]), 45, 19 + 12 * (i - _displatStart[index]), 45, textColor);
				tft.drawLine(19 + 12 * (i - _displatStart[index]), 45, 21 + 12 * (i - _displatStart[index]), 50, textColor);
				tft.drawLine(21 + 12 * (i - _displatStart[index]), 50, 24 + 12 * (i - _displatStart[index]), 34, textColor);
				tft.drawLine(24 + 12 * (i - _displatStart[index]), 34, 27 + 12 * (i - _displatStart[index]), 34, textColor);
			}
			else if (_strings[index][i] == '$')
			{
				tft.drawLine(16 + 12 * (i - _displatStart[index]), 44, 19 + 12 * (i - _displatStart[index]), 44, textColor);
				tft.drawLine(19 + 12 * (i - _displatStart[index]), 44, 21 + 12 * (i - _displatStart[index]), 51, textColor);
				tft.drawLine(21 + 12 * (i - _displatStart[index]), 51, 24 + 12 * (i - _displatStart[index]), 35, textColor);
				tft.drawLine(24 + 12 * (i - _displatStart[index]), 35, 27 + 12 * (i - _displatStart[index]), 35, textColor);

				tft.drawLine(16 + 12 * (i - _displatStart[index]), 45, 19 + 12 * (i - _displatStart[index]), 45, textColor);
				tft.drawLine(19 + 12 * (i - _displatStart[index]), 45, 21 + 12 * (i - _displatStart[index]), 50, textColor);
				tft.drawLine(21 + 12 * (i - _displatStart[index]), 50, 24 + 12 * (i - _displatStart[index]), 34, textColor);
				tft.drawLine(24 + 12 * (i - _displatStart[index]), 34, 27 + 12 * (i - _displatStart[index]), 34, textColor);

				tft.drawChar(16 + 12 * (i - _displatStart[index]), 36, '2', textColor, backgroundColor, 1);
			}
			else if (_strings[index][i] == '#')
			{
				tft.drawLine(16 + 12 * (i - _displatStart[index]), 44, 19 + 12 * (i - _displatStart[index]), 44, textColor);
				tft.drawLine(19 + 12 * (i - _displatStart[index]), 44, 21 + 12 * (i - _displatStart[index]), 51, textColor);
				tft.drawLine(21 + 12 * (i - _displatStart[index]), 51, 24 + 12 * (i - _displatStart[index]), 35, textColor);
				tft.drawLine(24 + 12 * (i - _displatStart[index]), 35, 27 + 12 * (i - _displatStart[index]), 35, textColor);

				tft.drawLine(16 + 12 * (i - _displatStart[index]), 45, 19 + 12 * (i - _displatStart[index]), 45, textColor);
				tft.drawLine(19 + 12 * (i - _displatStart[index]), 45, 21 + 12 * (i - _displatStart[index]), 50, textColor);
				tft.drawLine(21 + 12 * (i - _displatStart[index]), 50, 24 + 12 * (i - _displatStart[index]), 34, textColor);
				tft.drawLine(24 + 12 * (i - _displatStart[index]), 34, 27 + 12 * (i - _displatStart[index]), 34, textColor);

				tft.drawChar(16 + 12 * (i - _displatStart[index]), 36, '3', textColor, backgroundColor, 1);
			}
			else
				tft.drawChar(16 + 12 * (i - _displatStart[index]), 36, _strings[index][i], textColor, backgroundColor, 2);

			tft.drawChar(212, 36, '=', textColor, backgroundColor, 2);
		}
	}

	//Bottom
	if (_funktions[_pointAt].checkExistance())
	{
		int index = (_pointAt + 1) % 50;

		tft.drawRect(13, 123, 196, 33, strokeColor);
		tft.drawRect(14, 124, 194, 31, strokeColor);

		for (int i = _displatStart[index]; i < _displatStart[index] + 16 && i < _stringSize[index]; i++)
		{
			if (_strings[index][i] == '\\')
			{
				tft.drawLine(16 + 12 * (i - _displatStart[index]), 44 + 95, 19 + 12 * (i - _displatStart[index]), 44 + 95, textColor);
				tft.drawLine(19 + 12 * (i - _displatStart[index]), 44 + 95, 21 + 12 * (i - _displatStart[index]), 51 + 95, textColor);
				tft.drawLine(21 + 12 * (i - _displatStart[index]), 51 + 95, 24 + 12 * (i - _displatStart[index]), 35 + 95, textColor);
				tft.drawLine(24 + 12 * (i - _displatStart[index]), 35 + 95, 27 + 12 * (i - _displatStart[index]), 35 + 95, textColor);

				tft.drawLine(16 + 12 * (i - _displatStart[index]), 45 + 95, 19 + 12 * (i - _displatStart[index]), 45 + 95, textColor);
				tft.drawLine(19 + 12 * (i - _displatStart[index]), 45 + 95, 21 + 12 * (i - _displatStart[index]), 50 + 95, textColor);
				tft.drawLine(21 + 12 * (i - _displatStart[index]), 50 + 95, 24 + 12 * (i - _displatStart[index]), 34 + 95, textColor);
				tft.drawLine(24 + 12 * (i - _displatStart[index]), 34 + 95, 27 + 12 * (i - _displatStart[index]), 34 + 95, textColor);
			}
			else if (_strings[index][i] == '$')
			{
				tft.drawLine(16 + 12 * (i - _displatStart[index]), 44 + 95, 19 + 12 * (i - _displatStart[index]), 44 + 95, textColor);
				tft.drawLine(19 + 12 * (i - _displatStart[index]), 44 + 95, 21 + 12 * (i - _displatStart[index]), 51 + 95, textColor);
				tft.drawLine(21 + 12 * (i - _displatStart[index]), 51 + 95, 24 + 12 * (i - _displatStart[index]), 35 + 95, textColor);
				tft.drawLine(24 + 12 * (i - _displatStart[index]), 35 + 95, 27 + 12 * (i - _displatStart[index]), 35 + 95, textColor);

				tft.drawLine(16 + 12 * (i - _displatStart[index]), 45 + 95, 19 + 12 * (i - _displatStart[index]), 45 + 95, textColor);
				tft.drawLine(19 + 12 * (i - _displatStart[index]), 45 + 95, 21 + 12 * (i - _displatStart[index]), 50 + 95, textColor);
				tft.drawLine(21 + 12 * (i - _displatStart[index]), 50 + 95, 24 + 12 * (i - _displatStart[index]), 34 + 95, textColor);
				tft.drawLine(24 + 12 * (i - _displatStart[index]), 34 + 95, 27 + 12 * (i - _displatStart[index]), 34 + 95, textColor);

				tft.drawChar(16 + 12 * (i - _displatStart[index]), 36 + 95, '2', textColor, backgroundColor, 1);
			}
			else if (_strings[index][i] == '#')
			{
				tft.drawLine(16 + 12 * (i - _displatStart[index]), 44 + 95, 19 + 12 * (i - _displatStart[index]), 44 + 95, textColor);
				tft.drawLine(19 + 12 * (i - _displatStart[index]), 44 + 95, 21 + 12 * (i - _displatStart[index]), 51 + 95, textColor);
				tft.drawLine(21 + 12 * (i - _displatStart[index]), 51 + 95, 24 + 12 * (i - _displatStart[index]), 35 + 95, textColor);
				tft.drawLine(24 + 12 * (i - _displatStart[index]), 35 + 95, 27 + 12 * (i - _displatStart[index]), 35 + 95, textColor);

				tft.drawLine(16 + 12 * (i - _displatStart[index]), 45 + 95, 19 + 12 * (i - _displatStart[index]), 45 + 95, textColor);
				tft.drawLine(19 + 12 * (i - _displatStart[index]), 45 + 95, 21 + 12 * (i - _displatStart[index]), 50 + 95, textColor);
				tft.drawLine(21 + 12 * (i - _displatStart[index]), 50 + 95, 24 + 12 * (i - _displatStart[index]), 34 + 95, textColor);
				tft.drawLine(24 + 12 * (i - _displatStart[index]), 34 + 95, 27 + 12 * (i - _displatStart[index]), 34 + 95, textColor);

				tft.drawChar(16 + 12 * (i - _displatStart[index]), 36 + 95, '3', textColor, backgroundColor, 1);
			}
			else
				tft.drawChar(16 + 12 * (i - _displatStart[index]), 36 + 95, _strings[index][i], textColor, backgroundColor, 2);

		}
	}

	//Result

	tft.drawRect(50, 135, 265, 77, strokeColor);
	tft.drawRect(51, 136, 263, 75, strokeColor);
	tft.drawRect(52, 137, 261, 73, strokeColor);
	tft.drawRect(53, 138, 259, 71, strokeColor);
	tft.drawRect(54, 139, 257, 69, strokeColor);
	tft.fillRect(55, 140, 255, 67, backgroundColor);

	if (_funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].checkExistance())
	{
		String result;


		tft.setTextColor(selectionColor);
		switch (_settings._base)
		{
		case 0:
			result = toString(_funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].calculate(), DEC);
			tft.setCursor(31, 161);
			tft.setTextSize(1);
			tft.print("DEC");
			break;
		case 1:
			result = toString(_funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].calculate(), HEX);
			tft.setCursor(31, 161);
			tft.setTextSize(1);
			tft.print("HEX");
			break;
		case 2:
			result = toString(_funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].calculate(), BIN);
			tft.setCursor(31, 161);
			tft.setTextSize(1);
			tft.print("BIN");
			break;
		case 3:
			result = toString(_funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].calculate(), OCT);
			tft.setCursor(31, 161);
			tft.setTextSize(1);
			tft.print("OCT");
			break;
		default:
			break;
		}
		tft.setTextColor(textColor);

		tft.setCursor(55, 161);
		tft.setTextSize(3);
		tft.print(result);
	}



}

void RechnerClass::moveUp()
{
	if (_pointAt != 0)
	{
		if (_funktions[_pointAt - 1].checkExistance())
			_pointAt--;
	}
	else
		if (_funktions[49].checkExistance())
			_pointAt = 49;

	_pointInString = _stringSize[_pointAt];

	if (_stringSize[_pointAt] < 15)
		_displatStart[_pointAt] = 0;
	else
		_displatStart[_pointAt] = _stringSize[_pointAt] - 15;

	if (_pointAt > 0 && _funktions[(_pointAt - 1) % 5].checkExistance())
	{
	retryPoint:
		switch (_settings._base)
		{
		case 0:
			if (!alowsBase(_funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].calculate(), DEC))
			{
				_settings._base = (_settings._base + 1) % 4;
				goto retryPoint;
			}
			break;
		case 1:
			if (!alowsBase(_funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].calculate(), HEX))
			{
				_settings._base = (_settings._base + 1) % 4;
				goto retryPoint;
			}
			break;
		case 2:
			if (!alowsBase(_funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].calculate(), BIN))
			{
				_settings._base = (_settings._base + 1) % 4;
				goto retryPoint;
			}
			break;
		case 3:
			if (!alowsBase(_funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].calculate(), OCT))
			{
				_settings._base = (_settings._base + 1) % 4;
				goto retryPoint;
			}
			break;
		default:
			break;
		}
	}
}

void RechnerClass::moveDown()
{
	if (_pointAt != 49)
	{
		if (_pointAt != (_amountSaved + 1) % 50)
			_pointAt++;
	}
	else
		if (_pointAt != (_amountSaved + 1) % 50)
			_pointAt = 0;

	_pointInString = _stringSize[_pointAt];

	if (_stringSize[_pointAt] < 15)
		_displatStart[_pointAt] = 0;
	else
		_displatStart[_pointAt] = _stringSize[_pointAt] - 15;

	if (_funktions[(_pointAt - 1) % 5].checkExistance())
	{
	retryPoint:
		switch (_settings._base)
		{
		case 0:
			if (!alowsBase(_funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].calculate(), DEC))
			{
				_settings._base = (_settings._base + 1) % 4;
				goto retryPoint;
			}
			break;
		case 1:
			if (!alowsBase(_funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].calculate(), HEX))
			{
				_settings._base = (_settings._base + 1) % 4;
				goto retryPoint;
			}
			break;
		case 2:
			if (!alowsBase(_funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].calculate(), BIN))
			{
				_settings._base = (_settings._base + 1) % 4;
				goto retryPoint;
			}
			break;
		case 3:
			if (!alowsBase(_funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].calculate(), OCT))
			{
				_settings._base = (_settings._base + 1) % 4;
				goto retryPoint;
			}
			break;
		default:
			break;
		}
	}
}

void RechnerClass::moveRight()
{
	if (_pointInString < _stringSize[_pointAt])
		_pointInString++;

	if (_pointInString > _displatStart[_pointAt] + 15)
		_displatStart[_pointAt]++;
}

void RechnerClass::moveLeft()
{
	if (_pointInString > 0)
		_pointInString--;

	if (_pointInString < _displatStart[_pointAt])
		_displatStart[_pointAt]--;
}

void RechnerClass::insertChar(char c)
{
	if (_stringSize[_pointAt] < 512)
	{
		if (_pointInString == _stringSize[_pointAt]++)
		{
			_strings[_pointAt][_pointInString++] = c;
		}
		else
		{
			for (__uint8_t i = _stringSize[_pointAt]; i > _pointInString; i--)
			{
				_strings[_pointAt][i] = _strings[_pointAt][i - 1];
			}
			_strings[_pointAt][_pointInString++] = c;
		}

		if (_pointInString > _displatStart[_pointAt] + 15)
			_displatStart[_pointAt]++;
	}
}

void RechnerClass::enter()
{
	if (_stringSize[_pointAt] > 0)
	{

		if ((1 + _amountSaved) % 50 == _pointAt)
		{
			_amountSaved = (1 + _amountSaved) % 50;
			_stringSize[(1 + _amountSaved) % 50] = 0;
		}

		_funktions[_pointAt].reProgram(_strings[_pointAt], -1, _stringSize[_pointAt], _funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].getStart());

		_displatStart[_pointAt] = 0;
		_pointAt = (_pointAt + 1) % 50;
		_pointInString = _stringSize[_pointAt];

		if (_stringSize[_pointAt] < 15)
			_displatStart[_pointAt] = 0;
		else
			_displatStart[_pointAt] = _stringSize[_pointAt] - 15;

		if (_funktions[(_pointAt - 1) % 5].checkExistance())
		{
		retryPoint:
			switch (_settings._base)
			{
			case 0:
				if (!alowsBase(_funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].calculate(), DEC))
				{
					_settings._base = (_settings._base + 1) % 4;
					goto retryPoint;
				}
				break;
			case 1:
				if (!alowsBase(_funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].calculate(), HEX))
				{
					_settings._base = (_settings._base + 1) % 4;
					goto retryPoint;
				}
				break;
			case 2:
				if (!alowsBase(_funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].calculate(), BIN))
				{
					_settings._base = (_settings._base + 1) % 4;
					goto retryPoint;
				}
				break;
			case 3:
				if (!alowsBase(_funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].calculate(), OCT))
				{
					_settings._base = (_settings._base + 1) % 4;
					goto retryPoint;
				}
				break;
			default:
				break;
			}
		}
	}
}

void RechnerClass::delet()
{
	if (_pointInString != 0)
	{
		for (__uint8_t i = _pointInString; i < _stringSize[_pointAt]; i++)
		{
			_strings[_pointAt][i - 1] = _strings[_pointAt][i];
		}
		_stringSize[_pointAt]--;
		_pointInString--;

		if (_pointInString < _displatStart[_pointAt])
			_displatStart[_pointAt]--;
	}
}

void RechnerClass::deletAll()
{
	_pointInString = 0;
	_displatStart[_pointAt] = 0;
	_stringSize[_pointAt] = 0;
}

void RechnerClass::outputMode()
{
	_settings._base = (_settings._base + 1) % 4;

	if (_funktions[(_pointAt - 1) % 5].checkExistance())
	{
	retryPoint:
		switch (_settings._base)
		{
		case 0:
			if (!alowsBase(_funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].calculate(), DEC))
			{
				_settings._base = (_settings._base + 1) % 4;
				goto retryPoint;
			}
			break;
		case 1:
			if (!alowsBase(_funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].calculate(), HEX))
			{
				_settings._base = (_settings._base + 1) % 4;
				goto retryPoint;
			}
			break;
		case 2:
			if (!alowsBase(_funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].calculate(), BIN))
			{
				_settings._base = (_settings._base + 1) % 4;
				goto retryPoint;
			}
			break;
		case 3:
			if (!alowsBase(_funktions[(_pointAt - 1) < 0 ? 49 : _pointAt - 1].calculate(), OCT))
			{
				_settings._base = (_settings._base + 1) % 4;
				goto retryPoint;
			}
			break;
		default:
			break;
		}
	}
}

RechnerClass Rechner;

