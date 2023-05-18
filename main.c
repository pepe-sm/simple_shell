#include "main.h"

/**
 * main - Entry point to our simple_shell
 * Return: Exit status after loop is broken
 */
int main(void)
{
	char *cmd = NULL, **tokenizer = {NULL};
	char *direcroty = NULL, *path = NULL;
	size_t n = 0;
	ssize_t get_input = 0;
	int which_mode;

	which_mode = isatty(STDIN_FILENO); /*checks for mode interactive and non-interactive*/
	while (1)
	{
		if (which_mode == 1) /*print prompt, on condition mode is interactive*/
			printf("$ ");

		get_input = getline(&cmd, &n, stdin); /*use getline to allow input*/

		if (get_input == -1) /*"ctrl + d" exits the loop when quoted cmd is pressed*/
		{
			free(cmd);
			if (which_mode == 1)
				printf("\n"), exit(1);
			exit(0);
		}

		if (strcmp(cmd, "exit\n") == 0) /*uses string compare to check for "exit" if it matches, loop is broken*/
		{
			free(cmd);
			break;
		}

		directory = _getenv("PATH"); /*retrieve env  PATH*/
		if (!directory)
			free(cmd), perror("Error"), exit(127);

		tokenizer = _strtok(cmd); /*input tokenization*/
		if (tokenizer[0] == NULL)
			continue;

		if (access(tokenizer[0], F_OK) == 0) /*if input is path*/
			_execve(tokenizer[0], tokenizer); /*execute input*/

		else /*retrive path*/
		{
			path = _which(directory, tokenizer); /*search path and retrieve*/

		if (path == NULL) /*if path is null/ does not exist*/
		{
			free(tokenizer), perror("Error");
			continue;
		}

		_execve(path, tokenizer); /*execute path*/

		free(path);
		}
		free(tokenizer);
	}
	return (0);
}
