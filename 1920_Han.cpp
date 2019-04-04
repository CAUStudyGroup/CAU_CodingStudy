#include <iostream>
#include <algorithm>
using namespace std;

//백준 1920 바이너리 서치 문제 
//정렬되지 않은 데이터 탐색 -> 정렬 후 BS돌림 
//정렬 -> O(nlogn)
//BS반복 -> O(n * logn)

void printArr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		if (i < size - 1) {
			printf("%d ", arr[i]);
		}
		else {
			printf("%d", arr[i]);
		}
	}
	printf("\n");
}

int* BSearch(int* arr, int size, int n) {
	if (size < 1) {
		return NULL;
	}

	int tempIndex = size / 2;

	if (n > arr[tempIndex]) {
		//오른쪽만 다시 돌림
		int* startPos = arr + tempIndex + 1;
		int halfSize = size - (tempIndex + 1);
		BSearch(startPos, halfSize, n);
	}
	else if (n < arr[tempIndex]) {
		int* startPos = arr;
		int halfSize = tempIndex;
		BSearch(startPos, halfSize, n);
	}
	else {
		return arr + tempIndex;
	}

}

int main() {

	int n;
	cin >> n;
	int* arr1 = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}

	sort(arr1, arr1 + n);

	int a;
	cin >> a;
	int* arr2 = new int[a];
	for (int i = 0; i < a; i++) {
		cin >> arr2[i];
	}

	for (int i = 0; i < a; i++) {
		if (BSearch(arr1, n, arr2[i]) != NULL) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}

	//printArr(arr1, n);



	return 0;
}