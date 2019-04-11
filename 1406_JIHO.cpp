#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

char ans[600002];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	stack<char> s_L,s_R;
	char arr[600002];
	cin >> arr;
	int len = strlen(arr);
	for (int i = 0; i < len; i++)
		s_L.push(arr[i]); // ���� �ʱ�ȭ
	int t; 
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		char ch;
		cin >> ch;

		switch(ch)
		{
		case 'L': 
			if (!s_L.empty())
			{
				s_R.push(s_L.top());
				s_L.pop();// ���� ž�� ���������� �ű�
			}
			break;
		case 'D':
			if (!s_R.empty())
			{
				s_L.push(s_R.top());
				s_R.pop();// ���� �� ž�� �������� �ű�
			}
			break;
		case 'B':
			if(!s_L.empty())
				s_L.pop();
			break;
		case 'P':
			char tmp;
			cin >> tmp;
			s_L.push(tmp);
			break;
		default :
			break;
		}
	}
	len = s_L.size();// �̸� ������ ����
	while (!s_L.empty())
	{
		ans[s_L.size() - 1] = s_L.top();
		s_L.pop();
	}
	int len2 = s_R.size();
	int q = 0;
	while (!s_R.empty())
	{
		ans[len+q] = s_R.top();
		s_R.pop();
		q++;
	}
	for (int i = 0; i < len + len2 ; i++)
		cout << ans[i];
	return 0;
}