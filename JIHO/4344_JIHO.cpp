#include<iostream>
#include <stdio.h>
using namespace std;

int main() {

	int C, N, X[1000], count = 0, sum = 0;
	float ave;
	float rate;

	scanf("%d", &C);// ������� ����

	for (int i = 0; i < C; i++) {

		scanf("%d", &N); // ������� ����
		for (int j = 0; j < N; j++) {

			scanf("%d", &X[j]);//�л��� ����
			sum += X[j]; // �л��� ����
		}

		ave = (float)sum / N;// ��� 

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
