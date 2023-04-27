#include "main.h"

/*built-in for write handles*/

/**
 * handle_write_char - prototype that handle string printing
 * @c: parameter for char data types.
 * @buffer: parameter for buffer array
 * @flags:  parameter for flags
 * @width: parameter for width
 * @precision: parameter for precision
 * @size: parameter for size
 * Return: string.
 */
int handle_write_char(char c, char buffer[], int flags,
 int width, int precision, int size)
{
/*introducing parameter*/
char padd = ' ';
int i = 0;

UNUSED(size);
UNUSED(precision);

if (flags & F_ZERO)
padd = '0';

buffer[i++] = c;
buffer[i] = '\0';

if (width > 1)
{
buffer[BUFF_SIZE - 1] = '\0';
for (i = 0; i < width - 1; i++)
buffer[BUFF_SIZE - i - 2] = padd;

if (flags & F_MINUS)
return (write(1, &buffer[0], 1)
 + write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
else
return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1)
 + write(1, &buffer[0], 1));
}

return (write(1, &buffer[0], 1));
}

/**
 * write_number - prototype that handle number printing
 * @is_negative: verifying if its negative
 * @ind: parameter for index
 * @buffer: parameter for buffer array
 * @flags:  parameter for flags
 * @width: parameter for width
 * @precision: parameter for precision
 * @size: parameter for size
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int ind, char buffer[], int flags,
 int width, int precision, int size)
{
int length = BUFF_SIZE - ind - 1;
char padd = ' ', extra_ch = 0;

UNUSED(size);

if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (is_negative)
extra_ch = '-';
else if (flags & F_PLUS)
extra_ch = '+';
else if (flags & F_SPACE)
extra_ch = ' ';

return (write_num(ind, buffer, flags, width, precision,
length, padd, extra_ch));
}

/**
 * write_num - prototype that writes number using bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: parameter for buffer array
 * @flags:  parameter for flags
 * @width: parameter for width
 * @prec: parameter for precision
 * @length: parameter for size
 * @padd: parameter for character pading
 * @extra_c: parameter for Extra character
 * Return: numbers
 */
int write_num(int ind, char buffer[], int flags, int width,
 int prec,int length, char padd, char extra_c)
{
int i, padd_start = 1;

if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
return (0); /* printf(".0d", 0)  no char is printed */
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */
if (prec < length && prec > 0)
padd = ' ';
while (length < prec)
buffer[--ind] = '0', length++;
if (extra_c != 0)
length++;
if (length < width)
{
for (i = 1; i < width - length + 1; i++)
buffer[i] = padd;
buffer[i] = '\0';
if (flags & F_MINUS && padd == ' ')
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
}
else if (!(flags & F_MINUS) && padd == ' ')
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
{
if (extra_c)
buffer[--padd_start] = extra_c;
return (write(1, &buffer[padd_start], i - padd_start) +
write(1, &buffer[ind], length - (1 - padd_start)));
}
}
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - prototype that handle unsigned number printing
 * @is_negative: verifying if its negative
 * @ind: parameter for index
 * @buffer: parameter for buffer array
 * @flags:  parameter for flags
 * @width: parameter for width
 * @precision: parameter for precision
 * @size: parameter for size
 * Return: Number of written chars.
 */
int write_unsgnd(int is_negative, int ind, char buffer[], int flags,
 int width, int precision, int size)
{
char padd = ' ';
int i = 0, length = BUFF_SIZE - ind - 1;

UNUSED(size);
UNUSED(is_negative);

if (precision == 0 && buffer[ind] == '0' && ind == BUFF_SIZE - 2)
return (0);

if (length > precision && precision > 0)
padd = ' ';

while (length < precision)
{
buffer[--ind] = '0';
length++;
}

if (!(flags & F_MINUS) && (flags & F_ZERO))
padd = '0';

if (length < width)
{
for (i = 0; i < width - length; i++)
buffer[i] = padd;

buffer[i] = '\0';

if (flags & F_MINUS)
{
return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
}
else
{
return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
}
}

return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - prototype that writes a memory address
 * @buffer: parameter for buffer array
 * @ind: Index at which the number starts on the buffer
 * @length: parameter for size
 * @width: parameter for width
 * @flags:  parameter for flags
 * @padd: parameter for character pading
 * @extra_c: parameter for Extra character
 * @padd_start: parameter for Index at which padding should start
 * Return: memory address
 */
int write_pointer(char buffer[], int ind, int length, int width,
 int flags, char padd, char extra_c, int padd_start)
{
int i;

if (length < width)
{
for (i = 3; i < width - length + 3; i++)
buffer[i] = padd;
buffer[i] = '\0';
if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
}
else if (!(flags & F_MINUS) && padd == ' ')
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
}
else if (padd == '0' && !(flags & F_MINUS))
{
if (extra_c)
buffer[--padd_start] = extra_c;
buffer[1] = '0';
buffer[2] = 'x';
return (write(1, &buffer[padd_start], i - padd_start)
 + write(1, &buffer[ind], length - (1 - padd_start) - 2));
}
}
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
