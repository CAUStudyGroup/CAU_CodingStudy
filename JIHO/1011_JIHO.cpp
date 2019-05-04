#include <iostream>  

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{

		long long int start, end, sum = 0;

		cin >> start >> end;

		long long int distance = end - start;
		long long int tmp = 0;
		long long int loop_sum = 0;

		if (start == end)
			return 0;
		for (int j = 1; ; j++)
		{
			sum = sum + j;
			if (sum * 2 >= distance)
			{
				tmp = j - 1;
				//cout << tmp << endl;
				break;
			}
		}

		for (int j = 0; j <= tmp; j++)
		{
			loop_sum += j;
		}

		loop_sum *= 2;

		if (distance - loop_sum > tmp + 1)
			cout << 2 + 2 * tmp << endl;
		else if (distance - loop_sum == 0)
		{
			cout << tmp + 1 << endl;
		}
		else
			cout << 1 + 2 * tmp << endl;
	}
	return 0;
}
