#include <stdio.h>
#include <unistd.h>
int main(void)
{
	int a = 3;
	int b = 4;
	int sum = a + b;
	pid_t pid;

	pid = getpid();

	printf("sum of 3 and 4 is %d\n", sum);
	printf("pid of this is %d\n", pid);

	return (0);
}
