/*
백준 2012번 
데이터의 범위를 잘 생각할것
단순히 int로 하면 범위를 벗어나서 오답을 얻게 된다.
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