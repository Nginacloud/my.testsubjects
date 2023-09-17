#include <stdio.h>
#include <unistd.h>
int main(void)
{
	int a = 3;
	int b = 4;
	int sum = a + b;
	pid_t ppid;

	ppid = getppid();/*pid for process*/

	printf("sum of 3 and 4 is %d\n", sum);
	printf("ppid of this is %d\n", ppid);

	return (0);
}
