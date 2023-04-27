#include "shell.h"

int find_execute_command(char *command, char *executable_path)
{	int found_executable = 0;
	int i;
	char **argv = parse_args(command);

	if (argv[0] == NULL)
	{
	free(argv);
	return (0);
	}

	if (file_exists(argv[0]))
	{
	found_executable = 1;
	strcpy(executable_path, argv[0]);
	}
	else {
	char *path_env = get_env_value("PATH");

	if (path_env)
	{
	char *path_env_copy = strdup(path_env);
	char *token = strtok(path_env_copy, ":");
	while (token != NULL)
	{
	strcpy(executable_path, token);
	strcat(executable_path, "/");
	strcat(executable_path, argv[0]);

	if (file_exists(executable_path))
	{
	found_executable = 1;
	break;
	}
	token = strtok(NULL, ":");
	}
	free(path_env_copy);
	free(path_env);
	}
	}
	for (i = 1; argv[i] != NULL; i++)
	{
	argv[0] = executable_path;
	strcat(executable_path, " ");
	strcat(executable_path, argv[i]);
	}
	free(argv);
	return (found_executable);
}
