#include "main.h"

/**
 * print_reverse - prototypes to print reverse string.
 *
 * @types: parameter for first part of the arguments
 * @buffer: parameter for buffer array
 * @flags:  parameter for flags
 * @width: parameter for width
 * @precision: parameter for precision
 * @size: parameter for size
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	/*introducing and initializing variables*/
	int ret_val, i;
	char *str;

	ret_val = 0;

	UNUSED(flags);
	UNUSED(size);
	UNUSED(width);
	UNUSED(buffer);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		ret_val++;
	}
	return (ret_val);
}
