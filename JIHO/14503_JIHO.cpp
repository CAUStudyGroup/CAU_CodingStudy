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
		//���� ��Ҹ� û���ϸ鼭 cnt++
		if (map[r][c] == 0)
		{
			map[r][c] = 2;
			cnt++;
		}
		//�ѹ��� �� ���Ҵµ��� �ȵȴٸ� 
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
				//Ž�������ϸ�
				if ( map[r][c - 1] == 0)
				{
					c = c - 1;
					check = 0;
				}else//������
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