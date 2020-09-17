

#include "menu.h"

#define strg 1
#define up 2
#define down 3
#define left 4
#define right 5
#define del 6

void MenuClass::init()
{

}

void MenuClass::display()
{
	if (_change)
	{
		if (_pageAt == 0)
			Rechner.display();
		else if (_pageAt == 1)
			Grapher.display();
		else if (_pageAt == 2)
			Optionen.display();

		_change = false;

		tft.forceUpdate();
	}
}

void MenuClass::input()
{
	char customKey = customKeypad.getKey();
	if (customKey) {

		_change = true;
		switch (customKey)
		{

		case '\r':
			if (_pageAt == 0)
				Rechner.enter();
			else if (_pageAt == 1)
				Grapher.enter();
			else if (_pageAt == 2)
				Optionen.select();
			break;
		case '=':
			if (_pageAt == 0)
				Rechner.enter();
			else if (_pageAt == 1)
				Grapher.insertChar('=');
			break;
		case '\t':
			_pageAt = (1 + _pageAt) % 3;
			break;
		case '\b':
			if (_pageAt == 0)
				Rechner.delet();
			else if (_pageAt == 1)
				Grapher.delet();
			break;
		case del:
			if (_pageAt == 0)
				Rechner.deletAll();
			else if (_pageAt == 1)
				Grapher.deletAll();
			break;
		case strg:
			if (_pageAt == 1)
				Grapher.funktions();
			else if (_pageAt == 0)
				Rechner.outputMode();
			break;
		case up:
			if (_pageAt == 0)
				Rechner.moveUp();
			else if (_pageAt == 1)
				Grapher.moveUp();
			else if (_pageAt == 2)
				Optionen.moveUp();
			break;
		case down:
			if (_pageAt == 0)
				Rechner.moveDown();
			else if (_pageAt == 1)
				Grapher.moveDown();
			else if (_pageAt == 2)
				Optionen.moveDown();
			break;
		case left:
			if (_pageAt == 0)
				Rechner.moveLeft();
			else if (_pageAt == 1)
				Grapher.moveLeft();
			else if (_pageAt == 2)
				Optionen.moveLeft();
			break;
		case right:
			if (_pageAt == 0)
				Rechner.moveRight();
			else if (_pageAt == 1)
				Grapher.moveRight();
			else if (_pageAt == 2)
				Optionen.moveRight();
			break;
		default:
			if (_pageAt == 0)
			{
				Rechner.insertChar(customKey);
			}
			else if (_pageAt == 1)
			{
				Grapher.insertChar(customKey);
			}
			break;
		/*
		case 1:
			_secFunc = !_secFunc;
			break;
		case 2:
			_pageAt = (1 + _pageAt) % 3;
			break;
		case 3:
			if (_pageAt == 1)
				Grapher.funktions();
			else if (_pageAt == 0)
				Rechner.outputMode();
			break;
		case 4:
			if (_pageAt == 0)
				Rechner.moveLeft();
			else if (_pageAt == 1)
				Grapher.moveLeft();
			else if (_pageAt == 2)
				Optionen.moveLeft();
			break;
		case 5:
			if (_pageAt == 0)
				Rechner.moveUp();
			else if (_pageAt == 1)
				Grapher.moveUp();
			else if (_pageAt == 2)
				Optionen.moveUp();
			break;
		case 6:
			if (_secFunc)
			{
				if (_pageAt == 0)
					Rechner.insertChar('e');
				else if (_pageAt == 1)
					Grapher.insertChar('e');
			}
			else
			{
				if (_pageAt == 0)
					Rechner.insertChar('p');
				else if (_pageAt == 1)
					Grapher.insertChar('p');
			}
			break;
		case 7:
			if (!_secFunc)
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('l');
					Rechner.insertChar('o');
					Rechner.insertChar('g');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('l');
					Grapher.insertChar('o');
					Grapher.insertChar('g');
				}
			}
			else
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('l');
					Rechner.insertChar('n');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('l');
					Grapher.insertChar('n');
				}
			}
			break;
		case 8:
			if (_secFunc)
			{
				//if (_pageAt == 0)
				//	Rechner.insertChar('y');
				/*else*//* if (_pageAt == 1)
					Grapher.insertChar('y');
			}
			else
			{
				//if (_pageAt == 0)
				//	Rechner.insertChar('x');
				/*else*//* if (_pageAt == 1)
					Grapher.insertChar('x');
			}
			break;
		case 9:
			if (_pageAt == 0)
				Rechner.moveDown();
			else if (_pageAt == 1)
				Grapher.moveDown();
			else if (_pageAt == 2)
				Optionen.moveDown();
			break;
		case 10:
			if (_pageAt == 0)
				Rechner.moveRight();
			else if (_pageAt == 1)
				Grapher.moveRight();
			else if (_pageAt == 2)
				Optionen.moveRight();
			break;
		case 11:
			if (!_secFunc)
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('s');
					Rechner.insertChar('i');
					Rechner.insertChar('n');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('s');
					Grapher.insertChar('i');
					Grapher.insertChar('n');
				}
			}
			else
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('s');
					Rechner.insertChar('i');
					Rechner.insertChar('n');
					Rechner.insertChar('h');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('s');
					Grapher.insertChar('i');
					Grapher.insertChar('n');
					Grapher.insertChar('h');
				}
			}
			break;
		case 12:
			if (!_secFunc)
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('c');
					Rechner.insertChar('o');
					Rechner.insertChar('s');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('c');
					Grapher.insertChar('o');
					Grapher.insertChar('s');
				}
			}
			else
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('c');
					Rechner.insertChar('o');
					Rechner.insertChar('s');
					Rechner.insertChar('h');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('c');
					Grapher.insertChar('o');
					Grapher.insertChar('s');
					Grapher.insertChar('h');
				}
			}
			break;
		case 13:
			if (!_secFunc)
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('t');
					Rechner.insertChar('a');
					Rechner.insertChar('n');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('t');
					Grapher.insertChar('a');
					Grapher.insertChar('n');
				}
			}
			else
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('t');
					Rechner.insertChar('a');
					Rechner.insertChar('n');
					Rechner.insertChar('h');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('t');
					Grapher.insertChar('a');
					Grapher.insertChar('n');
					Grapher.insertChar('h');
				}
			}
			break;
		case 14:
			if (_secFunc)
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('{');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('{');
				}
			}
			else
			{
				if (_pageAt == 0)
					Rechner.delet();
				else if (_pageAt == 1)
					Grapher.delet();
			}
			break;
		case 15:
			if (_secFunc)
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('}');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('}');
				}
			}
			else
			{
				if (_pageAt == 0)
					Rechner.deletAll();
				else if (_pageAt == 1)
					Grapher.deletAll();
			}
			break;
		case 16:
			if (!_secFunc)
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('a');
					Rechner.insertChar('s');
					Rechner.insertChar('i');
					Rechner.insertChar('n');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('a');
					Grapher.insertChar('s');
					Grapher.insertChar('i');
					Grapher.insertChar('n');
				}
			}
			else
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('a');
					Rechner.insertChar('s');
					Rechner.insertChar('i');
					Rechner.insertChar('n');
					Rechner.insertChar('h');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('a');
					Grapher.insertChar('s');
					Grapher.insertChar('i');
					Grapher.insertChar('n');
					Grapher.insertChar('h');
				}
			}
			break;
		case 17:
			if (!_secFunc)
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('a');
					Rechner.insertChar('c');
					Rechner.insertChar('o');
					Rechner.insertChar('s');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('a');
					Grapher.insertChar('c');
					Grapher.insertChar('o');
					Grapher.insertChar('s');
				}
			}
			else
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('a');
					Rechner.insertChar('c');
					Rechner.insertChar('o');
					Rechner.insertChar('s');
					Rechner.insertChar('h');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('a');
					Grapher.insertChar('c');
					Grapher.insertChar('o');
					Grapher.insertChar('s');
					Grapher.insertChar('h');
				}
			}
			break;
		case 18:
			if (!_secFunc)
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('a');
					Rechner.insertChar('t');
					Rechner.insertChar('a');
					Rechner.insertChar('n');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('a');
					Grapher.insertChar('t');
					Grapher.insertChar('a');
					Grapher.insertChar('n');
				}
			}
			else
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('a');
					Rechner.insertChar('t');
					Rechner.insertChar('a');
					Rechner.insertChar('n');
					Rechner.insertChar('h');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('a');
					Grapher.insertChar('t');
					Grapher.insertChar('a');
					Grapher.insertChar('n');
					Grapher.insertChar('h');
				}
			}
			break;
		case 19:
			if (_secFunc)
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('[');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('[');
				}
			}
			else
			{
				if (_pageAt == 0)
					Rechner.insertChar('(');
				else if (_pageAt == 1)
					Grapher.insertChar('(');
			}
			break;
		case 20:
			if (_secFunc)
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar(']');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar(']');
				}
			}
			else
			{
				if (_pageAt == 0)
					Rechner.insertChar(')');
				else if (_pageAt == 1)
					Grapher.insertChar(')');
			}
			break;
		case 21:
			if (_secFunc)
			{
				if (_pageAt == 0)
					Rechner.insertChar('A');
				else if (_pageAt == 1)
					Grapher.insertChar('A');
			}
			else
			{
				if (_pageAt == 0)
					Rechner.insertChar('1');
				else if (_pageAt == 1)
					Grapher.insertChar('1');
			}
			break;
		case 22:
			if (_secFunc)
			{
				if (_pageAt == 0)
					Rechner.insertChar('B');
				else if (_pageAt == 1)
					Grapher.insertChar('B');
			}
			else
			{
				if (_pageAt == 0)
					Rechner.insertChar('2');
				else if (_pageAt == 1)
					Grapher.insertChar('2');
			}
			break;
		case 23:
			if (_secFunc)
			{
				if (_pageAt == 0)
					Rechner.insertChar('C');
				else if (_pageAt == 1)
					Grapher.insertChar('C');
			}
			else
			{
				if (_pageAt == 0)
					Rechner.insertChar('3');
				else if (_pageAt == 1)
					Grapher.insertChar('3');
			}
			break;
		case 24:
			if (_secFunc)
			{
				if (_pageAt == 0)
					Rechner.insertChar('!');
				else if (_pageAt == 1)
					Grapher.insertChar('!');
			}
			else
			{
				if (_pageAt == 0)
					Rechner.insertChar('^');
				else if (_pageAt == 1)
					Grapher.insertChar('^');
			}
			break;
		case 25:
			if (_secFunc)
			{
				if (_pageAt == 0)
					Rechner.insertChar('$');
				else if (_pageAt == 1)
					Grapher.insertChar('$');
			}
			else
			{
				if (_pageAt == 0)
					Rechner.insertChar('\\');
				else if (_pageAt == 1)
					Grapher.insertChar('\\');
			}
			break;
		case 26:
			if (_secFunc)
			{
				if (_pageAt == 0)
					Rechner.insertChar('D');
				else if (_pageAt == 1)
					Grapher.insertChar('D');
			}
			else
			{
				if (_pageAt == 0)
					Rechner.insertChar('4');
				else if (_pageAt == 1)
					Grapher.insertChar('4');
			}
			break;
		case 27:
			if (_secFunc)
			{
				if (_pageAt == 0)
					Rechner.insertChar('E');
				else if (_pageAt == 1)
					Grapher.insertChar('E');
			}
			else
			{
				if (_pageAt == 0)
					Rechner.insertChar('5');
				else if (_pageAt == 1)
					Grapher.insertChar('5');
			}
			break;
		case 28:
			if (_secFunc)
			{
				if (_pageAt == 0)
					Rechner.insertChar('F');
				else if (_pageAt == 1)
					Grapher.insertChar('F');
			}
			else
			{
				if (_pageAt == 0)
					Rechner.insertChar('6');
				else if (_pageAt == 1)
					Grapher.insertChar('6');
			}
			break;
		case 29:
			if (_pageAt == 0)
				Rechner.insertChar('*');
			else if (_pageAt == 1)
				Grapher.insertChar('*');
			break;
		case 30:
			if (_secFunc)
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('0');
					Rechner.insertChar('o');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('0');
					Grapher.insertChar('o');
				}
			}
			else
			{
				if (_pageAt == 0)
					Rechner.insertChar('/');
				else if (_pageAt == 1)
					Grapher.insertChar('/');
			}
			break;
		case 31:
			if (_secFunc)
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('|');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('|');
				}
			}
			else
			{
				if (_pageAt == 0)
					Rechner.insertChar('7');
				else if (_pageAt == 1)
					Grapher.insertChar('7');
			}
			break;
		case 32:
			if (_secFunc)
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('r');
					Rechner.insertChar('n');
					Rechner.insertChar('d');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('r');
					Grapher.insertChar('n');
					Grapher.insertChar('d');
				}
			}
			else
			{
				if (_pageAt == 0)
					Rechner.insertChar('8');
				else if (_pageAt == 1)
					Grapher.insertChar('8');
			}
			break;
		case 33:
			if (_pageAt == 0)
				Rechner.insertChar('9');
			else if (_pageAt == 1)
				Grapher.insertChar('9');
			break;
		case 34:
			if (_secFunc)
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('0');
					Rechner.insertChar('x');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('0');
					Grapher.insertChar('x');
				}
			}
			else
			{
				if (_pageAt == 0)
					Rechner.insertChar('+');
				else if (_pageAt == 1)
					Grapher.insertChar('+');
			}
			break;
		case 35:
			if (_secFunc)
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('0');
					Rechner.insertChar('b');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('0');
					Grapher.insertChar('b');
				}
			}
			else
			{
				if (_pageAt == 0)
					Rechner.insertChar('-');
				else if (_pageAt == 1)
					Grapher.insertChar('-');
			}
			break;
		case 36:
			if (_pageAt == 0)
				Rechner.insertChar('.');
			else if (_pageAt == 1)
				Grapher.insertChar('.');
			break;
		case 37:
			if (_pageAt == 0)
				Rechner.insertChar('0');
			else if (_pageAt == 1)
				Grapher.insertChar('0');
			break;
		case 38:
			if (_secFunc)
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('R');
					Rechner.insertChar('A');
					Rechner.insertChar('N');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('R');
					Grapher.insertChar('A');
					Grapher.insertChar('N');
				}
			}
			else
			{
				if (_pageAt == 0)
				{
					Rechner.insertChar('A');
					Rechner.insertChar('N');
					Rechner.insertChar('S');
				}
				else if (_pageAt == 1)
				{
					Grapher.insertChar('A');
					Grapher.insertChar('N');
					Grapher.insertChar('S');
				}
			}
			break;
		case 39:
			if (_secFunc)
			{
				if (_pageAt == 0)
					Rechner.enter();
				else if (_pageAt == 1)
					Grapher.insertChar('<');
			}
			else
			{
				if (_pageAt == 0)
					Rechner.enter();
				else if (_pageAt == 1)
					Grapher.enter();
				else if (_pageAt == 2)
					Optionen.select();
			}
			break;
		case 40:
			if (_secFunc)
			{
				if (_pageAt == 0)
					Rechner.enter();
				else if (_pageAt == 1)
					Grapher.insertChar('>');
			}
			else
			{
				if (_pageAt == 0)
					Rechner.enter();
				else if (_pageAt == 1)
					Grapher.insertChar('=');
			}
			break;
		
		default:
			break;
			*/
		}
		//if(customKey != 1)
		//	_secFunc = false;
	}
}


MenuClass Menu;

