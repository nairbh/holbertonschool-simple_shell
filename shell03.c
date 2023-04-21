#include "shell.h"
/**
 * custom_isprint - Checks if a character is a printable character
 * @ch: The character to check
 *
 * Return: 1 if the character is a printable character, 0 otherwise
 */
int custom_isprint(int ch)
{
        return ( ch >= 32 && ch <= 126);
}

/**
 * custom_strcmp - Compares two strings
 * @str1: The first string to compare
 * @str2: The second string to compare
 *
 * Return: 0 if the strings are equal, a positive or negative value
 *         indicating the difference between the strings otherwise
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
 * file_exists - Checks if a file exists
 * @path: The path to the file
 *
 * Return: 1 if the file exists, 0 otherwise
 */
int file_exists(const char *filepath)
{
        FILE *file = fopen(filepath, "r");
        {
                if (file != NULL)
                {
                        fclose(file);
                        return (1);
                }
                else
                {
                        return (0);
                }
        }
}

/**
 * env_var - An array of environment variables represented as strings
 *
 * This array stores environment variables as strings in the format
 * "KEY=VALUE". These variables are used by the shell to store
 */
char *env_var[] = {
        "USER=nicolas & houcine",
        "LANGUAGE=en_US",
        "SESSION=ubuntu",
        "COMPIZ_CONFIG_PROFILE=ubuntu",
        "SHLVL=1",
        "HOME=/home/houcine/nicolas",
        "C_IS=Fun_:)",
        "DESKTOP_SESSION=ubuntu",
        "LOGNAME=julien",
        "TERM=xterm-256color",
        "PATH=/home/julien/bin:/home/julien/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin",
        "DISPLAY=:0",
        NULL
};
char **env_set = env_var;
