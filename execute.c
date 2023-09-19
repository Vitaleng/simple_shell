#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
* execute - execute a command with its entire path variables.
* @data: a pointer to the program's data
* Return: If sucess returns zero, otherwise, return -1.
*/
int execute(data_of_program *data)
{
	int retval = 0, status;
	pid_t pidd;

	retval = builtins_list(data);
	if (retval != -1)
		return (retval);

	retval = find_program(data);
	if (retval)
		return (retval);

	pidd = fork();
	if (pidd == -1)
{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pidd == 0)
{
		retval = execvp(data->tokens[0], data->tokens);
		if (retval == -1)
{
			perror(data->command_name);
   exit(EXIT_FAILURE);
		}
	}
else
{
		wait(&status);
		if (WIFEXITED(status))
			errno = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			errno = 128 + WTERMSIG(status);
	}

	return (0);
	}