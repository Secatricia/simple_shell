#include "simple_shell.h"

/**
 * separate_av - separate the words
 *
 * @str: The String we want to know the words
 *
 * Return: The array of string
 */
char **separate_av(char *str)
{
	char *y, **j;
    int i = 0, length;

	if (str == NULL)
		return (NULL);

    length = count_word(str);
    y = strtok(str, " ");

    j = malloc(sizeof(char *) * (length + 1));
    j[length] = NULL;

	while (y != NULL)
	{
        j[i++] = y;
        y = strtok(NULL, " ");
	}

    return (j);
}

/**
 * free_separate_av - Free the memory alocated by separate_av
 *
 * @str: The array of string
 */
void free_separate_av(char **str)
{
	free(str);
}
