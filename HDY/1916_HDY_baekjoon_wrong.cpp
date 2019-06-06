#include <iostream>
#include <algorithm>
#include <math.h>
#include <functional>
#include <queue>
#include <string>
using namespace std;
int N;
int M;
int map[1001][1001];
int start, finish;
int dist[1001];
int seenNodes[1001];

int main() {
	
	//initialize
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			map[i][j] = 99999999;
		}
		dist[i]= 99999999;
	}
	/*
	//input
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int s, f, cost;
		cin >> s >> f >> cost;
		map[s][f] = cost;
	}
	cin >> start >> finish;
	*/
	N = 6;
	M = 20;
	int arr[20][3] = {
		{1,2,2},{2,1,2},
	{1,3,5},{3,1,5},
	{1,4,1},{4,1,4},
	{2,4,2},{4,2,2},
	{2,3,3},{3,2,3},
	{3,4,3},{4,3,3},
	{3,5,1},{5,3,1},
	{3,6,5},{6,3,5},
	{4,5,1},{5,4,1},
	{5,6,2},{6,5,2}
	};
	for (int i = 0; i < M; i++) {

		map[arr[i][0] ][arr[i][1]] = arr[i][2];
	}
	start = 1, finish = 6;


	//calculate
	int minNode = 0; //map[0][0] �� ������ 9999999���̹Ƿ�
	int checkNode = start; 
	for (int i = 1; i <= N; i++) {
		dist[i] = map[checkNode][i];//distance table
		if (dist[minNode] > dist[i])
			minNode = i;
	}
	seenNodes[checkNode] = 1; //Ž���� ��带 ǥ��

	int cnt = 1;//��� ��带 Ž���Ҷ� ����
	while (cnt != N) {
		//��� ��� ����
		checkNode = minNode;
		seenNodes[checkNode] = 1; //Ž���� ��带 ǥ��
		//distance table ������Ʈ
		minNode = 0;
		for (int i = 1; i <= N; i++) {
			if (seenNodes[i] == 0) {//�˻縦 �ؾ��ϴ� ���
				if (dist[i] > dist[checkNode] + map[checkNode][i]) {
					dist[i] = dist[checkNode] + map[checkNode][i];
				}
				if (dist[minNode] > dist[i])
					minNode = i;
			}
		}
		cnt++;
	}
	
	cout << dist[finish];
	cout << "";

}