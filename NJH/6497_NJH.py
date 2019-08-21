'''
최소비용신장트리 for 전력난

==>절약할 수 있는 최대 액수
최대 절약 액수=sum of all weight-최대 액수

'''
#N=집의수
#M=길의수
#마지막 0 0 은 왜있는지 모르겠음



import sys
from operator import itemgetter,attrgetter

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

while True:
    hap=sys.stdin.readline()
    if hap=="0 0\n":
        break
    hap=tuple(hap.split(' '))
    N=int(hap[0])
    M=int(hap[1])
    road=[tuple(map(int,sys.stdin.readline().split(' '))) for _ in range(M)]

    totalWeight=0
    for i in range(M):
        totalWeight+=road[i][2]

    #최소비용 신장트리만들기
    road.sort(key=itemgetter(2))

    parent=[ i for i in range(N)] #노드의 갯수만큼의 부모를 만들고
    costSum=0
    for i in range(M): #집의 번호가 아에 인덱스로 되어있는 것을 확인 가능
        if Find(parent,road[i][0],road[i][1])==0: #만약 같은 부모가 아니라면
            costSum+=road[i][2]
            UnionParent(parent,road[i][0],road[i][1]) #[주의]비용 계산후에 합쳐주기!

    print(totalWeight-costSum)
