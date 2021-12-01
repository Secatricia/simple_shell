#include "simple_shell.h"

void error_file(char *chaine, int i)
{
	_puts("hsh: ");
	print_int(i);
	_puts(": ");
	_puts(chaine);
	_puts(": not found\n");
}
