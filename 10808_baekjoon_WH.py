#10808_알파벳개수
import string
n=input()

for i in [c for c in string.ascii_lowercase]:
  print(n.count(i), end=' ')

