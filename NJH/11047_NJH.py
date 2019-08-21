'''
for greedy algorithm

using 거스름돈문제
'''
#입출력
n,hap = list(map(int, input().rstrip().split())) #시간 소요
coin=[]
for i in range(n):
    coin.append(int(input())) #오름차순으로 되어있는데
coin.sort(reverse=True)

#내림차순으로 정렬된 coin
how_many=[]
for c in coin:
    how_many.append(hap//c) #몫
    hap=hap%c #나머지

print(sum(how_many))
