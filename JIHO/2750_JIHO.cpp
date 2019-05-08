#include <iostream>  
using namespace std;

int main()
{
	int N;
	cin >> N;
	int M[1001] = { 0, };

	for (int i = 0; i < N; i++)
		cin >> M[i];

	for (int i = 0; i < N - 1; i++)
	{
		int min = M[i];
		int loc = 0, tmp = 0;
		for (int j = i; j < N - 1; j++)
		{
			if (min > M[j + 1])
			{
				min = M[j + 1];
				loc = j + 1;
				tmp = M[i];
				M[i] = M[loc];
				M[loc] = tmp;
			}
		}
	}

	for (int i = 0; i < N; i++)
		cout << M[i] << endl;

	return 0;
}

