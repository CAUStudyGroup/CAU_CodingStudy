#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(){
    list<int> li;
    int n;
    int temp;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d", &temp);
        li.push_back(temp);
    }
    li.sort();
    
    for(int item : li){
        printf("%d\n",item);
    }
    
    
    return 0;
}
