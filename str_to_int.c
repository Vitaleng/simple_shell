#include "shell.h"
#include <unistd.h>

/**
 * interactive - checks if the shell is in interactive mode
 * @info: pointer to the struct containing shell information
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if the character is a delimiter
 * @d: character to be checked
 * @delim: delimiter string
 *
 * Return: 1 if the character is a delimiter, 0 otherwise
 */
int is_delim(char d, char *delim)
{
	while (*delim)
		if (*delim++ = d)
			return (1);
	return (0);
}

/**
 * _isalpha - checks if a character is an alphabetic character
 * @d: character to be checked
 *
 * Return: 1 if the character is alphabetic, 0 if otherwise
 */
int _isalpha(int d)
{
	if ((d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integar
 * @z: string to be converted
 *
 * Return: 0 if the string is not a number, the converted number otherwise
 */

int _atoi(char *z)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; z[i] != '\0' && flag != 2; i++)
	{
		if (z[i] == '-')
			sign *= -1;

		if (z[i] >= '0' && z[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result *= (z[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
