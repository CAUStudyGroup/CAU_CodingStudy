#include <iostream>
#include <stack>
#include <string.h>
using namespace std;


int main()
{
	int tmp = 0,ans=0;

	stack<char> stack;

	char str[100001];
	cin >> str;

	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(')
		{
			stack.push(str[i]);
		}
		else 
		{
			if (str[i - 1] == ')')
			{
				stack.pop();
				ans = ans + 1;
			}
			else
			{
				stack.pop();
				tmp = stack.size();
				ans = ans + tmp;
			}
		}
	}

	cout << ans << endl;
	return 0;
}