#include <iostream>
#include <vector>

using namespace std;

void Swap(vector<int>& arr, int n1, int n2) {
	int tmp = arr[n1];
	arr[n1] = arr[n2];
	arr[n2] = tmp;
}

int main(void) {
	int num;
	cin >> num;
	vector<int> heapArr(num + 1, 0); //0으로 Vector 초기화
	heapArr[1] = 1;
	for (int i = 2; i <= num; i++) {
		heapArr[i] = i; 
		int j = i - 1; //항상 1이 여기있음.
		Swap(heapArr, i, j);
		while (j != 1) { //루트까지 올라가자
			Swap(heapArr, j, j / 2); //부모가 j/2
			j = j / 2;
		}
	}
	for (int i = 1; i <= num; i++)
		cout << heapArr[i] << ' ';
	return 0;
}