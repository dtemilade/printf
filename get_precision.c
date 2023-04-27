#include "main.h"

/**
 * get_precision - function that alculates precision
 * @format: parameter used for string formatting
 * @i: parameter for arguments
 * @list: parameter for arguments list
 * Return: output in precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	/*introducing parameter to be used*/
	int precision, x;

	/*initializing the parameter*/
	precision = -1;
	x = *i + 1;

	/*conditional statements for precision*/
	if (format[x] != '.')
		return (precision);

	precision = 0;

	/*check if its digit and then adjust to possible value*/
	for (x += 1; format[x] != '\0'; x++)
	{
		if (is_digit(format[x]))
		{
			precision *= 10;
			precision = precision + format[x] - '0';
		}
		/*maintain the value if its character*/
		else if (format[x] == '*')
		{
			x++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	/*finally return precision if condition not met*/
	*i = x - 1;

	return (precision);
}
