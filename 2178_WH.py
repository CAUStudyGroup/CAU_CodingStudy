#2178 -BFS .. DFS는 공부 후 차후 추가 예정
import sys

def main():
    x, y = map(int, sys.stdin.readline().split())
    data = [[0] * y for _ in range(x)]
    for i in range(x):
        temp = sys.stdin.readline()
        for j in range(y):
            data[i][j] = int(temp[j])
    # print(data)
    visit = [[0] * y for _ in range(x)]

    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    arr = []
    arr.append((0, 0))
    visit[0][0] = 1
    while arr:
        a, b = arr.pop(0)
        if a == x - 1 and b == y - 1:
            print(visit[a][b])
            sys.exit()
    for i in range(4):
        ax = a + dx[i]
        ay = b + dy[i]
        if ax >= 0 and ax < x and ay >= 0 and ay < y:
            if visit[ax][ay] == 0 and data[ax][ay] == 1:
                visit[ax][ay] = visit[a][b] + 1
                arr.append((ax, ay))


if __name__ == '__main__':
    main()