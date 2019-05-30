#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int map[25][25];
bool visit[25][25];
vector<int> aptNum;
int N;
int cnt; //´ÜÁö ¼ö

void dfs(int x, int y) {
	visit[x][y] = true;
	aptNum[cnt-1]++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (!visit[nx][ny] && map[nx][ny] == 1) {
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int row, col;
	string inputStr;
	cin >> N;
	for (row = 0; row < N; row++) {
		cin >> inputStr;
		for (col = 0; col < N; col++) {
			map[row][col] = inputStr[col] - '0';
		}
	}

	for (row = 0; row < N; row++) {
		for (col = 0; col < N; col++) {
			if (!visit[row][col] && map[row][col] == 1) {
				++cnt;
				aptNum.push_back(0);
				dfs(row, col); 
			}
		}
	}
	cout << cnt << '\n';
	sort(aptNum.begin(), aptNum.end());
	for (int s : aptNum) {
		cout << s << '\n';
	}
	return 0;
}