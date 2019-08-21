'''
[정답]
네트워크 연결
->전체 비용이 최소화 되어야하니까: 최소신장트리사용
방법1.크루스칼 알고리즘 사용(유니파인드 필요)
방법2.프림 알고리즘 사용

여기서는 크루스칼 알고리즘을 사용해서 써보도록 해보자.
'''
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

#기본 정보 받아오기
N=int(sys.stdin.readline()) #컴퓨터의수
M=int(sys.stdin.readline()) #연결할 수 있는 선의 수

#cost정보를 받아오기(간선 생성하는 대신해 해당 것으로 할 수 있다.
vector=[]
for i in range(M):
    vector.append(list(map(int, input().rstrip().split())))
#간선 오름차순 성렬(작->큰):왜냐하면 크루스칼 알고리즘의 핵심은 작은 간선 cost에대해서 연결해주는 거니까!
vector=sorted(vector,key=itemgetter(2)) #2번째 인덱스(cost를 의미)를 기준으로 sort를 해주어라

#부모노드 테이블
settable=[]
for i in range(N): #노드의 갯수==컴퓨터의 수만큼 생성됨
    settable.append(i)
costSum=0 #최소비용이 그래서 총 얼마인지에 대해서

#간선을 연결할때, 주의해야할 점은 절때 Cycle을 만들지 않아야한다는 것이다.
for i in range(M): #간선의 갯수==연결할 수 있는 선의 수
    #[주의]인덱스로 접근을 하기 때문에 -1을 해준것이다.
    if(Find(settable,vector[i][0]-1,vector[i][1]-1)==0):#같은 부모가 아니라면
        costSum+=vector[i][2] #cost부분을 추가하고
        UnionParent(settable,vector[i][0]-1,vector[i][1]-1) #하나의 Set으로 만들어준다.


#간선의 숫자만큼을 살핀다.(만약에 UnionParent가 완성이 되었다면, if문에 의해서 걸러질 것이다.
print(costSum)