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
}
if (chdir(path) != 0)
{
perror("cd failed");
}
}
