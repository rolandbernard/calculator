

#include "grapher.h"

float stepsizeX(float _scaleX)
{
	__int32_t exp = (__int32_t)floorf(log10f(_scaleX / 6));
	__int32_t val = (__int32_t)roundf(_scaleX / 6 / pow10f(exp));

	return val * pow10f(exp);
}

float stepsizeY(float _scaleY)
{
	__int32_t exp = (__int32_t)floorf(log10f(_scaleY / (6 * ASPECT_RATIO)));
	__int32_t val = (__int32_t)roundf(_scaleY / (6 * ASPECT_RATIO) / pow10(exp));

	return val * pow10f(exp);
}

__int16_t type(funktion* funk)
{

	if (FunktionBuffer._buffer[funk->getStart()]._type == 33 || FunktionBuffer._buffer[funk->getStart()]._type == 34)
		return 1;
	if (FunktionBuffer._buffer[FunktionBuffer._buffer[funk->getStart()]._leftNode]._type == 30 && !FunktionBuffer._buffer[FunktionBuffer._buffer[funk->getStart()]._rightNode].containsY())
		return 2;
	if (FunktionBuffer._buffer[FunktionBuffer._buffer[funk->getStart()]._leftNode]._type == 29 && !FunktionBuffer._buffer[FunktionBuffer._buffer[funk->getStart()]._rightNode].containsX())
		return 4;
	if (FunktionBuffer._buffer[FunktionBuffer._buffer[funk->getStart()]._rightNode]._type == 30 && !FunktionBuffer._buffer[FunktionBuffer._buffer[funk->getStart()]._leftNode].containsY())
		return 3;
	if (FunktionBuffer._buffer[FunktionBuffer._buffer[funk->getStart()]._rightNode]._type == 29 && !FunktionBuffer._buffer[FunktionBuffer._buffer[funk->getStart()]._leftNode].containsX())
		return 5;
	if (FunktionBuffer._buffer[funk->getStart()]._type == 32)
		return 0;

	return 0;
}

void GrapherClass::init()
{


}

