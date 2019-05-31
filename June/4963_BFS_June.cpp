#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
int map[50][50];
bool visit[50][50];
int w, h, r, c;
int island;
void bfs(int x, int y) {
	queue<pair<int, int>> Q;
	Q.push(make_pair(x, y));
	visit[x][y] = true;
	while (!Q.empty()) {
		x = Q.front().first;
		y = Q.front().second;
		Q.pop();
		for (int dir = 0; dir < 8; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
				if (!visit[nx][ny] && map[nx][ny] == 1) {
					Q.push(make_pair(nx, ny));
					visit[nx][ny] = true;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (true) {
		island = 0;
		memset(visit, 0, sizeof(visit));
		memset(map, 0, sizeof(map) / sizeof(map));
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		for (r = 0; r < h; r++) {
			for (c = 0; c < w; c++) {
				cin >> map[r][c];
			}
		}

		for (r = 0; r < h; r++) {
			for (c = 0; c < w; c++) {
				if (!visit[r][c] && map[r][c] == 1) {
					island++;
					bfs(r, c);
				}
			}
		}
		cout << island << '\n';
	}
	return 0;
}