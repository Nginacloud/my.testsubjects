#include <stdio.h>
int main()
{
	int i = 3, j = 5, k = 6;
	int result = (i + j) * k / i;

	printf("trying something i done see: (%d + %d) * %d / %d\n", i, j, k, i);
	printf("the result is: %d\n", result);
}
