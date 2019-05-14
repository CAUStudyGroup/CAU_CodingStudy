#include <iostream>
using namespace std;

int arr_[1000000];
int tmparr_[1000000];
int n;
//머지 소트
void merge(int *arr, int start, int end)
{
	int mid = (start + end) / 2;
	int left = start;
	int right = mid + 1;
	int k = start;

	while (left <= mid &&right <= end)
	{
		if (arr[left] > arr[right])
			tmparr_[k++] = arr[right++];
		else 
			tmparr_[k++] = arr[left++];
	}

	if (left > mid)
	{
		for (int i = right; i <= end; i++)
			tmparr_[k++] = arr[i];
	}
	else
	{
		for (int i = left; i <= mid; i++)
		{
			tmparr_[k++] = arr[i];
		}
	}

	for (int i = start; i <= end; i++)
		arr[i] = tmparr_[i];
}

void merges(int *arr, int start, int end)
{
	int mid = (start + end) / 2;
	if (end > start)
	{
		merges(arr, start, mid);
		merges(arr, mid + 1, end);
		merge(arr, start, end);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n; 

	for (int i = 0; i < n; i++)
		cin >> arr_[i];
	
	merges(arr_, 0, n-1);

	for (int i = 0; i < n; i++)
		cout << arr_[i] << '\n';

	return 0;
}