#include <stdio.h>
#include <stdlib.h>

/**
* expand_variables - expand variables
* @data: a pointer to a struct of the program's data
*
* Return: nothing, but sets errno.
*/
void expand_variables(data_of_program *data)
{
    if (data == NULL || data->input_line == NULL)
        return;

    /* Rest of the code... */

    if (!str_compare(data->input_line, line, 0))
    {
        free(data->input_line);
        data->input_line = str_duplicate(line);
    }
}

/**
* expand_alias - expand aliases
* @data: a pointer to a struct of the program's data
*
* Return: nothing, but sets errno.
*/
void expand_alias(data_of_program *data)
{
    if (data == NULL || data->input_line == NULL)
        return;

    /* Rest of the code... */

    if (was_expanded)
    {
        free(data->input_line);
        data->input_line = str_duplicate(line);
    }
}

/**
* buffer_add - append string at end of the buffer
* @buffer: buffer to be filled
* @str_to_add: string to be copied in the buffer
* Return: nothing, but sets errno.
*/
int buffer_add(char *buffer, char *str_to_add)
{
    int length = str_length(buffer);
    int i;

    for (i = 0; str_to_add[i] && (length + i) < BUFFER_SIZE - 1; i++)
    {
        buffer[length + i] = str_to_add[i];
    }
    buffer[length + i] = '\0';
    return (length + i);
}
