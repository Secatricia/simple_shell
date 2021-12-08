# Simple Shell

## General

    Hello, and welcome to our second team project.
    You are in the project of Franck LEGER and Lucie DELANNAY and in this project, 
    we write our own Shell program.

## Requirements

    For compiling:

    > gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c

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

## Usage example
    
    $ ./hsh
    ($) /bin/ls
    hsh main.c shell.c
    ($)
    ($) exit
    $

## names of files and contents of functions

* simple_shell.h

    All definition of macros, the struct and prototype of the functions.
    And including all libraries needed.

* simple_shell.c

    Containing the main function. And some other functions, like loop_asking:
    main - The main function for simple shell
    loop_asking - Infinite loop with invoking some functions
    _execute - Execute the command passes

* _strcmp.c

    _strcmp - copy as a function of n

* _strtok.c

    separate_av - separate the words and return the array of string
    free_separate_av - Free the memory alocated by separate_av

* allocate_functions

     _realloc - Function that reallocates a memory block using malloc and free 
     the pointer ptr has been free and the content is copy in a new pointer
     _calloc - Function that allocates memory for an array

* AUTHORS

    This file lists all individuals having contributed content to the repository.

* env_in_linked_list.c

    add_env_node - add a new node in the linked list env
    allocate_node_env - Allocate a new node for the linked list env
    free_linked_env - Free the linked list env
    create_env_variable - Create the linked list variable

* error_file.c

    error_file - handle error

* output_functions.c

    _prompt - Write the prompt
    _getline - Ask to the user what command he want
    exit_procedure - Free all variable when EOF or exit
    _printenv - Print all environment variables

* path_in_linked_list1.c

    add_path_node - add a new node in the linked list path
    allocate_node - Allocate a new node for the linked list path
    free_linked_path - Free the linked list path
    _getenv - Get an environment variable

* path_in_linked_list2.c

    separate_path - Separate a string when the char ':' is present
    create_path_variable - Create the linked list variable
    test_with_path - Test if an command exist in one path of path

* primary_functions1.c

    count_word - Return the number of word in the strings
    strwlen - Return the length of a word in the current string
    _puts - Print in standard output a string

* primary_functions2.c

    print_int - Print an int
    _putchar - Print the character in parameter
    _strcat - Concatenates the string src to string dest
    _strdup - Allocated a newly space in memory and copy a
    string given as a parameter


    
## Authors

Franck Léger - [Github: @Falendrac](https://github.com/Falendrac) - email: leger_franck@hotmail.fr
Lucie Delannay - [Github: @Secatricia](https://github.com/Secatricia) - email: lucie.delrue04@gmail.com
