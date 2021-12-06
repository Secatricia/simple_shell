#include "simple_shell.h"

/**
 * separate_path - Separate a string when the char ':' is present
 *
 * @str: The string we separate
 *
 * Return: j
 */
char **separate_path(char *str)
{
	char *y, **j;
	int i = 0, length;

	length = count_word(str, ':');
	y = strtok(str, ":");

	j = malloc(sizeof(char *) * (length + 1));
	j[length] = NULL;

	while (y != NULL)
	{
		j[i++] = y;
		y = strtok(NULL, ":");
	}

	return (j);
}

/**
 * create_path_variable - Create the linked list variable
 * path using the environ
 *
 * Return: path
 */
path_t *create_path_variable(void)
{
	char *str;
	char **the_path;
	path_t *path = NULL;
	int j = 0;

	str = _getenv("PATH");
	the_path = separate_path(str);

	while (the_path[j] != NULL)
	{
		if (j == 0)
			path = add_path_node(path, the_path[j]);
		else
			add_path_node(path, the_path[j]);
		j++;
	}

	free(the_path);
	return (path);
}

/**
 * test_with_path - Test if an command exist in one path of path
 *
 * @path: The linked list path
 * @buffer: The command give by the user
 *
 * Return: buffer if no command exist in path, otherwise path + command
 */
char *test_with_path(path_t *path, char *buffer)
{
	int lenValue;
	char *tmp_value, *tmp_buffer;
	int i = 0;
	struct stat st;

	while (path != NULL)
	{
		lenValue = _strlen(path->value);
		tmp_buffer = malloc(sizeof(char) * 256);
		*tmp_buffer = '\0';

		if (path->value[lenValue - 1] != '/')
		{
			tmp_value = strdup(path->value);
			tmp_buffer = _strcat(tmp_buffer, tmp_value);
			tmp_buffer[lenValue] = '/';
			while (buffer[i] != '\0')
			{
				tmp_buffer[lenValue + 1 + i] = buffer[i];
				i++;
			}
			tmp_buffer[lenValue + 1 + i] = '\0';
		}

		if (stat(tmp_buffer, &st) == 0)
		{
			free(tmp_value);
			free(buffer);
			return (tmp_buffer);
		}

		free(tmp_value);
		free(tmp_buffer);
		path = path->next;
		i = 0;
	}
	return (buffer);
}
