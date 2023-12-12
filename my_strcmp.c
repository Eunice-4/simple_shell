#include "shell.h"

/**
 * my_strcmp - Compare two strings
 * @strA: first string to compare
 * @strB: second string to compare
 *
 * Return: 0 if the strings are equal, otherwise the difference
 */
int my_strcmp(const char *strA, const char *strB)
{
	while (*strA && *strB && (*strA == *strB))
	{
		strA++;
		strB++;
	}

	if (*strA == '\0' && *strB == '\0')
	{
		return (0);
	}

	return (*strA - *strB);
}

