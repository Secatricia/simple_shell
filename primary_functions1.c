#include "simple_shell.h"

/**
 * _strlen - Return the length of a string
 *
 * @s: The String we want to know the length
 *
 * Return: length
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		s++;
		length++;
	}

	return (length);
}

/**
 * strtow - Splits a string into words
 *
 * @str: The string we split
 *
 * Return: str
 */
char **strtow(char *str)
{
	char **aled;
	int numberWords, i, iWord, iAled = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	numberWords = count_word(str);

	if (numberWords == 0)
		return (NULL);

	aled = (char **)malloc(sizeof(char *) * numberWords + 1);

	if (aled == NULL)
		return (NULL);

	for (i = 0; *(str + i) != '\0'; i++)
	{
		if (*(str + i) != ' ')
		{
			*(aled + iAled) = (char *)malloc(sizeof(char) * strwlen((str + i)) + 2);

			if (*(aled + iAled) == NULL)
			{
				for (iAled = 0; iAled < numberWords; iAled++)
					free(*(aled + iAled));

				free(aled);
				return (NULL);
			}

			for (iWord = 0; *(str + i + iWord) != ' ' && *(str + i + iWord); iWord++)
				*(*(aled + iAled) + iWord) = *(str + i + iWord);

			if (iWord > 0)
				iAled++;
			i += strwlen((str + i)) - 1;
		}
	}
	return (aled);
}

/**
 * count_word - Return the number of word in the strings
 *
 * @s: The String we want to know the words
 *
 * Return: length
 */
int count_word(char *s)
{
	int length, i = 0;

	if (s == NULL)
		return (0);

	if (*s != ' ')
		length = 1;
	else
		length = 0;

	while (s[i] != '\0')
	{
		if (s[i] != ' ' && i > 0 && s[i - 1] == ' ')
			length++;

		i++;
	}

	return (length);
}

/**
 * strwlen - Return the length of a word in the current string
 *
 * @s: The String we want to know the length
 *
 * Return: length
 */
int strwlen(char *s)
{
	int length = 0;

	while (*(s + length) != ' ' && *(s + length))
		length++;

	return (length);
}

/**
 * _puts - Print in standard output a string
 *
 * @str: The string we want to print
 */
void _puts(char *str)
{
	int length;

	length = _strlen(str);

	write(STDOUT_FILENO, str, length);
}