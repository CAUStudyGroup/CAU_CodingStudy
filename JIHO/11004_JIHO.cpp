#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	long long *arr = new long long[N];

	for (int i = 0; i < N; i++)
		scanf("%lld", arr + i);

	nth_element(arr,arr+K-1,arr+N);

	printf("%lld\n", arr[K - 1]);

	return 0;
}