#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int set_env_var(char *name, char *value)
{
if (name == NULL || value == NULL)
{
printf("setenv: too few arguments\n");
return (1);
}
if (strchr(name, '=') != NULL)
{
printf("setenv: Invalid environment variable name\n");
return (1);
}
if (setenv(name, value, 1) != 0)
{
perror("setenv failed");
return (1);
}
return (0);
}
