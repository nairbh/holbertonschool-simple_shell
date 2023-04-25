#include "shell.h"

env_var_node_t *env_vars[MAX_ENV_VARS] = {NULL};

int main(void)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	command_node_t *head = NULL;

	custom_setenv("PATH", "/bin:/usr/bin:/usr/local/bin", 1);

	while (1)
	{
		printf(PROMPT);
		if (read_line(&buffer, &buffer_size) <= 0)
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
			char **env;

			for (env = environ; *env != NULL; env++)
			{
				printf("%s\n", *env);
			}
		}
		else if (custom_strcmp(buffer, "help") == 0)
		{
			print_help();
		}
		else if (execute_linked_command(head, buffer) == -1)
		{
			add_command_node(&head, buffer);
			printf("%s: command not found\n", buffer);
		}
	}
	free_command_list(head);
	free(buffer);
	return (0);
}
