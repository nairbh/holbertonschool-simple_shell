#include "shell.h"

void free_string(char *string)
{
	if (string != NULL)
	{
		free(string);
	}
}
void free_all(char **command, char *str, char *execute_path)
{
    if (command != NULL)
    {
        free(command);
    }

    if (str != NULL)
    {
        free(str);
    }

    if (execute_path != NULL)
    {
        free(execute_path);
    }
}
