#ifndef NFuncs
#define NFuncs

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <NDefs.h>

#define BCD2DEC(num) hornerScheme(num, 0x10, 10)

unsigned long x2i(char*);

String toHex(unsigned long, byte);

int octalToDecimal(int);

long bitCast(unsigned long);

unsigned long bitCast(long);

double mapf(double, double, double, double, double);

unsigned long hornerScheme(unsigned long, unsigned long, unsigned long);

double intToFreq(double);

String boolToString(bool);

void byteWrite(byte, byte);

String boolToString(int);

String fromRight(String, String, byte);

#endif