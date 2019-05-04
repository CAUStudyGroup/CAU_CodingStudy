#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string test;
char result[888];
int main(){
	int n;
	cin>>n;
	
	while(n--){
		cin >> test;
		for(int i=0; i<test.size(); i++)
			result[i] = test[i];
		
		sort(result,result+test.size());
		int flag = 1;
		for(int i=1; i<test.size(); i++){
			if(result[i] != result[i-1]+1)
				flag = 0;
		}
		if(flag == 0)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
} 