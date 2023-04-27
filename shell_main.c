#include "shell.h"

int main(void)
{
	char *buffer = NULL;
	char *executable_path = NULL;
	size_t buffer_size = 0;

	int status = 1;
	int getline2;

	executable_path = malloc(BUFFER_SIZE);

	while (1)
	{
		status = isatty(0);

		if (status == 1)
		printf("$ ");

	getline2 = getline(&buffer, &buffer_size, stdin);

	if (getline2 == -1)
	{
		free(buffer);
		free(executable_path);
		exit(EXIT_SUCCESS);
	}

	buffer[strcspn(buffer, "\n")] = END_STRING_CHAR;

	if (strcmp(buffer, "exit") == 0)
	{
	free(buffer);
	free(executable_path);
	exit(0);
	}
	else if (strcmp(buffer, "env") == 0)
	{
	char **env;
	for (env = environ; *env != NULL; env++)
	{
	printf("%s\n", *env);
	}
	}
	else if (find_execute_command(buffer, executable_path) == 1)
	{
	char **args = parse_args(executable_path);
	execute_command(args);
	free_args(args);
	}
	else
	{
	printf("%s: command not found\n", buffer);
	}
	free(buffer);
	buffer = NULL;
	}

	return (0);
}
