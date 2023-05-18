#include "main.h"
/**
 * which_path - retrieve the full path of command
 * @env_val: value of path
 * @cmd: is the command input
 *
 * Return: specific path of the command
 */
char *which_path(char *env_val, char **cmd)
{
	char *cp_path = NULL, *token = NULL, *val = NULL;

	cp_path = strdup(env_val);
	if (!cp_path)
	{
		free(cp_path);
		perror("Error");
		exit(1);
	}

	token = strtok(cp_path, DELIM); 
	value = malloc(sizeof(char) * (strlen(env_val) + strlen(cmd[0])) + 2);

	while (token) 
	{
		strcpy(val, token);
		strcat(val, "/");
		strcat(val, cmd[0]); 

		if (!val) 
		{
			free(cp_path);
			return (NULL);
		}

		if (access(val, F_OK) == 0) 
		{
			free(cp_path);
			return (val);
		}

		token = NULL;
		token = strtok(NULL, DELIM); 
	}
	free(cp_path);
	free(val);
	free(token);
	return (NULL); 
}
