C - Simple Shell
Description
This is a simple UNIX command interpreter written in C.

Compilation
The shell program is compiled this way:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Usage
The shell program can run in either interactive or non-interactive mode.

Interactive Mode
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
Non-Interactive Mode
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
Included Built-Ins
The simple shell has support for the following built-in commands:

Command	Definition
exit [status]	Exits the shell with a given status
env	Prints the current environment
setenv [variable] [value]	Sets an environment variable to a given value
unsetenv [variable]	Removes an environment variable
Examples
$ /bin/ls
AUTHORS  README.md  built.c  env_list.c  hsh  lists.c  main.c  main.h  shell.c	strings.c
$ ls
AUTHORS  README.md  built.c  env_list.c  hsh  lists.c  main.c  main.h  shell.c	strings.c
$ ^C
$ hello world
./hsh: 1: hello: not found
$ exit

Written by:
1. Jeffrey Maina
2. Leah Mbuthia
