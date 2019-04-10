#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int q = 0; q < t; q++)
	{
		int n;
		cin >> n;
		int arr[101] = { 0 };

		for (int i = 0; i < n; i++)
			cin >> arr[i];

		long int sum = 0;

		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				int c = 0;
				int tmp1 = arr[i];
				int tmp2 = arr[j];
				while (arr[j])
				{
					c = arr[i];
					arr[i] = arr[j];
					arr[j] = c % arr[i];
				} //유클리드 호제
				sum += arr[i];
				arr[i] = tmp1;
				arr[j] = tmp2;
			}
		}
		cout << sum<<'\n';
	}
	return 0;
}