#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
void printArr(int arr[], int arr_size) {
	for (int i = 0; i < arr_size; i++)
		cout << arr[i] << "\n";
}

int arr[1000001] = { 0, };
int main() {
	priority_queue <int,vector<int>,greater<int>> q;
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		int tmp;
		cin >> tmp;
		q.push(tmp);
	}
	for (int i = 0; i < N; i++) {
		cout << q.top();
		q.pop();
	}

}