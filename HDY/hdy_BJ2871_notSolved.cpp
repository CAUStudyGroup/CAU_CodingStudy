/*
���� 2871��
����� ���ڸ� �����Ҷ� a�� 2�������� 
������ a�� ������ ������ a�� �������� ���� ����� �޶��� 
�̸� ����ؾ���
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
		int sg, hw; //�ƽ�Ű�ڵ�� ��

		//����� �� ������ ���ڸ� ����´�
		sg = (int)str.back();
		str = str.substr(0, str.length() - 1);
		alphabet[sg - 97]--;

		//����� ���������� �ռ��� ���ڸ� �����´�
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

		if (sg < hw) {//����� ���������� �ռ����� ��
			status = false;
			break;
		}
		else {//����� �ܾ ���� �߰�
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