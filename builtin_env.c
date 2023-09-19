#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * builtin_env - it shows the environment where the shell runs
 * @data: struct for the program's data
 * Return: 0 if success, or other number if it's declared in the arguments
 */
int buitlin_env(data_of_program *data)
{
	int i;
	char cpname[50] = {'\0'};
	char *var_copy = NULL;

	/* if no arguments */
	if (data->tokens[1] == NULL)
		print_environ(data);
	else
	{
		for (i = 0; data->tokens[1][i]; i++)
		{/* checks if there is a char = */
			if (data->tokens[1][i] == '=')
			{/* checks if there is a variable with the same name and changes its value temporarily */
				var_copy = str_duplicate(env_get_key(cpname, data));
				if (var_copy != NULL)
					env_set_key(cpname, data->tokens[1] + i + 1, data);

				/* print the environ */
				print_environ(data);
				if (env_get_key(cpname, data) == NULL)
				{/* print the variable if it does not exist in the environ */
					_print(data->tokens[1]);
					_print("\n");
				}
				else
				{/* returns the old value of the var */
					env_set_key(cpname, var_copy, data);
					free(var_copy);
				}
				return (0);
			}
			cpname[i] = data->tokens[1][i];
		}
		errno = 2;
		perror(data->command_name);
		errno = 127;
	}
	return (0);
}

/**
 * builtin_set_env - sets an environment variable
 * @data: struct for the program's data
 * Return: zero is success, another number if it's declared in the arguments
 */
int builtin_set_env(data_of_program *data)
{
	/* validate args */
	if (data->tokens[1] == NULL || data->tokens[2] == NULL)
		return (0);
	if (data->tokens[3] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}

	env_set_key(data->tokens[1], data->tokens[2], data);

	return (0);
}

/**
 * builtin_unset_env - unsets an environment variable
 * @data: struct for the program's data
 * Return: zero if success, another number if it's declared in the arguments
 */
int builtin_unset_env(data_of_program *data)
{
	/* validate args */
	if (data->tokens[1] == NULL)
		return (0);
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	env_remove_key(data->tokens[1], data);

	return (0);
}

				
			


