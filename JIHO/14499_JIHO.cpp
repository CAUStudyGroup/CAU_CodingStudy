#include <iostream>
using namespace std;

int N, M, x, y;
int map[21][21];
int dice[6];
int a, b, c, d;
int main()
{
	int k;
	cin >> N >> M >> x >> y >> k;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		int cmd;
		cin >> cmd;

		switch (cmd) 
		{
		case 1 :
			if (y + 1 < M)
			{
				y = y + 1; 
				//일단 이동해 놓고 밑면을 바꿈
				a = dice[0];
				b = dice[1];
				c = dice[2];
				d = dice[5];

				dice[0] = b, dice[1] = d, dice[5] = c, dice[2] = a;

				if (map[x][y] == 0)
				{
					map[x][y] = dice[0];
				}
				else
				{
					dice[0] = map[x][y];
					map[x][y] = 0;
				}
				cout << dice[5] << "\n";
			}
			break;
		case 2:
			if (y - 1 >= 0)
			{
				y = y - 1;
				a = dice[0];
				b = dice[1];
				c = dice[2];
				d = dice[5];

				dice[0] = c, dice[1] = a, dice[5] = b, dice[2] = d;

				if (map[x][y] == 0)
				{
					map[x][y] = dice[0];
				}
				else
				{
					dice[0] = map[x][y];
					map[x][y] = 0;
				}
				cout << dice[5] << "\n";
			}
			break;
		case 3:
			if (x - 1 >= 0)
			{
				x = x - 1;
				a = dice[0];
				b = dice[4];
				c = dice[5];
				d = dice[3];

				dice[0] = b, dice[4] = c, dice[5] = d, dice[3] = a;

				if (map[x][y] == 0)
				{
					map[x][y] = dice[0];
				}
				else
				{
					dice[0] = map[x][y];
					map[x][y] = 0;
				}
				cout << dice[5] << "\n";
			}
			break;
		case 4:
			if (x + 1 < N)
			{
				x = x + 1;
				a = dice[0];
				b = dice[4];
				c = dice[5];
				d = dice[3];

				dice[0] = d, dice[4] = a, dice[5] = b, dice[3] = c;

				if (map[x][y] == 0)
				{
					map[x][y] = dice[0];
				}
				else
				{
					dice[0] = map[x][y];
					map[x][y] = 0;
				}
				cout << dice[5] << "\n";
			}
			break;
		default :
			continue;
		}
	}

	return 0;
}