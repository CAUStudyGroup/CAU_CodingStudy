#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char arr[102];
		cin >> arr;
		int len = strlen(arr);
		int arr_int[102] = { 0 };
		if (len > 1)
		{
			for (int j = 0; j < len; j++)
			{
				arr_int[j] = arr[j];
			}
			for (int j = 0; j < len - 1; j++)
			{
				for (int k = j + 1; k < len; k++)
				{
					if (arr_int[j] > arr_int[k])
					{
						swap(arr_int[j], arr_int[k]);
					}
				}
			}

			for (int j = 0; j < len - 1; j++)
			{
				if (arr_int[j] + 1 != arr_int[j + 1])
				{
					cout << "No" << endl;
					break;
				}
				if (j == len - 2)
					cout << "Yes" << endl;
			}
		}
		if (len == 1)
		{
			cout << "Yes" << endl;
		}
	}
	return 0;
}