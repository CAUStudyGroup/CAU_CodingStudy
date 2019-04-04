//1065번 : 한수

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
			a = i / 100; //백의 자리
			b = (i / 10) % 10; //십의 자리
			c = i % 10; //일의 자리

			if ((a - b) == (b - c)) {
				han++;
			}
		}
		cout << han;
	}
}