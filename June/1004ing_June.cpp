#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
typedef pair<int, int> pi;
typedef tuple<pi, int> ti;
//1004 little Prince
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, n, i, j, x1, y1, x2, y2, cx, cy, r, inOutNum;
	vector<vector<ti>> v_vTuple;
	cin >> T;
	for(i=0; i<T; i++) {
		inOutNum = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		pi startP = make_pair(x1, y1);
		pi endP = make_pair(x2, y2);
		cin >> n;
		vector<ti> vTuple;
		v_vTuple.push_back(vTuple);
		for(j=0; j<n; j++) {
			cin >> cx >> cy >> r;
			pi center = make_pair(cx, cy);
			ti planet = make_tuple(center, r);
			v_vTuple[i].push_back(planet);
		}
		cout << inOutNum << '\n';
	}
	return 0;
}