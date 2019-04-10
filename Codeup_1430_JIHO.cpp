#include <iostream>
using namespace std;

int arr[10000001];

int main()
{
	long int N;
	int tmp = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		arr[tmp - 1] = tmp;
	}

	int arr_M[100000] = { 0 };
	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
		cin >> arr_M[i];

	for (int i = 0; i < M; i++)
	{
		if (arr_M[i] == arr[arr_M[i] - 1])
			cout << "1 ";
		else
			cout << "0 ";
	}

	return 0;
}