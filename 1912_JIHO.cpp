#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[100002] = { 0 };
	int DP[100002] = { 0 };
	int n,ans;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	ans = DP[1] = arr[1];

	for (int i = 2; i <= n; i++)
	{
		DP[i] = max(DP[i - 1] + arr[i], arr[i]);
		if (ans <= DP[i])
			ans = DP[i];
	}
	cout << ans << '\n';
	return 0;
}