#include <iostream>
#include <algorithm>
#include <math.h>
#include <functional>
#include <queue>
using namespace std;
int N;
int map[26][26];
int d[26][26];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int answer[10000];

void dfs(int x, int y, int cnt) {
	d[x][y] = cnt;
	answer[cnt]++;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < N && 0 <= ny && ny <= N) {
			if (map[nx][ny] == 1 && d[nx][ny] == 0) {
				dfs(nx, ny, cnt);
				
			}
		}
	}
}

void bfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = cnt;
	answer[cnt]++;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < N && 0 <= ny && ny <= N) {
				if (map[nx][ny] == 1 && d[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = cnt;
					answer[cnt]++;

				}
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		for (int j = N-1; j >=0; j--) {
			int namuji = k % 10;
			k = (int)k / 10;
			map[i][j]=namuji;
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && d[i][j] == 0) {
				//dfs(i, j, ++cnt);
				bfs(i, j, ++cnt);
			}
		}
	}

	cout << cnt << "\n";
	
	priority_queue<int, vector<int>, greater<int> > ans;
	int k = 1;
	while (answer[k] != 0) {
		ans.push(answer[k]);
		k++;
	}

	while (!ans.empty()) {
		cout << ans.top() << "\n";
		ans.pop();
	}
	cout << "\n";
}