#include "shell.h"

/**
 * _eputs - print a string to a standard error
 * @string: the string to be printed
 *
 * Return: None
 */
void _eputs(char *string)
{
	int j = 0;

	if (!string)
		retur;
	while (string[j] != '\0')
	{
		_eputchar(string[j]);
		j++;
	}
}

/**
 * _eputchar - write a character to standard error
 * @d: the character to be written
 *
 * Return: on success 1
 * on error, -1 is returned, and errno printed
 */
int _eputchar(char d)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(2, buf, j);
		j = 0;

	}
	if (d != BUF_FLUSH)
		buf[j++] = d;
	return (1);
}

/**
 * _putfd - write a characters to a file descriptor
 * @d: the character to be written
 * @fd: the file descriptor to write to or modify
 *
 * Return: on success 1
 * on error, -1 is returned, and errno is returned
 */
int _putfd(char d, int fd)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(fd, buf, j);
		j = 0;
	}
	if (d != BUF_FLUSH)
		buf[j++] = d;
	return (1);
}

/**
 * _putsfd - print a string to a file descriptor
 * @string: the string to be printed
 * @fd: the file descriptor to write to or modify
 *
 * Return: the number of chars put
 */
int _putsfd(char *string, int fd)
{
	int j = 0;

	if (!string)
		return (0);
	while (*string)
	{
		j += _putfd(*string++, fd);
	}
	return (j);
}
