//���� 2577�� : ������ ����
//�ڵ��� �ʹ� ���� ��Ծ... (���� ���Ǵ�...)
//�������� �ͺ��� Ǯ�����ϴ٤Ф�!!

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