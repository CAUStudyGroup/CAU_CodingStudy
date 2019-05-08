#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

vector<int> v[200001];
int arr[200001] = { 0 };
priority_queue <int ,vector<int>, greater<int>> pqx;
priority_queue <int, vector<int>, greater<int>> pqy;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int x; int y;
	
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		x += 100000;
		v[x].push_back(y); //x��ǥ�� ���� y��ǥ�� ����
		arr[x]++;
		if (arr[x] == 1) //x��ǥ �ѹ� ��ȴٸ�
			pqx.push(x); //x��ǥ�� ���� ����
		else
			continue;
	}
	while (!pqx.empty())
	{
		int now = pqx.top(); //���� ���� x��ǥ
		pqx.pop();
		for (int i = 0; i < arr[now]; i++)
			pqy.push(v[now][i]);
		while (!pqy.empty())
		{
			cout << now-100000 << ' ' << pqy.top()<< '\n';
			pqy.pop();
		}
	}
	return 0;
}