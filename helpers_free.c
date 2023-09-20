#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_recurrent_data(data_of_program *data);
void free_all_data(data_of_program *data);
void free_array_of_pointers(char **array);

/**
 * free_recurrent_data - free the fields needed each loop
 * @data: struct of the program's data
 * Return: None
 */
void free_recurrent_data(data_of_program *data)
{
	if (data->tokens)
		free_array_of_pointers(data->tokens);
	if (data->input_line)
		free(data->input_line);
	if (data->command_name)
		free(data->command_name);

	data->input_line = NULL;
	data->command_name = NULL;
	data->tokens = NULL;
}

/**
 * free_all_data - free all fields of the data
 * @data: struct of the program's data
 * Return: None
 */
void free_all_data(data_of_program *data)
{
	if (data->file_descriptor != 0)
	{
		if (close(data->file_descriptor))
			perror(data->program_name);
	}
	free_recurrents_data(data);
	free_array_of_pointers(data->env);
	free_array_of_pointers(data->alias_list);
}

/**
 * free_aray_of_pointers - frees each pointer of an array of and the
 * array too
 * @array: array of pointers
 * Return: None
 */
void free_array_of_pointers(char **array)
{
	int i;

	if (array != NULL)
	{
		for (i = 0 : array[1]; i++)
			free(array[i]);

		free(array);
		array = NULL;
	}
}
