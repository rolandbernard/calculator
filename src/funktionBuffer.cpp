

#include "funktionBuffer.h"


void FunktionBufferClass::init()
{


}

space FunktionBufferClass::requestSpaceObject()
{
	space out;
	out._overWrite = ++_overWrite[_used % BUFFER_SIZE];
	out._pointer = (_used++) % BUFFER_SIZE;

	return out;
}

__int16_t FunktionBufferClass::requestSpace()
{
	_overWrite[_used % BUFFER_SIZE]++;

	return (_used++) % BUFFER_SIZE;
}

FunktionBufferClass FunktionBuffer;

bool funktionNode::reProgram(char * _input, __int16_t _start, __int16_t _end, char _strings[50][512], __int16_t * _sizes, __int16_t preFunk)
{
startPoint:

	if (_start + 1 >= _end)
		return false;

	__int16_t found = findLast(_input, _start, _end, "=><", 3);

	if (found != -1)
	{
		if (found != findfirst(_input, _start, _end, "=><", 3))
			return false;

		if (_input[found] == '=')
			_type = 32;
		else if (_input[found] == '>')
			_type = 33;
		else if (_input[found] == '<')
			_type = 34;


		_leftNode = FunktionBuffer.requestSpace();
		_rightNode = FunktionBuffer.requestSpace();

		FunktionBuffer._buffer[_leftNode].reProgram(_input, _start, found, _strings, _sizes, preFunk);
		FunktionBuffer._buffer[_rightNode].reProgram(_input, found, _end, _strings, _sizes, preFunk);

		return true;
	}

	found = findLast(_input, _start, _end, "+-", 2);

startPoint2:

	if (found != -1)
	{
		if (found != _start + 1)
		{
			if (_input[found - 1] == '1' || _input[found - 1] == '2' || _input[found - 1] == '3' || _input[found - 1] == '4' || _input[found - 1] == '5' || _input[found - 1] == '6' || _input[found - 1] == '7' || _input[found - 1] == '8' || _input[found - 1] == '9' || _input[found - 1] == '0' || _input[found - 1] == '.' || _input[found - 1] == ')' || _input[found - 1] == 'p' || _input[found - 1] == 'e' || _input[found - 1] == 'x' || _input[found - 1] == 'y' || _input[found - 1] == 'A' || _input[found - 1] == 'B' || _input[found - 1] == 'C' || _input[found - 1] == 'D' || _input[found - 1] == 'E' || _input[found - 1] == 'F' || _input[found - 1] == 'S' || _input[found - 1] == 'N')
			{
				if (_input[found] == '+')
				{
					_type = 0;
				}
				else
				{
					_type = 1;
				}

				_leftNode = FunktionBuffer.requestSpace();
				_rightNode = FunktionBuffer.requestSpace();

				FunktionBuffer._buffer[_leftNode].reProgram(_input, _start, found, _strings, _sizes, preFunk);
				FunktionBuffer._buffer[_rightNode].reProgram(_input, found, _end, _strings, _sizes, preFunk);
				
				return true;
			}
			else
			{
				found = findLast(_input, _start, found, "+-", 2);

				goto startPoint2;
			}
		}
		else
			goto startPoint3;
	}


	found = findLast(_input, _start, _end, "*/", 2);

	if (found != -1)
	{
		if (_input[found] == '*')
		{
			_type = 2;
		}
		else
		{
			_type = 3;
		}

		_leftNode = FunktionBuffer.requestSpace();
		_rightNode = FunktionBuffer.requestSpace();

		FunktionBuffer._buffer[_leftNode].reProgram(_input, _start, found, _strings, _sizes, preFunk);
		FunktionBuffer._buffer[_rightNode].reProgram(_input, found, _end, _strings, _sizes, preFunk);

		return true;
	}

	found = findfirst(_input, _start, _end, "^\\#$", 4);

	if (found != -1)
	{
		if (_input[found] == '^')
		{
			_type = 4;

			_leftNode = FunktionBuffer.requestSpace();
			_rightNode = FunktionBuffer.requestSpace();

			FunktionBuffer._buffer[_leftNode].reProgram(_input, _start, found, _strings, _sizes, preFunk);
			FunktionBuffer._buffer[_rightNode].reProgram(_input, found, _end, _strings, _sizes, preFunk);

		}
		else if(_input[found] == '\\')
		{
			_type = 5;

			_leftNode = FunktionBuffer.requestSpace();
			_rightNode = FunktionBuffer.requestSpace();

			FunktionBuffer._buffer[_leftNode].reProgram(_input, _start, found, _strings, _sizes, preFunk);
			FunktionBuffer._buffer[_rightNode].reProgram(_input, found, _end, _strings, _sizes, preFunk);

		}
		else if (_input[found] == '$')
		{
			_type = 6;

			_rightNode = FunktionBuffer.requestSpace();

			FunktionBuffer._buffer[_rightNode].reProgram(_input, found, _end, _strings, _sizes, preFunk);

		}
		else
		{
			_type = 7;

			_rightNode = FunktionBuffer.requestSpace();

			FunktionBuffer._buffer[_rightNode].reProgram(_input, found, _end, _strings, _sizes, preFunk);

		}

		return true;
	}

	if (_input[_end - 1] == '!')
	{
		_type = 8;

		_leftNode = FunktionBuffer.requestSpace();

		FunktionBuffer._buffer[_leftNode].reProgram(_input, _start, _end - 1, _strings, _sizes, preFunk);

		return true;
	}

	if (_input[_start + 1] == '(')
	{
		_end = _sizes[_input[_start + 2] - 1];
		_input = _strings[_input[_start + 2] - 1];

		_start = -1;

		goto startPoint;
	}

	if (_input[_start + 1] == '[')
	{
		_type = 38;

		_rightNode = FunktionBuffer.requestSpace();

		FunktionBuffer._buffer[_rightNode].reProgram(_strings[_input[_start + 2] - 1], -1, _sizes[_input[_start + 2] - 1], _strings, _sizes, preFunk);

		return true;
	}

	if (_input[_start + 1] == '{')
	{
		_type = 39;

		_rightNode = FunktionBuffer.requestSpace();

		FunktionBuffer._buffer[_rightNode].reProgram(_strings[_input[_start + 2] - 1], -1, _sizes[_input[_start + 2] - 1], _strings, _sizes, preFunk);

		return true;
	}

	if (_input[_start + 1] == '|')
	{
		_type = 37;

		_rightNode = FunktionBuffer.requestSpace();

		FunktionBuffer._buffer[_rightNode].reProgram(_strings[_input[_start + 2] - 1], -1, _sizes[_input[_start + 2] - 1], _strings, _sizes, preFunk);

		return true;
	}

	if (_end == _start + 2)
	{
		if (_input[_start + 1] == 'e')
		{
			_type = 27;

			return true;
		}
		if (_input[_start + 1] == 'p')
		{
			_type = 26;

			return true;
		}
		if (_input[_start + 1] == 'x')
		{
			_type = 29;

			return true;
		}
		if (_input[_start + 1] == 'y')
		{
			_type = 30;

			return true;
		}
	}

	if (_end == _start + 4)
	{
		if (_input[_start + 1] == 'A' && _input[_start + 2] == 'N' && _input[_start + 3] == 'S')
		{
			_type = 31;

			_rightNode = preFunk;

			return true;
		}

		if (_input[_start + 1] == 'R' && _input[_start + 2] == 'A' && _input[_start + 3] == 'N')
		{
			_type = 35;

			return true;
		}
	}

	if (_end > _start + 2)
	{
		if (_input[_start + 1] == 'l' && _input[_start + 2] == 'n')
		{
			_type = 9;

			_rightNode = FunktionBuffer.requestSpace();

			FunktionBuffer._buffer[_rightNode].reProgram(_input, _start + 2, _end, _strings, _sizes, preFunk);

			return true;
		}
	}

	if (_end > _start + 4)
	{

		if (_input[_start + 1] == 's' && _input[_start + 2] == 'i' && _input[_start + 3] == 'n' && _input[_start + 4] == 'h')
		{
			_type = 10;

			_rightNode = FunktionBuffer.requestSpace();

			FunktionBuffer._buffer[_rightNode].reProgram(_input, _start + 4, _end, _strings, _sizes, preFunk);

			return true;
		}

		if (_input[_start + 1] == 'c' && _input[_start + 2] == 'o' && _input[_start + 3] == 's' && _input[_start + 4] == 'h')
		{
			_type = 11;

			_rightNode = FunktionBuffer.requestSpace();

			FunktionBuffer._buffer[_rightNode].reProgram(_input, _start + 4, _end, _strings, _sizes, preFunk);

			return true;
		}

		if (_input[_start + 1] == 't' && _input[_start + 2] == 'a' && _input[_start + 3] == 'n' && _input[_start + 4] == 'h')
		{
			_type = 12;

			_rightNode = FunktionBuffer.requestSpace();

			FunktionBuffer._buffer[_rightNode].reProgram(_input, _start + 4, _end, _strings, _sizes, preFunk);

			return true;
		}

		if (_input[_start + 1] == 'r' && _input[_start + 2] == 'n' && _input[_start + 3] == 'd')
		{
			_type = 36;

			_rightNode = FunktionBuffer.requestSpace();

			FunktionBuffer._buffer[_rightNode].reProgram(_input, _start + 3, _end, _strings, _sizes, preFunk);

			return true;
		}

		if (_input[_start + 1] == 's' && _input[_start + 2] == 'i' && _input[_start + 3] == 'n')
		{
			_type = 13;

			_rightNode = FunktionBuffer.requestSpace();

			FunktionBuffer._buffer[_rightNode].reProgram(_input, _start + 3, _end, _strings, _sizes, preFunk);

			return true;
		}

		if (_input[_start + 1] == 'c' && _input[_start + 2] == 'o' && _input[_start + 3] == 's')
		{
			_type = 14;

			_rightNode = FunktionBuffer.requestSpace();

			FunktionBuffer._buffer[_rightNode].reProgram(_input, _start + 3, _end, _strings, _sizes, preFunk);

			return true;
		}

		if (_input[_start + 1] == 't' && _input[_start + 2] == 'a' && _input[_start + 3] == 'n')
		{
			_type = 15;

			_rightNode = FunktionBuffer.requestSpace();

			FunktionBuffer._buffer[_rightNode].reProgram(_input, _start + 3, _end, _strings, _sizes, preFunk);

			return true;
		}

		if (_input[_start + 1] == 'l' && _input[_start + 2] == 'o' && _input[_start + 3] == 'g')
		{
			_type = 17;

			_rightNode = FunktionBuffer.requestSpace();

			FunktionBuffer._buffer[_rightNode].reProgram(_input, _start + 3, _end, _strings, _sizes, preFunk);

			return true;
		}

	}

	if (_end > _start + 5)
	{

		if (_input[_start + 1] == 'a' && _input[_start + 2] == 's' && _input[_start + 3] == 'i' && _input[_start + 4] == 'n' && _input[_start + 5] == 'h')
		{
			_type = 18;

			_rightNode = FunktionBuffer.requestSpace();

			FunktionBuffer._buffer[_rightNode].reProgram(_input, _start + 5, _end, _strings, _sizes, preFunk);

			return true;
		}

		if (_input[_start + 1] == 'a' && _input[_start + 2] == 'c' && _input[_start + 3] == 'o' && _input[_start + 4] == 's' && _input[_start + 5] == 'h')
		{
			_type = 19;

			_rightNode = FunktionBuffer.requestSpace();

			FunktionBuffer._buffer[_rightNode].reProgram(_input, _start + 5, _end, _strings, _sizes, preFunk);

			return true;
		}

		if (_input[_start + 1] == 'a' && _input[_start + 2] == 't' && _input[_start + 3] == 'a' && _input[_start + 4] == 'n' && _input[_start + 5] == 'h')
		{
			_type = 20;

			_rightNode = FunktionBuffer.requestSpace();

			FunktionBuffer._buffer[_rightNode].reProgram(_input, _start + 5, _end, _strings, _sizes, preFunk);


			return true;
		}

		if (_input[_start + 1] == 'a' && _input[_start + 2] == 's' && _input[_start + 3] == 'i' && _input[_start + 4] == 'n')
		{
			_type = 21;

			_rightNode = FunktionBuffer.requestSpace();

			FunktionBuffer._buffer[_rightNode].reProgram(_input, _start + 4, _end, _strings, _sizes, preFunk);

			return true;
		}

		if (_input[_start + 1] == 'a' && _input[_start + 2] == 'c' && _input[_start + 3] == 'o' && _input[_start + 4] == 's')
		{
			_type = 22;

			_rightNode = FunktionBuffer.requestSpace();

			FunktionBuffer._buffer[_rightNode].reProgram(_input, _start + 4, _end, _strings, _sizes, preFunk);

			return true;
		}

		if (_input[_start + 1] == 'a' && _input[_start + 2] == 't' && _input[_start + 3] == 'a' && _input[_start + 4] == 'n')
		{
			_type = 23;

			_rightNode = FunktionBuffer.requestSpace();

			FunktionBuffer._buffer[_rightNode].reProgram(_input, _start + 4, _end, _strings, _sizes, preFunk);

			return true;
		}
	}

startPoint3:

	if (_input[_start + 1] == '-')
	{
		_type = 24;

		_rightNode = FunktionBuffer.requestSpace();

		FunktionBuffer._buffer[_rightNode].reProgram(_input, found, _end, _strings, _sizes, preFunk);

		return true;
	}

	if (_input[_start + 1] == '+')
	{
		_start++;
		goto startPoint;
	}

	if (found == -1)
	{
		_type = 28;

		if (_input[_start + 1] == '0' && _input[_start + 2] == 'x')
			_value = toScalar(_input, _start + 2, _end, HEX);
		else if (_input[_start + 1] == '0' && _input[_start + 2] == 'b')
			_value = toScalar(_input, _start + 2, _end, BIN);
		else if (_input[_start + 1] == '0' && _input[_start + 2] == 'o')
			_value = toScalar(_input, _start + 2, _end, OCT);
		else
			_value = toScalar(_input, _start, _end, DEC);

		return true;
	}

	return false;
}

