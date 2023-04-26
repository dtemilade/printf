#include "main.h"

/**
 * get_size - prototype to calculate the size to cast the argument
 * @format: parameter for string formatting
 * @i: arguments to get size from.
 * Return: size as output to the terminal.
 */
int get_size(const char *format, int *i)
{
int size = 0, x;

x = *i + 1;

/*conditional statement to verify size*/
if (format[x] == 'l')
size = S_LONG;

else if (format[x] == 'h')
size = S_SHORT;

/*conditional statement to determine value*/
if (size == 0)
*i = x - 1;

else
*i = x;
/*returning the precision size*/
return (size);
}
