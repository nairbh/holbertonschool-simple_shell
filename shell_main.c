#include "shell.h"

int main (void)
{
	char buffer[BUFFER_SIZE];
	/* system env char **env = environ;*/
	int read_result, i;

	while (1)
	{
		printf(PROMPT);
		read_result = read_line(buffer, BUFFER_SIZE);
		if (read_result == -1)
		{
			printf("\n");
			break;
		}

		if (read_result <= 0)
		{
			printf("\n");
			break;
		}
		if (custom_strcmp(buffer, "exit") == 0)
		{
			exit(0);
		}
		else if (custom_strcmp(buffer, "env") == 0)
		{	
			for (i = 0; env_set[i] != NULL; i++)
			{
			printf("%s\n", env_set[i]);
			} 	
			/*for (env = environ; *env != NULL; env++)
			{
				printf("%s\n", *env);

			} systeme env */

		}
		else if (execute_command(buffer) == -1)
		{
			printf("%s: command no found sorry about that\n", buffer);
		}
	}
	return (0);
}
