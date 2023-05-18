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

	len = len_counter(cmd);
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
	char *_full_path = NULL;
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
