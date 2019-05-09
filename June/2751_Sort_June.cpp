#include <iostream>
#include <cstring>
using namespace std;
int arr[1000002];
int leftArr[500002];
int rightArr[500002];
//2751 Merge Sort (Huge Data)
void merge(int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	memset(leftArr, 0, n1);
	memset(rightArr, 0, n2);

	for (i = 0; i < n1; i++)
		leftArr[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		rightArr[j] = arr[mid + 1 + j];

	i = 0;	j = 0; 
	k = left; 
	while (i < n1 && j < n2)
	{
		if (leftArr[i] <= rightArr[j])
		{
			arr[k++] = leftArr[i++];
		}
		else
		{
			arr[k++] = rightArr[j++];
		}
	}

	while (i < n1)
	{
		arr[k++] = leftArr[i++];
	}
	while (j < n2)
	{
		arr[k++] = rightArr[j++];
	}
}
void mergeSort(int left, int right) {
	int mid = (left + right) / 2;
	if (right > left) {
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merge(left, mid, right);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, num, i;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> num;
		arr[i] = num;
	}

	mergeSort(0, N-1);

	for (i = 0; i < N; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}
