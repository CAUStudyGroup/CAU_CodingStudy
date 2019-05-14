#include <iostream>
#include <string>
using namespace std;

int main()
{
	string num;
	int n, x, y;
	cin >> n >> x >> y;
	cin >> num;
	int count = 0;

	for (int i = n - x ; i < n; i++)
	{
		if (i != n - y - 1)
		{
			if (num[i] == '1')
				count++;
		}
		else if (i == n - y - 1)
		{
			if (num[i] == '0')
				count++;
		}
	}

	cout << count;
	return 0;
}