#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main()
{
	stack<char> ari;
	string str ="(";
	string tmp;
	cin >> tmp;
	tmp += ")";
	str += tmp; // ū��ȣ

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 65 && str[i] <= 90) // ������ �Ÿ���
		{
			cout << str[i];
		}
		else // ������ ����
		{
			if (str[i] != ')')
			{
				//���� ����� ������ ��ġ�� ���
				if (str[i] == '+' || str[i] == '-')
				{
					if (ari.top() == '+' || ari.top() == '-')
					{
						cout << ari.top(); // ���� ��� ���� ������ �켱 �Ǿ�� ��
						ari.pop();
						ari.push(str[i]);// ���Ӱ� ����
					}
					else if (ari.top() == '*' || ari.top() == '/')// *�̳� /�ΰ��
					{
						while (ari.top() != '(')
						{
							cout << ari.top();
							ari.pop();
						}
						ari.push(str[i]);
					}
					else
						ari.push(str[i]);
				}
				else if (str[i] == '*' || str[i] == '/')
				{
					if (ari.top() == '*' || ari.top() == '/') //���� ���
					{
						cout << ari.top();
						ari.pop();
						ari.push(str[i]);
					}
					else
						ari.push(str[i]);
				}
				else
					ari.push(str[i]);

			}
			else if(str[i]==')')
			{
				while (ari.top() != '(')
				{
					cout << ari.top();
					ari.pop();
				} // (�� ������ ������ ����
				ari.pop(); //(����
			}
		}
	
	}
	return 0;
}