#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;

	int arr[5000];
	for (int i = 0; i < N; i++)
		arr[i] = i+1;

	cout << "<";
	int many = N;
	int idx = 0;
	int adder = 0;
	while (many>0) {
		
		if (arr[idx% N] > 0) {
			if (adder == K-1 ) {
				if(many==1)
					cout << arr[idx  % N];
				else
					cout << arr[idx  % N] << ", ";
				arr[idx  % N] = -1;
				many--;
				adder = 0;
			}
			else {
				adder++;
			}
		}
		idx++;
	}
	
	cout << ">";
}