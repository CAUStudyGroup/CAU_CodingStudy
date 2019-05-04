#include <iostream>
#include <algorithm>
using namespace std;

#define INF 999

int main()
{
	int n, k;
	cin >> n >> k;
	int DP[10001] = { 0 };
	int coins[101] = { 0 };

	for (int i = 1; i <= n; i++)
		cin >> coins[i];
	
	for (int i = 1; i <= k; i++)
		DP[i] = INF; 

	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i - coins[j] >= 0)
			{
				DP[i] = min(DP[i], DP[i - coins[j]] + 1); 
			}
		}
	}
	if (DP[k] == INF)
		cout << "-1";
	else
		cout << DP[k]<<'\n';

	return 0;
}