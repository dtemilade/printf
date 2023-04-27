#include "main.h"

/**
 * print_non_printable - prototypes to print ascii codes
 *
 * @types: parameter for first part of the arguments
 * @buffer: parameter for buffer array
 * @flags:  parameter for flags
 * @width: parameter for width
 * @precision: parameter for precision
 * @size: parameter for size
 * Return: ascii codes in hexa of non printable
 */

int print_non_printable(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	/*introducing and initializing variables*/
	char *str = va_arg(types, char *);
	int offset = 0, i = 0;

	UNUSED(size);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(width);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset = offset + append_hexa_code(str[i], buffer, i + offset);
		i++;
	}
	buffer[i + offset] = '\0';
	return (write(1, buffer, i + offset));
}
