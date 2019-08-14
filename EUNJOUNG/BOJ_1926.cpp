#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second

int board[502][502];
bool visit[502][502];

int main(void) {
	int n, m;
	int size = 0, count = 0;
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { 1, -1,0,0 };
	pair<int, int> tmp;

	ios::sync_with_stdio(0);
	cin.tie(0);

	queue< pair<int, int> > Q;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 || visit[i][j]) continue;

			count++;
			visit[i][j] = 1;
			Q.push({ i,j });
			int area = 0;
			while (!Q.empty()) {
				area++;
				tmp = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = tmp.X + dx[dir];
					int ny = tmp.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (visit[nx][ny] || board[nx][ny] != 1) continue;
					visit[nx][ny] = 1;
					Q.push({ nx,ny });
				}
			}
			size = max(size, area);

		}
	}
	cout << count << '\n' << size;
	return 0;
}