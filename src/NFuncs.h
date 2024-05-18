#ifndef NFuncs_h
#define NFuncs_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <NDefs.h>
#include <WString.h>
#include <Stream.h>

#define NFUNCS_MAJOR_VERSION 1
#define NFUNCS_MINOR_VERSION 1
#define NFUNCS_PATCH_VERSION 0

constexpr size_t ulltoa_len = (sizeof(unsigned long long) * 8) + 1;

unsigned long long hexToInteger(const char *);

unsigned long long hornerScheme(unsigned long long number, unsigned long long divisor, unsigned long long factor);

template <typename IntegralType>
IntegralType mapValue(IntegralType input, IntegralType inputLow, IntegralType inputHigh, IntegralType outputLow, IntegralType outputHigh)
{
	return ((input - inputLow) * (outputHigh - outputLow)) / ((inputHigh - inputLow) + outputLow);
}

char* ulltoa(unsigned long long __value, char* __buffer, unsigned char __radix = DEC);

String ulltostr(unsigned long long __value, unsigned char __radix = DEC);

String fromRight(String left, String right, byte columns);

#endif
