#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void cd(char *path)
{
if (path == NULL)
{
path = getenv("HOME");
if (path == NULL)
{
printf("Error: Home environment variable not set\n");
return;
}
}
if (chdir(path) != 0)
{
perror("Directory does not exit");
}
}
