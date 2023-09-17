#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void tokenize_input(char *input, char **tokens, int *token_count)
{
	char *token;
	token = strtok(input, " ");
	*token_count = 0;

	while (token != NULL && *token_count < 64)
	{
		tokens[(*token_count)++] = token;
		token = strtok(NULL, " ");
	}
}
int main()
{
	while (1)
	{
		char input[256];
		/*char *tokens[64];*/
		/*int token_count;*/
		ssize_t bytes_read;
		char *prompt = "$";
		int status;
		pid_t child_pid;

		char *tokens[64];
		int token_count;

		write(STDOUT_FILENO, prompt, strlen(prompt));
		bytes_read = read(STDIN_FILENO, input, sizeof(input));
		if (bytes_read == -1)
		{
			perror("Error (read)");
			break;
		}
		input[bytes_read - 1] = '\0';

		tokenize_input(input, tokens, &token_count);

		if (strcmp(tokens[0], "exit") == 0)
		{
			return (0);
		}
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error (fork)");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(tokens[0], tokens, NULL) == -1)
			{
				perror("Error (execve)");
				return (1);
			}
		}
		else
		{
			waitpid(child_pid, &status, 0);
		}
	}

	return (0);
}
