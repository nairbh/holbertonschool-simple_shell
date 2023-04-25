#include "shell.h"

/**
 * custom_getenv - gets the value of an environment variable
 * @key: environment variable
 *
 * Return: a pointer to the value in the environment
 */

char *custom_getenv(const char *key)
{
	unsigned long hash = 5381;
	int c;
	int index;
	env_var_node_t *current;

	while ((c = *key++))
	{
		hash = ((hash << 5) + hash) + c;
	}

	index = hash % MAX_ENV_VARS;

	current = env_vars[index];

	while (current != NULL)
	{
		if (custom_strcmp(current->key, key) == 0)
		{
			return (current->value);
		}
		current = current->next;
	}
	return (NULL);
}

/**
 * custom_setenv - change or add an environment variable
 * @key: environment variable
 * @value: value of variable
 * @overwrite: overwrite
 *
 * Return: zero on success, or -1 on error
 */

int custom_setenv(const char *key, const char *value, int overwrite)
{
	unsigned long hash = 5381;
	int c;
	int index;
	env_var_node_t *current;
	env_var_node_t *new_node;

	while ((c = *key++))
	{
		hash = ((hash << 5) + hash) + c;
	}

	index = hash % MAX_ENV_VARS;

	current = env_vars[index];

	while (current != NULL)
	{
		if (custom_strcmp(current->key, key) == 0)
		{
			if (overwrite)
			{
				free(current->value);
				current->value = custom_strdup(value);
			}
			return (0);
		}
		current = current->next;
	}

	new_node = (env_var_node_t *)malloc(sizeof(env_var_node_t));

	if (new_node == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	new_node->key = custom_strdup(key);
	new_node->value = custom_strdup(value);
	new_node->next = env_vars[index];
	env_vars[index] = new_node;

	return (0);
}
