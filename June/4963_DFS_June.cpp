#include <iostream>
#include <cstring>
using namespace std;
int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
int map[50][50];
bool visit[50][50];
int w, h, r, c;
int island;
void dfs(int x, int y) {
	visit[x][y] = true;
	for (int dir = 0; dir < 8; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
			if (!visit[nx][ny] && map[nx][ny] == 1) {
				visit[nx][ny] = true;
				dfs(nx, ny);
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
					dfs(r, c);
				}
			}
		}
		cout << island << '\n';
	}
	return 0;
}