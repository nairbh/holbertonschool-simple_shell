#include "shell.h"
/**
 * custom_getenv - gets the value of an environment variable
 * @key: environment variable
 *
 * Return: a pointer to the value in the environment
 */

char *custom_getenv(const char *key)
{
	return (getenv(key));
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
	return (setenv(key, value, overwrite));
}

