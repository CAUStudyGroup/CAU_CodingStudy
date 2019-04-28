#include <stdio.h>
#include <math.h>

void hanoi(int n ,int from, int by, int to)
{
	if (n == 0)
		return;
	hanoi(n - 1, from, to, by);
	printf("%d %d\n", from, to);
	hanoi(n - 1, by, from, to);
}
int main()
{
	int N;
	scanf("%d", &N);
	int tmp = pow(2, N) - 1;
	printf("%d\n", tmp);
	hanoi(N, 1, 2, 3);

	return 0;
}