void GrapherClass::display()
{
	for (__int16_t i = 0; i < 5; i++)
		_funktions[i].checkExistance();

	if (_pageAt == 0)
	{
		//Border
		tft.fillScreen(backgroundColor);
		tft.drawRect(0, 0, 320, 240, strokeColor);
		tft.drawRect(1, 1, 319, 239, strokeColor);
		tft.drawRect(2, 2, 318, 238, strokeColor);


		//  |
		//__|__
		//  |
		float step = stepsizeX(_scaleX);
		for (__int64_t i = (__int64_t)((_x - _scaleX / 2) / step); i <= (__int64_t)((_x + _scaleX / 2) / step); i++)
		{
			tft.drawFastVLine(toRealX(i * step, _x, _scaleX), 4, 234, strokeColor);
		}

		step = stepsizeY(_scaleY);
		for (__int64_t i = (__int64_t)((_y - _scaleY / 2) / step); i <= (__int64_t)((_y + _scaleY / 2) / step); i++)
		{
			tft.drawFastHLine(4, toRealY(i * step, _y, _scaleY), 314, strokeColor);
		}


		//Graph
		if (_graphChange)
		{
			for (__int16_t i = 0; i < 5; i++)
			{
				if (_stringSize[i] != 0)
				{
					if (_funktions[i].checkExistance())
					{
						Graph[i].calculateAndDisplay(&(_funktions[i]), _x, _y, _scaleX, _scaleY, type(&(_funktions[i])), _settings._color[i]);
					}
				}
			}
			_graphChange = false;
		}
		else
		{
			for (__int16_t i = 0; i < 5; i++)
			{
				if (_stringSize[i] != 0)
				{
					if (_funktions[i].checkExistance())
					{
						Graph[i].display(_settings._color[i]);
					}
				}
			}
		}


		//  |
		//__|__
		//  |
		if (_x > _scaleX * 0.45)
		{

			if (_y < _scaleY * -0.45 * ASPECT_RATIO)
			{
				float step = stepsizeX(_scaleX);

				//x
				for (__int64_t i = (__int64_t)((_x - _scaleX / 2) / step); i <= (__int64_t)((_x + _scaleX / 2) / step); i++)
				{
					tft.drawFastVLine(toRealX(i * step, _x, _scaleX) , 234, 5, textColor);
					tft.setCursor(toRealX(i * step, _x, _scaleX) - 5, 226);
					tft.setTextSize(1);
					tft.print(toString2(i * step, 5));
				}

				step = stepsizeY(_scaleY);
				//y
				for (__int64_t i = (__int64_t)((_y - _scaleY / 2) / step); i <= (__int64_t)((_y + _scaleY / 2) / step); i++)
				{
					tft.drawFastHLine(3, toRealY(i * step, _y, _scaleY), 5, textColor);
					tft.setCursor(12, toRealY(i * step, _y, _scaleY) - 5);
					tft.setTextSize(1);
					tft.print(toString2(-i * step, 5));
				}
			}
			else if (_y > _scaleY * +0.45 * ASPECT_RATIO)
			{
				float step = stepsizeX(_scaleX);

				//x
				for (__int64_t i = (__int64_t)((_x - _scaleX / 2) / step); i <= (__int64_t)((_x + _scaleX / 2) / step); i++)
				{
					tft.drawFastVLine(toRealX(i * step, _x, _scaleX), 3, 5, textColor);
					tft.setCursor(toRealX(i * step, _x, _scaleX) - 5, 9);
					tft.setTextSize(1);
					tft.print(toString2(i * step, 5));
				}

				step = stepsizeY(_scaleY);
				//y
				for (__int64_t i = (__int64_t)((_y - _scaleY / 2) / step); i <= (__int64_t)((_y + _scaleY  / 2) / step); i++)
				{
					tft.drawFastHLine(3, toRealY(i * step, _y, _scaleY), 5, textColor);
					tft.setCursor(12, toRealY(i * step, _y, _scaleY) - 5);
					tft.setTextSize(1);
					tft.print(toString2(-i * step, 5));
				}
			}
			else
			{

				float step = stepsizeX(_scaleX);

				// x
				tft.drawFastHLine(4, toRealY(0, _y, _scaleY), 314, textColor);
				for (__int64_t i = (__int64_t)((_x - _scaleX / 2) / step); i <= (__int64_t)((_x + _scaleX / 2) / step); i++)
				{
					tft.drawFastVLine(toRealX(i * step, _x, _scaleX), toRealY(0, _y, _scaleY) - 5, 5, textColor);
					tft.setCursor(toRealX(i * step, _x, _scaleX) - 5, toRealY(0, _y, _scaleY) + 5);
					tft.setTextSize(1);
					tft.print(toString2(i * step, 6));
				}

				step = stepsizeY(_scaleY);
				// y
				for (__int64_t i = (__int64_t)((_y - _scaleY / 2) / step); i <= (__int64_t)((_y + _scaleY / 2) / step); i++)
				{
					tft.drawFastHLine(3, toRealY(i * step, _y, _scaleY), 5, textColor);
					tft.setCursor(12, toRealY(i * step, _y, _scaleY) - 5);
					tft.setTextSize(1);
					tft.print(toString2(-i * step, 6));
				}
			}
		}
		else if (_x < _scaleX * -0.45)
		{

			if (_y > _scaleY * 0.45 * ASPECT_RATIO)
			{

				float step = stepsizeX(_scaleX);

				//x
				for (__int64_t i = (__int64_t)((_x - _scaleX / 2) / step); i <= (__int64_t)((_x + _scaleX / 2) / step); i++)
				{
					tft.drawFastVLine(toRealX(i * step, _x, _scaleX), 3, 5, textColor);
					tft.setCursor(toRealX(i * step, _x, _scaleX) - 5, 9);
					tft.setTextSize(1);
					tft.print(toString2(i * step, 5));
				}

				step = stepsizeY(_scaleY);
				//y
				for (__int64_t i = (__int64_t)((_y - _scaleY / 2) / step); i <= (__int64_t)((_y + _scaleY / 2) / step); i++)
				{
					tft.drawFastHLine(312, toRealY(i * step, _y, _scaleY), 5, textColor);
					String str = toString2(-i * step, 5);
					tft.setCursor(311 - (str.length() * 6), toRealY(i * step, _y, _scaleY) - 5);
					tft.setTextSize(1);
					tft.print(str);
				}
			}
			else if (_y < _scaleY * -0.45 * ASPECT_RATIO)
			{
				float step = stepsizeX(_scaleX);

				//x
				for (__int64_t i = (__int64_t)((_x - _scaleX / 2) / step); i <= (__int64_t)((_x + _scaleX / 2) / step); i++)
				{
					tft.drawFastVLine(toRealX(i * step, _x, _scaleX), 234, 5, textColor);
					tft.setCursor(toRealX(i * step, _x, _scaleX) - 5, 226);
					tft.setTextSize(1);
					tft.print(toString2(i * step, 5));
				}

				step = stepsizeY(_scaleY);
				//y
				for (__int64_t i = (__int64_t)((_y - _scaleY / 2) / step); i <= (__int64_t)((_y + _scaleY / 2) / step); i++)
				{
					tft.drawFastHLine(312, toRealY(i * step, _y, _scaleY), 5, textColor);
					String str = toString2(-i * step, 5);
					tft.setCursor(311 - (str.length() * 6), toRealY(i * step, _y, _scaleY) - 5);
					tft.setTextSize(1);
					tft.print(str);
				}
			}
			else
			{

				float step = stepsizeX(_scaleX);

				// x
				tft.drawFastHLine(4, toRealY(0, _y, _scaleY), 314, textColor);
				for (__int64_t i = (__int64_t)((_x - _scaleX / 2) / step); i <= (__int64_t)((_x + _scaleX / 2) / step); i++)
				{
					tft.drawFastVLine(toRealX(i * step, _x, _scaleX), toRealY(0, _y, _scaleY) - 5, 5, textColor);
					tft.setCursor(toRealX(i * step, _x, _scaleX) - 5, toRealY(0, _y, _scaleY) + 2);
					tft.setTextSize(1);
					tft.print(toString2(i * step, 6));
				}

				step = stepsizeY(_scaleY);
				// y
				for (__int64_t i = (__int64_t)((_y - _scaleY / 2) / step); i <= (__int64_t)((_y + _scaleY / 2) / step); i++)
				{
					tft.drawFastHLine(312, toRealY(i * step, _y, _scaleY), 5, textColor);
					String str = toString2(-i * step, 5);
					tft.setCursor(311 - (str.length() * 6), toRealY(i * step, _y, _scaleY) - 5);
					tft.setTextSize(1);
					tft.print(str);
				}
			}
		}
		else
		{
			if (_y < _scaleY * -0.45 * ASPECT_RATIO)
			{
				float step = stepsizeX(_scaleX);

				//x
				for (__int64_t i = (__int64_t)((_x - _scaleX / 2) / step); i <= (__int64_t)((_x + _scaleX / 2) / step); i++)
				{
					tft.drawFastVLine(toRealX(i * step, _x, _scaleX), 234, 5, textColor);
					tft.setCursor(toRealX(i * step, _x, _scaleX) - 5, 226);
					tft.setTextSize(1);
					tft.print(toString2(i * step, 6));
				}

				step = stepsizeY(_scaleY);
				//y
				tft.drawFastVLine(toRealX(0, _x, _scaleX), 4, 234, textColor);
				for (__int64_t i = (__int64_t)((_y - _scaleY / 2) / step); i <= (__int64_t)((_y + _scaleY / 2) / step); i++)
				{
					tft.drawFastHLine(toRealX(0, _x,_scaleX), toRealY(i * step, _y, _scaleY), 5, textColor);
					tft.setCursor(toRealX(0, _x, _scaleX) + 7, toRealY(i * step, _y, _scaleY) - 5);
					tft.setTextSize(1);
					tft.print(toString2(-i * step, 6));
				}
			}
			else if (_y > _scaleY * 0.45 * ASPECT_RATIO)
			{
				float step = stepsizeX(_scaleX);

				//x
				for (__int64_t i = (__int64_t)((_x - _scaleX / 2) / step); i <= (__int64_t)((_x + _scaleX / 2) / step); i++)
				{
					tft.drawFastVLine(toRealX(i * step, _x, _scaleX), 3, 5, textColor);
					tft.setCursor(toRealX(i * step, _x, _scaleX) - 5, 9);
					tft.setTextSize(1);
					tft.print(toString2(i * step, 6));
				}

				step = stepsizeY(_scaleY);
				//y
				tft.drawFastVLine(toRealX(0, _x, _scaleX), 4, 234, textColor);
				for (__int64_t i = (__int64_t)((_y - _scaleY / 2) / step); i <= (__int64_t)((_y + _scaleY / 2) / step); i++)
				{
					tft.drawFastHLine(toRealX(0, _x, _scaleX), toRealY(i * step, _y, _scaleY), 5, textColor);
					tft.setCursor(toRealX(0, _x, _scaleX) + 7, toRealY(i * step, _y, _scaleY) - 5);
					tft.setTextSize(1);
					tft.print(toString2(-i * step, 6));
				}
			}
			else
			{

				float step = stepsizeX(_scaleX);

				// x
				tft.drawFastHLine(4, toRealY(0, _y, _scaleY), 314, textColor);
				for (__int64_t i = (__int64_t)((_x - _scaleX / 2) / step); i <= (__int64_t)((_x + _scaleX / 2) / step); i++)
				{
					tft.drawFastVLine(toRealX(i * step, _x, _scaleX), toRealY(0, _y, _scaleY) - 5, 5, textColor);
					tft.setCursor(toRealX(i * step, _x, _scaleX) - 5, toRealY(0, _y, _scaleY) + 2);
					tft.setTextSize(1);
					tft.print(toString2(i * step, 6));
				}

				step = stepsizeY(_scaleY);
				// y
				tft.drawFastVLine(toRealX(0, _x, _scaleX), 4, 234, textColor);
				for (__int64_t i = (__int64_t)((_y - _scaleY / 2) / step); i <= (__int64_t)((_y + _scaleY / 2) / step); i++)
				{
					tft.drawFastHLine(toRealX(0, _x, _scaleX), toRealY(i * step, _y, _scaleY), 5, textColor);
					tft.setCursor(toRealX(0, _x, _scaleX) + 7, toRealY(i * step, _y, _scaleY) - 5);
					tft.setTextSize(1);
					tft.print(toString2(-i * step, 6));
				}
			}
		}


		//sizeChange
		if (_x != _xw || _y != _yw)
		{
			tft.drawFastVLine(toRealX(_xw, _x, _scaleX), toRealY(_yw, _y, _scaleY) - 5, 11, lightSelectionColor);
			tft.drawFastHLine(toRealX(_xw, _x, _scaleX) - 5, toRealY(_yw, _y, _scaleY), 11, lightSelectionColor);
			tft.drawRect(toRealX(_xw - _scaleXw / 2, _x, _scaleX), toRealY(_yw - _scaleYw / 2, _y, _scaleY), _scaleXw / _scaleX * 320, _scaleYw / _scaleY * 240, lightSelectionColor);
		}
		else if (_scaleX != _scaleXw || _scaleY != _scaleYw)
		{
			tft.drawRect(toRealX(_xw - _scaleXw / 2, _x, _scaleX), toRealY(_yw - _scaleYw / 2, _y, _scaleY), _scaleXw / _scaleX * 320, _scaleYw / _scaleY * 240, lightSelectionColor);
		}

		if (_scaleMode == 1)
		{
			tft.drawChar(15, 15, 'x', selectionColor, backgroundColor, 1);
		}
		else if (_scaleMode == 2)
		{
			tft.drawChar(15, 15, 'y', selectionColor, backgroundColor, 1);
		}


		//
		if (_select)
		{
			__int16_t fType = type(&(_funktions[_selected]));

			__int32_t x = 0;
			__int32_t y = 0;

			float realX = .0;
			float realY = .0;

			//Calculating Xs and Ys
			if (fType == 2 || fType == 3)
			{
				realX = _xSelect;
				x = toRealX(realX, _x, _scaleX);

				if (fType == 3)
				{
					realY = FunktionBuffer._buffer[FunktionBuffer._buffer[_funktions[_selected].getStart()]._leftNode].calculate(realX, NAN);
				}
				else
				{
					realY = FunktionBuffer._buffer[FunktionBuffer._buffer[_funktions[_selected].getStart()]._rightNode].calculate(realX, NAN);
				}

				y = toInvRealY(realY, _y, _scaleY);
			}
			else if (fType == 4 || fType == 5)
			{
				realY = _ySelect;
				y = toRealY(realY, _y, _scaleY);

				if (fType == 5)
				{
					realX = FunktionBuffer._buffer[FunktionBuffer._buffer[_funktions[_selected].getStart()]._leftNode].calculate(NAN, -realY);
				}
				else
				{
					realX = FunktionBuffer._buffer[FunktionBuffer._buffer[_funktions[_selected].getStart()]._rightNode].calculate(NAN, -realY);
				}

				x = toRealX(realX, _x, _scaleX);
					
			}

			tft.drawFastHLine(0, y, x + 5, selectionColor);
			tft.drawFastVLine(x, 0, y + 5, selectionColor);

			tft.setTextColor(selectionColor, backgroundColor);
			tft.setCursor(x + 5, y + 5);
			tft.setTextSize(1);
			tft.println("y = " + toString2(realY, 6));
			tft.setCursor(x + 5, y + 15);
			tft.print("x = " + toString2(realX, 6));
			tft.setTextColor(selectionColor);

		}

	}
	else if (_pageAt == 1)
	{
		//Background
		tft.drawRect(0, 6, 78, 227, strokeColor);
		tft.drawRect(0, 7, 77, 225, strokeColor);
		tft.drawRect(0, 8, 76, 223, strokeColor);
		tft.fillRect(0, 9, 74, 221, backgroundColor);

		//f1
		tft.drawRect(5, 15, 65, 37, strokeColor);
		tft.drawRect(6, 16, 63, 35, strokeColor);
		tft.drawRect(7, 17, 61, 33, strokeColor);
		tft.fillRect(10, 20, 55, 27, _settings._color[0]);

		if ( _pointAt == 0)
		{
			tft.drawRect(5, 15, 65, 37, selectionColor);
			tft.drawRect(4, 14, 67, 39, selectionColor);
			tft.drawRect(3, 13, 69, 41, selectionColor);
		}


		//f2
		tft.drawRect(5, 58, 65, 37, strokeColor);
		tft.drawRect(6, 59, 63, 35, strokeColor);
		tft.drawRect(7, 60, 61, 33, strokeColor);
		tft.fillRect(10, 63, 55, 27, _settings._color[1]);

		if (_pointAt == 1)
		{
			tft.drawRect(5, 58, 65, 37, selectionColor);
			tft.drawRect(4, 57, 67, 39, selectionColor);
			tft.drawRect(3, 56, 69, 41, selectionColor);
		}


		//f3
		tft.drawRect(5, 101, 65, 37, strokeColor);
		tft.drawRect(6, 102, 63, 35, strokeColor);
		tft.drawRect(7, 103, 61, 33, strokeColor);
		tft.fillRect(10, 106, 55, 27, _settings._color[2]);

		if (_pointAt == 2)
		{
			tft.drawRect(5, 101, 65, 37, selectionColor);
			tft.drawRect(4, 100, 67, 39, selectionColor);
			tft.drawRect(3, 99, 69, 41, selectionColor);
		}


		//f4
		tft.drawRect(5, 144, 65, 37, strokeColor);
		tft.drawRect(6, 145, 63, 35, strokeColor);
		tft.drawRect(7, 146, 61, 33, strokeColor);
		tft.fillRect(10, 149, 55, 27, _settings._color[3]);

		if (_pointAt == 3)
		{
			tft.drawRect(5, 144, 65, 37, selectionColor);
			tft.drawRect(4, 143, 67, 39, selectionColor);
			tft.drawRect(3, 142, 69, 41, selectionColor);
		}


		//f5
		tft.drawRect(5, 187, 65, 37, strokeColor);
		tft.drawRect(6, 188, 63, 35, strokeColor);
		tft.drawRect(7, 189, 61, 33, strokeColor);
		tft.fillRect(10, 192, 55, 27, _settings._color[4]);

		if (_pointAt == 4)
		{
			tft.drawRect(5, 187, 65, 37, selectionColor);
			tft.drawRect(4, 186, 67, 39, selectionColor);
			tft.drawRect(3, 185, 69, 41, selectionColor);
		}


		//Writing
		tft.drawRect(70, 62, 241, 60, strokeColor);
		tft.drawRect(71, 63, 239, 58, strokeColor);
		tft.drawRect(72, 64, 237, 56, strokeColor);
		tft.fillRect(73, 65, 235, 54, backgroundColor);

		for (int i = _displatStart[_pointAt]; i < _displatStart[_pointAt] + 13 && i < _stringSize[_pointAt]; i++)
		{
			if (_strings[_pointAt][i] == '\\')
			{
				tft.drawLine(74 + 18 * (i - _displatStart[_pointAt]), 90, 79 + 18 * (i - _displatStart[_pointAt]), 90, textColor);
				tft.drawLine(79 + 18 * (i - _displatStart[_pointAt]), 90, 82 + 18 * (i - _displatStart[_pointAt]), 103, textColor);
				tft.drawLine(82 + 18 * (i - _displatStart[_pointAt]), 103, 86 + 18 * (i - _displatStart[_pointAt]), 79, textColor);
				tft.drawLine(86 + 18 * (i - _displatStart[_pointAt]), 79, 91 + 18 * (i - _displatStart[_pointAt]), 79, textColor);

				tft.drawLine(74 + 18 * (i - _displatStart[_pointAt]), 91, 79 + 18 * (i - _displatStart[_pointAt]), 91, textColor);
				tft.drawLine(79 + 18 * (i - _displatStart[_pointAt]), 91, 82 + 18 * (i - _displatStart[_pointAt]), 102, textColor);
				tft.drawLine(82 + 18 * (i - _displatStart[_pointAt]), 102, 86 + 18 * (i - _displatStart[_pointAt]), 78, textColor);
				tft.drawLine(86 + 18 * (i - _displatStart[_pointAt]), 78, 91 + 18 * (i - _displatStart[_pointAt]), 78, textColor);

				tft.drawLine(74 + 18 * (i - _displatStart[_pointAt]), 92, 79 + 18 * (i - _displatStart[_pointAt]), 92, textColor);
				tft.drawLine(79 + 18 * (i - _displatStart[_pointAt]), 92, 82 + 18 * (i - _displatStart[_pointAt]), 101, textColor);
				tft.drawLine(82 + 18 * (i - _displatStart[_pointAt]), 101, 86 + 18 * (i - _displatStart[_pointAt]), 77, textColor);
				tft.drawLine(86  + 18 * (i - _displatStart[_pointAt]), 77, 91 + 18 * (i - _displatStart[_pointAt]), 77, textColor);
			}
			else if (_strings[_pointAt][i] == '$')
			{
				tft.drawLine(74 + 18 * (i - _displatStart[_pointAt]), 90, 79 + 18 * (i - _displatStart[_pointAt]), 90, textColor);
				tft.drawLine(79 + 18 * (i - _displatStart[_pointAt]), 90, 82 + 18 * (i - _displatStart[_pointAt]), 103, textColor);
				tft.drawLine(82 + 18 * (i - _displatStart[_pointAt]), 103, 86 + 18 * (i - _displatStart[_pointAt]), 79, textColor);
				tft.drawLine(86 + 18 * (i - _displatStart[_pointAt]), 79, 91 + 18 * (i - _displatStart[_pointAt]), 79, textColor);

				tft.drawLine(74 + 18 * (i - _displatStart[_pointAt]), 91, 79 + 18 * (i - _displatStart[_pointAt]), 91, textColor);
				tft.drawLine(79 + 18 * (i - _displatStart[_pointAt]), 91, 82 + 18 * (i - _displatStart[_pointAt]), 102, textColor);
				tft.drawLine(82 + 18 * (i - _displatStart[_pointAt]), 102, 86 + 18 * (i - _displatStart[_pointAt]), 78, textColor);
				tft.drawLine(86 + 18 * (i - _displatStart[_pointAt]), 78, 91 + 18 * (i - _displatStart[_pointAt]), 78, textColor);

				tft.drawLine(74 + 18 * (i - _displatStart[_pointAt]), 92, 79 + 18 * (i - _displatStart[_pointAt]), 92, textColor);
				tft.drawLine(79 + 18 * (i - _displatStart[_pointAt]), 92, 82 + 18 * (i - _displatStart[_pointAt]), 101, textColor);
				tft.drawLine(82 + 18 * (i - _displatStart[_pointAt]), 101, 86 + 18 * (i - _displatStart[_pointAt]), 77, textColor);
				tft.drawLine(86 + 18 * (i - _displatStart[_pointAt]), 77, 91 + 18 * (i - _displatStart[_pointAt]), 77, textColor);

				tft.drawChar(74 + 18 * (i - _displatStart[_pointAt]), 82, '2', textColor, backgroundColor, 1);
			}
			else if (_strings[_pointAt][i] == '#')
			{
				tft.drawLine(74 + 18 * (i - _displatStart[_pointAt]), 90, 79 + 18 * (i - _displatStart[_pointAt]), 90, textColor);
				tft.drawLine(79 + 18 * (i - _displatStart[_pointAt]), 90, 82 + 18 * (i - _displatStart[_pointAt]), 103, textColor);
				tft.drawLine(82 + 18 * (i - _displatStart[_pointAt]), 103, 86 + 18 * (i - _displatStart[_pointAt]), 79, textColor);
				tft.drawLine(86 + 18 * (i - _displatStart[_pointAt]), 79, 91 + 18 * (i - _displatStart[_pointAt]), 79, textColor);

				tft.drawLine(74 + 18 * (i - _displatStart[_pointAt]), 91, 79 + 18 * (i - _displatStart[_pointAt]), 91, textColor);
				tft.drawLine(79 + 18 * (i - _displatStart[_pointAt]), 91, 82 + 18 * (i - _displatStart[_pointAt]), 102, textColor);
				tft.drawLine(82 + 18 * (i - _displatStart[_pointAt]), 102, 86 + 18 * (i - _displatStart[_pointAt]), 78, textColor);
				tft.drawLine(86 + 18 * (i - _displatStart[_pointAt]), 78, 91 + 18 * (i - _displatStart[_pointAt]), 78, textColor);

				tft.drawLine(74 + 18 * (i - _displatStart[_pointAt]), 92, 79 + 18 * (i - _displatStart[_pointAt]), 92, textColor);
				tft.drawLine(79 + 18 * (i - _displatStart[_pointAt]), 92, 82 + 18 * (i - _displatStart[_pointAt]), 101, textColor);
				tft.drawLine(82 + 18 * (i - _displatStart[_pointAt]), 101, 86 + 18 * (i - _displatStart[_pointAt]), 77, textColor);
				tft.drawLine(86 + 18 * (i - _displatStart[_pointAt]), 77, 91 + 18 * (i - _displatStart[_pointAt]), 77, textColor);

				tft.drawChar(74 + 18 * (i - _displatStart[_pointAt]), 82, '3', textColor, backgroundColor, 1);
			}
			else
				tft.drawChar(74 + 18 * (i - _displatStart[_pointAt]), 80, _strings[_pointAt][i], textColor, backgroundColor, 3);

		}

		tft.fillRect(74 + 18 * (_pointInString - _displatStart[_pointAt]), 102, 15, 3, textColor);
	}
}

