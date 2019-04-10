#include <iostream>
using namespace std;
#define MOD 10007
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[1002][12] = { 0 };
	int DP[1002] = { 0 };
	int N;
	cin >> N;

	for (int i = 0; i <= 9; i++)
	{
		arr[1][i] = 1; 
		DP[i] = 1;
	}

	for (int j = 2; j <= N; j++) // 계단 번호
	{
		for(int k = 1; k <= 9; k++)
		{ 
			arr[j][k] = DP[k-1]%MOD + arr[j - 1][k]%MOD;
			DP[k] = arr[j][k];
		}
	}
	int sum = 0;
	for (int i = 0; i <= 9; i++)
		sum += DP[i];

	cout << sum%MOD << '\n';
	return 0;
}