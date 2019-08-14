#include <iostream>
using namespace std;
#define endl '\n'

int board[103][103];
int apple[103][103];
int direction[10007];

int main(void) {
	int n, m, cnt = 0,size =1;
	int x, y,dc=4;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0, 1,0,-1 };
	char c;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> y>> x;
		apple[x][y] = 1;
	}
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		cin >> x >> c;
		if (c == 'D') {
			direction[x] = 1;
		}
		else if (c == 'L') {
			direction[x] = -1;
		}
	}
	x = 1; y = 1;
	while (1) {
		cnt++;
		board[x][y] = cnt;
	
		int nx, ny;
		dc = (dc + direction[cnt]) % 4;
		if (dc == 0) {
			nx = x + dx[dc]; ny = y + dy[dc];
		}
		else if (dc == 1) {
			nx = x + dx[dc]; ny = y + dy[dc];
		}
		else if (dc == 2) {
			nx = x + dx[dc]; ny = y + dy[dc];
		}
		else if (dc == 3) {
			nx = x + dx[dc]; ny = y + dy[dc];
		}
		if (apple[nx][ny] == 1)
		{
			size++;
			apple[nx][ny] = 0;
		}
		if (nx <= 0 || nx > n) {
			cnt++; break;
		}
		if (ny <= 0 || ny > n) {
			cnt++;  break;
		}
		if (board[nx][ny] != 0) {
			if (board[x][y] - board[nx][ny] < size) {
				cnt++; break;
			}
		}

		x = nx; y = ny;

	}
	cout << cnt << endl;

}