void GrapherClass::moveUp()
{
	if (_pageAt == 0)
	{
		if (_select)
			_ySelect -= _movement * _scaleY;
		else
			_yw -= _movement * _scaleY;
	}
	else if (_pageAt == 1)
	{
		if (_pointAt != 0)
			_pointAt--;
		else
			_pointAt = 4;


		_pointInString = _stringSize[_pointAt];

		if (_stringSize[_pointAt] < 12)
			_displatStart[_pointAt] = 0;
		else
			_displatStart[_pointAt] = _stringSize[_pointAt] - 12;
	}
}

void GrapherClass::moveDown()
{
	if (_pageAt == 0)
	{
		if (_select)
			_ySelect += _movement * _scaleY;
		else
			_yw += _movement * _scaleY;
	}
	else if (_pageAt == 1)
	{
		if (_pointAt != 4)
			_pointAt++;
		else
			_pointAt = 0;

		_pointInString = _stringSize[_pointAt];

		if (_stringSize[_pointAt] < 12)
			_displatStart[_pointAt] = 0;
		else
			_displatStart[_pointAt] = _stringSize[_pointAt] - 12;
	}
}

void GrapherClass::moveRight()
{
	if (_pageAt == 0)
	{
		if (_select)
			_xSelect += _movement * _scaleX;
		else
			_xw += _movement * _scaleX;
	}
	else if (_pageAt == 1)
	{
		if (_pointInString < _stringSize[_pointAt])
			_pointInString++;

		if (_pointInString > _displatStart[_pointAt] + 12)
			_displatStart[_pointAt]++;
	}
}

