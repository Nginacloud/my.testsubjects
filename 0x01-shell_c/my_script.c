#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
	size_t n = 0;
	ssize_t bytes, bytes_read;
	char *buff = NULL;
	char *prompt = "$ ";

	/*char *buffer = malloc(sizeof(char) * buffer);*/
	/*bytes = getline(&buff, &buff_size, stdin);*/
	/*printf("enter name ");*/
	while (1)/*&& free_pipe*/
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));
		bytes = getline(&buff, &n, stdin);

		if (bytes == -1)
		{
			perror("Error (getline)");
			 free(buff);
			 exit(EXIT_FAILURE);
		}
		if (buff[bytes - 1] == '\n')
		{
			buff[bytes - 1] = '\0';
		}
		if (strcmp(buff, "exit") == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
	char input[256];
	char *tokens[64];
	char *token;
	int token_count;

	bytes_read = read(STDIN_FILENO, input, sizeof(input));
	if (bytes_read == -1)
	{
		perror("Error (read)");
		return (1);
	}
	input[bytes_read - 1] = '\0';
	token = strtok(input, " ");
	token_count = 0;
	while (token != NULL && token_count < 64)
	{
		tokens[token_count++] = token;
		token = strtok(NULL, " ");
	}
	pid_t child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error (fork)");
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			perror("Error (fork)");
			return (1);
		}
	}
	else
	{
		int status;
		waitpid(child_pid, &status, 0);
	}
	return (0);
}
/*	if (bytes == -1)
	{
		perror("Error (getline)");
		free(buffer);
		exit(EXIT_FAILURE);
	}
	if (buffer(bytes - 1) == '\n')
		buffer(bytes - 1) = '\0';*/
	/*getline(&buffer, &n, stdin);*/
	/*printf("name is %sBuffer size is %ld\n", buffer, n);*/
	/*free(buffer);*/
	/*return (0);*/
