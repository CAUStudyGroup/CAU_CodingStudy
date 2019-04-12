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
	str += tmp; // 큰괄호

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 65 && str[i] <= 90) // 미지수 거르기
		{
			cout << str[i];
		}
		else // 미지수 말고
		{
			if (str[i] != ')')
			{
				//이전 연산과 서열이 겹치는 경우
				if (str[i] == '+' || str[i] == '-')
				{
					if (ari.top() == '+' || ari.top() == '-')
					{
						cout << ari.top(); // 같은 경우 이전 연산이 우선 되어야 함
						ari.pop();
						ari.push(str[i]);// 새롭게 갱신
					}
					else if (ari.top() == '*' || ari.top() == '/')// *이나 /인경우
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
					if (ari.top() == '*' || ari.top() == '/') //같은 경우
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
				} // (을 만나기 전까지 삭제
				ari.pop(); //(삭제
			}
		}
	
	}
	return 0;
}