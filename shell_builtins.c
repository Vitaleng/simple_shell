#include "shell.h"

/**
 * my_history - function that displays the history list
 * @inf: structure containing potential arguments
 *
 * Return: always 0
 */
int my_history(info_t *inf)
{
	print_list(inf->history);
	return (0);
}

/**
 * unset_alias - function that unsets an alias
 * @info: parameter struct
 * @str: string alias
 *
 * Return: Always 0 on success, 1 upon error
 */
int unset_alias(info_t *info, char *str)
{
	char *q, d;
	int re;

	q = _strchr(str, '=');
	if (!q)
		return (1);
	d = *q;
	*q = 0;
	re = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*q = d;
	return (re);
}

/**
 * set_alias - function that sets an alias
 * @info: parameter struct
 * @str1: string alias
 *
 * Return: always 0 on success, 1 upon error
 */
int set_alias(info_t *info, char *str1)
{
	char *q;

	q = _strchr(str1, '=');
	if (!q)
		return (1);
	if (!*++q)
		return (unset_alias(info, str1));

	unset_alias(info, str1);
	return (add_node_end(&(info->alias), str1, 0) == NULL);
}

/**
 * print_alias - function that prints an alias string
 * @node1: alias node
 *
 * Return: always 0 on success, 1 upon error
 */
int print_alias(list_t *node1)
{
	char *q = NULL, *a = NULL;

	if (node1)
	{
		q = _strchr(node1->str, '=');
		for (a = node1->str; a <= q; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(q + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * my_alias - function that handles aliases
 * @info: struct containing potential arguments
 *
 * Return: always 0
 */
int my_alias(info_t *info)
{
	int j = 0;
	char *q = NULL;
	list_t *node2 = NULL;

	if (info->argc == 1)
	{
		node2 = info->alias;
		while (node2)
		{
			print_alias(node2);
			node2 = node2->next;
		}
		return (0);
	}
	for (j = 1; info->argv[j]; j++)
	{
		q = _strchr(info->argv[j], '=');
		if (q)
			set_alias(info, info->argv[j]);
		else
			print_alias(node_starts_with(info->alias, info->argv[j], '='));
	}

	return (0);
}
