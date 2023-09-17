#include <stdio.h>
#include <unistd.h>
/**
 *
 * Return: -1 if unsuccessful
 */
int main(void)
{
	pid_t pid;

	pid = fork();/*no parameters*/

	if (pid == -1)
	{
		perror("unsuccessful");
		return 1;
	}
	if (pid == 0)
	{
		sleep(5);
		printf("child\n");
	}
	else
	{
		printf("parent shell\n");
	}

	/*printf("became a success\n");*/

	return 0;
}
