#include <iostream>
using namespace std;

void printArr(int arr[], int arr_size) {
	for (int i = 0; i < arr_size; i++)
		cout << arr[i] << "\n";
	cout << "ddddddddd";
}
void bubbleSort(int arr[], int N) {
	for (int i = 0; i < N; i++) {
		bool status = true;
		for (int j = 0; j < N - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				//앞,뒤 수를 비교해서 자리교환
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				status = false;//한번이라도 자리 교환이 일어났는지 검사
			}
		}
		//printArr(arr, N); cout << "\n";
		if (status == true) //한번도 자리 교환일어나지 않았을 경우 탈출
			break;
	}
}
int main() {
	int N;
	cin >> N;
	int arr[1001] = { 0, };
	for(int i=0;i<N;i++){
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
	}
	bubbleSort(arr, N);
	printArr(arr, N);
}
