#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int count2 = 0, count5 = 0;
	int tmp = 0;

	for (int i = N; i > 0; i--)
	{
		if (i % 2 == 0)
		{
			tmp = i;
			while (tmp % 2 == 0)
			{
				count2++;
				tmp /= 2;
			}
			tmp = 0;
		}

		if (i % 5 == 0)
		{
			tmp = i;
			while (tmp % 5 == 0)
			{
				count5++;
				tmp /= 5;
			}
			tmp = 0;
		}
	}
	if (count2 > count5)
		cout << count5 << endl;
	else
		cout << count2 << endl;
	return 0;
}