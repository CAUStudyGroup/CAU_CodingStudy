#include <iostream>
using namespace std;

int hist_arr[10000001];

int main(){
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i = 0;i<n;i++)
	{
		cin >> arr[i];
	}
	
	int m;
	cin >> m;
	int* hist = new int[m];
	for(int i = 0;i<m;i++)
	{
		cin >> hist[i];
	}
	
	for(int i = 0;i<n;i++)
	{
		hist_arr[arr[i]] = 1;
	}
	
	for(int i = 0; i<m; i++){
		if(hist_arr[hist[i]] == 1){
			cout << 1 << " ";
		}
		else{
			cout << 0 << " ";
		}
	}
}
