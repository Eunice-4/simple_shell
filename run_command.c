#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * run_command - takes user input and executes it with execve
 * @user_input: pointer to a string containing user input
 */
void run_command(char *user_input)
{
	char **command_arg = malloc(sizeof(char *) * 4);
	pid_t child_pid;
	int child_status;

	if (command_arg == NULL)
	{
		perror("Error: malloc on input");
		exit(1);
	}

	command_arg[0] = "/bin/sh";
	command_arg[1] = "-c";
	command_arg[2] = user_input;
	command_arg[3] = NULL;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error: failed to fork");
		exit(1);
	}
	if (child_pid == 0)
	{
		if (execve("/bin/sh", command_arg, NULL) == -1)
		{
			perror("Error: execve");
			exit(1);
		}
	}
	else
	{
		waitpid(child_pid, &child_status, 0);
	}
	free(command_arg);
}

