#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	int n,tmp; 
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		pq.push(tmp);
	}
	int j = 1; 
	while (!pq.empty())
	{
		if (j <= pq.top())
			j++;
		pq.pop();
	}
	cout << j-1<<'\n';
	return 0;
}