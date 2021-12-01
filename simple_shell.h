#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

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
int count_word(char *s);

void _prompt(void);
char *_getline(void);
void loop_asking(int i, char *argv[]);
int _execute(char **sep);
void error_file(char *chaine, int i, char *argv[]);

#endif
