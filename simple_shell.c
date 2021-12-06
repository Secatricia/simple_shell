#include "simple_shell.h"

/**
 * main - The main function for simple shell
 *
 * @argc: Count of the arguments passes
 * @argv: Arguments value with the name of the executable
 * @env: List of environment variable
 *
 * Return: 0 if is a success
 */
int main(__attribute__((unused)) int argc, char *argv[], __attribute__((unused))char *env[])
{
	int i = 0;

	loop_asking(i, argv);

	return (0);
}

/**
 * loop_asking - Infinite loop with invoking some functions
 * for asking to user a command, and execute the command if is
 * possible
 *
 * @i: The count of error
 * @argv: The arguments values with the name of executable
 */
void loop_asking(int i, char *argv[])
{
	char *buffer = "", **sep;
	struct stat st;
	path_t *path;

	path = create_path_variable();

	do {
		i++;
		_prompt();
		buffer = _getline(path, i, argv);
		if (buffer != NULL)
		{
			sep = separate_av(buffer);
			sep[0] = test_with_path(path, sep[0]);

			if (buffer != NULL && stat(sep[0], &st) == 0)
				_execute(sep);
			else if (buffer != NULL)
				error_file(buffer, i, argv);

			free_separate_av(sep);
			free(buffer);
		}
	} while (1);

}

/**
 * _execute - Execute the command passes
 *
 * @sep: Array of string with all arguments for the command
 *
 * Return: 1 if an error is occurs, 0 if is a success
 */
int _execute(char **sep)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(sep[0], sep, NULL) == -1)
		{
			perror("Error:");
		}
	}
	else
	{
		wait(&status);
	}

	return (0);
}
