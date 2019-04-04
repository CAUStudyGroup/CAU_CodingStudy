#include <iostream>

using namespace std;

long int arr_N[10000001];

int main()
{
	long int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr_N[i];
	}
	int arr_M[100000];

	int M; 
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> arr_M[i];
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr_M[i] == arr_N[j])
			{
				cout << "1 ";
				arr_M[i] = 0;
				break;
			}
		}
		if (arr_M[i] != 0)
			cout << "0 ";
	}
	

	return 0;
}