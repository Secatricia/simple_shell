#include "simple_shell.h"

/**
 * _prompt - Write the prompt
 *
 */
void _prompt(void)
{
	_puts("$ ");
}

/**
 * _getline - Ask to the user what command he want
 *
 * Return: Buffer, or NULL if EOF
 */
char *_getline(void)
{
	size_t size = 126;
	ssize_t charactersGet;
	char buffer[126];
	char *string = buffer;

	charactersGet = getline(&string, &size, stdin);

	if (charactersGet == EOF)
	{
		_putchar('\n');
		exit (EXIT_SUCCESS);
	}

	buffer[charactersGet - 1] = '\0';
	charactersGet -= 1;

	return (string);
}
