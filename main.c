#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

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
char *command;
char *argument;
char *name;
char *value;
char *args[3];
int status;

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
command = strtok(user_input, " ");
argument = strtok(NULL, " ");
if (my_strcmp(user_input, "cd") == 0)
{
cd(argument);
}
else if (my_strcmp(command, "setenv") == 0)
{
name = strtok(argument, " ");
value = strtok(NULL, " ");
set_env_var(name, value);
}
else if (my_strcmp(command, "exit") == 0)
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
else
{
pid_t pid = fork();
if (pid == 0)
{
args[0] = command;
args[1] = argument;
args[2] = NULL;
execvp(args[0], args);
perror("exec");
exit(EXIT_FAILURE);
}
else if (pid > 0)
{
waitpid(pid, &status, 0);
if (WIFEXITED(status))
{
exit_status = WEXITSTATUS(status);
}
}
else
{
perror("fork");
exit(EXIT_FAILURE);
{
wait(NULL);
}
}
free(user_input);
user_input = NULL;
}
return (0);
}
}
