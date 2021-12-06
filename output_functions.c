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
 * @path: The linked list path, if EOF or exit, it's free
 *
 * Return: Buffer, or NULL if EOF or exit
 */
char *_getline(path_t *path, int i, char *argv[])
{
	size_t size = 256;
	ssize_t charactersGet;
	char *buffer;

	buffer = malloc(sizeof(char) * size);

	charactersGet = getline(&buffer, &size, stdin);

	if (charactersGet > 256)
	{
		error_file(buffer, i, argv);
		free(buffer);
		return (NULL);
	}

	if (charactersGet == EOF)
	{
		free_linked_path(path);
		free(buffer);
		_putchar('\n');
		exit(EXIT_SUCCESS);
	}

	buffer[charactersGet - 1] = '\0';
	charactersGet -= 1;

	if (charactersGet == 0)
	{
		free(buffer);
		return (NULL);
	}

	if (_strcmp(buffer, "exit") == 0)
	{
		free_linked_path(path);
		free(buffer);
		exit(EXIT_SUCCESS);
	}

	return (buffer);
}
