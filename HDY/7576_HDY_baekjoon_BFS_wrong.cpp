#include <iostream>
#include <algorithm>
#include <math.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
int M, N;
int map[1001][1001];
int d[1001][1001];
int dx[] = {0,0,1,-1};
int dy[] = { 1,-1,0,0 };
int answer;
int bar;
int hi[2];

void dfs(int x, int y, int cnt) {
	d[x][y] = cnt;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < M && 0 <= ny && ny <= N) {
			if (map[nx][ny] == 0 && d[nx][ny] == 0) {
				dfs(nx, ny, ++cnt);
				
			}
		}
	}
}

void bfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = cnt;
	answer = cnt;
	bool status = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		//if (status) {
			cnt++;
			answer = cnt;
		//}

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (map[nx][ny] == 0 && d[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = cnt;
					answer = cnt;
				}
			}
		}
	}
}

int main() {
	cin >> M >> N;
	//입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	//섬개수 세기
	//int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && d[i][j] == 0) {
				//dfs(i, j, ++cnt);
				bfs(i, j, 1);
			}
		}
	}


	cout << answer;
	cout << "\n";
}