# Simple Shell :shell:

This is a simple UNIX command intepreter that is part of the ALX low-level programming and algorithm curriculumn.

## Description :speech_balloon:

A simple UNIX command language intepreter that reads commands from a file or standard input and executes them.

### Invocation :running:

Usage: **main** [filename]

To invoke its usage, compile all `.c` files in the repository and run the resulting executable:

```
gcc *.c -o main
./main
```

**main** can be invoked both interactively and non-interactively. If **main** is invoked with standard input not connected to a terminal, it reads and executes the commands it has recieved in\
 order.

Example:
```
$ echo "echo 'hello'" | ./main
'hello'
$
```

If **main** is invoked with standard input connected to a terminal, an *interactive* shell is opened. When executing interactively, **main** displays the prompt `$` when it is ready to read a\
 command.

Example:
```
$./main
$
```

Alternatively, if the command line arguments are supplied upon invocation, **main** treats the first argument as a file from which to read commands. The supplied file should contain one comma\
nd per line. **main** runs each of the commands contained in the file in order before exiting.

Example:
```
$ cat test
echo 'hello'
$ ./main test
'hello'
$
```
======
readme
