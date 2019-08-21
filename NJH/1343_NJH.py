'''
정답!
for greedy

'''

x=input()
y=list(x)
xn = -1  # x의 숫자(연속적으로 나오는 x의 숫자가 몇개였는지)
xs = -1
flag = 0  # 0은 이전에 x가 없었다는 것 1은 이전에 x가 있었다는 것
q=0 #몫
res=0
for i in range(len(x)):
    #'.'이 나오는 경우
    if x[i]=='.' and flag==0: #시작부터 .이거나 지속적으로 .이 나오는 경우
        continue
    if x[i]=='.' and flag==1:
        #print("fist_change!!::",xn,"<",xs,">",xn // 4,y)
        if xn%2==1: #홀수
            res=-1
            break
        else:#2이상의 짝수
            flag=0
            q=xn//4
            for j in range(xs,xs+(4*q),1):
                y[j]='A'
            if xn%4!=0:
                y[xs+4*q]='B'
                y[xs+4*q+1] = 'B'
    #'X'가 나오는 경우
    if x[i]=='X' and flag==0:#처음으로 X가 나오는 경우
        xn=1
        xs=i
        flag=1
    elif x[i]=='X' and flag==1:#두번째로 X가 나오는 경우
        xn+=1

#마지막 요건 채워주기
if flag==1:
    #print("second_change!:",xn,"<",xs,">",xn // 4,y)
    if xn % 2 == 1:  # 홀수
        res = -1
    else:  # 2이상의 짝수
        flag = 0
        q = xn // 4
        for j in range(xs, xs + 4 * q):
            y[j] = 'A'
        if xn % 4 != 0:
            y[xs + 4 * q] = 'B'
            y[xs + 4 * q + 1] = 'B'


if res==-1:
    print("-1")
else:
    print(''.join(y))


'''

for greedy

우선적으로 4가 넘어가면

x=input()
y=x #shadow copy(굳이 복사할 필요없음;가독성을 위해서 이렇게 표시함)

def result(x,y):
    xn = -1  # x의 숫자(연속적으로 나오는 x의 숫자가 몇개였는지)
    xs = -1
    flag = 0  # 0은 이전에 x가 없었다는 것 1은 이전에 x가 있었다는 것
    q=0 #몫
    for i in range(len(x)):
        #'.'이 나오는 경우
        if x[i]=='.' and flag==0: #시작부터 .이거나 지속적으로 .이 나오는 경우
            continue
        if x[i]=='.' and flag==1:
            if xn%2==1: #홀수
                return -1
            else:#2이상의 짝수
                flag=0
                q=xn//4
                for j in range(xs,xs+4*q+1):
                    y[j]='A'
                if xn%4!=0:
                    y[xs+4*q+1]='B'
                    y[xs+4*q+2] = 'B'
        #'X'가 나오는 경우
        if x[i]=='X' and flag==0:#처음으로 X가 나오는 경우
            xn=1
            xs=i
            flag=1
        if x[i]=='X' and flag==1:#두번째로 X가 나오는 경우
            xn+=1

if result(x,y)==-1:
    print("-1")
else:
    print(y)


'''