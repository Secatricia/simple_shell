#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

extern char **environ;

typedef struct linked_path
{
	char *value;
	struct linked_path *next;
} path_t;

int _strlen(char *s);
char **strtow(char *str);
int strwlen(char *s);
void _puts(char *str);
char **separate_av(char *str);
void free_separate_av(char **str);
int print_int(int n);
int _putchar(char c);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);
int count_word(char *s, char sep);
int _strcmp(char *s1, char *s2);
path_t *linked_lp(path_t *head, char *value);
path_t *create_linked_lp(char *the_path);
void free_node(path_t *head);

void _prompt(void);
char *_getline(path_t *path, int i, char *argv[]);
void loop_asking(int i, char *argv[]);
int _execute(char **sep);
void error_file(char *chaine, int i, char *argv[]);

path_t *add_path_node(path_t *head, char *value);
path_t *allocate_node(char *value, path_t *next);
char **separate_path(char *str);
char *_getenv(const char *name);
void free_linked_path(path_t *head);
path_t *create_path_variable(void);
void last_c_linked_path(path_t *path);
char *_strcat(char *dest, char *src);
char *test_with_path(path_t *path, char *buffer);
char *_strdup(char *str);

#endif
