#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int arr[303][303] = { 0 };
	
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
		}
	}
	int k;
	cin >> k;

	for (int q = 0; q < k; q++)
	{
		int i, j, x, y;
		int sum = 0;
		int DP[10002]= { 0 };

		cin >> i >> j >> x >> y;
		int tmp = j;
		while (j <= y)
		{
			DP[q] += arr[i][j++];
			if (j > y&&i<x)
			{
				j = tmp;
				i++;
			}
		}
		cout << DP[q] << '\n';
	}
	return 0;
}