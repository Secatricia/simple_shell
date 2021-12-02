#include "simple_shell.h"

/**
 * error_file - handle error
 *
 * @chaine: user's chain
 * @i: count
 * @argv: Argument value passes at the beginning
 */
void error_file(char *chaine, int i, char *argv[])
{
	_puts(argv[0]);
	_puts(": ");
	print_int(i);
	_puts(": ");
	_puts(chaine);
	_puts(": not found\n");
}
