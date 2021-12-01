#include "simple_shell.h"

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
