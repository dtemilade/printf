#include "main.h"

/**
 * get_flags - function proptotype for flags
 * @format: parameter used for formatted string
 * @i: input parameter.
 * Return: Flags as output to the terminal:
 */
int get_flags(const char *format, int *i)
{

/*character with their corresponding value*/
/* - + 0 # ' ' */
/* 1 2 4 8  16 */

/*introducing parameter to be used*/
const char VAL_F[] = {'-', '+', '0', '#', ' ', '\0'};
const int ARR_F[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
int x, y;
int flags = 0;

/* conditional statement for the flags*/
for (y = *i + 1; format[y] != '\0'; y++)
{
for (x = 0; VAL_F[x] != '\0'; x++)
if (format[y] == VAL_F[x])
{
/*output result based on conditional statement*/
flags |= ARR_F[x];
break;
}
/*output result based on conditional statement*/
if (VAL_F[x] == 0)
break;
}

*i = y - 1;

return (flags);
}
