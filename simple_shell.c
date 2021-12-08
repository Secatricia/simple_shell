#include "simple_shell.h"

/**
 * main - The main function for simple shell
 *
 * @argc: Count of the arguments passes
 * @argv: Arguments value with the name of the executable
 *
 * Return: 0 if is a success
 */
int main(__attribute__((unused)) int argc, char *argv[])
{
	int i = 0;
	path_t *path;
	env_t *env;

	env = create_env_variable();
	path = create_path_variable(env);

	loop_asking(i, argv, env, path);

	return (0);
}

/**
 * loop_asking - Infinite loop with invoking some functions
 * for asking to user a command, and execute the command if is
 * possible
 *
 * @i: The count of error
 * @argv: The arguments values with the name of executable
 * @env: The linked list of env variable
 * @path: The linked list of path variable
 */
void loop_asking(int i, char *argv[], env_t *env, path_t *path)
{
	char *buffer = "", **sep;
	int path_exec, size_test = 0;
	struct stat st;

	do {
		i++;
		_prompt();
		buffer = _getline(path, env);
		sep = separate_av(buffer, " \t\n\v\r\f");

		if (sep != NULL && _strlen(sep[0]) > 255)
		{
			error_file(sep[0], i, argv, 1);
			size_test = 1;
		}
		if (buffer != NULL && sep != NULL && size_test == 0)
			if ((buffer[0] == '.' && buffer[1] != '\0') || buffer[0] != '.')
			{
				path_exec = test_with_path(path, sep, argv, i);

				if ((_strcmp(sep[0], "env") == 0 || _strcmp(sep[0], "printenv") == 0))
					if (path_exec == 0)
					_printenv(env, sep);

				if (_strcmp(sep[0], "exit") == 0)
				{
					free_separate_av(sep);
					exit_procedure(buffer, path, env);
				}

				if (buffer != NULL && path_exec == 1 && stat(sep[0], &st) == 0)
					_execute(sep[0], sep, argv, i);
				else if (buffer != NULL && path_exec == 1)
					error_file(sep[0], i, argv, 0);
			}
		if (sep != NULL)
			free_separate_av(sep);
		free(buffer);
		size_test = 0;
	} while (1);
}

/**
 * _execute - Execute the command passes
 *
 * @command: The command passes by the user
 * @sep: Array of string with all arguments for the command
 * @argv: Argument value passes when the program is executed
 * @i: The count of loop
 *
 * Return: 1 if an error is occurs, 0 if is a success
 */
int _execute(char *command, char **sep, char **argv, int i)
{
	pid_t child_pid;
	int status;

	if (command[0] == '.' && command[1] == '.')
	{
		error_file(command, i, argv, 2);
		return (1);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(command, sep, environ) == -1)
		{
			error_file(command, i, argv, 2);
		}
	}
	else
	{
		wait(&status);
	}

	return (0);
}
