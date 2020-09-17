

#include "graph.h"

void GraphClass::drawLine(__int16_t _x1, __int16_t _y1, __int16_t _x2, __int16_t _y2)
{
	__int16_t distX = _x1 - _x2;
	__int16_t distY = _y1 - _y2;
	__int16_t minY;
	__int16_t minX;

	if ((distX < 0 ? -distX : distX) > (distY < 0 ? -distY : distY))
	{
		minX = _x1 < _x2 ? _x1 : _x2;
		if (minX == _x1)
			minY = _y1;
		else
			minY = _y2;

		for (__int16_t i = minX; i <= minX + (distX < 0 ? -distX : distX); i++)
		{
			drawPixel(i, (__int16_t)(((i - minX) * ((float)distY / distX)) + .5) + minY);
		}
	}
	else
	{
		minY = _y1 < _y2 ? _y1 : _y2;
		if (minY == _y1)
			minX = _x1;
		else
			minX = _x2;

		for (__int16_t i = minY; i <= minY + (distY < 0 ? -distY : distY); i++)
		{
			drawPixel((__int16_t)(((i - minY) * ((float)distX / distY)) + .5) + minX, i);
		}
	}
}

void GraphClass::drawPixel(__int16_t _x, __int16_t _y)
{
	if (_x > -1 && _x < 320 && _y > -1 && _y < 240)
		_map[_x / 32][_y] |= 1 << (_x % 32);
}

void GraphClass::drawLineAndDraw(__int16_t _x1, __int16_t _y1, __int16_t _x2, __int16_t _y2, __uint16_t _color)
{
	__int16_t distX = _x1 - _x2;
	__int16_t distY = _y1 - _y2;
	__int16_t minY;
	__int16_t minX;

	if ((distX < 0 ? -distX : distX) >(distY < 0 ? -distY : distY))
	{
		minX = _x1 < _x2 ? _x1 : _x2;
		if (minX == _x1)
			minY = _y1;
		else
			minY = _y2;

		for (__int16_t i = minX; i <= minX + (distX < 0 ? -distX : distX); i++)
		{
			drawPixelAndDraw(i, (__int16_t)(((i - minX) * ((float)distY / distX)) + .5) + minY, _color);
		}
	}
	else
	{
		minY = _y1 < _y2 ? _y1 : _y2;
		if (minY == _y1)
			minX = _x1;
		else
			minX = _x2;

		for (__int16_t i = minY; i <= minY + (distY < 0 ? -distY : distY); i++)
		{
			drawPixelAndDraw((__int16_t)(((i - minY) * ((float)distX / distY)) + .5) + minX, i , _color);
		}
	}
}

void GraphClass::drawPixelAndDraw(__int16_t _x, __int16_t _y, __uint16_t _color)
{
	if (_x > -1 && _x < 320 && _y > -1 && _y < 240)
	{
		_map[_x / 32][_y] |= 1 << (_x % 32);
		tft.drawPixel(_x, _y, _color);
	}
}

bool GraphClass::getPixel(__int16_t _x, __int16_t _y)
{
	return ((_map[_x / 32][_y] >> (_x % 32) ) & 1);
}

void GraphClass::init()
{


}

void GraphClass::display(__uint16_t _color)
{

	for (__int16_t x = 3; x < 317; x++)
	{
		for (__int16_t y = 3; y < 237; y++)
		{
			if (getPixel(x, y))
				tft.drawPixel(x, y, _color);
		}
	}
}

