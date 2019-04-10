#include <iostream>
using namespace std;
#define MOD 10007

int main()
{
	int n; 
	cin >> n;
	 
	long long arr[1002] = { 0 };
	arr[1] = 1;
	arr[2] = 2;
	for(int i = 3; i <= n; i++)
	{
		arr[i] = arr[i - 1]%MOD	+ arr[i - 2]%MOD;
	}
	cout << arr[n]%MOD << '\n';
	return 0;
}