#include "shell.h"
#include <unistd.h>
#include <errno.h>
#include <string.h>

ssize_t str_length(const char *string);
void long_to_string(long num, char *str, int base);
int _print(char *string);
int _printe(char *string);
int _print_error(int errorcode, data_of_program *data);

/**
 * str_length - returns the length of a string
 * @string: the input string
 * Return: the length of the string
 */
ssize_t str_length(const char *string)
{
	return (strlen(string));
}

/**
 * long_to_string - converts a long number to a string
 * @num: the input number
 * str: the output string
 * @base: the base for conversion
 * Return: None
 */
void long_to_string(long num, char *str, int base)
{
	/* Implementation of long_to_string */
}
/** 
 * _print - writes a array of chars in the standard output
 * @string: pointer to the array of chars
 * Return: the number of bytes written
 * On error, -1 is returned, and errno is set appropriately
 */
int _print(char *string)
{
	return (write(STDOUT_FILENO, string, str_length(string)));
}

/**
 * _printe - writes an array of chars to the standard error
 * @string: pointer to the array of chars
 * Return: the number of bytes written
 * On error, -1 is returned, and errno is set appropriately
 */
int _printe(char *string)
{
	return (write(STDERR_FILENO, string, str_length(string)));
}

/**
 * _print_error - writes an array of chars to the standard error
 * @errorcode: error code to print
 * @data: a pointer to the program's data
 * Return: the number of bytes written
 * On error, -1 is returned, and errno is set appropriately
 */
int _print_error(int errorcode, data_of_program *data)
{
	char n_as_string[10] = {'\0'};

	long_to_string((long) data->exec_counter, n_as_string, 10);

	if (errorcode == 2 || errorcode == 3)
	{
		_printe(data->program_name);
		-printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->tokens[0]);
		if (errorcode == 2)
			_printe(": Illegal number: ");
		else
			_printe(": can't cd to ");
		_printe(data->tokens[1]);
		_printe("\n");
	}
	else if (errorcode == 127)
	{
		-printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": not found\n");
	}
	else if (errorcode == 126)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": Permission denied\n");
	}
	return (0);
}

