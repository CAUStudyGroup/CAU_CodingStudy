#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int P[10002] = { 0 };
	int DP[10002] = { 0 };
	int N,ans=0; 
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> P[i];
		DP[i] = P[i];
	}
	for (int i = 2; i <= N; i++)
	{
		int j = 1;
		while (j<=(i+1)/2)
		{
			DP[i] = max(DP[i], DP[i - j] + DP[j]);
			j++;
		}
	}
	cout << DP[N] << '\n';
	return 0;
}