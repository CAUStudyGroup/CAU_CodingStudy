#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int DP[1001][1001];
int main()
{
	string str1, str2;
	cin >> str1 >> str2;

	str1 = "0" + str1;
	str2 = "0" + str2;

	for (int i = 1; i < str1.size(); i++)
	{
		for (int j = 1; j < str2.size(); j++)
		{
			if (str1.at(i) == str2.at(j))
				DP[i][j] = DP[i - 1][j - 1] + 1;
			else
				DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
		}
	}
	cout << DP[str1.size()-1][str2.size()-1] << '\n';
	return 0;
}