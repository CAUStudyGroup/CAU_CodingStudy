#include <iostream>
#include <vector>
#include <queue>
#include<functional>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; 
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			if (pq.size() == 0)
				cout << "0\n";
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
			pq.push(x);
	}
	return 0;
}