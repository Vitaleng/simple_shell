#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/************* MACROS *************/

#include "macros.h" /* for msg help and prompt */

/************* MAIN FUNCTIONS *************/

void inicialize_data(data_of_program *data, int arc, char *argv[], char **env);
void sisifo(char *prompt, data_of_program *data);
void handle_ctrl_c(int opr UNUSED);

/************* OTHER FUNCTIONS *************/

int _getline(data_of_program *data);
int check_logic_ops(char *array_commands[], int i, char array_operators[]);
void expand_variables(data_of_program *data);
void expand_alias(data_of_program *data);
int buffer_add(char *buffer, char *str_to_add);
void tokenize(data_of_program *data);
char *_strtok(char *line, char *delim);
int execute(data_of_program *data);
int builtins_list(data_of_program *data);
char tokenize_path(data_of_program *data);
int find_program(data_of_program *data);
void free_array_of_pointers(char **directories);
void free_recurrent_data(data_of_program *data);
void free_all_data(data_of_program *data);
int builtin_exit(data_of_program *data);
int builtin_cd(data_of_program *data);
int set_working_directory(data_of_program *data, char *new_dir);
int builtin_help(data_of_program *data);
int builtin_alias(data_of_program *data);
int builtin_env(data_of_program *data);
int builtin_set_env(data_of_program *data);
int builtin_unset_env(data_of_program *data);
char *env_get_key(char *name, data_of_program *data);
int env_set_key(char *key, char *value, data_of_program *data);
int env_remove_key(char *key, data_of_program *data);
void print_environ(data_of_program *data);
int _print(char *string);
int _printe(char *string);
int _print_error(int errorcode, data_of_program *data);
int str_length(char *string);
char *str_duplicate(char *string);
int str_compare(char *string1, char *string2, int number);
char *str_concat(char *string1, char *string2);
void str_reverse(char *string);
void long_to_string(long number, char *string, int base);
int _atoi(char *s);
int count_characters(char *string, char *character);
int print_alias(data_of_program *data, char *alias);
int set_alias(char *alias_string, data_of_program *data);

#endif
