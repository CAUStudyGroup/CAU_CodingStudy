#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int num1, num2;
	string str1, str2;
	cin >> num1 >> num2;
	str1 = to_string(num1);
	str2 = to_string(num2);
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	num1 = stoi(str1);
	num2 = stoi(str2);
	num1 = num1 < num2 ? num2 : num1;
	cout << num1;
	return 0;
}