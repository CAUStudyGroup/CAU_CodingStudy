#include <iostream>
using namespace std;

int main()
{
#include <iostream>
#include <string.h>
	using namespace std;

	int main()
	{
		int arr[26] = { 0 };
		char str[101];
		cin >> str;
		int len = strlen(str), tmp;
		for (int i = 0; i < len; i++)
		{
			tmp = str[i];
			arr[tmp - 97]++;
		}
		for (int i = 0; i < 26; i++)
			cout << arr[i] << " ";
		return 0;
	}
}