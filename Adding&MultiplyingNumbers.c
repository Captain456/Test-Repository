#include <stdio.h>

int main()
{
	int i, j, k, m;
	i = 10;
	printf("i is equal to: %d\n", i);
	j = 9 + i;
	printf("j is equal to 9 + i. j is equal to: %d\n", j);
	k = j + i + 1;
	printf("k is equal to 1 + j + i. k is equal to: %d\n", k);
	m = k * j * i;
	printf("m stands for Multiplication! It's equal to i * j * k. m is equal to: %d\n", m);
	return 0;
}
