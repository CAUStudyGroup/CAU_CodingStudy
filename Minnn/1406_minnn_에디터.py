a=list(input())
n=int(input())
cursor=len(a)

for i in range(n):
    b=input()
    if 'L' in b:
        if cursor==0:
            continue
        cursor-=1
    if 'D' in b:
        if cursor==len(a)+1:
            continue
        cursor+=1
    if 'B' in b:
        if cursor==0:
            continue
        a.pop(cursor-1)
        cursor-=1
    if 'P' in b:
        a.insert(cursor,b[2])
        cursor+=1
    #print(a,cursor)

print(''.join(a))
