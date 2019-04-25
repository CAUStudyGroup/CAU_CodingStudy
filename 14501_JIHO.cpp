#include <iostream>
#include <algorithm>
using namespace std;

int arr[18][2];
int DP[18];
int main()

{
	int N;
	cin >> N;
	int ans = 0; 

	for (int i = 1; i <= N; i++)
		cin >> arr[i][0] >> arr[i][1];

	for (int i = 1; i <= N; i++)
	{
		if (i + arr[i][0] <= N+1)
		{
			DP[i] = max(arr[i][1], DP[i] + arr[i][1]);

			if (ans <= DP[i])
				ans = DP[i];
			
			for (int j = i + arr[i][0]; j <= N; j++)
			{ 
				if (DP[j] <= DP[i])
					DP[j] = DP[i];
			}
		}
	}
	cout << ans << '\n';
	return 0;
}