#include "shell.h"

char **parse_args(char *command)
{

	char *token;
	int argc = 0;
	int i;
	char **argv = malloc(sizeof(char *) * (COMMAND_SIZE + 1));


	if (argv == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(command, " \t");

	while (token != NULL)
	{

	if (argc >= COMMAND_SIZE)
	{
	fprintf(stderr, "Too many arguments\n");
	free(argv);
	exit(EXIT_FAILURE);
	}
	argv[argc++] = token;
	token = strtok(NULL, " \t");
	}
	
	argv[argc] = NULL;

	return (argv);
}
int file_exists(const char *filepath)
{
	struct stat st;
	return (stat(filepath, &st) == 0);
}
