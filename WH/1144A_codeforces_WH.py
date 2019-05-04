#1144 A. Diverse Strings

for _ in range(int(input())):
    s = sorted(input())
    if len(set((*s, ))) == len(s) and ord(s[-1]) - ord(s[0]) + 1 == len(s):
        print("Yes")
    else:
        print("No")

