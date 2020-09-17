#pragma once

#include <SDL2/SDL.h>
#include "WProgram.h"
#include "font.h"

#define ILI9341_BLACK       0x0000     
#define ILI9341_NAVY        0x000F   
#define ILI9341_DARKGREEN   0x03E0   
#define ILI9341_DARKCYAN    0x03EF    
#define ILI9341_MAROON      0x7800    
#define ILI9341_PURPLE      0x780F     
#define ILI9341_OLIVE       0x7BE0   
#define ILI9341_LIGHTGREY   0xC618   
#define ILI9341_DARKGREY    0x7BEF
#define ILI9341_BLUE        0x001F 
#define ILI9341_GREEN       0x07E0   
#define ILI9341_CYAN        0x07FF     
#define ILI9341_RED         0xF800     
#define ILI9341_MAGENTA     0xF81F     
#define ILI9341_YELLOW      0xFFE0     
#define ILI9341_WHITE       0xFFFF     
#define ILI9341_ORANGE      0xFD20    
#define ILI9341_GREENYELLOW 0xAFE5      
#define ILI9341_PINK        0xF81F
 
#define SCALE 2

#define F1 1
#define up 2
#define down 3
#define left 4
#define right 5
#define del 6


class ILI9341_t3
{
public:
	ILI9341_t3();
	ILI9341_t3(int, int, int, int, int, int);
	~ILI9341_t3();

