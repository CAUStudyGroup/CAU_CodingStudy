#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
enum DAYS{
	SUN,MON,TUE,WED,THU,FRI,SAT
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int foods[3];
	int originalRestFoods[3];
	int restDays = 0, cycleDay;
	vector<int> arr_RestDays;
	int itDay;
	bool isTripEnd = false;
	for (int i = 0; i < 3; i++) {
		cin >> foods[i];
	}
	int m = min(foods[0] / 3, min(foods[1] / 2, foods[2] / 2));
	int baseDays = m * 7;

	foods[0] = foods[0] - m * 3;
	foods[1] = foods[1] - m * 2;
	foods[2] = foods[2] - m * 2;
	if (foods[0] > 3) foods[0] = 3;
	if (foods[1] > 2) foods[1] = 2;
	if (foods[2] > 2) foods[2] = 2;
	std::copy(std::begin(foods), std::end(foods), std::begin(originalRestFoods));
	for (itDay = SUN; itDay <= SAT; itDay++) {
		isTripEnd = false;
		restDays = itDay;
		while(true) {
			cycleDay = restDays % 7;
			switch (cycleDay)
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
			else restDays++;
		}
		restDays -= itDay;
		arr_RestDays.push_back(restDays);
		std::copy(std::begin(originalRestFoods), std::end(originalRestFoods), std::begin(foods));
	}
	sort(arr_RestDays.begin(), arr_RestDays.end());
	std::cout << baseDays + arr_RestDays[arr_RestDays.size()-1];
	return 0;
}