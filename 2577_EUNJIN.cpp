//백준 2577번 : 숫자의 개수
//코딩을 너무 많이 까먹어서... (정말 거의다...)
//기초적인 것부터 풀었습니다ㅠㅠ!!

#include<iostream>
using namespace std;
int main() {
	int a, b, c;
	int num[10] = { 0 };
	cin >> a >> b >> c;
	int result = a * b*c;

	while (result != 0) {
		num[result % 10] = num[result % 10] + 1;
		result = result / 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << num[i] << endl;
	}
}