void GraphClass::calculate(funktion* _funk, float _x, float _y, float _scaleX, float _scaleY, __int16_t _type)
{
	for (__int16_t x = 0; x < 10; x++)
		for (__int16_t y = 0; y < 240; y++)
			_map[x][y] = 0;

	/*if (_type == 2 || _type == 3 )
	{

		__int32_t prey = 0;

		if(_type == 3)
			for (__int16_t x = 0; x < 320; x++)
			{

				__int32_t y = toInvRealY(FunktionBuffer._buffer[FunktionBuffer._buffer[_funk->getStart()]._leftNode].calculate(toFakeX(x + .5, _x, _scaleX), NAN), _y, _scaleY);
				
				//if (x != 0)
				//	drawLine(x, y, x - 1, prey);

				drawPixel(x, y);
				prey = y;
			}
		else
			for (__int16_t x = 0; x < 320; x++)
			{

				__int32_t y = toInvRealY(FunktionBuffer._buffer[FunktionBuffer._buffer[_funk->getStart()]._rightNode].calculate(toFakeX(x + .5, _x, _scaleX), NAN), _y, _scaleY);

				//if (x != 0)
				//	drawLine(x, y, x - 1, prey);

				drawPixel(x, y);
				prey = y;
			}
	}
	else if (_type == 4 || _type == 5)
	{

		__int32_t prex = 0;

		if (_type == 5)
			for (__int16_t y = 0; y < 240; y++)
			{

				__int32_t x = toRealX(FunktionBuffer._buffer[FunktionBuffer._buffer[_funk->getStart()]._leftNode].calculate(NAN, toFakeY(y + .5, _y, _scaleY)), _x, _scaleX);

				//if (y != 0)
				//	drawLine(x, y, prex, y - 1);

				drawPixel(x, y);

				prex = x;
			}
		else
			for (__int16_t y = 0; y < 240; y++)
			{

				__int32_t x = toRealX(FunktionBuffer._buffer[FunktionBuffer._buffer[_funk->getStart()]._rightNode].calculate(NAN, toFakeY(y + .5, _y, _scaleY)), _x, _scaleX);
				
				//if (y != 0)
				//	drawLine(x, y, prex, y - 1);

				drawPixel(x, y);

				prex = x;
			}
	}
	else*/
	{

		float tempMap[3][240];

		if (_type == 0)
		{

			tempMap[0][0] = _funk->calculate(toFakeX(.5, _x, _scaleX), toFakeY(0.5, _y, _scaleY));
			tempMap[1][0] = _funk->calculate(toFakeX(1.5, _x, _scaleX), toFakeY(0.5, _y, _scaleY));

			tempMap[0][1] = _funk->calculate(toFakeX(.5, _x, _scaleX), toFakeY(1.5, _y, _scaleY));
			tempMap[1][1] = _funk->calculate(toFakeX(1.5, _x, _scaleX), toFakeY(1.5, _y, _scaleY));

			for (__int16_t x = 1; x < 319; x++)
			{
				tempMap[2][0] = _funk->calculate(toFakeX(x + 1.5, _x, _scaleX), toFakeY(0.5, _y, _scaleY));
				tempMap[2][1] = _funk->calculate(toFakeX(x + 1.5, _x, _scaleX), toFakeY(1.5, _y, _scaleY));

				for (__int16_t y = 1; y < 239; y++)
				{
					if (x == 1)
					{
						tempMap[0][y + 1] = _funk->calculate(toFakeX(x - .5, _x, _scaleX), toFakeY(y + 1.5, _y, _scaleY));
						tempMap[1][y + 1] = _funk->calculate(toFakeX(x + .5, _x, _scaleX), toFakeY(y + 1.5, _x, _scaleY));
					}
					tempMap[2][y + 1] = _funk->calculate(toFakeX(x + 1.5, _x, _scaleX), toFakeY(y + 1.5, _y, _scaleY));

					if (((tempMap[1][y] <= tempMap[1][y - 1] && tempMap[1][y] <= tempMap[1][y + 1]) && (tempMap[1][y] <= tempMap[0][y] && tempMap[1][y] <= tempMap[2][y])))
						drawPixel(x, y);

					if (y != 1)
					{
						tempMap[0][y - 2] = tempMap[1][y - 2];
						tempMap[1][y - 2] = tempMap[2][y - 2];
					}
					if (y == 238)
					{
						tempMap[0][y - 1] = tempMap[1][y - 1];
						tempMap[1][y - 1] = tempMap[2][y - 1];
						tempMap[0][y] = tempMap[1][y];
						tempMap[1][y] = tempMap[2][y];
						tempMap[0][y + 1] = tempMap[1][y + 1];
						tempMap[1][y + 1] = tempMap[2][y + 1];
					}
				}
				
			}
		}
		else
		{

			tempMap[0][0] = _funk->calculate(toFakeX(.5, _x, _scaleX), toFakeY(0.5, _y, _scaleY));
			tempMap[1][0] = _funk->calculate(toFakeX(1.5, _x, _scaleX), toFakeY(0.5, _y, _scaleY));

			tempMap[0][1] = _funk->calculate(toFakeX(.5, _x, _scaleX), toFakeY(1.5, _y, _scaleY));
			tempMap[1][1] = _funk->calculate(toFakeX(1.5, _x, _scaleX), toFakeY(1.5, _y, _scaleY));

			for (__int16_t x = 1; x < 319; x++)
			{
				tempMap[2][0] = _funk->calculate(toFakeX(x + 1.5, _x, _scaleX), toFakeY(0.5, _y, _scaleY));
				tempMap[2][1] = _funk->calculate(toFakeX(x + 1.5, _x, _scaleX), toFakeY(1.5, _y, _scaleY));

				for (__int16_t y = 1; y < 239; y++)
				{
					if (x == 1)
					{
						tempMap[0][y + 1] = _funk->calculate(toFakeX(x - .5, _x, _scaleX), toFakeY(y + 1.5, _y, _scaleY));
						tempMap[1][y + 1] = _funk->calculate(toFakeX(x + .5, _x, _scaleX), toFakeY(y + 1.5, _y, _scaleY));
					}
					tempMap[2][y + 1] = _funk->calculate(toFakeX(x + 1.5, _x, _scaleX), toFakeY(y + 1.5, _y, _scaleY));

					if (tempMap[1][y] > 0)
					{
						if (tempMap[0][y] <= 0 || tempMap[2][y] <= 0 || tempMap[1][y - 1] <= 0  || tempMap[1][y + 1] <= 0 || (x + y) % 2 == 0)
							drawPixel(x, y);
					}
					
					if (y != 1)
					{
						tempMap[0][y - 2] = tempMap[1][y - 2];
						tempMap[1][y - 2] = tempMap[2][y - 2];
					}
					if (y == 238)
					{
						tempMap[0][y - 1] = tempMap[1][y - 1];
						tempMap[1][y - 1] = tempMap[2][y - 1];
						tempMap[0][y] = tempMap[1][y];
						tempMap[1][y] = tempMap[2][y];
						tempMap[0][y + 1] = tempMap[1][y + 1];
						tempMap[1][y + 1] = tempMap[2][y + 1];
					}
				}
			}
		}

	}
}

