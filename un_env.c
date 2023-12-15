#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

void unset_env_var(char *name)
{
if (name == NULL)
{
printf("unsetenv: too few arguments\n");
return;
}
if (unsetenv(name) != 0)
{
perror("unsetenv failed");
return;
}
}
