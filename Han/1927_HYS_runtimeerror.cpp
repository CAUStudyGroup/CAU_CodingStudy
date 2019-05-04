#include <iostream>
using namespace std;

//첫칸 비우면 왼쪽자식: 2n 오른쪽 자식 2n+1 부모는 n/2
int arr[100002];
int currIndex = 1;


void init(){
    for(int i=0;i<100002;i++){
        arr[i] = 0;
    }
}

//인덱스 i부터 재귀적으로 부모노드와 스왑
void compareParent(int i){
    if(i == 100002){
        //cout<<"isFull";
        return;
    }
    if( i == 0 ){
        return;
    }
    if(arr[i/2] > arr[i]){
        int temp = arr[i];
        arr[i] = arr[i/2];
        arr[i/2] = temp;
    }
    compareParent(i/2);
    return;
}

void compareChildren(int i){
    int smallChildIndex = 0;
    
    if(arr[2*i] == 0 && arr[2*i+1] == 0){
        return;
    }
    
    if(arr[2*i] != 0 && arr[2*i+1] != 0){
        if(arr[2*i] > arr[2*i+1]){
            smallChildIndex = 2*i+1;
        }
        else{
            smallChildIndex = 2*i;
        }
    }
    else if(arr[2*i] == 0 && arr[2*i+1] != 0){
        smallChildIndex = 2*i+1;
    }
    else if(arr[2*i] != 0 && arr[2*i+1] == 0){
        smallChildIndex = 2*i;
    }
    
    if(arr[smallChildIndex] < arr[i]){
        int temp = arr[smallChildIndex];
        arr[smallChildIndex] = arr[i];
        arr[i] = temp;
        compareChildren(smallChildIndex);
    }
    return;
}

void insertHeap(int n){
    if(currIndex == 100001){
        //cout<<"isFull";
        return;
    }
    arr[currIndex] = n;
    compareParent(currIndex);
    //cout << arr[currIndex] << "is in !";
    currIndex++;
    
}

void deleteHeap(){
    if(currIndex == 1){
        printf("0\n");
        return;
    }
    printf("%d\n",arr[1]);
    arr[1] = arr[currIndex-1];
    arr[currIndex-1] = 0;
    currIndex--;
    
    compareChildren(1);
    
}


int main() {
    
    init();
    int n;
    int c;
    scanf("%d",&n);
    for(int i = 0; i < n ; i++){
        scanf("%d",&c);
        if(c == 0){
            deleteHeap();
        }
        else{
            insertHeap(c);
        }
    }
    
    return 0;
}
