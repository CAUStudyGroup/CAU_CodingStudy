#include <iostream>
#include <vector>
#include <queue>
#include<functional>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
vector<int> v_first[32001];
int v_did[32001];

int main()
{
	int n, m;
	cin >> n >> m;

	int x, y;

	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		v_first[x].push_back(y); // x를 먼저 풀어야 풀 수 있는 y들 삽입
		v_did[y]++; //앞에서 y에 대한 선행조건이 언급된 횟수
	}
	for (int i = 1; i <= n; i++)
	{
		if (v_did[i] == 0) // 언급된 적 없다면 먼저 풀어도 됨
			pq.push(i);
	}
	
	while (!pq.empty())
	{
		cout << pq.top() << ' '; // 일단 선행조건 없으므로 출력
		int now = pq.top();
		pq.pop();
		//출력된 애가 선행조건인 경우에 대해 생각.. 
		if (v_first[now].size() > 0)
		{
			for (int i = 0; i < v_first[now].size(); i++)
			{
				v_did[v_first[now][i]]--; // 언급된 횟수 제거
				if (v_did[v_first[now][i]] == 0)
					pq.push(v_first[now][i]);
			}
		}
	}
	return 0;
}