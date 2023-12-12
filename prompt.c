#include "shell.h"
#include <unistd.h>
#include <stdio.h>

/**
 * display_prompt - displays shell prompt to terminal
 **/
void display_prompt(void)
{
	char prompt[] = "$ ";

	write(STDOUT_FILENO, prompt, 2);
}

