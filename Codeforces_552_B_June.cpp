#include <iostream>
#include <vector>
#define SWAP(a, b)((a) != (b) ? ((a) ^= (b), (b) ^= (a), (a) ^= (b)) : ((a), (b)))
#define MAX(a, b)((a) > (b) ? (a) : (b))
using namespace std;
int memo[101];
int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, input, sum = 0, avg, D = -1;
	vector<int> an;
	cin >> n;
	while (n--) {
		cin >> input;
		memo[input]++;
	}
	for (int i = 1; i <= 100; i++) {
			if (memo[i] != 0)
				an.push_back(i);
	}
	//an is sorted automatically
	if (an.size() == 1 || an.size() > 3) {
		D = -1;
	}
	else if(an.size() == 2){
		for (auto s : an) {
			sum += s;
		}
		avg = sum / an.size(); //D <= avg		
		//Brute-force
		for (int i = 0; i <= avg; i++) {
			if ((an[0] + i == an[1] - i) || (an[0] + i == an[1]) || (an[0] == an[1]-i)) {
				D = i;
				break;
			}			
		}
	}
	else if (an.size() == 3) {
		for (auto s : an) {
			sum += s;
		}
		avg = sum / an.size(); //D <= avg
		//Brute-force
		for (int i = 0; i <= avg; i++) {
			if ((an[0] + i == an[1]) && (an[1] == an[2] - i)) {
				D = i;
				break;
			}
		}
	}
	cout << D;
	return 0;
} //Wrong on test 5