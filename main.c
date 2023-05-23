#include "shell.h"

/**
 * main - Entry point to our simple_shell
 * Return: Exit status after loop is broken
 */
int main(void)
{
	char *cmd = NULL, **tokenizer = {NULL};
	char *directory = NULL, *path = NULL;
	size_t n = 0;
	ssize_t get_input = 0;
	int which_mode;

	which_mode = isatty(STDIN_FILENO);
	while (1)
	{
		if (which_mode == 1)
			printf("$ ");

		get_input = getline(&cmd, &n, stdin);

		if (get_input == -1)
		{
			free(cmd);
			if (which_mode == 1)
				printf("\n"), exit(1);
			exit(0);
		}

		if (strcmp(cmd, "exit\n") == 0)
		{
			free(cmd);
			break;
		}

		directory = get_env("PATH");
		if (!directory)
			free(cmd), perror("Error"), exit(127);

		tokenizer = _strtok(cmd);
		if (tokenizer[0] == NULL)
			continue;

		if (access(tokenizer[0], F_OK) == 0)
			_execve(tokenizer[0], tokenizer);

		else
		{
			path = which_path(directory, tokenizer);

		if (path == NULL)
		{
			free(tokenizer), perror("Error");
			continue;
		}

		_execve(path, tokenizer);

		free(path);
		}
		free(tokenizer);
	}
	return (0);
}
