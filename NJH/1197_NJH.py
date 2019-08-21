'''
최소 스패닝 트리
->가중치합을 최소로 만들되 하나로 어디든지 갈 수 있는 간선을 유지시키기(단, 사이클은 존재하면안됨)

이번에는 프림 알고리즘을 이용해서 구현해보자.
프림알고리즘:정점 하나를 기준으로 연결된 다른 점으로 갈때 가장 적은 비용이 드는 것
->신장 트리 집합을 단계적으로 확장
->bfs&priority Queue이용
(따로, 사이클 검사를 하지는 않지만, 방문한 노드에 대해서 방문하지 않는 다는 것을 원칙으로 함)

#목표 단순 가중치 출력
'''

import heapq
#9999999999

# def prim(graph,N):
#     visited=[False]*N
#     pq=[]
#     start=0
#     sumCost = 0
#     for next in range(1,N):#다음 갈 곳 찾기
#         if graph[start][next]!=9999999999 and visited[next]==False:
#             heapq.heappush(pq,(graph[start][next],next))
#
#     while len(pq)!=0:
#         weight,curNode=heapq.heappop(pq) #가장 작은 weight를 갖는 값임에 틀림 없음
#         #현재 노드를 방문했다면 검사하지 않음
#         if visited[curNode]==True: continue
#         #미방문지를 방문지 체크하고
#         visited[curNode]=True
#         sumCost+=weight
#
#         for next in range(1, N):  # 다음 갈 곳 찾기
#             if graph[curNode][next] != 9999999999 and visited[next] == False:
#                 heapq.heappush(pq, (graph[curNode][next], next))
#     return sumCost
# N,M=tuple(map(int,sys.stdin.readline().split(' '))) #N=정점의 갯수 M=간선의 갯수
# #배열 그래프 생성하기
# graph=[[9999999999]*N for _ in range(N)] #N*N #sys.inf나 ,math.inf안쓰고 그냥 절대 올수 없는 값을 넣음
# for _ in range(M):
#     u,v,w=tuple(map(int, sys.stdin.readline().split(' ')))
#     graph[u-1][v-1]=w
#     graph[v-1][u-1]=w
#
# print(prim(graph,N))



##프림으로 했을시 메모리 에러떠서 그냥 크루스칼을 적용시키도록 하겠다.
import sys
from operator import itemgetter
#Union-find
def GetParent(set,x): #1. 부모노드를 가져와서
    if set[x]==x: return x #자기 자신과 같아질때까지 계속 호출을 시키자.
    set[x] = GetParent(set, set[x])
    return set[x]

def UnionParent(parent,a,b):#2. 부모노드를 합쳐줌
    #각각의 부모 노드를 얻음
    a=GetParent(parent,a)
    b=GetParent(parent,b)
    #더 작은 부모 노드 값으로 통합(인덱스가 더 작은 것 기준으로 통합하자.
    if a<b: parent[b]=a
    else: parent[a]=b

def Find(parent,a,b): #3. 같은 부모인가를 판단한다.
    a = GetParent(parent, a)
    b = GetParent(parent, b)
    #같다면 1반환 아니면 반환
    if a==b: return 1
    return 0

N,M=tuple(map(int,sys.stdin.readline().split(' '))) #N=정점의 갯수 M=간선의 갯수
road=[tuple(map(int,sys.stdin.readline().split(' '))) for _ in range(M)]
#최소비용 신장트리만들기
road.sort(key=itemgetter(2))
parent=[ i for i in range(N)] #노드의 갯수만큼의 부모를 만들고
costSum=0
for i in range(M):
    if Find(parent,road[i][0]-1,road[i][1]-1)==0: #만약 같은 부모가 아니라면
        costSum+=road[i][2]
        UnionParent(parent,road[i][0]-1,road[i][1]-1) #[주의]비용 계산후에 합쳐주기!

print(costSum)