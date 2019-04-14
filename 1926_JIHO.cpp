#include <iostream>
#include <queue>
using namespace std;

int arr[501][501];

int visit[501][501];

struct pic
{
	int one; 
	int two;
};
int main()
{
	int n, m;

	cin >> n >> m;

	queue<struct pic> q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> arr[i][j]; //초기화
	}

	int pic_count = 0;
	int S=0;
	int max = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1 && visit[i][j] == 0)
			{
				q.push({ i,j }); //그리기 시작
				pic_count++;
				S = 0;
				while (1)
				{
					int a = q.front().one;
					int b = q.front().two;

					if (a > 0 && visit[a - 1][b] == 0)
					{
						if (arr[a - 1][b] == 1)
						{
							q.push({ a - 1,b });
							visit[a - 1][b] = 1;
							S++;
						}
					}
					if (a + 1 <= n - 1 && visit[a + 1][b] == 0)
					{
						if (arr[a + 1][b] == 1)
						{
							q.push({ a + 1,b });
							visit[a + 1][b] = 1;
							S++;
						}
					}
					if (b > 0 && visit[a][b - 1] == 0)
					{
						if (arr[a][b - 1] == 1)
						{
							q.push({ a,b - 1 });
							visit[a][b - 1] = 1;
							S++;
						}
					}
					if (b + 1 < m&&visit[a][b + 1] == 0)
					{
						if (arr[a][b + 1] == 1)
						{
							q.push({ a,b + 1 });
							visit[a][b + 1] = 1;
							S++;
						}
					}
					q.pop();

					if (q.empty())
					{ 
						if (max <= S)
							max = S;
						break;
					}
				}
			}
		}
	}

	if (pic_count > 0&&max == 0) // 그림 넓이가 1일때
		max = 1;

	cout << pic_count << '\n' << max<<'\n';
	return 0;
}