scalar funktionNode::calculate()
{
	scalar v;

	switch (_type)
	{
	case 0:
		return FunktionBuffer._buffer[_leftNode].calculate() + FunktionBuffer._buffer[_rightNode].calculate();
		break;
	case 1:
		return FunktionBuffer._buffer[_leftNode].calculate() - FunktionBuffer._buffer[_rightNode].calculate();
		break;
	case 2:
		return FunktionBuffer._buffer[_leftNode].calculate() * FunktionBuffer._buffer[_rightNode].calculate();
		break;
	case 3:
		return FunktionBuffer._buffer[_leftNode].calculate() / FunktionBuffer._buffer[_rightNode].calculate();
		break;
	case 4:
		return powl(FunktionBuffer._buffer[_leftNode].calculate(), FunktionBuffer._buffer[_rightNode].calculate());
		break;
	case 5:
		return powl(FunktionBuffer._buffer[_rightNode].calculate(),1 / FunktionBuffer._buffer[_leftNode].calculate());
		break;
	case 6:
		return sqrtl(FunktionBuffer._buffer[_rightNode].calculate());
		break;
	case 7:
		return cbrtl(FunktionBuffer._buffer[_rightNode].calculate());
		break;
	case 8:
		return tgammal(FunktionBuffer._buffer[_leftNode].calculate() + 1);
		break;
	case 9:
		return logl(FunktionBuffer._buffer[_rightNode].calculate());
		break;
	case 10:

		v = FunktionBuffer._buffer[_rightNode].calculate();

		if (v == 0.0)
			return 0.0;

		return sinhl( _settings._rad ? v : v * DEG_TO_RAD);
		break;
	case 11:

		v = FunktionBuffer._buffer[_rightNode].calculate();

		if (v == 0.0)
			return 1.0;

		return coshl(_settings._rad ? v : v * DEG_TO_RAD);
		break;
	case 12:

		v = FunktionBuffer._buffer[_rightNode].calculate();

		if (v == 0.0)
			return 0.0;

		return tanhl(_settings._rad ? v : v * DEG_TO_RAD);
		break;
	case 13:

		v = FunktionBuffer._buffer[_rightNode].calculate();

		if (fmodl(v, (_settings._rad ? PI : 180.0l)) == 0.0)
			return 0.0;

		return sinl(_settings._rad ? v : v * DEG_TO_RAD);
		break;
	case 14:

		v = FunktionBuffer._buffer[_rightNode].calculate();

		if (fmodl(v, (_settings._rad ? TWO_PI : 360.0l)) == 0.0)
			return 1.0;
		else if (fmodl(v, (_settings._rad ? PI : 180.0l)) == 0.0)
			return -1.0;
		else if (fmodl(v, (_settings._rad ? HALF_PI : 90.0l)) == 0.0)
			return 0.0;


		return cosl(_settings._rad ? v : v * DEG_TO_RAD);
		break;
	case 15:

		v = FunktionBuffer._buffer[_rightNode].calculate();

		if (fmodl(v, (_settings._rad ? PI : 180.0l)) == 0.0)
			return 0.0;

		return tanl(_settings._rad ? v : v * DEG_TO_RAD);
		break;
	case 17:
		return log10l(FunktionBuffer._buffer[_rightNode].calculate());
		break;
	case 18:

		v = FunktionBuffer._buffer[_rightNode].calculate();

		if (v == 0.0)
			return 0.0;

		return (_settings._rad ? 1 : RAD_TO_DEG) * asinhl(v);
		break;
	case 19:

		 v = FunktionBuffer._buffer[_rightNode].calculate();

		if (v == 1.0)
			return 0.0;

		return (_settings._rad ? 1 : RAD_TO_DEG) * acoshl(v);
		break;
	case 20:

		 v = FunktionBuffer._buffer[_rightNode].calculate();

		if (v == 0.0)
			return 0.0;

		return (_settings._rad ? 1 : RAD_TO_DEG) * atanhl(v);
		break;
	case 21:

		 v = FunktionBuffer._buffer[_rightNode].calculate();

		if (v == 0.0)
			return 0.0;

		return (_settings._rad ? 1 : RAD_TO_DEG) * asinl(v);
		break;
	case 22:

		 v = FunktionBuffer._buffer[_rightNode].calculate();

		if (v == 1.0)
			return 0.0;

		return (_settings._rad ? 1 : RAD_TO_DEG) * acosl(v);
		break;
	case 23:

		 v = FunktionBuffer._buffer[_rightNode].calculate();

		if (v == 0.0)
			return 0.0;

		return (_settings._rad ? 1 : RAD_TO_DEG) * atanl(v);
		break;
	case 24:
		return -FunktionBuffer._buffer[_rightNode].calculate();
		break;
	case 26:
		return PI;
		break;
	case 27:
		return E;
		break;
	case 28:
		return _value;
		break;
	case 31:
		if (_rightNode >= 0 && _rightNode < BUFFER_SIZE)
			return FunktionBuffer._buffer[_rightNode].calculate();
		else
			return NAN;
		break;
	case 32:
		return fabsl(FunktionBuffer._buffer[_leftNode].calculate() - FunktionBuffer._buffer[_rightNode].calculate());
		break;
	case 33:
		return FunktionBuffer._buffer[_leftNode].calculate() - FunktionBuffer._buffer[_rightNode].calculate();
		break;
	case 34:
		return FunktionBuffer._buffer[_rightNode].calculate() - FunktionBuffer._buffer[_leftNode].calculate();
		break;
	case 35:
		return drand48();
		break;
	case 36:
		return roundl(FunktionBuffer._buffer[_rightNode].calculate());
		break;
	case 37:
		return fabsl(FunktionBuffer._buffer[_rightNode].calculate());
		break;
	case 38:
		return floorl(FunktionBuffer._buffer[_rightNode].calculate());
		break;
	case 39:
		return ceill(FunktionBuffer._buffer[_rightNode].calculate());
		break;
	default:
		return NAN; 
	}
	return NAN;
}

