//1193 : �м�ã��

#include<stdio.h>
int main() {
	int n, test = 0;
	scanf_s("%d", &n);
	while (n > 0) {
		test++;
		n = n - test;
	}
	if (test % 2 == 0)//¦���̸�
	{
		printf("%d/%d", test + n, 1 - n);
	}
	else {
		printf("%d/%d", 1 - n, test + n);
	}
}