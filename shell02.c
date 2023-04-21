#include "shell.h"
/**
 * find_execute_command - find and execute a command
 * @argv: the arguments array containing the command and its parameters
 * @executable_path: the buffer where the path of the executable will be stored
 *
 * Return: 1 if the executable is found, 0 otherwise
 */
int find_execute_command(char *command, char *executable_path)
{
	int found_executable = 0;
	int i;
	char **argv = parse_args(command);

	if (file_exists(argv[0]))
	{
		found_executable = 1;
		custom_strcpy(executable_path, argv[0]);
	}
	else
	{
		const char *fixed_directory[] = {"/bin/", "/usr/bin/", NULL};

		for (i = 0; fixed_directory[i] != NULL; i++)
		{
			custom_strcpy(executable_path, fixed_directory[i]);
			custom_strcat(executable_path, argv[0]);

			if (file_exists(executable_path))
			{
				found_executable = 1;
				break;
			}
		}
	}
	free(argv);
	return (found_executable);
}

/**
 * execute_command - Executes a given command
 * @command: The command to execute
 *
 * Return: 0 if successful, -1 if the command is not found
 */
int execute_command(char *command)
{
	char executable_path[COMMAND_SIZE];
	int found_executable = find_execute_command(command, executable_path);
	char **argv = parse_args(command);	
	if (found_executable)
	{
		pid_t pid = fork();

		if (pid == 0)
		{
			if (execv(executable_path, argv) == -1)
			{
				perror("execv");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
			free(argv);
			return (0);
		}
	}
	else
	{
		free(argv);
		return (-1);
	}
}

/**
 * parse_args - Parses a command into arguments
 * @command: The command to parse
 *
 * Return: A NULL-terminated array of string pointers to arguments
 */
char **parse_args(char *command)
{
	int i;
	char *token;
	int argc = 0;
	char **argv = malloc(sizeof(char *) * (COMMAND_SIZE / 2));

	if (argv == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(command, " \t");

	while (token != NULL)
	{
		argv[argc++] = token;
		token = strtok(NULL, " \t");
	}

	argv[argc] = NULL;

	return (argv);
}
