#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	string XXXX = "XXXX";
	string XX = "XX";
	string AAAA = "AAAA";
	string BB = "BB";

	cin >> str;
	while (str.find(XXXX)!=string::npos) {
		str.replace(str.find(XXXX), 4, AAAA);
		cout << str << endl;
	}

	while (str.find(XX) != string::npos) {
		str.replace(str.find(XX), 2, BB);
		cout << str << endl;
	}

	if (str.find('X') != string::npos) {
		cout << -1;
	}
	else {
		cout << str;
	}
	cout << "finish" << endl;



	return 0;
}