void GrapherClass::moveLeft()
{
	if (_pageAt == 0)
	{
		if(_select)
			_xSelect -= _movement * _scaleX;
		else
			_xw -= _movement * _scaleX;
	}
	else if (_pageAt == 1)
	{
		if (_pointInString > 0)
			_pointInString--;

		if (_pointInString < _displatStart[_pointAt])
			_displatStart[_pointAt]--;
	}
}

void GrapherClass::insertChar(char c)
{
	if (_pageAt == 0)
	{
		if (c == '+')
		{
			if (_scaleXw < _scaleX && _scaleXw < _scaleX)
			{
				switch (_scaleMode)
				{
				case 0:
						_scaleXw += _movement * _scaleX;

						_scaleYw += _movement * _scaleY;
					break;
				case 1:
						_scaleXw += _movement * _scaleX;
					break;
				case 2:
						_scaleYw += _movement * _scaleY;
					break;
				default:
					break;
				}
			}
			else
			{
				_graphChange = true;

				_scaleX += _movement * _scaleX;
				_scaleXw = _scaleX;
				_scaleY += _movement * _scaleY;
				_scaleYw = _scaleY;
			}
		}
		else if (c == '-')
		{
			switch (_scaleMode)
			{
			case 0:
				if (_scaleXw > _movement * _scaleX)
					_scaleXw -= _movement * _scaleX;

				if (_scaleYw > _movement * _scaleY)
					_scaleYw -= _movement * _scaleY;
				break;
			case 1:
				if (_scaleXw > _movement * _scaleX)
					_scaleXw -= _movement * _scaleX;
				break;
			case 2:
				if (_scaleYw > _movement * _scaleY)
					_scaleYw -= _movement * _scaleY;
				break;
			default:
				break;
			}
		}
		else if (c == 'x' || c == 'y')
		{
			_scaleMode = (_scaleMode + 1) % 3;
		}
		else if (c == '*')
		{
			_movement *= 2;
		}
		else if (c == '/')
		{
			_movement /= 2;
		}
		else if (c == '^')
		{
			if (_select)
			{
				_select = false;
			}
			else
			{
				bool found = false;
				for (__int16_t i = 0; i < 5; i++)
					if (type(&(_funktions[i])) != 0 && type(&(_funktions[i])) != 1 && _stringSize[i] != 0)
					{
						found = true;
						_canidateForSeclect[i] = true;
					}
					else
						_canidateForSeclect[i] = false;


				if (found)
				{
					_select = true;
					for (__int16_t i = 0; i < 5; i++)
						if (_canidateForSeclect[i])
						{
							_selected = i;
							break;
						}
				}

				_xSelect = _x;
				_ySelect = _y;
			}
		}
		else if (c == '\\')
		{
			if (_select)
			{
				for (__int16_t i = _selected + 1; i < _selected + 6; i++)
					if (_canidateForSeclect[i % 5])
					{
						_selected = i % 5;
						break;
					}

				_xSelect = _x;
				_ySelect = _y;
			}
		}

	}
	else if (_pageAt == 1)
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

			if (_pointInString > _displatStart[_pointAt] + 12)
				_displatStart[_pointAt]++;
		}
	}
}

