#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
enum DAYS{
	MON,TUE,WED,THU,FRI,SAT,SUN
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int foods[3];
	int tmpStoredFoods[3];
	int today;
	int dayCnt = 0;
	int itDay;
	int firstDay, lastDay;
	int maxFood=-1, maxIdx;
	bool isTripEnd = false;
	vector<int>v_dayCnt;
	for (int i = 0; i < 3; i++) {
		cin >> foods[i];
		tmpStoredFoods[i] = foods[i];
		if (maxFood <= foods[i]) {
			maxFood = foods[i];
			maxIdx = i;
		}
	}
	switch (maxIdx)
	{
	case 0://Fish
		firstDay = FRI;
		lastDay = SUN;
		break;
	case 1://Rabbit
		firstDay = MON;
		lastDay = WED;
		break;
	case 2://Chicken
		firstDay = TUE;
		lastDay = THU;
		break;
	}
	for (itDay = firstDay; itDay <= lastDay; itDay++) {
		isTripEnd = false;
		dayCnt = itDay;
		while (true) {
			today = dayCnt % 7;
			switch (today)
			{
			case MON: case THU: case SUN:
				if (0 != foods[0])
					foods[0]--;
				else
					isTripEnd = true;
				break;
			case TUE: case SAT:
				if (0 != foods[1])
					foods[1]--;
				else
					isTripEnd = true;
				break;
			case WED: case FRI:
				if (0 != foods[2])
					foods[2]--;
				else
					isTripEnd = true;
				break;
			}
			if (isTripEnd) break;
			else dayCnt++;
		}
		dayCnt -= itDay;
		v_dayCnt.push_back(dayCnt);
		std::copy(std::begin(tmpStoredFoods), std::end(tmpStoredFoods), std::begin(foods));
	}
	sort(v_dayCnt.begin(), v_dayCnt.end());
	cout << v_dayCnt[v_dayCnt.size() - 1];
	return 0;
}