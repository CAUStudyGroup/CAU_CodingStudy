#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int indeg[32002];
vector<int> adj[32002];
//min-heap
priority_queue<int,vector<int>,greater<int>> topologyQue;


int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i<M; i++){
        int from;
        int to;
        scanf("%d %d",&from, &to);
        adj[from].push_back(to);
        indeg[to]++;
    }
    
    //처음 0인거 집어넣기
    for(int i = 1; i <= N; i++){
        if(indeg[i] == 0){
            topologyQue.push(i);
        }
    }
    
    while(!topologyQue.empty()){
        int temp = topologyQue.top();
        topologyQue.pop();
        indeg[temp]--;
        printf("%d ",temp);
        
        for(int next : adj[temp]){
            indeg[next]--;
            if(indeg[next] == 0){
                topologyQue.push(next);
            }
        }
    }
    
    
    return 0;
}
