import sys
import heapq
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    n = int(input())
    nums = []
    for _ in range(n//10 + 1) :
        nums += list(map(int, input().split()))

    li = []
    ans = []
    for i in range(0, n, 2):
        li = nums[:i+1]
        heapq.heapify(li)
        ans.append(heapq.nsmallest(i+1, li)[i//2])
    l = len(ans)
    print(l)
    for i in range(l//10+1):
        if i == l//10 :
            print(*ans[i*10:l])
        else :
            print(*ans[10 * i:10*(i+1)])