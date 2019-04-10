#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

char a[101];
int v1[26];
int len;
int main() {
	cin.getline(a, 101);
	len = strlen(a);

	//vector <int> v1(n,0);

	for (int i = 0; i <= len; i++) {
		//a: 97
		int temp = a[i] - 97;
		v1[temp]++;
	}
	for (int i = 0; i < 26; i++) {
		cout << v1[i] << " ";
	}
	cout << '\n';
	return 0;
}