void GraphClass::calculateAndDisplay(funktion * _funk, float _x, float _y, float _scaleX, float _scaleY, __int16_t _type, __uint16_t _color)
{
	for (__int16_t x = 0; x < 10; x++)
		for (__int16_t y = 0; y < 240; y++)
			_map[x][y] = 0;

	if (_type == 2 || _type == 3)
	{

		float prey = 0;

		if (_type == 3)
			for (__int16_t x = 0; x < 320; x++)
			{
				float realY = FunktionBuffer._buffer[FunktionBuffer._buffer[_funk->getStart()]._leftNode].calculate(toFakeX(x + .5, _x, _scaleX), nanf(""));

				float y = -1;

				y = toInvRealY(realY, _y, _scaleY);

				if (x != 0 && ((y < 320 && y > -1) || (prey < 320 && prey > -1)) && (isnormal(y) || y == 0) && (isnormal(prey) || prey == 0) && (isnormal(realY) || realY == 0))
					drawLineAndDraw(x, y, x - 1, prey, _color);

				//drawPixel(x, y);
				prey = y;
			}
		else
			for (__int16_t x = 0; x < 320; x++)
			{
				float realY = FunktionBuffer._buffer[FunktionBuffer._buffer[_funk->getStart()]._rightNode].calculate(toFakeX(x + .5, _x, _scaleX), nanf(""));

				float y = -1;

				y = toInvRealY(realY, _y, _scaleY);

				if (x != 0 && ((y < 320 && y > -1) || (prey < 320 && prey > -1)) && (isnormal(y) || y == 0) && (isnormal(prey) || prey == 0) && (isnormal(realY) || realY == 0))
					drawLineAndDraw(x, y, x - 1, prey, _color);

				//drawPixel(x, y);
				prey = y;
			}
	}
	else if (_type == 4 || _type == 5)
	{

		float prex = 0;

		if (_type == 5)
			for (__int16_t y = 0; y < 240; y++)
			{
				float realX = FunktionBuffer._buffer[FunktionBuffer._buffer[_funk->getStart()]._leftNode].calculate(NAN, toFakeY(y + .5, _y, _scaleY));

				float x = -1;

				x = toRealX(realX, _x, _scaleX);

				if (y != 0 && ((x < 320 && x > -1) || (prex < 320 && prex > -1)) && (isnormal(x) || x == 0) && (isnormal(prex) || prex == 0) && (isnormal(realX) || realX == 0))
					drawLineAndDraw(x, y, prex, y - 1, _color);

				//drawPixel(x, y);

				prex = x;
			}
		else
			for (__int16_t y = 0; y < 240; y++)
			{
				float realX = FunktionBuffer._buffer[FunktionBuffer._buffer[_funk->getStart()]._rightNode].calculate(NAN, toFakeY(y + .5, _y, _scaleY));

				float x = -1;

				x = toRealX(realX, _x, _scaleX);

				if (y != 0 && ((x < 320 && x > -1)||( prex < 320 && prex > -1))  && (isnormal(x) || x == 0) && (isnormal(prex) || prex == 0) && (isnormal(realX) || realX == 0))
					drawLineAndDraw(x, y, prex, y - 1, _color);

				//drawPixel(x, y);
				
				prex = x;
			}
	}
	else
	{

		if (_type != 1)
		{

			float tempMap[3][240];

			tempMap[0][0] = _funk->calculate(toFakeX(.5, _x, _scaleX), toFakeY(0.5, _y, _scaleY));
			tempMap[1][0] = _funk->calculate(toFakeX(1.5, _x, _scaleX), toFakeY(0.5, _y, _scaleY));

			tempMap[0][1] = _funk->calculate(toFakeX(.5, _x, _scaleX), toFakeY(1.5, _y, _scaleY));
			tempMap[1][1] = _funk->calculate(toFakeX(1.5, _x, _scaleX), toFakeY(1.5, _y, _scaleY));

			for (__int16_t x = 1; x < 319; x ++)
			{
				tempMap[2][0] = _funk->calculate(toFakeX(x + 1.5, _x, _scaleX), toFakeY(0.5, _y, _scaleY));
				tempMap[2][1] = _funk->calculate(toFakeX(x + 1.5, _x, _scaleX), toFakeY(1.5, _y, _scaleY));

				for (__int16_t y = 1; y < 239; y ++)
				{
					if (x == 1)
					{
						tempMap[0][y + 1] = _funk->calculate(toFakeX(x - .5, _x, _scaleX), toFakeY(y + 1.5, _y, _scaleY));
						tempMap[1][y + 1] = _funk->calculate(toFakeX(x + .5, _x, _scaleX), toFakeY(y + 1.5, _x, _scaleY));
					}
					tempMap[2][y + 1] = _funk->calculate(toFakeX(x + 1.5, _x, _scaleX), toFakeY(y + 1.5, _y, _scaleY));

					__int8_t tempSign[3][3];

					tempSign[1][1] = tempMap[1][y] < 0 ? -1 : 1;
					tempSign[0][1] = tempMap[0][y] < 0 ? -1 : 1;
					tempSign[2][1] = tempMap[2][y] < 0 ? -1 : 1;
					tempSign[1][0] = tempMap[1][y-1] < 0 ? -1 : 1;
					tempSign[1][2] = tempMap[1][y+1] < 0 ? -1 : 1;

					if ((tempSign[1][1] != tempSign[0][1]) /*|| tempSign[1][1] != tempSign[2][1]*/ || (tempSign[1][1] != tempSign[1][0]) /*|| tempSign[1][1] != tempSign[1][2]*/)
						drawPixelAndDraw(x, y, _color);

					if (y != 1)
					{
						tempMap[0][y - 2] = tempMap[1][y - 2];
						tempMap[1][y - 2] = tempMap[2][y - 2];
					}
					if (y == 238)
					{
						tempMap[0][y - 1] = tempMap[1][y - 1];
						tempMap[1][y - 1] = tempMap[2][y - 1];
						tempMap[0][y] = tempMap[1][y];
						tempMap[1][y] = tempMap[2][y];
						tempMap[0][y + 1] = tempMap[1][y + 1];
						tempMap[1][y + 1] = tempMap[2][y + 1];
					}
				}

			}//*/

			/*float tempMap[3][3];

			for (__int16_t x = 1; x < 319; x+= 3)
			{
				for (__int16_t y = 1; y < 239; y += 3)
				{
					tempMap[0][0] = _funk->calculate(toFakeX(x - .5, _x, _scaleX), toFakeY(y - .5, _y, _scaleY));
					tempMap[2][0] = _funk->calculate(toFakeX(x + 1.5, _x, _scaleX), toFakeY(y - .5, _y, _scaleY));
					tempMap[0][2] = _funk->calculate(toFakeX(x - .5, _x, _scaleX), toFakeY(y + 1.5, _y, _scaleY));
					tempMap[2][2] = _funk->calculate(toFakeX(x + 1.5, _x, _scaleX), toFakeY(y + 1.5, _y, _scaleY));

					if (!((tempMap[0][0] < 0 && tempMap[0][2] < 0 && tempMap[2][0] < 0 && tempMap[2][2] < 0) || (tempMap[0][0] > 0 && tempMap[0][2] > 0 && tempMap[2][0] > 0 && tempMap[2][2] > 0)))
					{
						if (((tempMap[0][0] > 0 && tempMap[0][2] < 0 && tempMap[2][0] < 0 && tempMap[2][2] < 0) || (tempMap[0][0] < 0 && tempMap[0][2] > 0 && tempMap[2][0] > 0 && tempMap[2][2] > 0)))
						{
							drawPixelAndDraw(x, y - 1, _color);
							drawPixelAndDraw(x - 1, y, _color);
						}
						else if (((tempMap[0][0] < 0 && tempMap[0][2] > 0 && tempMap[2][0] < 0 && tempMap[2][2] < 0) || (tempMap[0][0] > 0 && tempMap[0][2] < 0 && tempMap[2][0] > 0 && tempMap[2][2] > 0)))
						{
							drawPixelAndDraw(x-1, y, _color);
							drawPixelAndDraw(x, y+1, _color);
						}
						else if (((tempMap[0][0] < 0 && tempMap[0][2] < 0 && tempMap[2][0] > 0 && tempMap[2][2] < 0) || (tempMap[0][0] > 0 && tempMap[0][2] > 0 && tempMap[2][0] < 0 && tempMap[2][2] > 0)))
						{
							drawPixelAndDraw(x , y-1, _color);
							drawPixelAndDraw(x+1, y, _color);
						}
						else if (((tempMap[0][0] < 0 && tempMap[0][2] < 0 && tempMap[2][0] < 0 && tempMap[2][2] > 0) || (tempMap[0][0] > 0 && tempMap[0][2] > 0 && tempMap[2][0] > 0 && tempMap[2][2] < 0)))
						{
							drawPixelAndDraw(x+1, y, _color);
							drawPixelAndDraw(x, y+1, _color);
						}
						else if (((tempMap[0][0] < 0 && tempMap[0][2] < 0 && tempMap[2][0] > 0 && tempMap[2][2] > 0) || (tempMap[0][0] > 0 && tempMap[0][2] > 0 && tempMap[2][0] < 0 && tempMap[2][2] < 0)))
						{
							drawPixelAndDraw(x, y-1, _color);
							drawPixelAndDraw(x, y+1, _color);
						}
						else if (((tempMap[0][0] < 0 && tempMap[0][2] > 0 && tempMap[2][0] < 0 && tempMap[2][2] > 0) || (tempMap[0][0] > 0 && tempMap[0][2] < 0 && tempMap[2][0] > 0 && tempMap[2][2] < 0)))
						{
							drawPixelAndDraw(x-1, y, _color);
							drawPixelAndDraw(x+1, y, _color);
						}
						else if (tempMap[0][0] > 0 && tempMap[0][2] < 0 && tempMap[2][0] < 0 && tempMap[2][2] > 0)
						{
							tempMap[1][1] = _funk->calculate(toFakeX(x + .5, _x, _scaleX), toFakeY(y + .5, _y, _scaleY));

							if (tempMap[1][1] > 0)
							{
								drawPixelAndDraw(x, y - 1, _color);
								drawPixelAndDraw(x + 1, y, _color);

								drawPixelAndDraw(x - 1, y, _color);
								drawPixelAndDraw(x, y+1, _color);
							}
							else
							{
								drawPixelAndDraw(x, y - 1, _color);
								drawPixelAndDraw(x - 1, y, _color);

								drawPixelAndDraw(x + 1, y, _color);
								drawPixelAndDraw(x, y + 1, _color);
							}
						}
						else if (tempMap[0][0] < 0 && tempMap[0][2] > 0 && tempMap[2][0] > 0 && tempMap[2][2] < 0)
						{
							tempMap[1][1] = _funk->calculate(toFakeX(x + .5, _x, _scaleX), toFakeY(y + .5, _y, _scaleY));

							if (tempMap[1][1] < 0)
							{
								drawPixelAndDraw(x, y - 1, _color);
								drawPixelAndDraw(x + 1, y, _color);

								drawPixelAndDraw(x - 1, y, _color);
								drawPixelAndDraw(x, y + 1, _color);
							}
							else
							{
								drawPixelAndDraw(x, y - 1, _color);
								drawPixelAndDraw(x - 1, y, _color);

								drawPixelAndDraw(x + 1, y, _color);
								drawPixelAndDraw(x, y + 1, _color);
							}
						}
					}
				}
			}*/
		}
		else
		{

			float tempMap[3][240];

			tempMap[0][0] = _funk->calculate(toFakeX(.5, _x, _scaleX), toFakeY(0.5, _y, _scaleY));
			tempMap[1][0] = _funk->calculate(toFakeX(1.5, _x, _scaleX), toFakeY(0.5, _y, _scaleY));

			tempMap[0][1] = _funk->calculate(toFakeX(.5, _x, _scaleX), toFakeY(1.5, _y, _scaleY));
			tempMap[1][1] = _funk->calculate(toFakeX(1.5, _x, _scaleX), toFakeY(1.5, _y, _scaleY));

			for (__int16_t x = 1; x < 319; x++)
			{
				tempMap[2][0] = _funk->calculate(toFakeX(x + 1.5, _x, _scaleX), toFakeY(0.5, _y, _scaleY));
				tempMap[2][1] = _funk->calculate(toFakeX(x + 1.5, _x, _scaleX), toFakeY(1.5, _y, _scaleY));

				for (__int16_t y = 1; y < 239; y++)
				{
					if (x == 1)
					{
						tempMap[0][y + 1] = _funk->calculate(toFakeX(x - .5, _x, _scaleX), toFakeY(y + 1.5, _y, _scaleY));
						tempMap[1][y + 1] = _funk->calculate(toFakeX(x + .5, _x, _scaleX), toFakeY(y + 1.5, _y, _scaleY));
					}
					tempMap[2][y + 1] = _funk->calculate(toFakeX(x + 1.5, _x, _scaleX), toFakeY(y + 1.5, _y, _scaleY));

					if (tempMap[1][y] > 0)
					{
						if (tempMap[0][y] <= 0 || tempMap[2][y] <= 0 || tempMap[1][y - 1] <= 0 || tempMap[1][y + 1] <= 0 || (x + y) % 2 == 0)
							drawPixelAndDraw(x, y, _color);
					}

					if (y != 1)
					{
						tempMap[0][y - 2] = tempMap[1][y - 2];
						tempMap[1][y - 2] = tempMap[2][y - 2];
					}
					if (y == 238)
					{
						tempMap[0][y - 1] = tempMap[1][y - 1];
						tempMap[1][y - 1] = tempMap[2][y - 1];
						tempMap[0][y] = tempMap[1][y];
						tempMap[1][y] = tempMap[2][y];
						tempMap[0][y + 1] = tempMap[1][y + 1];
						tempMap[1][y + 1] = tempMap[2][y + 1];
					}
				}
			}
		}

	}
}

GraphClass Graph[5];