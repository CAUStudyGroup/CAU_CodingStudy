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
		v_first[x].push_back(y); // x�� ���� Ǯ��� Ǯ �� �ִ� y�� ����
		v_did[y]++; //�տ��� y�� ���� ���������� ��޵� Ƚ��
	}
	for (int i = 1; i <= n; i++)
	{
		if (v_did[i] == 0) // ��޵� �� ���ٸ� ���� Ǯ� ��
			pq.push(i);
	}
	
	while (!pq.empty())
	{
		cout << pq.top() << ' '; // �ϴ� �������� �����Ƿ� ���
		int now = pq.top();
		pq.pop();
		//��µ� �ְ� ���������� ��쿡 ���� ����.. 
		if (v_first[now].size() > 0)
		{
			for (int i = 0; i < v_first[now].size(); i++)
			{
				v_did[v_first[now][i]]--; // ��޵� Ƚ�� ����
				if (v_did[v_first[now][i]] == 0)
					pq.push(v_first[now][i]);
			}
		}
	}
	return 0;
}