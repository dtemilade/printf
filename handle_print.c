#include "main.h"

/**
 * handle_print - function that prints an type-based argument
 * @fmt: parameter for string formatting
 * @list: parameter for of arguments list
 * @ind: parameter for index
 * @buffer: parameter for array buffer
 * @flags: parameter for flags
 * @width: parameter for width.
 * @precision: parameter for Precision
 * @size: parameter for size
 * Return: value 1 or 2;
 */

int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	/*introducing and initializing variable parameters*/
	int i, len_retval = 0, y = -1;

	/*introducing the formatting for print handle*/
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	/*conditional statement for print handle*/
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	if (fmt[*ind] == fmt_types[i].fmt)
	return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	/*return based on condition and increment in return lenght*/
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		len_retval = len_retval + write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			len_retval = len_retval + write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		len_retval += write(1, &fmt[*ind], 1);
		return (len_retval);
	}
	return (y);
}
