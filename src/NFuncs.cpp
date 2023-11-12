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

char* ulltoa(unsigned long long __value, char* __buffer, unsigned char __radix)
{
    constexpr char digits[] = "0123456789ABCDEF";
    constexpr size_t digit_count = sizeof(digits) - 1;

    if (__radix < 2)
        __radix = 2;
    else if (__radix > digit_count)
        __radix = digit_count;

    char* digit = __buffer + ulltoa_len;
    *--digit = '\0';

    do
    {
        *--digit = digits[__value % __radix];
        __value /= __radix;
    } while (__value > 0);

    return digit;
}

String ulltostr(unsigned long long __value, unsigned char __radix)
{
    char buffer[ulltoa_len];
    return String(ulltoa(__value, buffer, __radix));
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