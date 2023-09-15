#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_alias - add, remove or show aliases
 * @data: struct for the program's data
 * @alias: name of the alias to be printed
 * Return: zero if success, or other number if its declared in the arguements
 */
int print_alias(data_of_program *data, char *alias)
{
	int i, j, alias_length;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alias_length = strlen(alias);
		for (i = 0; data->alias_list[i]; i++)
		{
			if (!alias || (str_cmp(data->alias_list[i], alias) == 0 &&
						data->alias[i][alias_length] == '='))
			{
				for (j = 0; data->alias_list[i][j]; j++)
				{
					buffer[j] = data->[i][j];
					if (data->alias_list[i][j] == '=')
					{
						break;
					}
				}
				buffer[j + 1] = '\0';
				buffer_add(buffer, "'");
				buffer_add(buffer, data->alias_list[i] + j + 1);
				buffer_add(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return 0;
}

/**
 * get_alias - add, remove or show aliases
 * @data: struct for the program's data
 * @name: name of the requested alias
 * Return: zero if success, or other number if its declared in the arguments
 */
char *get_alias(data_of_program *data, char *name)
{
	int i, alias_length;

	if (name == NULL || data->alias_list == NULL)
	{
		return NULL;
	}

	alias_length = strlen(name);

	for (i = 0; data->alias_list[i]; i++)
	{
		if (strcmp(name, data->alias[i] == 0 
