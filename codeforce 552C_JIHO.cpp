#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[7] = { 0 };
	long long a, b, c;
	cin >> a >> b >> c;

	long long m = min(a / 3, min(b / 2, c / 2)); //���� ���� ���� �������� �� Ƚ��
	long long base = 0;
	base = m * 7;

	a = a - m * 3;
	b = b - m * 2;
	c = c - m * 2;
	//�������� ���� ���̱� ����
	if (a > 3)	a = 3;
	if (b > 2)  b = 2;
	if (c > 2)  c = 2;

	//bc���� 
	m = min(b, c);
	int tmp = 0;
	if (m == 1)
	{
		if (a == 0)
		{
			tmp = m * 2;
		}
		else if (a == 1)
		{
			if (c > b)
				tmp = m * 2 + a + 1;
			else
				tmp = m * 2 + a;
		}
		else if (a >= 2)
		{
			if (abs(b - c) > 0)
			{
				tmp = m * 2 + a + 1;
			}
			else
			{
				tmp = m * 2 + a;
			}
		}
	}
	else if (m == 2)
	{
		if (a < 1)
			m = 1;
		tmp = m * 2 + a;
	}
	else if (m == 0) //������ �ϳ��� �Ȼ��涧 b�� c �ϳ��� ������ ����
	{
		if (b > 0) // b�� �ִ� ���
		{
			if (a == 3)
				a = 2;
			if (a < 2)
				b = 1;
			tmp = a + b;
		}
		else if (c > 0)// c�� �ִ� ���
		{
			if (a > 1)
				a = 1;
			if (a == 0)
			{
				if (c > 0)
					c = 1;
			}
			tmp = a + c;
		}
		else
		{
			if (a > 2)
				a = 2;
			tmp = a;
		}
	}
	cout << tmp + base << '\n';
	return 0;
}