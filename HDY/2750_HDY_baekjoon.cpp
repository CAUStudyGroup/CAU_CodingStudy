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
				//��,�� ���� ���ؼ� �ڸ���ȯ
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				status = false;//�ѹ��̶� �ڸ� ��ȯ�� �Ͼ���� �˻�
			}
		}
		//printArr(arr, N); cout << "\n";
		if (status == true) //�ѹ��� �ڸ� ��ȯ�Ͼ�� �ʾ��� ��� Ż��
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
