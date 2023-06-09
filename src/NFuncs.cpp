#include "NFuncs.h"

unsigned long long hexToInteger(const char* pointer)
{
    unsigned long long result = 0;
    while (true)
    {
		if (*pointer >= '0' && *pointer <= '9')
		{
			result *= 16;
			result += *pointer - '0';
		}
		else if (*pointer >= 'A' && *pointer <= 'F')
		{
			result *= 16;
			result += (*pointer - 'A') + 10;
		}
		else
			break;
		pointer++;
    }
}

#warning Not implemented
unsigned long long octalToDecimal(unsigned long long octal)
{
	return 0;
}

unsigned long long hornerScheme(unsigned long long number, unsigned long long divisor, unsigned long long factor)
{
    unsigned long long remainder = number % divisor, quotient = number / divisor, result = 0;
    if (quotient != 0 || remainder != 0)
        result += hornerScheme(quotient, divisor, factor) * factor + remainder;
    return result;
}

String fromRight(String left, String right, byte columns)
{
    unsigned char whiteSpaceCount = columns - left.length() - right.length();
    left.reserve(columns);
    for (unsigned char index = 0; index < whiteSpaceCount; index++)
        left += ' ';
    left += right;
    return left;
}