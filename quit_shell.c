#include "shell.h"

/**
 ** _strncpy - it is to copy a string
 *@dest: where the string will be stored
 *@scr : source string
 *@n : sums all the characters  to be copied
 *Return : the link string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (scr[i] != '\0' && i < n - 1)
	{
		dest[i] = scr[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0'
				j++;
		}
	}
	return (s);
}

/**
 **_strncat - links two strings
 *@dest : first string
 *@src : second string
 *@n : amount of bytes used
 *Return : the linked string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest
		
		j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		j++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - finds a character in a  string
 *@s : string to be converted
 *@c : the character to find
 *Return : (s) pointer to memory s
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');
	
	return (NULL);
}

