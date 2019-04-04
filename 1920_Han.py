import sys
sys.setrecursionlimit(10000)

def BS(arr, start, end, search):

    if start > end:
        return None
       
    mid = (start + end) // 2
    #print("mid: %d  %d -> %d" %(mid,start,end)) 
    if arr[mid] == search:
        return mid
        
    elif arr[mid] > search:
        end = mid - 1

    else:
        start = mid + 1
  
    return BS(arr,start,end,search)
      

a = int(sys.stdin.readline())
list1 = list(map(int, sys.stdin.readline().split()))
list1 = sorted(list1)

b = int(sys.stdin.readline())
list2 = list(map(int,sys.stdin.readline().split()))


for i in list2:
    res = BS(list1,0,a-1,i)
    if res != None:
        print("1")
    else:
        print("0")