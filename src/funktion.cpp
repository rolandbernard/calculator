

#include "funktion.h"

void funktion::init()
{

	
}

bool funktion::reProgram(char * _input, __int16_t _start, __int16_t _end, __int16_t preFunk)
{
	char newInput[255];
	for (__int16_t i = 0; i < _end; i++)
		newInput[i] = _input[i];

	__uint16_t starts[10];
	unsigned char index = 0;
	unsigned char amoundSaved = 0;
	for (__int16_t i = 0; i < _end; i++)
	{
		if (newInput[i] == '(' || newInput[i] == '[' || newInput[i] == '{')
			starts[index++] = i;

		if (newInput[i] == '|')
		{
			if (i == 0)
				starts[index++] = i;
			else if (newInput[i - 1] == '1' || newInput[i - 1] == '2' || newInput[i - 1] == '3' || newInput[i - 1] == '4' || newInput[i - 1] == '5' || newInput[i - 1] == '6' || newInput[i - 1] == '7' || newInput[i - 1] == '8' || newInput[i - 1] == '9' || newInput[i - 1] == '0' || newInput[i - 1] == '.' || newInput[i - 1] == ')' || newInput[i - 1] == 'p' || newInput[i - 1] == 'e' || newInput[i - 1] == 'x' || newInput[i - 1] == 'y' || newInput[i - 1] == 'A' || newInput[i - 1] == 'B' || newInput[i - 1] == 'C' || newInput[i - 1] == 'D' || newInput[i - 1] == 'E' || newInput[i - 1] == 'F' || newInput[i - 1] == 'S' || newInput[i - 1] == 'N')
			{

				__int16_t c = 0;
				for (__int16_t j = starts[--index] + 1; j < i; j++)
				{
					FunktionBuffer._strings[amoundSaved][c] = newInput[j];

					if (c == 0)
						newInput[j] = amoundSaved + 1;
					else
						newInput[j] = ' ';
					c++;
				}
				FunktionBuffer._sizes[amoundSaved++] = c;

			}
			else
				starts[index++] = i;
		}

		if ((newInput[i] == ')' || newInput[i] == ']' || newInput[i] == '}') && index > 0)
		{

			__int16_t c = 0;
			for (__int16_t j = starts[--index] + 1; j < i; j++)
			{
				FunktionBuffer._strings[amoundSaved][c] = newInput[j];

				if (c == 0)
					newInput[j] = amoundSaved + 1;
				else
					newInput[j] = ' ';
				c++;
			}
			FunktionBuffer._sizes[amoundSaved++] = c;

		}

	}
	for (__int16_t i = 0; i < index; i++)
	{
		newInput[starts[i]] = '+';
	}

	space thisSpace = FunktionBuffer.requestSpaceObject();

	_overWrite = thisSpace._overWrite;
	_funktionStart = thisSpace._pointer;

	if (_funktionStart == -1)
		return false;

	return FunktionBuffer._buffer[_funktionStart].reProgram(newInput, _start, _end, FunktionBuffer._strings, FunktionBuffer._sizes, preFunk);
}

bool funktion::checkExistance()
{
	if (_funktionStart == -1 || FunktionBuffer._overWrite[_funktionStart] > _overWrite)
		return false;
	else
		return true;
}

scalar funktion::calculate()
{
	return FunktionBuffer._buffer[_funktionStart].calculate();
}

scalar funktion::calculate(scalar _x, scalar _y)
{
	return FunktionBuffer._buffer[_funktionStart].calculate(_x, _y);
}

__int16_t funktion::getStart()
{
	return _funktionStart;
}


