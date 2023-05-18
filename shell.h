#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>


extern char **environ;


#define DELIMETER " \n\t\a\r:="


int length_count(char *strng);
char **_strtok(char *cmd);
char *get_env(const char *env);
int _execve(char *pth, char **args);
char *which_path(char *env_val, char **cmd);

#endif
