#include <iostream>
#include <algorithm>
#include <math.h>
#include <functional>
#include <string>
using namespace std;
int N;
int M;
int map[101][101];

int main() {
	
	//initialize
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			map[i][j] = 99999999;
		}
	}
	
	//input
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int s, f;
		cin >> s >> f ;
		//무방향 그래프
		map[s][f] = 1;
		map[f][s] = 1;
	}

	//calc
	for (int k = 1; k <=N; k++) {   // 1->k->j vs 1->j
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][k] + map[k][j] < map[i][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}

	int cnt = 0;
	for (int i = 2; i <= N; i++) {
		if (map[1][i] < 99999999)
			cnt++;
	}
	cout << cnt;

}