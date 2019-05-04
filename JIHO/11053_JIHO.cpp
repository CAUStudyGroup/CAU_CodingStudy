#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[1002] = { 0 };

	int check = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	int DP[1002] = { 0 };
	
	DP[1] = 1;

	int ans = 0;
	
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++) // 1부터 검사
		{
			if (arr[i] > arr[j])
			{
				DP[i] = max(DP[j]+1, DP[i]);
			}
			else
			{
				if(DP[i]==0)
					DP[i] = 1;
			}

		}
		if (ans < DP[i])
			ans = DP[i];
	}

	if (n == 1)
		ans = 1;

	cout << ans << '\n';
	return 0;
}