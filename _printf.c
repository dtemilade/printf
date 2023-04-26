#include "main.h"

/**
 * print_buffer - function that shows the contents of the buffer exist
 * @buffer: parameter for arrays of character
 * @buff_ind: parameter for index
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

/**
 * _printf - protoype function for printf project
 * @format: parameter for the print format
 * Return: Always return the printed characters.
 */
int _printf(const char *format, ...)
{
	/*introducing variable parameters*/
	char buffer[BUFF_SIZE];
	int x, y, i;
	int precision, width, size, flags, buff_ind;
	va_list list;

	/*initializing variable parameters*/
	x = 0;
	y = 0;
	buff_ind = 0;

	/*declaring conditional statements*/

	if (format == NULL)
		return (-1);

	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			y++;
		}
		else
		{
			/*output to the terminal*/
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			x = handle_print(format, &i, list, buffer,
					flags, width, precision, size);
			if (x == -1)
				return (-1);
			y += x;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);

	return (y);
}
