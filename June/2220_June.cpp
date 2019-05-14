#include <iostream>

using namespace std;

inline int getParentIdx(int idx) {
	return idx / 2;
}

inline int getLChildIdx(int idx) {
	return idx * 2;
}

inline int getRChildIdx(int idx) {
	return getLChildIdx(idx) + 1;
}

void heapify(int arr[]) {
	
}

void heapSort(int arr[], int len) {

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	//1~n까지 최악의 힙 구성하기.
	return 0;
}
