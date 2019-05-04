#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, t = 0;
	int arr[10002] = { 0, };
	int DP[10002][3];
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i]; // 배열 초기화
	}
	DP[1][1] = arr[1]; //1번 o 
	DP[2][0] = arr[1]; // 1번 o 2번 x //아직 2번을 마시지 않음
	DP[2][1] = arr[2]; // 1번 x 2번 o
	DP[2][2] = arr[1] + arr[2]; // 1번 o 2번 x

	for (int i = 3; i <= n; i++)
	{
		DP[i][0] = max(max(DP[i - 1][2], DP[i - 1][1]), DP[i - 1][0]);//i번째 마시기 전, 즉 그 전의 잔
		DP[i][1] = DP[i - 1][0] + arr[i];
		DP[i][2] = DP[i - 1][1] + arr[i];
	}

	cout << max(max(DP[n][0], DP[n][1]), DP[n][2]) << endl;

	return 0;
}