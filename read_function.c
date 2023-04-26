#include "shell.h"

/**
 * read_line - Reads a line from stdin and stores it in the provided buffer.
 * @buffer: Pointer to the buffer where the line should be stored.
 * @buffer_size: Pointer to the size of the buffer.
 *
 * Return: Length of the read line, or -1 on failure.
 */

int read_line(char **buffer, size_t *buffer_size)
{
	ssize_t length = 0;
	int i;

	length = getline(buffer, buffer_size, stdin);

	if (length == -1)
	{
	return (-1);
	}

	if ((*buffer)[length - 1] == '\n')
	{
	(*buffer)[length - 1] = '\0';
	length--;
	}

	for (i = 0; i < length; i++)
	{

	if (!custom_isprint((*buffer)[i]) && !custom_isspace((*buffer)[i]))
		{
		(*buffer)[i] = END_STRING;
		length = i;

		break;
		}
	}

	return (length);
}
/**
 * parse_args - Parses the given command string into an array of arguments.
 * @command: Command string to parse.
 *
 * Return: A NULL-terminated array of pointers to the parsed arguments.
 */
char **parse_args(char *command)
{
	int argc = 0;
	char *token;
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
/**
 * custom_isprint - Checks if the given character is printable.
 * @ch: Character to check.
 *
 * Return: 1 if the character is printable, 0 otherwise.
 */
int custom_isprint(int ch)
{
	return (ch >= 32 && ch <= 126);
}
/**
 * custom_isspace - Checks if the given character is a whitespace character.
 * @ch: Character to check.
 *
 * Return: 1 if the character is a whitespace character, 0 otherwise.
 */
int custom_isspace(int ch)
{
	return (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\r');
}
/**
 * print_help - Prints a help message to stdout.
 */
void print_help(void)
{
	printf("Holbies Shell\n");
	printf("Supported internal commands:\n");
	printf(" All function on /bin\n");
	printf(" help - Display this help message\n");
	printf(" env - Display environment variables\n");
	printf(" exit - Exit the shell\n");
	printf("Other commands will be executed as external programs.\n");
}
