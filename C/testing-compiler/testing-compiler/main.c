#include <stdio.h>

void beat()
{
	getchar();
}

int main(int argc, char *argv[])
{
	int distance = 100;

	printf("You are %d miles away.\n", distance);
	beat();

	return 0;
}