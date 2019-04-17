#include <iostream>
#include <vector>
#include <algorithm>
#define SWAP(a, b)((a) != (b) ? ((a) ^= (b), (b) ^= (a), (a) ^= (b)) : ((a), (b)))
#define MAX(a, b)((a) > (b) ? (a) : (b))
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long foods[3];
	long long dayCnt = 0;
	vector<long long>v_dayCnt;
	for (int i = 0; i < 3; i++) {
		cin >> foods[i];
	}
	for (int j = 0; j < 7; j++) {
		for (int i = j; i < 7; i++) {
			dayCnt++;
			switch (i)
			{
			case 0: case 3: case 6:
				foods[0]--;
				break;
			case 1: case 5:
				foods[1]--;
				break;
			case 2: case 4:
				foods[2]--;
				break;
			}
			if (foods[0] == 0 || foods[1] == 0 || foods[2] == 0) {
				break;
			}
			else if(i == 6){
				i = j;
			}
		}
		v_dayCnt.push_back(dayCnt);
		dayCnt = 0;
	}
	sort(v_dayCnt.begin(), v_dayCnt.end());
	cout << v_dayCnt[v_dayCnt.size()-1];
	return 0;
}