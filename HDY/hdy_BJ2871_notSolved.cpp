/*
백준 2871번
희원이 글자를 선택할때 a가 2개있으면 
앞쪽의 a를 택할지 뒤쪽의 a를 택할지에 따라 결과가 달라짐 
이를 고려해야함
*/
#include <iostream>
#include <cmath>
#include <queue>
#include <string>
using namespace std;
priority_queue<long long> pq;
int main(){
	
	int N;
	int alphabet[26] = { 0, };
	string str, HW = "";

	cin >> N;
	cin >> str;

	for (int i = 0; i < N; i++) {
		alphabet[str.at(i) - 97]++;;
	}

	N = N / 2;

	bool status = true;
	int alphabet_ascii_Idx = 97;
	while (status && N--) {
		int sg, hw; //아스키코드로 비교

		//상근은 맨 오른쪽 글자를 갖고온다
		sg = (int)str.back();
		str = str.substr(0, str.length() - 1);
		alphabet[sg - 97]--;

		//희원은 사전적으로 앞서는 글자를 가져온다
		for (int i = 0; i < 26; i++) {
			if (alphabet[i] > 0) {
				alphabet[i]--;

				hw = i + 97;
			}
		}
		while (alphabet[alphabet_ascii_Idx - 97] == 0) { 
			alphabet_ascii_Idx++;
		}
		hw = alphabet_ascii_Idx;
		alphabet[alphabet_ascii_Idx - 97]--;

		if (sg < hw) {//희원이 사전적으로 앞서는지 비교
			status = false;
			break;
		}
		else {//희원의 단어에 글자 추가
			char ch = (char)hw;
			HW = HW + ch;
		}
	}

	if (status == false) {
		cout << "NE";
	}
	else {
		cout << "DA\n" << HW;
	}
}