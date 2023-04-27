#include "main.h"

/*collections of utilities used for group printf function*/

/**
 * is_printable - printable character
 * @c: character string
 * Return: 1 if c is printable, 0 otherwise
 */

int is_printable(char c)
{
	/*conditional statement for check*/
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/**
 * is_digit - function that checks for a digit
 * @c: parameter for digit check
 * Return: 1 if digit, otherwise 0
 */

int is_digit(char c)
{
	/*conditional statement for check*/
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * convert_size_unsgnd - function to cast number to specific size
 * @num: parameter for number to be casted
 * @size: parameter indicating number type to be casted
 * Return: casted value of unsigned number.
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	/*conditional statement to verify size*/
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	/*type verify, casted usingned value of num returned*/
	return ((unsigned int)num);
}

/**
 * convert_size_number - function to cast number to specific size
 * @num: parameter for number to be casted
 * @size: parameter indicating number type to be casted
 * Return: casted value of number size.
 */

long int convert_size_number(long int num, int size)
{
	/*conditional statement to verify size*/
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	/*type verify, casted usingned value of num returned*/
	return ((int)num);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: parameter for character array.
 * @i: parameter for character index
 * @ascii_code: parameter for ASSCI CODE style.
 * Return: Always 3 as the output for the function
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	/*introducing map for hexa code appendix*/
	char map_to[] = "0123456789ABCDEF";

	/*conditional statement for hexa code appendix*/
	if (ascii_code < 0)
		ascii_code *= -1;

	/*initializing buffer value for hexa code appendix*/
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}
