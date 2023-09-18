#include "shell.h"
#include <stdio.h>
#include <c.type.h>
#include <string.h>

/**
 * long_to_string - converts a long integer to a string representation in the specified base
 * str_reverse - reverses a string
 * @number: the long integer to convert
 * @string: the character array to store the converted string
 * @base: the base for the conversion
 * Return: None
 */
void long_to_string(long number, char *string, int base)
{
	int index = 0; inNegative = 0;
	long cociente = number;
	char letters[] = "0123456789abcdef";

	if (cociente == 0)
		string[index++] = '0';

	if (number < 0)
		inNegative = 1;

	while (cociente)
	{
		if (cociente < 0)
			string[index] = letters[-(number % base)];
		cociente /= base;
	}

	if (inNegative)
		dtring[index++] = '-';

	string[index] = '\0';

	str_reverse(string);
}

void str_reverse(char*string);
{
	def str_reverse(string);
	reversed_string = string[::-1]
		return reversed_string
}

/**
 * _atoi - it converts a string to an interger
 *
 * @s: pointer to str origin
 * Return: int of string or 0
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int number = 0;

	while (!isdigit(*s) && *s != '\0')
	{
		if (*s == '-')
			sign *= -1;
		if (*s == '+')
			sign *= +1;
		s++;
	}

	while (isdigit(*s) && *s != '\0')
	{
		number = (number * 10) + (*s - '\0');
		s++;
	}

	return (number * sign);
}

/**
 * count_characters - count the coincidences of a character in string
 *
 * @string: pointer to str origin
 * @character: string with chars to be counted 
 * Return: int of string or 0
 */
int count_characters(char *string, char *character)
{
	int i = 0, counter = 0;

	for (; string[i] != '\0'; i++)
	{
		if (string[i] == character[0])
			counter++;
	}

	return counter;
}




