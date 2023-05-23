#include "shell.h"

/**
 * _strtok - uses strtok to tokenize cmd
 * @str: cmd input
 * Return: array of tokenized string 
 */
char **_strtok(char *cmd)
{
	char **tokenized = {NULL}, *tok = NULL;
	size_t n = 0;
	int len = 0;

	len = length_count(cmd);
	tokenized = malloc(sizeof(char *) * (len + 1));
	if (!tokenized)
	{
		free(tokenized);
		perror("Error");
		exit(1);
	}

	tok = strtok(cmd, DELIMETER);

	for (; tok; n++)
	{
		tokenized[n] = tok;
		tok = strtok(NULL, DELIMETER);
	}
	tokenized[n] = NULL;
	return (tokenized);
}

/**
 * get_env - retrives env variable from environ
 * @env: env var to find
 * Return: env val
 */
char *get_env(const char *env)
{
	char *full_path = NULL;
	int n = 0;

	while (environ[n]) 
	{
		if (strncmp(environ[n], env, 4) == 0)
		{
			full_path = environ[n];
			return (full_path);
		}
		n++;
	}
	return (NULL);
}

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
