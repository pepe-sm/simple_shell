#include "shell.h"

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
	token = strtok(str_cp, DELIMETER);

	for (c = 1; token; c++) 
	{
		token = strtok(NULL, DELIMETER); 
	}
	free(str_cp);
	return (c); 
}
