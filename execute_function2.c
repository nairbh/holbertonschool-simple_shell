#include "shell.h"

/**
 * search_command_in_path - Searches for a command in the directories
 * listed in the PATH environment variable
 * @command: command to search for
 *
 * Return: a pointer to a string containing the full path to the command if
 * found, otherwise NULL
 */
char *search_command_in_path(const char *command)
{
	char *path = custom_getenv("PATH");
	char *path_copy = strdup(path);
	char *path_dir = strtok(path_copy, ":");
	char *executable_path = malloc(BUFFER_SIZE);

	while (path_dir)
	{
		sprintf(executable_path, "%s/%s", path_dir, command);

		if (file_exists(executable_path))
		{
			free(path_copy);
			return (executable_path);
		}
		path_dir = strtok(NULL, ":");
	}
	free(path_copy);
	free(executable_path);
	return (NULL);
}
/**
 * file_exists - checks if a file exists at the given filepath
 * @filepath: the path to the file to check
 *
 * Return: 1 if the file exists, 0 otherwise
 */
int file_exists(const char *filepath)
{
	FILE *file = fopen(filepath, "r");
	{
		if (file != NULL)
	{
		fclose(file);
		return (1);
	}
		else
		{
			return (0);
		}
	}
}
