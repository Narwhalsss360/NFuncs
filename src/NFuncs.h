#ifndef NFuncs_h
#define NFuncs_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <NDefs.h>

#define NFUNCS_MAJOR_VERSION 1
#define NFUNCS_MINOR_VERSION 1
#define NFUNCS_PATCH_VERSION 0

#define BCD2DEC(num) hornerScheme(num, 0x10, 10)

unsigned long long hexToInteger(const char *);

unsigned long long octalToDecimal(unsigned long long);

template <typename IntegralType>
IntegralType mapValue(IntegralType input, IntegralType inputLow, IntegralType inputHigh, IntegralType outputLow, IntegralType outputHigh)
{
	return ((input - inputLow) * (outputHigh - outputLow)) / ((inputHigh - inputLow) + outputLow);
}

unsigned long long hornerScheme(unsigned long long number, unsigned long long divisor, unsigned long long factor);

String fromRight(String left, String right, byte columns);

#endif
