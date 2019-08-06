#include <iostream>
using namespace std;

int map[51][51];
int n, m, r, c;
int cnt;
int main()
{
	int d;
	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}
	int check = 0;
	while (1)
	{
		//현재 장소를 청소하면서 cnt++
		if (map[r][c] == 0)
		{
			map[r][c] = 2;
			cnt++;
		}
		//한바퀴 다 돌았는데도 안된다면 
		if (check == 4)
		{
			if (d == 0)
			{
				if (map[r + 1][c] == 1)
				{
					cout << cnt << '\n';
					break;
				}
				else
				{
					check = 0;
					r = r + 1;
					continue;
				}
			}
			else if (d == 3)
			{
				if (map[r][c+1] == 1)
				{
					cout << cnt << '\n';
					break;
				}
				else
				{
					check = 0;
					c = c + 1;
					continue;
				}
			}
			else if (d == 2)
			{
				if (map[r-1][c] == 1)
				{
					cout << cnt << '\n';
					break;
				}
				else
				{
					check = 0;
					r = r - 1;
					continue;
				}
			}
			else
			{
				if (map[r][c - 1] == 1)
				{
					cout << cnt << '\n';
					break;
				}
				else
				{
					check = 0;
					c = c - 1;
					continue;
				}
			}
		}
		else
		{
			switch (d)
			{
			case 0:
				//탐지가능하면
				if ( map[r][c - 1] == 0)
				{
					c = c - 1;
					check = 0;
				}else//못가면
				{
					check++;
				}
				d = 3;
				continue;

			case 3:
				if (map[r + 1][c] == 0)
				{
					check = 0;
					r = r + 1;
				}else
				{
					check++;
				}
				d = 2;
				continue;

			case 2:
				if (map[r][c + 1] == 0)
				{
					check = 0;
					c = c + 1;
				}else
				{
					check++;
				}
				d = 1;
				continue;

			case 1:
				if (map[r - 1][c] == 0)
				{
					check = 0;
					r = r - 1;
				}
				else
				{
					check++;
				}
				d = 0;
				continue;
			}
		}
	}
	return 0;
}