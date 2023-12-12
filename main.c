#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point
 *
 * Description: Executes a basic shell interface
 * Return: Always returns 0
 */
int main(void)
{
	char *user_input = NULL;
	size_t size_of_input = 0;
	ssize_t work_done;
	int exit_status;
	char *strstat;

	while (1)
	{
		display_prompt();
		work_done = getline(&user_input, &size_of_input, stdin);
		if (work_done == -1)
		{
			free(user_input);
			perror("Error: Getline");
			exit(1);
		}
		user_input[work_done - 1] = '\0';
		if (my_strcmp(user_input, "exit") == 0)
		{
			if (work_done > 50 && user_input[4] == ' ')
			{
				strstat = user_input + 4;
				exit_status = custom_atoi(strstat);
				free(user_input);
				exit(exit_status);
			}
			else
			{
				free(user_input);
				exit(0);
			}
		}
		run_command(user_input);
	}

	return (0);
}

