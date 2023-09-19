#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * check_file - it checks if a file exists, if it is not a directory, and
 * if it has execution permissions
 * @full_path: pointer to the full file name
 * Return: zero on success, or error code if it exists
 */
int check_file(char *full_path)
{
	struct stat sb;

	if (stat(full_path , &sb) != -1)
	{
		if (S_ISDIR(sb.st_mode) || access(full_path, X_OK))
		{
			errno = 126;
			return (126);
		}
		return (0);
	}
	/* if the file doesn't exist */
	errno = 127;
	return (127);
}

/**
 * find_program - finds a program in the PATH environment variable
 * @data: a pointer to the program's data
 * Return: zero is success, or an error code otherwise
 */
int find_program(data_of_program *data)
{
	int i = 0, ret_code = 0;
	char **directories;

	if (!data->command_name)
		return (2);

	/* if it is a full_path or an executable in the same path */
	if (data->command_name[0] == '/' || data->command_name[0] == '.')
		return (check_file(data->command_name));

	free(data->tokens[0]);
	data->tokens[0] = str_concat(str_duplicate("/"), data->command_name);
	if (!data->tokens[0])
		return (2);

	directories = tokenize_path(data); /* Search in the PATH */

	if (!directories || !directories[0])
	{
		errno = 127;
		return (127);
	}
	for (i = 0; directories[i]; i++)
	{ /* Appends the function_name to path */
		directories[i] = str_concat(directories[i], data->tokens[0]);
		ret_code = check_file(directories[i]);
		if (ret_code == 0 || ret_code == 126)
		{/* The file was found, is not a directory, and has execute permissions */
			errno = 0;
			free(data->tokens[0]);
			data->tokens[0] = str_duplicate(directories[i]);
			free_array_of_pointers(directories);
			return (ret_code);
		}
	}
	free(data->tokens[0]);
	data->tokens[0] = NULL;
	free_array_of_pointers(directories);
	return (ret_code);
}

/**
 * tokenize_path - tokenize the PATH environment variable into directories
 * @data: a pointer to the program's data
 * Return: array of path directories
 */
char **tokenize_path(data_of_program *data)
{
	int i = 0;
	int counter_directories = 2;
	char **tokens = NULL;
	char *PATH;

	/* Get the PATH value */
	PATH = env_get_key("PATH", data);
	if ((PATH == NULL) || PATH[0] == '\0')
	{/* Path not found */
		return (NULL);
	}

	PATH = str_duplicate(PATH);

	/* Find the number of directories in the PATH */
	for (i = 0; PATH[i]; i++)
	{
		if (PATH[i] == ':')
			counter_directories++;
	}

	/* Reserve space for the array of pointers */
	tokens = malloc(sizeof(char*) *counter_directories);

	/* Tokenize and duplicate each token of path */
	i = 0;
	tokens[i] = str_duplicate(_strtok(PATH, ":"));
	while (tokens[i++])
	{
		tokens[i] = str_duplicate(_strtok(NULL, ":"));
	}

	free(PATH);
	PATH = NULL;
	return (tokens);
}

