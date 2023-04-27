#include "main.h"

/**
 * get_width - prototype to calculate width and return its value to terminal
 * @format: parameter for string
 * @i: arguments index parameter
 * @list: parameter for argument list
 * Return: the value of width to the terminal.
 */

int get_width(const char *format, int *i, va_list list)
{
	/*introducing parameter to be used*/
	int x, width = 0;

	for (x = *i + 1; format[x] != '\0'; x++)
	{
		/*check if its digit and then adjust to possible value*/
		if (is_digit(format[x]))
		{
			width *= 10;
			/*new value for width*/
			width = width + format[x] - '0';
		}
		/*maintain the value if its character*/
		else if (format[x] == '*')
		{
			x++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
		}
	/*finally return width if condition not met*/
	*i = x - 1;
	return (width);
}
