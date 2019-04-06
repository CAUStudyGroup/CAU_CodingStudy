#include <iostream>
#include <algorithm>
using namespace std;

int two(long long a)
{
	long long count = 0;
	for (long long i = 2; i <= a; i *= 2)
	{
		count += (a/i);
	}
	return count;
}

int five(long long b)
{
	long long count = 0;
	for (long long i = 1; i <= b; i *= 5)
		count += (b/i);
	return count;
}

int main()
{
	long long n, m;
	cin >> n >> m;
	
	long long realtwo = two(n) - two(m) - two(n - m);
	long long realfive = five(n) - five(m) - five(n - m);
	cout << min(realtwo, realfive) << '\n';
	return 0;
}