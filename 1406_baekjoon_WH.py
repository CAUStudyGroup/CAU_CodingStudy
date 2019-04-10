#1406_에디터
import sys
right = []
 
left = list(sys.stdin.readline().strip())
num = int(sys.stdin.readline())

for i in range(num):
    line = sys.stdin.readline().split()
    if line[0]=='L':
        if left:
            right.append(left.pop())
    elif line[0]=='P':
        left.append(line[1])
    elif line[0]=='D':
        if right:
            left.append(right.pop())
    elif line[0]=='B':
        if left:
            left.pop()          
right.reverse()
sys.stdout.write(''.join(left) + ''.join(right))

