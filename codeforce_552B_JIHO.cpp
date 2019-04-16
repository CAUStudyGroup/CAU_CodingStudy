#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	int arr[102] = { 0 };

	int n,m,imsi;
	cin >> n;

	
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	if (n == 1)
	{
		cout << "0\n";
		return 0;
	}
	sort(arr, arr + n);
	
	for (int i = 0; i < n-1; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			if (i == n - 2)
			{
				cout << "0\n"; //모든 원소가 같은 경우
				return 0;
			}
		}
		else if(arr[i]!=arr[i+1])//달라지는 순간 
		{
			int tmp = i;
			if (arr[tmp + 1] == arr[n - 1])
			{
				int min = arr[n - 1] - arr[tmp]; //만약 그냥 더하는 것보다 평균이 있다면?
				if ((arr[tmp] + arr[n - 1]) / 2 < min)
				{
					 m = (arr[tmp] + arr[n - 1]) / 2;
					if (m - arr[tmp] == arr[n - 1] - m)
						min = arr[n - 1] - m;
				}
				cout << min << '\n';
				return 0;
			}
			else //다음 원소가 마지막 것과 다름
			{
				m = (arr[tmp] + arr[n - 1]) / 2;
				imsi = m - arr[tmp];
				int j = 0;
				while (j<n)
				{
					if (arr[j] == m)
					{
						j++;
					}
					else if (abs(arr[j] - m) == imsi)
					{
						j++;
					}
					else
					{
						cout << "-1\n";
						return 0;
					}
				}
				cout << imsi << '\n';
				return 0;
			}
		}
	}



	return 0;
}