#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int q = 0; q < T; q++)
	{
		int N;
		cin >> N;
		int DP[102] = { 0,1,1,1 ,2,2 };
		for (int i = 6; i <= N; i++)
			DP[i] = DP[i - 1] + DP[i - 5];

		cout << DP[N] << '\n';
	}
	return 0;
}