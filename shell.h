#ifndef SHELL_H
#define SHELL_H

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "sys/stat.h"
#include "sys/wait.h"

int _strlen(char *str);
int execute(char **arg);
int builtins(void);
int c_d(char **arg);
int ex_it(__attribute__((unused))char **arg);
int launch(char **args);
char **splitline(char *str);
char *readline(void);
int _strcmp(char *s1, char *s2);

#endif
