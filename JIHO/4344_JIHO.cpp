#include<iostream>
#include <stdio.h>
using namespace std;

int main() {

	int C, N, X[1000], count = 0, sum = 0;
	float ave;
	float rate;

	scanf("%d", &C);// 몇반인지 정함

	for (int i = 0; i < C; i++) {

		scanf("%d", &N); // 몇명인지 정함
		for (int j = 0; j < N; j++) {

			scanf("%d", &X[j]);//학생의 점수
			sum += X[j]; // 학생의 총점
		}

		ave = (float)sum / N;// 평균 

		for (int k = 0; k < N; k++) {
			if (ave < X[k])
				count++;
		}
		rate = (float)count * 100 / N;
		printf("%.3f", rate);
		cout << "%" << endl;
		count = 0;
		sum = 0;

	}



}
