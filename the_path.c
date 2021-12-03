#include "simple_shell.h"

/**
 * linked_lp - prints the environment
 * @head:
 * Return: NULL.
 */
path_t *linked_lp(path_t *head, char *value)
{
	path_t *new;

	new = malloc(sizeof(path_t));
	if (new == NULL)
	{
		return (NULL);
	}

	new->valeur = value;
	new->next = NULL;

	if (head != NULL)
	{
		while (head->next != NULL)
			head = head->next;

		head->next = new;
	}

	return (new);
}

char *_getenv(const char *name, char **env)
{
	char *str;
	int i = 0;

	while (env[i] != NULL)
	{
		str = strtok(env[i], "=");

		if (strcmp(str, name) == 0)
		{
			str = strtok(NULL, "=");
			return (str);
		}
		i++;
	}

	str = "(null)";

	return (str);
}

path_t *create_linked_lp(char *the_path)
{
	int i;
	path_t *head = NULL;
	while (the_path[i] != NULL)
	{
		if (head == NULL)
			head = linked_lp(head, the_path[i]);
		else
			linked_lp(head, the_path[i]);

		i++;
	}
	return (head);
}

void free_node(path_t *head)
{
	path_t *tmp;
	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
