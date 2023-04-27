#include "main.h"

/*advanced built-in print functions*/

/**
 * print_unsigned - prototypes to prints an unsigned number
 * @types: parameter for first part of the arguments
 * @buffer: parameter for buffer array
 * @flags:  parameter for flags
 * @width: parameter for width
 * @precision: parameter for precision
 * @size: parameter for size
 * Return: unsigned number.
 */
int print_unsigned(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	/*introducing parameter for prototype used*/
	unsigned long int num = va_arg(types, unsigned long int);
	int i = BUFF_SIZE - 2;

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num = num / 10;
	}
	i++;

	return (write_unsgnd(0, i, buffer, flags,
				width, precision, size));
}

/**
 * print_octal - prototypes to prints octal notation
 * @types: parameter for first part of the arguments
 * @buffer: parameter for buffer array
 * @flags:  parameter for flags
 * @width: parameter for width
 * @precision: parameter for precision
 * @size: parameter for size
 * Return: octal notation
 */

int print_octal(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	/*introducing parameter for prototype used*/
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;
	int i = BUFF_SIZE - 2;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - prototypes to prints hexadecimal notation
 * @types: parameter for first part of the arguments
 * @buffer: parameter for buffer array
 * @flags:  parameter for flags
 * @width: parameter for width
 * @precision: parameter for precision
 * @size: parameter for size
 * Return: hexadecimal notation
 */

int print_hexadecimal(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer, flags,
			'x', width, precision, size));
}

/**
 * print_hexa_upper - prototypes to prints upper hexadecimal notation
 * @types: parameter for first part of the arguments
 * @buffer: parameter for buffer array
 * @flags:  parameter for flags
 * @width: parameter for width
 * @precision: parameter for precision
 * @size: parameter for size
 * Return: upper hexadecimal notation
 */
int print_hexa_upper(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags,
				'X', width, precision, size));
}

/**
 * print_hexa - prototypes to print hexadecimal number either lower or upper
 * @types: parameter for first part of the arguments
 * @buffer: parameter for buffer array
 * @flags:  parameter for flags
 * @width: parameter for width
 * @precision: parameter for precision
 * @size: parameter for size
 * @map_to: parameter to map the number to
 * @flag_ch: active flags parameters
 * Return: hexadecimal number either lower or upper
 */
int print_hexa(va_list types, char map_to[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size)
{
	/*introducing parameter for prototype used*/
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;
	int i = BUFF_SIZE - 2;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num = num / 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags,
				width, precision, size));
}
