# PROJECT SIMPLE SHELL

## Table of Contents 🔍
1. Description
2. Requeriments
3. How to work
4. How to use
5. Files and prototypes used for our program
6. Examples

## 1. Description 📖
What is a shell?
A Shell is a program that takes the command inputs written from the the user’s keyboard and passes them to the machine to execute them through the kernel. It also verifies if the command inputs from the user are correct.

Simple_shell:
It is a C language program that interprets commands but in a simpler way than Shell.

## 2. Requirements ⚙️

List of allowed functions and system calls

* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* getpid (man 2 getpid)
* isatty (man 3 isatty)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)

## 3. How to work 💻

1. When executing our shell, the prompt appears on the screen waiting for orders
2. once the user enters the text line that contains the commands, simple_shell gets this line and saves it in a variable.
3. Then divide this line into arguments
4. Look for these arguments or commands in the directories of the path variable
5. If the command exists, it starts the process and executes it, otherwise it shows an error on the screen.

To understand how our function works, check the flowchart. 👀

![Flowchart](https://github.com/KevinAndresG/simple_shell/blob/main/flowchart%20simple%20shell.png)

## 4. How to use ⌨️

To compile our code you must use:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

The interactive mode ./hsh
```
$ ./hsh
Holbies$ /bin/ls
AUTHORS  _getenv.c  func_builtin.c  getargs.c  hsh  path.c shell.c README.md  execute.c  func_helper.c   getline.c  man_1_simple_shell  shell.h
Holbies$ exit
$
```

The non-interactive mode is, for example, when you type
```
$ echo "/bin/ls" | ./hsh
AUTHORS   _getenv.c  func_builtin.c  getargs.c  hsh path.c shell.c README.md  execute.c  func_helper.c   getline.c  man_1_simple_shell  shell.h
$
```

## 5. Files and prototypes used for our program 📚


| FILE | DESCRIPTION | PROTOTYPES |
| ------ | ------ | ------ |
| shell.h | This file contains all the prototypes of the functions and structures used. |
| shell.c | This file contains our main function. | int main(void)
| getline.c | Contain the function that get the line  | char *read_line(void)
| getargs.c | Takes a string and divides it into small strings that will be the arguments | char **tokenize(char *str, char *delim)
| path.c | Look for the correct command in the directories of the PATH variable | char *get_path(char *args)
| execute.c | Use fork to start the process and run the command | int execute(char *path, char **args)
| func_helper.c | Contains several functions that allow to manipulate strings | int _strlen(const char *s) - char *_strdup(const char *s) - char *_strcat(char *dest, char *src) - int _strcmp(char *s1, char *s2)
| func_builtin.c | contains a function that prints errors and a function that displays signals | void p_error(char *argv, __attribute__((unused)) int count) - void _sign(__attribute__((unused)) int signal)

# 6. Examples and test

Interactive mode
```
$ ./hsh
Holbies$ ls
AUTHORS    _getenv.c  func_builtin.c  getargs.c  hsh  path.c  shell.c README.md  execute.c  func_helper.c   getline.c  man_1_simple_shell  shell.h
Holbies$ whoami
isagomez
Holbies$
Holbies$
Holbies$ exit
```

non-interactive mode
```
$ echo "pwd" | ./hsh
/home/isagomez/workspace/simple_shell
```

## Authors ✒️
* Kevin García  - [KevinAndresG](https://github.com/KevinAndresG)
* Laura Isabela Gómez - [IsabelaGomez101](https://github.com/IsabelaGomez101)

