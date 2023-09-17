#include <string.h>
#include <stdio.h>
int main(void)
{
	char str[] = "i cannot anymore";
	char *delim = " ";
	char *token;

	token = strtok(str, delim);
	/*printf("%s", token);

	*token = strtok(NULL, delim);
	*printf("%s", token);*/
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}
	return (0);
}
