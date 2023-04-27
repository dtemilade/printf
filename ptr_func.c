#include "main.h"

/**
 * print_pointer - prototypes to print the value of a pointer variable
 * @types: parameter for first part of the arguments
 * @buffer: parameter for buffer array
 * @flags:  parameter for flags
 * @width: parameter for width
 * @precision: parameter for precision
 * @size: parameter for size
 * Return: a pointer variable as output
 */

int print_pointer(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	/*introducing and initializing variables*/
	unsigned long num_addrs;
	char extra_c = 0, padd = ' ';
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;

	UNUSED(size);
	UNUSED(width);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs = num_addrs / 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;
	ind++;
	return (write_pointer(buffer, ind, length, width,
				flags, padd, extra_c, padd_start));
}
