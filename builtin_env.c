#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * builtin_env - it shows the environment where the shell runs
 * @data: struct for the program's data
 * Return: 0 if success, or other number if it's declared in the arguments
 */
int builtin_env(data_of_program *data)
{
	int i;
	char cpname[50] = {'\0'};
	char *var_copy = NULL;

	/* if no arguments */
	if (data->tokens[1] == NULL)
		print_environ(data);	


