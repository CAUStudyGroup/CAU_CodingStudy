#include <iostream>
#include <algorithm>
using namespace std;

int arr[3][100002] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int q = 0; q < t; q++)
	{
		int DP[200003] = { 0 };
		int n;
		cin >> n;
		for (int i = 1; i <= 2; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> arr[i][j]; // arr√ ±‚»≠
			}
		}

		DP[1] = arr[1][1];
		DP[2] = arr[2][1];
		DP[3] = arr[1][2] + arr[2][1];
		DP[4] = arr[2][2] + arr[1][1];

		for (int i = 5; i <= 2 * n; i++)
		{
			if (i % 2 != 0)
				DP[i] = max(DP[i - 1] + arr[1][i / 2 + 1], DP[i - 3] + arr[1][i / 2 + 1]);
			else
				DP[i] = max(DP[i - 3] + arr[2][i / 2], DP[i - 5] + arr[2][i / 2]);
		}
		
		cout << max(DP[2 * n], DP[2 * n - 1]) << endl;
	}
	return 0;
}