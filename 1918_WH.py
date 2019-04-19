#1918 -- stack개념 다시 보기!
d_or= {"-": 1, "+": 1, "*": 2, "/": 2, "(": 0}

e= input()
stack = []

for c in e:
    if c in d_or.keys():
        if not stack or c == '(':
            stack.append(c)
        else:
            while stack and d_or[c] <= d_or[stack[-1]]:
                print(stack.pop(), end='')
            stack.append(c)
    elif c == ')':
        while stack and stack[-1] != '(':
            print(stack.pop(), end='')
        if stack and stack[-1] == '(':
            stack.pop()
    else:
        print(c, end='')

while stack:
    print(stack.pop(), end='')
