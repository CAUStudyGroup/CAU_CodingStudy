#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<int, vector<int>, greater<int>> RQ; // mid���� ū �� �ּ��� 
	priority_queue<int> LQ; // mid���� ���� �� �ִ���

	int mid = 0, n;
	int num,tmp;
	int cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		cnt++;
		if (cnt == 1)
		{
			mid = num;
			cout << mid << '\n';
			continue;
		}
		else
		{
			if (mid <= num)
				RQ.push(num);
			else
				LQ.push(num);

			if (cnt % 2 ==0)//¦�����
			{
				if (LQ.size() > RQ.size())
				{
						RQ.push(mid);
						mid = LQ.top();
						LQ.pop();
				}
			}
			else//Ȧ�����
			{
				if (RQ.size() > LQ.size())
				{
					LQ.push(mid);
					mid = RQ.top();
					RQ.pop();
				}
				else if(RQ.size()<LQ.size())
				{
					RQ.push(mid);
					mid = LQ.top();
					LQ.pop();
				}
			}
		}
		cout << mid << "\n";
	}
	return 0;
}