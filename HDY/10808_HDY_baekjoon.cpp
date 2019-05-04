#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	cin >> str;

	int alpha[26] = { 0, };
	for (int i = 0; i < str.length(); i++) {
		alpha[(int)str[i] - 97]++;
	}
	for (int i = 0; i < 26; i++)
		cout << alpha[i] << " ";

}