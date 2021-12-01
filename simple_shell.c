#include "simple_shell.h"

int main (__attribute__((unused)) int argc, char *argv[], __attribute__((unused)) char *env[])
{
	int i = 0;

	loop_asking(i, argv);

	return (0);
}

void loop_asking(int i, char *argv[])
{
	char *buffer = "", **sep;
	struct stat st;

	do
	{
		_prompt();
		buffer = _getline();
		sep = separate_av(buffer);

		if (stat(sep[0], &st) == 0)
			_execute(sep);
		else
		{
			i++;
			error_file(buffer, i, argv);
		}
	} while (1);
}

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