void GrapherClass::enter()
{
	if (_pageAt == 0)
	{
		_x = _xw;
		_y = _yw;
		_scaleX = _scaleXw;
		_scaleY = _scaleYw;
	}
	else if (_pageAt == 1)
	{
		_select = false;
		_pageAt = 0;

		for (__int16_t i = 0; i < 5; i++)
			if (_stringSize[i] != 0)
				_funktions[i].reProgram(_strings[i], -1, _stringSize[i], -1);

	}

	_graphChange = true;

}

void GrapherClass::funktions()
{
	if (_pageAt == 0)
		_pageAt = 1;
	else if (_pageAt == 1)
	{
		_pageAt = 0;
		_select = false;
		_graphChange = true;

		for (__int16_t i = 0; i < 5; i++)
			if (_stringSize[i] != 0)
				_funktions[i].reProgram(_strings[i], -1, _stringSize[i], -1);
	}
}

void GrapherClass::delet()
{
	if (_pageAt == 0)
	{
		_x = 0;
		_y = 0;
		_scaleX = 2;
		_scaleY = 2 * ASPECT_RATIO;
		_xw = 0;
		_yw = 0;
		_scaleXw = 2;
		_scaleYw = 2 * ASPECT_RATIO;

		_graphChange = true;
	}
	else
	if (_pageAt == 1)
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
}

void GrapherClass::deletAll()
{
	if (_pageAt == 0)
	{
		_xw = _x;
		_yw = _y;
		_scaleXw = _scaleX;
		_scaleYw = _scaleY;
	}
	else if (_pageAt == 1)
	{
		_pointInString = 0;
		_displatStart[_pointAt] = 0;
		_stringSize[_pointAt] = 0;
	}
}


GrapherClass Grapher;