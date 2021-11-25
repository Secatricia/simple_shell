# Simple Shell

## General

### Background Context

Write a simple UNIX command interpreter.

### Objective

* Who designed and implemented the original Unix operating system
* Who wrote the first version of the UNIX shell
* Who invented the B programming language (the direct predecessor
 to the C programming language)
* Who is Ken Thompson
* How does a shell work
* What is a pid and a ppid
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of main
* How does the shell use the PATH to find the programs
* How to execute another program with the execve system call
* How to suspend the execution of a process until one of its children terminates
* What is EOF / “end-of-file”?

## Contents of functions

## Usage example
    
    $ ./hsh
    ($) /bin/ls
    hsh main.c shell.c
    ($)
    ($) exit
    $

## names of files

* simple_shell.h

    All definition of macros and prototype of the functions.
    And including all libraries needed.

* simple_shell.c

    Containing the main function. And some other functions, like prompt:
    * int main(int argc, char **argv, char **env);
    * void prompt(void);
    

    
## Authors

Franck Léger - [Github: @Falendrac](https://github.com/Falendrac) - email: leger_franck@hotmail.fr
Lucie Delannay - [Github: @Secatricia](https://github.com/Secatricia) - email: lucie.delrue04@gmail.com
