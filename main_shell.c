#include "shell.h"


int main(void)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	command_node_t *head = NULL;

	custom_setenv("PATH", "/bin:/usr/bin:/usr/local/bin:/usr/sbin", 1);

	while (1)
	{
		printf(PROMPT);
		if (read_line(&buffer, &buffer_size) <= 0)
		{
			printf("\n");
			break;
		}
		if (strcmp(buffer, "exit") == 0)
		{
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
		else if (strcmp(buffer, "help") == 0)
		{
			print_help();
		}
		else if (strlen(buffer) > 0 && execute_linked_command(head, buffer) == -1)
		{
			add_command_node(&head, buffer);
			printf("%s: command not found\n", buffer);
		}
	}
	free_command_list(head);
	free(buffer);
	return (0);
}
