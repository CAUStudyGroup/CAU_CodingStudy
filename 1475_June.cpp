#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N, ninesixCount=0, _maxCount=-1, i;
	int plastic[9] = { 0 };
	cin >> N;
	do {
		if (N % 10 == 9 || N % 10 == 6) ninesixCount++;
		else plastic[N % 10]++;		
	} while (N /= 10);
	plastic[6] = ceil((double)ninesixCount / (double)2);
	for (i = 0; i < 9; i++) {
		_maxCount = _maxCount <= plastic[i] ? plastic[i] : _maxCount;
	}
	cout << _maxCount;
	return 0;
}