float funktionNode::calculate(float _x, float _y)
{
	switch (_type)
	{
	case 0:
		return FunktionBuffer._buffer[_leftNode].calculate(_x, _y) + FunktionBuffer._buffer[_rightNode].calculate(_x, _y);
		break;
	case 1:
		return FunktionBuffer._buffer[_leftNode].calculate(_x, _y) - FunktionBuffer._buffer[_rightNode].calculate(_x, _y);
		break;
	case 2:
		return FunktionBuffer._buffer[_leftNode].calculate(_x, _y) * FunktionBuffer._buffer[_rightNode].calculate(_x, _y);
		break;
	case 3:
		return FunktionBuffer._buffer[_leftNode].calculate(_x, _y) / FunktionBuffer._buffer[_rightNode].calculate(_x, _y);
		break;
	case 4:
		return powf(FunktionBuffer._buffer[_leftNode].calculate(_x, _y), FunktionBuffer._buffer[_rightNode].calculate(_x, _y));
		break;
	case 5:
		return powf(FunktionBuffer._buffer[_rightNode].calculate(_x, _y), 1 / FunktionBuffer._buffer[_leftNode].calculate(_x, _y));
		break;
	case 6:
		return sqrtf(FunktionBuffer._buffer[_rightNode].calculate(_x, _y));
		break;
	case 7:
		return cbrtf(FunktionBuffer._buffer[_rightNode].calculate(_x, _y));
		break;
	case 8:
		return tgammaf(FunktionBuffer._buffer[_leftNode].calculate(_x, _y) + 1);
		break;
	case 9:
		return logf(FunktionBuffer._buffer[_rightNode].calculate(_x, _y));
		break;
	case 10:
		return sinhf((_settings._rad ? 1 : DEG_TO_RAD) * FunktionBuffer._buffer[_rightNode].calculate(_x, _y));
		break;
	case 11:
		return coshf((_settings._rad ? 1 : DEG_TO_RAD) * FunktionBuffer._buffer[_rightNode].calculate(_x, _y));
		break;
	case 12:
		return tanhf((_settings._rad ? 1 : DEG_TO_RAD) * FunktionBuffer._buffer[_rightNode].calculate(_x, _y));
		break;
	case 13:
		return sinf((_settings._rad ? 1 : DEG_TO_RAD) * FunktionBuffer._buffer[_rightNode].calculate(_x, _y));
		break;
	case 14:
		return cosf((_settings._rad ? 1 : DEG_TO_RAD) * FunktionBuffer._buffer[_rightNode].calculate(_x, _y));
		break;
	case 15:
		return tanf((_settings._rad ? 1 : DEG_TO_RAD) * FunktionBuffer._buffer[_rightNode].calculate(_x, _y));
		break;
	case 17:
		return log10f(FunktionBuffer._buffer[_rightNode].calculate(_x, _y));
		break;
	case 18:
		return (_settings._rad ? 1 : RAD_TO_DEG) * asinhf(FunktionBuffer._buffer[_rightNode].calculate(_x, _y));
		break;
	case 19:
		return (_settings._rad ? 1 : RAD_TO_DEG) * acoshf(FunktionBuffer._buffer[_rightNode].calculate(_x, _y));
		break;
	case 20:
		return (_settings._rad ? 1 : RAD_TO_DEG) * atanhf(FunktionBuffer._buffer[_rightNode].calculate(_x, _y));
		break;
	case 21:
		return (_settings._rad ? 1 : RAD_TO_DEG) * asinf(FunktionBuffer._buffer[_rightNode].calculate(_x, _y));
		break;
	case 22:
		return (_settings._rad ? 1 : RAD_TO_DEG) * acosf(FunktionBuffer._buffer[_rightNode].calculate(_x, _y));
		break;
	case 23:
		return (_settings._rad ? 1 : RAD_TO_DEG) * atanf(FunktionBuffer._buffer[_rightNode].calculate(_x, _y));
		break;
	case 24:
		return -FunktionBuffer._buffer[_rightNode].calculate(_x, _y);
		break;
	case 26:
		return PI;
		break;
	case 27:
		return E;
		break;
	case 28:
		return _value;
		break;
	case 29:
		return _x;
		break;
	case 30:
		return _y;
		break;
	case 31:
		if (_rightNode >= 0 && _rightNode < BUFFER_SIZE)
			return FunktionBuffer._buffer[_rightNode].calculate(_x, _y);
		else
			return NAN;
		break;
	case 32:
		return FunktionBuffer._buffer[_leftNode].calculate(_x, _y) - FunktionBuffer._buffer[_rightNode].calculate(_x, _y);
		break;
	case 33:
		return FunktionBuffer._buffer[_leftNode].calculate(_x, _y) - FunktionBuffer._buffer[_rightNode].calculate(_x, _y);
		break;
	case 34:
		return FunktionBuffer._buffer[_rightNode].calculate(_x, _y) - FunktionBuffer._buffer[_leftNode].calculate(_x, _y);
		break;
	case 35:
		return drand48(); 
		break;
	case 36:
		return roundf(FunktionBuffer._buffer[_rightNode].calculate(_x, _y));
		break;
	case 37:
		return fabsf(FunktionBuffer._buffer[_rightNode].calculate(_x, _y));
		break;
	case 38:
		return floorf(FunktionBuffer._buffer[_rightNode].calculate(_x, _y));
		break;
	case 39:
		return ceilf(FunktionBuffer._buffer[_rightNode].calculate(_x, _y));
		break;
	default:
		return NAN;
	}
	return NAN;
}

bool funktionNode::containsX()
{
	if (_type == 29)
		return true;

	if (_leftNode != -1)
		if (FunktionBuffer._buffer[_leftNode].containsX())
			return true;

	if (_rightNode != -1)
		if (FunktionBuffer._buffer[_rightNode].containsX())
			return true;

	return false;
}

bool funktionNode::containsY()
{

	if (_type == 30)
		return true;

	if (_leftNode != -1)
		if (FunktionBuffer._buffer[_leftNode].containsY())
			return true;

	if (_rightNode != -1)
		if (FunktionBuffer._buffer[_rightNode].containsY())
			return true;

	return false;
}
