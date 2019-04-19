#include <iostream>
#include <string>
#include <stack>
using namespace std;
struct point{
	int x;
	int y;
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};
/*
1 2 3 4 = M = y
2
3
4
= N = x
*/
int main() {
	while (true) {
	
		int N, M, count = 0;
		stack<point> stk;
		cin >> N >> M;

		int arr[101][101] = { 0, };
		string str;
		cin >> str;
		int k = 0;
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < M + 1; j++) {
				arr[i][j] = str[k] - '0';
				k++;
			}
		}

		//start
		stk.push(point(1, 1));
		int x = 1, y = 1;

		while (!(x == N && y == M)) {
			x = stk.top().x;
			y = stk.top().y;
			arr[x][y] = 2; // I have been here
			count++;

			bool status = false;
			stk.pop();
			if (y - 1 >0 && arr[x][y - 1] == 1) { //left
				stk.push(point(x, y - 1));
				status = true;
			}
			if (x - 1>0 && arr[x - 1][y] == 1) { //up
				stk.push(point(x - 1, y));
				status = true;
			}
			if (x + 1 <= N && arr[x + 1][y] == 1) { //down
				stk.push(point(x + 1, y));
				status = true;
			}
			if (y - 1 <= M && arr[x][y + 1] == 1) { //right
				stk.push(point(x, y + 1));
				status = true;
			}

			if(!status) {//there is no road
				if (!(x == N && y == M)) {
					count--;
					arr[x][y] = 3;
				}else if (x == N && y == M) {
					arr[x][y] = 2;
				}
			}

			/*
			cout << endl << "test maze   count=" << count << "x=" << x << " y=" << y << endl;
			for (int i = 1; i < N + 1; i++) {
				for (int j = 1; j < M + 1; j++) {
					cout << arr[i][j];
				}
				cout << endl;
			}
			cout << "";*/
		}

		cout << count;
	}
	
}
