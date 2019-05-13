#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int DP[1001][1001];
int k; 
int now_max; 

int main()
{
	string str1, str2,str3;
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
	k = str2.size() - 1;
	for (int i = str1.size() - 1; i > 0; i--)
	{
		for (int j = k; j > 0; j--)
		{
			if (DP[i][j] != DP[i][j - 1])
			{
				if (DP[i - 1][j] != DP[i][j])
				{
					str3.push_back(str1.at(i));
					k = j - 1;
				}
				else
					k = j;
				break;
			}
		}
	}
	reverse(str3.begin(),str3.end());
	cout << str3 << '\n';
	return 0;
}