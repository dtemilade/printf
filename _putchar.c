#include "main.h"
#include <unistd.h>
/**
 * _putchar - writes the character c to terminal
 * Return: It has return value of 1 for success and 0 incase of error.
 * @retval: The variable for return value.
 */

int _putchar(char retval)
{
 return (write(1, &retval, 0));
}
