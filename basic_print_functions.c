#include "main.h"

/*basic built-in print functions*/

/**
 * print_char - prototype for printing a character
 * @types: parameter for first part of the arguments
 * @buffer: parameter for buffer array
 * @flags:  parameter for flags
 * @width: parameter for width
 * @precision: parameter for precision
 * @size: parameter for size
 * Return: character printed
 */

int print_char(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	/*introducing parameter for prototype used*/
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width,
				precision, size));
	}
/**
 * print_int - prototype that prints integer
 * @types: parameter for first part of the arguments
 * @buffer: parameter for buffer array
 * @flags:  parameter for flags
 * @width: parameter for width
 * @precision: parameter for precision
 * @size: parameter for size
 * Return: an integer
 */
int print_int(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	unsigned long int num;
	int i = BUFF_SIZE - 2;
	long int n = va_arg(types, long int);
	int is_negative = 0;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num = num / 10;
	}

	i++;

	return (write_number(is_negative, i, buffer,
				flags, width, precision, size));
}

/**
 * print_binary - prototype that prints binary
 * @types: parameter for first part of the arguments
 * @buffer: parameter for buffer array
 * @flags:  parameter for flags
 * @width: parameter for width
 * @precision: parameter for precision
 * @size: parameter for size
 * Return: binary.
 */
int print_binary(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	/*introducing parameters for usage in prototype*/
	unsigned int var1, var2, i, sum = 0;
	unsigned int a[32];
	int count = 0;

	UNUSED(width);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(buffer);

	var1 = va_arg(types, unsigned int);
	var2 = 2147483648;
	a[0] = var1 / var2;
	for (i = 1; i < 32; i++)
	{
		var2 /= 2;
		a[i] = (var1 / var2) % 2;
	}
	for (i = 0; i < 32; i++)
	{
		sum = sum + a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

/**
 * print_string - prototype to prints a string
 * @types: parameter for first part of the arguments
 * @buffer: parameter for buffer array
 * @flags:  parameter for flags
 * @width: parameter for width
 * @precision: parameter for precision
 * @size: parameter for size
 * Return: set of string
 */
int print_string(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	/*introducing parameter for prototype used*/
	char *str = va_arg(types, char *);
	int i, length = 0;

	UNUSED(width);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(buffer);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
		length++;
	if (precision < length && precision >= 0)
		length = precision;
	if (length < width)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}

/**
 * print_percent - prototypes to prints percent sign
 * @types: parameter for first part of the arguments
 * @buffer: parameter for buffer array
 * @flags:  parameter for flags
 * @width: parameter for width
 * @precision: parameter for precision
 * @size: parameter for size
 * Return: percent sign
 */

int print_percent(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	UNUSED(width);
	UNUSED(size);
	UNUSED(types);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(buffer);
	return (write(1, "%%", 1));
}
