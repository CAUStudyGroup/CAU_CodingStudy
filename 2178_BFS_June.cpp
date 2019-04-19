#include <iostream>
#include <queue>
#include <tuple>
#include <string>
using namespace std;
int N, M;
const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };
int miro[101][101];
bool visited[101][101];
int answer = 100000;
void bfs() {
	tuple<int, int, int> node(1, 1, 1); //X,Y,Cnt
	queue<tuple<int, int, int>> Q;
	Q.push(node);
	int initX, initY;
	tie(initX, initY, ignore) = Q.front();
	visited[initX][initY] = true;
	while (!Q.empty()) {
		int curX, curY, cnt;
		tie(curX, curY, cnt) = Q.front(); //계속 Q.front() 어쩌고 쓰기 귀찮으니까 임시변수생성
		Q.pop();
		if (curX == N && curY == M) {
			answer = cnt; //종점에 도착
			return;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nextX = curX + dx[dir];
			int nextY = curY + dy[dir];
			if (nextX >= 1 && nextX <= N && nextY >= 1 && nextY <= M) {
				if (!visited[nextX][nextY] && miro[nextX][nextY] == 1) {
					visited[nextX][nextY] = true;
					get<0>(node) = nextX;
					get<1>(node) = nextY;
					get<2>(node) = cnt + 1;
					Q.push(node);
				}
			}
		}

	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int row,col;
	cin >> N >> M;
	string tmpStr;
	for (row = 1; row <= N; row++) {
		cin >> tmpStr;
		for (col = 1; col <= M; col++) {
			miro[row][col] = tmpStr[col-1] - '0';
		}
	}
	bfs();
	cout << answer;
	return 0;
}