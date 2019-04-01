#include <iostream>
#include <string>
using namespace std;
int main() {
	int num,sum=0,cnt=0;
	int stor[10] = { 0, };
	cin >> num;
	
	//숫자를 잘라서 저장
	while (num>=1) {
		stor[num % 10]++;
		sum++;
		num = (int)(num / 10);
	}

	//6과 9를 같은것으로 취급
	if ((stor[6] + stor[9]) % 2 == 1)
		stor[6] = (int)(stor[6] + stor[9]) / 2 + 1;
	else
		stor[6] = (int)(stor[6] + stor[9]) / 2;
	stor[9] = 0;

	//세트 갯수 세기
	while (true) {
		bool status = true;
		for (int i = 0; i < 10; i++) {
			stor[i]--;
			if (stor[i] > 0) status = false;
		}

		cnt++;
		if (status) {
			break;
		}		
	}
	cout << cnt;;
}