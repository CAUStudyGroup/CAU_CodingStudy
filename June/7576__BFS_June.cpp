#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
int M, N, row, col;
int box[1000][1000];
int noRipedTomato = 0;
queue<pair<int, int>> Q;
int bfs() {
	int lastDay = 0;
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (box[nx][ny] == 0) {
					Q.push(make_pair(nx, ny));
					box[nx][ny] = box[x][y]+1; //day +1 before day tomato
					noRipedTomato--;
					lastDay = box[nx][ny];
				}
			}
		}
	}
	return noRipedTomato > 0 ? -1 : lastDay - 1;
	//If there is any no riped Tomato left, return -1, else return ans-1
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(box, -1, sizeof(box) / sizeof(int));
	cin >> M >> N;
	for (row = 0; row < N; row++) {
		for (col = 0; col < M; col++) {
			cin >> box[row][col];
			if (box[row][col] == 0) noRipedTomato++;
			else if (box[row][col] == 1) Q.push(make_pair(row, col));
		}
	}

	if (noRipedTomato == 0) cout << 0;
	else cout << bfs();

	return 0;
}