	void begin() {
	
		SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO);
		window = SDL_CreateWindow("Calculaor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCALE * 320, SCALE * 240, SDL_WINDOW_BORDERLESS);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	};
	void setRotation(int) {}
	void setTextColor(__int16 in, __int16 back = 0x01) {
		textColor = in;
		textBackgroundcolor = back;
	}
	void forceUpdate()
	{
		SDL_RenderPresent(renderer);
	}
	void drawPixel(int x, int y, __int16 color)
	{
		SDL_Rect rect;

		rect.x = x * SCALE;
		rect.y = y * SCALE;
		rect.w = SCALE;
		rect.h = SCALE;

		SDL_SetRenderDrawColor(renderer, (color >> 8) & 0xf8, (color >> 3) & 0xfc, (color & 0x1f) << 3, 255);
		SDL_RenderDrawRect(renderer, &rect);
		//SDL_RenderPresent(renderer);
	}
	void fillScreen(__int16 color)
	{
		SDL_SetRenderDrawColor(renderer, (color >> 8) & 0xf8, (color >> 3) & 0xfc, (color & 0x1f) << 3, 255);
		SDL_RenderClear(renderer);
	}
	void drawRect(int x, int y, int w, int h, __int16 color)
	{
		SDL_Rect rect;

		rect.x = x * SCALE;
		rect.y = y * SCALE;
		rect.w = w * SCALE;
		rect.h = h * SCALE;

		SDL_SetRenderDrawColor(renderer, (color >> 8) & 0xf8, (color >> 3) & 0xfc, (color & 0x1f) << 3, 255);
		for (int i = 0; i < SCALE; i++)
		{
			SDL_RenderDrawRect(renderer, &rect);
			rect.x++;
			rect.y++;
			rect.w -= 2;
			rect.h -= 2;
		}

		//SDL_RenderPresent(renderer);

	}
	void fillRect(int x, int y, int w, int h, __int16 color)
	{
		SDL_Rect rect;

		rect.x = x * SCALE;
		rect.y = y * SCALE;
		rect.w = w * SCALE;
		rect.h = h * SCALE;

		SDL_SetRenderDrawColor(renderer, (color >> 8) & 0xf8, (color >> 3) & 0xfc, (color & 0x1f) << 3, 255);
		SDL_RenderFillRect(renderer, &rect);
		//SDL_RenderPresent(renderer);
	}
	void drawLine(int x1, int y1, int x2, int y2, __int16 color)
	{
		__int16_t distX = x1 - x2;
		__int16_t distY = y1 - y2;
		__int16_t minY;
		__int16_t minX;

		if ((distX < 0 ? -distX : distX) >(distY < 0 ? -distY : distY))
		{
			minX = x1 < x2 ? x1 : x2;
			if (minX == x1)
				minY = y1;
			else
				minY = y2;

			for (__int16_t i = minX; i <= minX + (distX < 0 ? -distX : distX); i++)
			{
				drawPixel(i, (__int16_t)(((i - minX) * ((float)distY / distX)) + .5) + minY, color);
			}
		}
		else
		{
			minY = y1 < y2 ? y1 : y2;
			if (minY == y1)
				minX = x1;
			else
				minX = x2;

			for (__int16_t i = minY; i <= minY + (distY < 0 ? -distY : distY); i++)
			{
				drawPixel((__int16_t)(((i - minY) * ((float)distX / distY)) + .5) + minX, i, color);
			}
		}
	}
	void drawFastVLine(int x, int y, int d, __int16 color)
	{
		drawLine(x, y, x, y + d, color);
	}
	void drawFastHLine(int x, int y, int d, __int16 color)
	{
		drawLine(x, y, x + d, y, color);
	}
	void setCursor(int x, int y)
	{
		textCursorX = x;
		textCursorY = y;
	}
	void setTextSize(int s)
	{
		textSize = s;
	}
	void drawChar(int ix, int iy, char c, __int16 color, __int16 colorBack, int s)
	{
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 5; x++)
			{
				if ((glcdfont[c * 5 + x] >> y) & 0b1)
				{
					for (int xi = 0; xi < s; xi++)
						for (int yi = 0; yi < s; yi++)
							drawPixel(ix + x * s + xi, iy + y * s + yi, color);
				}
				else if(colorBack != 0x01)
				{
					for (int xi = 0; xi < s; xi++)
						for (int yi = 0; yi < s; yi++)
							drawPixel(ix + x * s + xi, iy + y * s + yi, colorBack);
				}
			}
		}
	}
	void print(String s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			drawChar(textCursorX + i * textSize * 6, textCursorY, s[i], textColor, textBackgroundcolor, textSize);
		}
	}
	void println(String s)
	{
		print(s);
		textCursorY += 10 * textSize;
	}
	char getInput()
	{
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			switch (e.type)
			{
			case SDL_KEYDOWN:
					switch (e.key.keysym.sym)
					{
					case SDLK_ESCAPE:
						SDL_DestroyRenderer(renderer);
						SDL_DestroyWindow(window);
						SDL_Quit();
						exit(0);
					case SDLK_UP:
						return up;
					case SDLK_DOWN:
						return down;
					case SDLK_LEFT:
						return left;
					case SDLK_RIGHT:
						return right;
					case SDLK_DELETE:
						return del;
					case SDLK_F1:
						return F1;
					case SDLK_BACKSPACE:
						return '\b';
					case SDLK_TAB:
						return '\t';
					case SDLK_RETURN:
						return '\r';
					case SDLK_0:
						if ((e.key.keysym.mod & KMOD_CTRL) && (e.key.keysym.mod & KMOD_ALT))
							return '}';
						else if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return '=';
						else
							return '0';
					case SDLK_1:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return '!';
						else
							return '1';
					case SDLK_2:
						return '2'; 
					case SDLK_3:
						return '3';
					case SDLK_4:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return '$';
						else
							return '4';
					case SDLK_5:
						return '5';
					case SDLK_6:
						return '6';
					case SDLK_7:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return '/';
						else if ((e.key.keysym.mod & KMOD_CTRL) && (e.key.keysym.mod & KMOD_ALT))
								return '{';
						else
							return '7';
					case SDLK_8:
						if ((e.key.keysym.mod & KMOD_CTRL) && (e.key.keysym.mod & KMOD_ALT))
							return '[';
						else if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return '(';
						else
							return '8';
					case SDLK_9:
						if ((e.key.keysym.mod & KMOD_CTRL) && (e.key.keysym.mod & KMOD_ALT))
							return ']';
						else if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return ')';
						else
							return '9';
					case SDLK_LESS:
						if ((e.key.keysym.mod & KMOD_CTRL) && (e.key.keysym.mod & KMOD_ALT))
							return '|';
						else if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return '>';
						else
							return '<';
					case SDLK_CARET:
						return '^';
					case SDLK_PLUS:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return '*';
						 else
							return '+';
					case SDLK_MINUS:
						return '-';
					case SDLK_PERIOD:
						return '.';
					case SDLK_a:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'A';
						else
							return 'a';
					case SDLK_b:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'B';
						else
							return 'b';
					case SDLK_c:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'C';
						else
							return 'c';
					case SDLK_d:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'D';
						else
							return 'd';
					case SDLK_e:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'E';
						else
							return 'e';
					case SDLK_f:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'F';
						else
							return 'f';
					case SDLK_g:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'G';
						else
							return 'g';
					case SDLK_h:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'H';
						else
							return 'h';
					case SDLK_i:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'I';
						else
							return 'i';
					case SDLK_j:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'J';
						else
							return 'j';
					case SDLK_k:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'K';
						else
							return 'k';
					case SDLK_l:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'L';
						else
							return 'l';
					case SDLK_m:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'M';
						else
							return 'm';
					case SDLK_n:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'N';
						else
							return 'n';
					case SDLK_o:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'O';
						else
							return 'o';
					case SDLK_p:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'P';
						else
							return 'p';
					case SDLK_q:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'Q';
						else
							return 'q';
					case SDLK_r:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'R';
						else
							return 'r';
					case SDLK_s:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'S';
						else
							return 's';
					case SDLK_t:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'T';
						else
							return 't';
					case SDLK_u:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'U';
						else
							return 'u';
					case SDLK_v:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'V';
						else
							return 'v';
					case SDLK_w:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'W';
						else
							return 'w';
					case SDLK_x:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'X';
						else
							return 'x';
					case SDLK_y:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'Y';
						else
							return 'y';
					case SDLK_z:
						if (e.key.keysym.mod & (KMOD_SHIFT | KMOD_CAPS))
							return 'Z';
						else
							return 'z';
					case 223:
						if ((e.key.keysym.mod & KMOD_CTRL) && (e.key.keysym.mod & KMOD_ALT))
							return '\\';
						else
							break;
					default:
						//std::cout << "Key: " << e.key.keysym.sym << std::endl;
						break;
					}
					break;

			case SDL_QUIT:
				SDL_DestroyRenderer(renderer);
				SDL_DestroyWindow(window);
				SDL_Quit();
				exit(0);
			default:
				break;
			}
		}
		return 0;
	}
	

private:
	__int16 textColor = 0;
	__int16 textBackgroundcolor = 0;

	int textCursorX = 0;
	int textCursorY = 0;

	int textSize = 1;

	SDL_Window* window;
	SDL_Renderer* renderer;
};

