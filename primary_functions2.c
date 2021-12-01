#include "simple_shell.h"

/**
 * print_int - Print an int
 *
 * @arg: Int to print
 *
 * Return: Lenght of int
 */
int print_int(int n)
{
	int size = 1, number, i, length = 0;

	while (n / size > 9 || n / size < -9)
		size *= 10;

	if (n < 0)
		length += _putchar('-');

	for (i = size; i >= 1; i /= 10, length++)
	{
		if (n >= 0)
			number = (n / i) % 10;
		else
			number = ((n / i) % 10) * -1;

		_putchar(number + '0');
	}
	return (length);
}

/**
 * _putchar - Print the character in parameter
 *
 * @c: The character we want to print
 *
 * Return: 1 if it works
 * -1 if we have an error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strcat - Concatenates the string src to string dest
 *
 * @dest: The first string we add an other string
 * @src: The second string we take to add to dest
 *
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int loop, length_dest, length_src;

	length_dest = _strlen(dest);
	length_src = _strlen(src);

	for (loop = 0; loop < length_src; loop++)
		*(dest + length_dest + loop) = *(src + loop);

	return (dest);
}
