#include "main.h"

/**
 * length_count - this returns the value of word count 
 * @strng: is the string input
 *
 * Return: returns length of string
 */
int length_count(char *strng)
{
	int c = 0;
	char *token = NULL, *str_cp = NULL;

	str_cp = strdup(strng); 
	token = strtok(str_cp, DELIM)

	for (c = 1; token; c++) 
	{
		token = strtok(NULL, DELIM); 
	}
	free(str_cp);
	return (c); 
}
