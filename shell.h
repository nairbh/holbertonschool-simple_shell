#ifndef _SHELL_H
#define _SHELL_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#define MAX_ENV_VARS 128
#define PROMPT "$holbiies "
#define BUFFER_SIZE 1024
#define COMMAND_SIZE 64
#define END_STRING '\0'

extern char **environ;

typedef struct command_node
{
	char *command;
	struct command_node *next;
} command_node_t;

command_node_t

*create_command_node(char *command);

typedef struct env_var_node
{
	char *key;
	char *value;
	struct env_var_node *next;
} env_var_node_t;

env_var_node_t *env_vars[MAX_ENV_VARS] = {NULL};


void add_command_node(command_node_t **head, char *command);


int read_line(char **buffer, size_t *buffer_size);
int make_directory(const char *pathname);
int custom_setenv(const char *key, const char *value, int overwrite);
char *custom_getenv(const char *key);
int execute_linked_command(command_node_t *head, char *command);
int execute_command(char *command);
void free_command_list(command_node_t *head);
char *search_command_in_path(const char *command);
char **parse_args(char *command);


int custom_strlen(char *str);
char *custom_strdup(const char *source);
void custom_strcpy(char *destination, const char *source);
void custom_strcat(char *destination, const char *source);
int file_exists(const char *filepath);
int custom_isspace(int ch);
int custom_strcmp(const char *str1, const char *str2);
int custom_isprint(int ch);
void print_help();

#endif /* _SHELL_H */
