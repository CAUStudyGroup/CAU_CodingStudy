#include <iostream>
#include <stack>
#include <tuple>
#include <string>
using namespace std;
int N, M;
const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };
int miro[101][101];
int visited[101][101];
int answer = 100000;
void dfs(tuple<int,int,int> node) {
	stack<tuple<int, int, int>> s;
	int curX, curY, cnt;
	tie(curX, curY, cnt) = node;
	s.push(node);
	while (!s.empty()) {
		get<0>(node) = get<0>(s.top());
		get<1>(node) = get<1>(s.top());
		get<2>(node) = get<2>(s.top());
		s.pop();

		visited[curX][curY] = cnt;
		if (curX == N && curY == M) {
			answer = answer > cnt ? cnt : answer;
			continue;
		}

		int nextX, nextY;
		for (int dir = 0; dir < 4; dir++) {
			nextX = curX + dx[dir];
			nextY = curY + dy[dir];
			if (visited[nextX][nextY] == 0 || (cnt + 1) < visited[nextX][nextY]) {
				tuple<int, int, int> newNode = make_tuple(nextX, nextY, cnt + 1);
				s.push(newNode);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int row, col;
	cin >> N >> M;
	string tmpStr;
	for (row = 1; row <= N; row++) {
		cin >> tmpStr;
		for (col = 1; col <= M; col++) {
			miro[row][col] = tmpStr[col - 1] - '0';
		}
	}
	tuple<int, int, int> node(1, 1, 1);
	dfs(node);
	cout << answer;
	return 0;
} //Solving