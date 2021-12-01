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
	char *buffer;

	buffer = malloc(sizeof(char) * size);

	charactersGet = getline(&buffer, &size, stdin);

	if (charactersGet == EOF)
	{
		free(buffer);
		_putchar('\n');
		exit (EXIT_SUCCESS);
	}

	buffer[charactersGet - 1] = '\0';
	charactersGet -= 1;

	if (_strcmp(buffer, "exit") == 0)
	{
		free(buffer);
		exit (EXIT_SUCCESS);
	}

	return (buffer);
}
