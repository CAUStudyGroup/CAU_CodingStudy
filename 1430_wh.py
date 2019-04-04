Python 3.6.5 (v3.6.5:f59c0932b4, Mar 28 2018, 16:07:46) [MSC v.1900 32 bit (Intel)] on win32
Type "copyright", "credits" or "license()" for more information.
>>> num = []
n=int(input())
for i in range(n):
    num.append(int(input().split()))
    
m=int(input())
test=[]
for i in range(m):
    test.append(int(input().split()))
    
for i in test:
  for j in num:
    if test[i] == num[j]:
      print(0)
    else:
      print(1)
    
    
