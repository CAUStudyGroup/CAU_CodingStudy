#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int DP[92] = {0 };
	DP[1] = 1;
	DP[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}

	cout << DP[n] << endl;
}