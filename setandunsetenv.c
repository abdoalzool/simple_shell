#include "main.h"

/**
 * setenv_builtin - Set or modify an environment variable
 * @args: An array containing the command and arguments
 */
void setenv_builtin(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		char error_msg[] = "Usage: setenv VARIABLE VALUE\n";

		write(STDERR_FILENO, error_msg, 29);
		return;
	}

	if (args[3] != NULL)
	{
		char error_msg[] = "setenv: Too many arguments\n";

		write(STDERR_FILENO, error_msg, 24);
		return;
	}

	if (setenv(args[1], args[2], 1) == -1)
	{
		char error_msg[] = "setenv: Error while setting environment variable\n";

		write(STDERR_FILENO, error_msg, 46);
	}
}

/**
 * unsetenv_builtin - Remove an environment variable
 * @args: An array containing the command and arguments
 */
void unsetenv_builtin(char **args)
{
	if (args[1] == NULL)
	{
		char error_msg[] = "Usage: unsetenv VARIABLE\n";

		write(STDERR_FILENO, error_msg, 27);
		return;
	}

	if (args[2] != NULL)
	{
		char error_msg[] = "unsetenv: Too many arguments\n";

		write(STDERR_FILENO, error_msg, 22);
		return;
	}

	if (unsetenv(args[1]) == -1)
	{
		char error_msg[] = "unsetenv: Error while unsetting environment variable\n";

		write(STDERR_FILENO, error_msg, 53);
	}
}
