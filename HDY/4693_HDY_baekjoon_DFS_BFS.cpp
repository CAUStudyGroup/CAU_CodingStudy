#include <iostream>
#include <algorithm>
#include <math.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
int h, w;
int map[51][51];
int d[51][51];
int dx[] = { 1,1,1,0,-1,-1,-1,0 };
int dy[] = { 1,0,-1,-1,-1,0,1,1 };
queue<int> answer;

void dfs(int x, int y, int cnt) {
	d[x][y] = cnt;
	for (int k = 0; k < 8; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < h && 0 <= ny && ny < w) {
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
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < h && 0 <= ny && ny < w) {
				if (map[nx][ny] == 1 && d[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = cnt;
				}
			}
		}
	}
}

int main() {

	 w = -1, h = -1;
	cin >> w >> h;
	while( !(w == 0 && h == 0)) {
		//입력
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		//섬개수 세기
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && d[i][j] == 0) {
					dfs(i, j, ++cnt);
					//bfs(i, j, ++cnt);
				}
			}
		}
		//개수 저장
		//answer.push(cnt);
		cout << cnt << "\n";
		
		//초기화 , 입력
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				map[i][j]=0;
				d[i][j] = 0;
			}
		}
		cin >> w >> h;
	}

	//출력
	//while (!answer.empty()) {
	//	cout << answer.front() << "\n";
	//	answer.pop();
	//}
	//cout << "\n";
}