#include "shell.h"

/**
 * custom_strdup - Copies a string into a newly allocated memory block
 *
 * @source: Pointer to the source string to be copied
 *
 * Return: Pointer to the newly allocated memory
 */

char *custom_strdup(const char *source)
{
	int length = custom_strlen((char *)source) + 1;
	/* +1 for the null-terminator */

	char *destination = malloc(length * sizeof(char));

	if (destination == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	custom_strcpy(destination, source);

	return (destination);
}
/**
 * custom_strlen - Calculates the length of a string
 *
 * @str: Pointer to the string to be measured
 *
 * Return: Length of the string
 */
int custom_strlen(char *str)
{
	int length = 0;

	while (str[length] != END_STRING)
	{
		length++;
	}
	return (length);
}
/**
 * custom_strcmp - Compares two strings
 *
 * @str1: Pointer to the first string to be compared
 * @str2: Pointer to the second string to be compared
 *
 * Return: Integer value representing the result of the comparison
 */
int custom_strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
		{
		return (*str1 - *str2);
		}
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
/**
 * custom_strcpy - Copies a string from source to destination
 *
 * @destination: Pointer to the destination buffer
 * @source: Pointer to the source string
 *
 * This function copies the string pointed to by source (including the
 * terminating null character) to the buffer pointed to by destination.
 *
 * Return: Pointer to the destination buffer
 */
void custom_strcpy(char *destination, const char *source)

{
	int i = 0;

	while (source[i] != END_STRING)
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = source[i];
}

/**
 * custom_strcat - Concatenates a source string to the end of a destination
 *
 * @destination: Pointer to the destination buffer
 * @source: Pointer to the source string
 *
 * This function appends the string pointed to by source (including the
 * terminating null character) to the end of the string pointed to by
 * destination.
 */
void custom_strcat(char *destination, const char *source)
{
	/* Get the length of the destination string */
	int dest_length = custom_strlen(destination);
	int i = 0;
	/* Append characters from source to destination */
	while (source[i] != END_STRING)
	{
		destination[dest_length + i] = source[i];
		i++;
	}
	/* Append the terminating null character to the destination string */
	destination[dest_length + i] = END_STRING;
}
