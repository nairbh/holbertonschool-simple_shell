#include "shell.h"

int main(void)
{
	char *buffer = NULL;
	char *executable_path = NULL;
	size_t buffer_size = 0;
	int status = 1;
	executable_path = malloc(BUFFER_SIZE);

	while (status)
	{
		status = isatty[0];
	printf(PROMPT);	

	if (getline(&buffer, &buffer_size, stdin) <= 0)
	{
	printf("\n");
	break;
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
	execute_command(parse_args(executable_path));
	}
	else
	{
	printf("%s: command not found\n", buffer);
	}
	}

	free(buffer);
	free(executable_path);
	return (0);
}
