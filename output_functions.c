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
 * @i: The number of increment of loop
 * @argv: All arguments passes when the program is executed
 * @env: The linked list of all environment variable
 *
 * Return: Buffer, or NULL if EOF or exit
 */
char *_getline(path_t *path, int i, char *argv[], env_t *env)
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
		_putchar('\n');
		exit_procedure(buffer, path, env);
	}

	buffer[charactersGet - 1] = '\0';
	charactersGet -= 1;

	if (charactersGet == 0)
	{
		free(buffer);
		return (NULL);
	}

	if (_strcmp(buffer, "exit") == 0)
		exit_procedure(buffer, path, env);

	return (buffer);
}

/**
 * exit_procedure - Free all variable when EOF or exit
 *
 * @buffer: The buffer of getline
 * @path: The linked list path
 * @env: The linked list of all environment variable
 */
void exit_procedure(char *buffer, path_t *path, env_t *env)
{
		free_linked_env(env);
		free_linked_path(path);
		free(buffer);
		exit(EXIT_SUCCESS);
}

/**
 * _printenv - Print all environment variables
 *
 * @env: Linked list of all environment variables
 * @sep: All options for printenv
 */
void _printenv(env_t *env, char **sep)
{

	while (env != NULL)
	{
		_puts(env->name);
		_puts("=");

		if (env->value != NULL)
			_puts(env->value);

		if (sep[1] == NULL || (sep[1] != NULL && _strcmp(sep[1], "-0") != 0))
			putchar('\n');

		env = env->next;
	}
}
