#include "shell.h"

/**
 * create_command_node - Creates a new command node for the linked list
 * @command: the command to add to the new node
 *
 * Return: Pointer to the new node created
 */
command_node_t *create_command_node(char *command)

{
command_node_t *new_node = (command_node_t *)malloc(sizeof(command_node_t));

if (new_node == NULL)
{
	perror("malloc");
	exit(EXIT_FAILURE);
}

	new_node->command = command;
	new_node->next = NULL;

	return (new_node);
}
/**
 * add_command_node - Adds a command node to the end of the linked list
 * @head: pointer to the head pointer of the linked list
 * @command: command to be added to the new node
 */
void add_command_node(command_node_t **head, char *command)
{	
	command_node_t *current;

	if (*head == NULL)
	{
	*head = create_command_node(command);
	return;
	}

	current = *head;

	while (current->next != NULL)
	{
	current = current->next;
	}

	current->next = create_command_node(command);
}
/**
 * free_command_list - Frees the memory allocated to the linked list of command
 * @head: pointer to the first node of the linked list
 */
void free_command_list(command_node_t *head)
{
	command_node_t *temp;

	while (head != NULL)
	{
	temp = head;
	head = head->next;
	free(temp);
	}
}
/**
 * execute_linked_command - Searches and executes a command in the linked list
 * If the command is not found in the list, it is added and executed
 * @head: pointer to the first node of the linked list
 * @command: command to execute
 *
 * Return: Return value of the command execution
 */
int execute_linked_command(command_node_t *head, char *command)
{
	command_node_t *current = head;

	while (current != NULL)
	{
	if (custom_strcmp(current->command, command) == 0)
	{
	return (execute_command(command));
	}
	current = current->next;
	}
/* Command not found in the linked list, execute it and add to the list */
	add_command_node(&head, command);

	return (execute_command(command));
}
/**
 * execute_command - Executes a command by creating a new process
 * @command: command to execute
 *
 * Return: Return value of the command execution
 */
int execute_command(char *command)
{
	char **argv = parse_args(command);
	int status;
	pid_t pid = fork();

	if (pid == 0)
	{

	char *executable_path = search_command_in_path(argv[0]);

	if (executable_path)
	{
	execve(executable_path, argv, environ);
	free(executable_path);
	}
	else
	{
	printf("%s: command not found\n", argv[0]);
	}
	exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	else
	{

	waitpid(pid, &status, 0);
	free(argv);
	return (status);
	}
}
