import sys
import heapq
input = sys.stdin.readline

t = int(input())
hq = []
for _ in range(t):
    n = int(input())
    if n > 0 :
        heapq.heappush(hq, (n, n))
    elif n < 0 :
        heapq.heappush(hq, (-n, n))
    else :
        if len(hq) == 0 :
            print(0)
        else :
            print(heapq.heappop(hq)[1])