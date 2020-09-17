
#include "global.h"

#define ROWS  8
#define COLS  5 


char hexaKeys[ROWS][COLS] =
{
	{  1, 2, 3, 4, 5 },
	{  6, 7, 8, 9,10 },
	{ 11,12,13,14,15 },
	{ 16,17,18,19,20 },
	{ 21,22,23,24,25 },
	{ 26,27,28,29,30 },
	{ 31,32,33,34,35 },
	{ 36,37,38,39,40 },
};

byte rowPins[ROWS] = { 0, 1, 2, 3, 4, 5, 6, 7 };
byte colPins[COLS] = { 23, 18, 39, 37, 33 };

ILI9341_t3 tft = ILI9341_t3(TFT_CS, TFT_DC, TFT_RST, TFT_MOSI, TFT_SCLK, TFT_MISO);
settings _settings;
Keypad customKeypad = Keypad(0, rowPins, colPins, ROWS, COLS);

String toString2(scalar _input, __int16_t _digits)
{
	__uint8_t maxDigits = _digits;
	char buffer[15];

restartPoint:

	__int16_t ret = snprintf(buffer, sizeof(buffer), "%.*llg", maxDigits, _input);

	if (ret >= sizeof(buffer))
		if (maxDigits != 0)
		{
			maxDigits -= 1 + ret - sizeof(buffer);
			goto restartPoint;
		}
	

	return String(buffer);
}

String toString(scalar _input, __int16_t _base)
{
	__uint8_t maxDigits = 10;
	char buffer[15];

restartPoint:

	
	if (_base == HEX)
	{
		if (_input == (int)_input &&  _input <= 72057594037927935.0l)
		{
		   snprintf(buffer, sizeof(buffer), "%*X", 14, (int)_input);


		}
		/*else
		{
			__int16_t ret = snprintf(buffer, sizeof(buffer), "%*.*A", 14, maxDigits, (int)_input);

			if (ret >= sizeof(buffer))
				if (maxDigits != 0)
				{
					maxDigits -= 1 + ret - sizeof(buffer);
					goto restartPoint;
				}
		}*/
	}
	else if (_base == BIN)
	{
		__int16_t temp = (int)_input;
		bool first = true;

		for(__int8_t i = 13; i >= 0; i--)
			if ((temp >> i) & 1)
			{
				first = false;
				buffer[13 - i] = '1';
			}
			else
			{
				if (first && i != 0)
					buffer[13 - i] = ' ';
				else
					buffer[13 - i] = '0';
			}
		buffer[14] = 0;
	}
	else if (_base == OCT)
	{
		if (_input == (int)_input &&  _input <= 4398046511103)
			snprintf(buffer, sizeof(buffer), "%*o", 14, (int)_input);
	}
	else
	{
		__int16_t ret = snprintf(buffer, sizeof(buffer), "%*.*llg", 14, maxDigits, _input);

		if (ret >= sizeof(buffer))
			if (maxDigits != 0)
			{
				maxDigits -= 1 + ret - sizeof(buffer);
				goto restartPoint;
			}
			
	}
	

	return String(buffer);
}

bool alowsBase(scalar _input,__int16_t _base)
{
	if (_base == HEX)
	{
		__int16_t ret = snprintf(nullptr, 0, "%*X", 14, (int)_input);
		if (ret >= 15 || ret < 0 || _input != (int)_input)
			return false;
		else 
			return true;
	}
	else if (_base == BIN)
	{
		if (_input == (int)_input &&  _input <= 16383)
			return true;
		else
			return false;
	}
	else if (_base == OCT)
	{
		if (_input == (int)_input &&  _input <= 72057594037927935.0l)
			return true;
		else
			return false;
	}
	else
	{
		return true;
	}
}

