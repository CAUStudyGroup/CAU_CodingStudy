/*
���� 2012�� 
�������� ������ �� �����Ұ�
�ܼ��� int�� �ϸ� ������ ����� ������ ��� �ȴ�.
*/
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

priority_queue<long long> pq;
int main(){
	int N;
	cin >> N;

	long long sum = 0;

	for (int i = 0; i < N; i++) {
		long long n;
		cin >> n;
		pq.push(n);
	}

	while (N--) {
		sum = sum + abs(N+1-pq.top());
		pq.pop();
	}
	cout << sum;
	return 0;
}