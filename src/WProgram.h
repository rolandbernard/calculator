#pragma once

#include <string>
#include <iostream>
#include <math.h>
#include <stdint.h>

#define refrenceVoltage 3.3f

#define __uint8_t uint8_t
#define __int8_t int8_t
#define __uint16_t uint16_t
#define __int16_t int16_t
#define __uint32_t uint32_t
#define __int32_t int32_t
#define __uint64_t uint64_t
#define __int64_t int64_t

#define __uint8 uint8_t
#define __int8 int8_t
#define __uint16 uint16_t
#define __int16 int16_t
#define __uint32 uint32_t
#define __int32 int32_t
#define __uint64 uint64_t
#define __int64 int64_t

typedef uint8_t byte;

#define DEC 10
#define BIN 2
#define HEX 16
#define OCT 8

#define DEG_TO_RAD 0.01745329252f
#define RAD_TO_DEG 57.295779513f
#define PI 3.14159265358979323846f
#define TWO_PI 6.28318530717958647692f
#define HALF_PI 1.57079632679489661923f

#define String std::string

#define srand48(s) srand(s) 
#define drand48() (((double)rand())/((double)RAND_MAX)) 
#define lrand48() rand()


#define pow10f(x) powf(10, x)
#define pow10(x) pow(10, x)


class serialPort
{
public:
	serialPort() {}
	~serialPort() {}

	void print(String out)
	{
		std::cout << out;
	}
	void println(String out)
	{
		std::cout << out << std::endl;
	}
	void print(int out)
	{
		std::cout << out;
	}
	void println(int out)
	{
		std::cout << out << std::endl;
	}
	void print(float out)
	{
		std::cout << out;
	}
	void println(float out)
	{
		std::cout << out << std::endl;
	}

};

extern serialPort Serial;

extern void analogWriteDAC0(int in);

