'''
for greedy algorithm

using 태스크 스케쥴링
'''

n = int(input()) #몇명인지
t = list(map(int, input().rstrip().split())) #시간 소요
t.sort()

hap=0
for i in range(n):
    if i!=0:
        hap+=sum(t[0:(i+1)])
    else:
        hap+=t[0]

print(hap)