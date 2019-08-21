'''
정답!
for greedy

using greedy And sorted

'''

import sys

n=int(input())
exp=[]
for i in range(n):
    exp.append(int(sys.stdin.readline()))
angry=0
exp.sort()
#가장 낮은 등수부터 차례로!
for i in range(n,0,-1):
    angry+=abs(i-exp.pop())
print(angry)