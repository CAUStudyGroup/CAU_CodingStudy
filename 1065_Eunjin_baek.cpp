//1065�� : �Ѽ�

#include<iostream>
using namespace std;
int main() {
	int n, han;
	int a, b, c;
	cin >> n;
	if (n < 100) {
		cout << n;
	}
	else
	{
		han = 99;
		for (int i = 100; i <= n; i++) {
			a = i / 100; //���� �ڸ�
			b = (i / 10) % 10; //���� �ڸ�
			c = i % 10; //���� �ڸ�

			if ((a - b) == (b - c)) {
				han++;
			}
		}
		cout << han;
	}
}