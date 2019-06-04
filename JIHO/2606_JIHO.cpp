#include <iostream>

using namespace std;
#define INF 1000000000
int n, p;
int arr[101][101];

void floyd()
{
	int distance[101][101];
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			distance[i][j] = arr[i][j];
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (distance[i][k] + distance[k][j] <= distance[i][j])
					distance[i][j] = distance[i][k] + distance[k][j];
			}
		}
	}


	for (int i = 1; i <= n; i++)
	{
		if (distance[1][i] != 0 && distance[1][i]!=INF)
			count++;
	}
	cout << count;

}
int main()
{
	cin >> n >> p;

	int x, y;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
				arr[i][j] = INF;
		}
	}

	for (int i = 0; i < p; i++)
	{
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}

	floyd();
	return 0;
}