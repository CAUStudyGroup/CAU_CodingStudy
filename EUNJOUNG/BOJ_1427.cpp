#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
	int arr[10] = { 0,0, };
	int n;
	int a=1, b=1;
	scanf("%d", &n);
	while (n != 0 && b != 0) {
		arr[n % 10]++;
		n = n / 10;
		b = n % 10;
	}
	for (int i = 0; i < 10; i++) {
		if (arr[i] != 0) printf("%d", i);
		else continue;
	}
}