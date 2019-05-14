#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	priority_queue<int, vector<int>, greater<int>> pq;
	int n;
	cin >> n;
	int tmp;
	for (int i = 1; i <= n; i++)
	{
		cin >> tmp;
		pq.push(tmp);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << pq.top()<<'\n';
		pq.pop();
	}
	return 0;
}