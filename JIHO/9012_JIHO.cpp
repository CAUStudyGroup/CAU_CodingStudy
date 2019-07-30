#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		stack<char> st;
		cin >> s;
		bool check = 1;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				st.push('(');
			else
			{
				if (!st.empty())
					st.pop();
				else
				{
					check = 0;
				}
			}
		}
		if (check)
		{
			if (!st.empty())
				cout << "NO\n";
			else
				cout << "YES\n";
		}
		else
			cout << "NO\n";
	}
	return 0;
}