#include "main.h"

/**
 * _execve - this function executes a command
 * @pth: is the command path
 * @args: command & arguments
 *
 * Return: void
 */
int _execve(char *pth, char **args)
{
	int stat = 0;
	pid_t pid = 0;

	pid = fork(); 

	if (pid == -1) 
	{
		perror("Error");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			free(path);
			free(args);
			exit(EXIT_FAILURE);
		}
	}
	else 
	{
		wait(&stat);
	}
	return (WEXITSTATUS(stat)); 
}
