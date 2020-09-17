
#pragma once

#include "WProgram.h"
#include "SPI.h"
#include "ILI9341_t3.h"
extern ILI9341_t3 tft;
#include "Keypad.h"
#include "settings.h"
#include <stdlib.h>
#include <stdio.h>

#define backgroundColor 0xC638
#define strokeColor 0xDF1B
#define textColor 0x0000
#define lightColor 0xFF27
#define selectionColor 0x1956
#define lightSelectionColor 0x7D3C

#define ASPECT_RATIO 0.70588235294117647058823529411765

//#define DEBUG_OUT 1

#define TFT_DC      15
#define TFT_CS      10
#define TFT_RST     255  // 255 = unused, connect to 3.3V
#define TFT_MOSI    11
#define TFT_SCLK    13
#define TFT_MISO    12

typedef long double scalar;

extern Keypad customKeypad;

String toString2(scalar _input, __int16_t _digits);
String toString(scalar _input, __int16_t _base);
bool alowsBase(scalar _input, __int16_t _base);
scalar toScalar(char * _input, __int16_t _start, __int16_t _end, __int16_t _base = DEC);
__int16_t findLast(char * _searchIn, __int16_t _start, __int16_t _end, char * _searchFor, signed char  _size);
__int16_t findfirst(char * _searchIn, __int16_t _start, __int16_t _end, char * _searchFor, signed char _size);
__int16_t findfirstnot(char * _searchIn, __int16_t _start, __int16_t _end, char * _searchFor, signed char _size);
float toRealX(float _xw, float _x, float _scaleX);
__int16_t toRealY(float _yw, float _y, float _scaleY);
float toInvRealY(float _yw, float _y, float _scaleY);
float toFakeX(float _xf, float _x, float _scaleX);
float toFakeY(float _iyf, float _y, float _scaleY);

int freeRam();
void printFreeRam();
