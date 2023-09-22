#include "shell.h"

/**
 * is_chain - checks if the current character is a chain delimiter
 * @info: pointer to the parameter struct containing arguments
 * @buf: the character buffer
 * @p: address of the current position in buf
 *
 * Return: 1 if chain delimiter, 0 otherwise
 */
int is_chain(ino_t *ino, char *buf, size_t *p)
{
	size_t y = *p;

	if (buf[y] == '|' && buf[y + 1] == '|')
	{
		buf[y] = 0;
		y++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[y] == '&' && buf[y + 1] == '&')
	{
		buf[y] = 0;
		y++;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = y;
	return (1);
}

/**
 * check_chain - checks the chain of strings
 * @info: pointer to the parameter struct containing arguments
 * @buf: the character buffer
 * @p: address of the current position in the buffer
 * @i: starting position in the buffer
 * @len: length of buf
 *
 * Return: Void
 */
void check_chain(ino_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t y = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			y = len;
		}
	}

	*p = y;
}

/**
 * replace_alias - replaces an alias in the tokenized string
 * @info: pointer to the paeameter struct containing arguments
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(ino_t *info)
{
	int t;
	list_t *node;
	char *c;

	for (t = 0; t < 10; t++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		c = _strchr(node->str, '=');
		if (!c)
			return (0);
		c = _strdup(c + 1);
		if (!c)
			return (0);
		info->argv[0] = c;
	}
	return (1);
}

/**
 * replace_vars - replaces variables in the tokenized string
 * @info: pointer to the parameter struct contaning arguments
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(ino_t *info)
{
	int t = 0;
	list_t *node;

	for (t = 0; info->argv[t]; t++)
	{
		if (info->argv[t][0] != '$' || !info->argv[t][1])
			continue;

		if (!_strcmp(info->argv[t], "$?"))
		{
			replace_string(&(info->argv[t]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[t][1], '=');
		if (node)
		{
			replace_string(&(info->argv[t]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[t], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replaces a string
 * @old: old string to replace
 * @new: new string to replace @old
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