scalar toScalar(char * _input, __int16_t _start, __int16_t _end,  __int16_t _base)
{
	if (_end - _start > 50 || _end < _start + 2)
		return NAN;

	char buffer[50];
	for (__uint16_t i = _start + 1; i < _end; i++)
	{
		buffer[i - 1 - _start] = _input[i];
	}
	buffer[_end - 1 - _start] = 0;

	scalar value = 0;

	if (_base == HEX)
	{
		__int16_t found = findfirstnot(_input, _start, _end, "0123456789ABCDEF.", 17);
		if (found != -1)
			return NAN;

		found = findfirst(_input, _start, _end, ".", 1);
		if (found == -1)
			found = _end;

		for (__int16_t i = _start + 1; i < _end; i++)
		{
			if (i != found)
				switch (_input[i])
				{
				case '1':
					value += pow(16.0f, i < found ? found - i - 1 : found - i);
					break;
				case '2':
					value += 2.0f * pow(16.0f, i < found ? found - i - 1 : found - i);
					break;
				case '3':
					value += 3.0f * pow(16.0f, i < found ? found - i - 1 : found - i);
					break;
				case '4':
					value += 4.0f * pow(16.0f, i < found ? found - i - 1 : found - i);
					break;
				case '5':
					value += 5.0f * pow(16.0f, i < found ? found - i - 1 : found - i);
					break;
				case '6':
					value += 6.0f * pow(16.0f, i < found ? found - i - 1 : found - i);
					break;
				case '7':
					value += 7.0f * pow(16.0f, i < found ? found - i - 1 : found - i);
					break;
				case '8':
					value += 8.0f * pow(16.0f, i < found ? found - i - 1 : found - i);
					break;
				case '9':
					value += 9.0f * pow(16.0f, i < found ? found - i - 1 : found - i);
					break;
				case 'A':
					value += 10.0f * pow(16.0f, i < found ? found - i - 1 : found - i);
					break;
				case 'B':
					value += 11.0f * pow(16.0f, i < found ? found - i - 1 : found - i);
					break;
				case 'C':
					value += 12.0f * pow(16.0f, i < found ? found - i - 1 : found - i);
					break;
				case 'D':
					value += 13.0f * pow(16.0f, i < found ? found - i - 1 : found - i);
					break;
				case 'E':
					value += 14.0f * pow(16.0f, i < found ? found - i - 1 : found - i);
					break;
				case 'F':
					value += 15.0f * pow(16.0f, i < found ? found - i - 1 : found - i);
					break;
				}
		}
	}
	else if (_base == BIN)
	{
		__int16_t found = findfirstnot(_input, _start, _end, "01.", 3);
		if (found != -1)
			 return NAN;

		found = findfirst(_input, _start, _end, ".", 1);
		if (found == -1)
			found = _end;

		for (__int16_t i = _start + 1; i < _end; i++)
		{
			if (i != found)
				if (_input[i] == '1')
					value += pow(2.0f, i < found ? found - i - 1 : found - i);
		}
	}
	else if (_base == OCT)
	{
		__int16_t found = findfirstnot(_input, _start, _end, "01234567.", 9);
		if (found != -1)
			return NAN;

		found = findfirst(_input, _start, _end, ".", 1);
		if (found == -1)
			found = _end;

		for (__int16_t i = _start + 1; i < _end; i++)
		{
			if (i != found)
				value += (_input[i] - 48) * pow(8.0f, i < found ? found - i - 1 : found - i);
		}
	}
	else
	{
		__int16_t ret = sscanf(buffer, "%llg", &value);

		if (ret <= 0)
			return NAN;
	}



	return value;
}

__int16_t findLast(char * _searchIn, __int16_t _start, __int16_t _end, char * _searchFor, signed char  _size)
{
	for (__int16_t i = _end - 1; i > _start; i--)
	{
		for (unsigned char s = 0; s < _size; s++)
		{
			if (_searchIn[i] == _searchFor[s])
				return i;
		}
	}

	return -1;
}

__int16_t findfirst(char * _searchIn, __int16_t _start, __int16_t _end, char * _searchFor, signed char _size)
{
	for (__int16_t i = _start + 1; i < _end; i++)
	{
		for (unsigned char s = 0; s < _size; s++)
		{
			if (_searchIn[i] == _searchFor[s])
				return i;
		}
	}

	return -1;
}

__int16_t findfirstnot(char * _searchIn, __int16_t _start, __int16_t _end, char * _searchFor, signed char _size)
{
	bool oneOf = true;
	for (__int16_t i = _start + 1; i < _end; i++)
	{
		oneOf = false;
		for (unsigned char s = 0; s < _size; s++)
		{
			if (_searchIn[i] == _searchFor[s])
				oneOf = true;
		}
		if (!oneOf)
			return i;
	}

	return -1;
}

float toRealX(float _xw, float _x, float _scaleX)
{
	return roundf((_scaleX / 2 - _x + _xw) * 320 / _scaleX);
}

__int16_t toRealY(float _yw, float _y, float _scaleY)
{
	return roundf((_scaleY / 2 - _y + _yw) * 240 / _scaleY);
}

float toInvRealY(float _yw, float _y, float _scaleY)
{
	return roundf((_scaleY / 2 - _y - _yw) * 240 / _scaleY);
}

float toFakeX(float _xf, float _x, float _scaleX)
{
	return _xf * _scaleX / 320 - _scaleX / 2 + _x;
}

float toFakeY(float _iyf, float _y, float _scaleY)
{
	return  -(_iyf * _scaleY / 240 - _scaleY / 2 + _y);
}

int freeRam()
{
	intptr_t stackTop;
	intptr_t heapTop;

	// current position of the stack.
	stackTop = (intptr_t)&stackTop;

	// current position of heap.
	void* hTop = malloc(1);
	heapTop = (intptr_t)hTop;
	free(hTop);

	// The difference is the free, available ram.
	return stackTop - heapTop;
}

void printFreeRam()
{
	Serial.println(freeRam());
}