#include "main.h"

/**
 * print_rot13string - prototypes to print a string in rot13.
 *
 * @types: parameter for first part of the arguments
 * @buffer: parameter for buffer array
 * @flags:  parameter for flags
 * @width: parameter for width
 * @precision: parameter for precision
 * @size: parameter for size
 * Return: string in rot13.
 */
int print_rot13string(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int ret_val = 0;
	unsigned int i, j;
	char x;
	char *str;

	str = va_arg(types, char *);

	UNUSED(width);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(buffer);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				ret_val++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			ret_val++;
		}
	}
	return (ret_val);
}
