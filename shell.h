#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <readline/readline.h>
#include <readline/history.h>
#define PROMPT "$holbiies "
#define BUFFER_SIZE 1024
#define COMMAND_SIZE 64
#define END_STRING_CHAR '\0'
extern char *env_var[];
extern char **env_set;
/* extern char **environ; systeme env */
char **parse_args(char *command);
int custom_strlen(char *str);
int read_line(char *buffer, int buffer_size);
int execute_command(char *command);
void custom_strcpy(char *destination, const char *source);
void custom_strcat(char *destination, const char *source);
int file_exists(const char *filepath);
int custom_isspace(int ch);
int custom_strcmp(const char *str1, const char *str2);
int custom_isprint(int ch);

#endif /* _SHELL_H */
