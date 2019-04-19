#include <iostream>
#include <string>
#include <queue>
using namespace std;
// 1 2 3 4 = M = y
// 2 0 0 0
// 3 0 0 0
// 4 0 0 0
// = N = x

struct point{
	int x;
	int y;
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int arr[102][102] = { 0, };
int record[102][102] = { 0, };
int N, M;
queue<point> que;

bool setRecord(int x,int y,int nX,int nY){
	point pnt = { nX,nY };
	que.push(pnt);
	//if I have not been there ,OR, now record is smaller than~
	if ((record[nX][nY] == 0) || (record[x][y] + 1 < record[nX][nY])) { 
		record[nX][nY] = record[x][y] + 1;
	}
	return true;
}

int main() {
	cin >> N >> M;

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
	point temp = { 1,1 };
	que.push(temp);
	int x = 1, y = 1;
	record[x][y] = 1;

	//solve
	while (!(x == N && y == M)) {
		x = que.front().x;
		y = que.front().y;
		que.pop();
		arr[x][y] = 2;//i have been there			
			
		bool status = false;
		if (y - 1 >0 && arr[x][y - 1] == 1) { //left
			status=setRecord(x, y, x,y-1);
		}
		if (x - 1>0 && arr[x - 1][y] == 1) { //up
			status = setRecord(x, y, x-1, y);
		}
		if (x + 1 <= N && arr[x + 1][y] == 1) { //down
			status = setRecord(x, y, x+1, y);
		}
		if (y - 1 <= M && arr[x][y + 1] == 1) { //right
			status = setRecord(x, y, x, y+1);
		}
	}
	cout << record[N][M];
}

/*
cout << endl << "record " << endl;
for (int i = 0; i < N + 1; i++) {
for (int j = 0; j < M + 1; j++) {
cout << record[i][j];
}
cout << endl;
}
cout << "";


cout << endl << "arr"<< endl;
for (int i = 0; i < N + 1; i++) {
for (int j = 0; j < M + 1; j++) {
cout << arr[i][j];
}
cout << endl;
}
cout << "";*/