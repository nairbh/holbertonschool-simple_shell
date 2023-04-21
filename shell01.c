#include "shell.h"

/**
 * custom_isspace - checks if the given character is a whitespace character
 * @ch: the character to be checked
 *
 * Return: 1 if the character is a whitespace, 0 otherwise
 */
int custom_isspace(int ch)
{
	return (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\v');
}

/**
 * custom_strlen - calculates the length of the given string
 * @str: the string whose length is to be calculated
 *
 * Return: the length of the string
 */
int custom_strlen(char *str)
{
	int lenght = 0;

	while (str[lenght] != END_STRING_CHAR)
	{
		lenght++;
	}
	return (lenght);
}

/**
 * read_line - reads a line of input from the user
 * @buffer: the buffer to store the input
 * @buffer_size: the size of the buffer
 *
 * Return: the number of characters read
 */
int read_line(char *buffer, int buffer_size)
{
	int lenght, i;

	if (fgets(buffer, buffer_size, stdin) == NULL)
	{
		return (-1);
	}
		lenght = custom_strlen(buffer);

		if (buffer[lenght - 1] == '\n')
		{
			buffer[lenght - 1] = END_STRING_CHAR;
		}
	for (i = 0; i < lenght; i++)
	{
		if (!custom_isprint(buffer[i]) && !custom_isspace(buffer[i]))
		{
			buffer[i] = END_STRING_CHAR;
			break;
		}
	}

		return (lenght - 1);
}

/**
 * custom_strcat - concatenates two strings
 * @dest: the destination string where the source string will be appended
 * @src: the source string to be appended to the destination string
 *
 * Return: a pointer to the destination string
 */
void custom_strcat(char *destination, const char *source)
{
	int dest_lenght = custom_strlen(destination);

	int i = 0;

	while (source[i] != END_STRING_CHAR)
	{
		destination[dest_lenght + i] = source[i];
		i++;
	}
	destination[dest_lenght + i] = END_STRING_CHAR;
}
/**
 * custom_strcpy - copies the content of the source string into the destination string
 * @destination: the destination string where the content will be copied
 * @source: the source string whose content will be copied
 *
 * Return: void
 */
void custom_strcpy(char *destination, const char *source)
{
	int i = 0;

	while (source[i] != END_STRING_CHAR)
	{
		destination[i] = source[i];
			i++;
	}
	destination[i] = END_STRING_CHAR;
}
