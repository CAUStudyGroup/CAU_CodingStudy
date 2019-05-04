#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int result[26] = { 0, };
	string eng;
	cin >> eng;
	for (int i = 0; i < eng.size(); i++) {
		result[eng[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << result[i] << " ";
	}
}
