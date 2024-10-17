import sys
import heapq
input = sys.stdin.readline

n, m = map(int, input().split())
ind = [0 for _ in range(n)]
order = [[] for _ in range(n)]
hq = []
for _ in range(m):
    a,b = map(int, input().split())
    ind[b-1] += 1
    order[a-1].append(b-1)

for i in range(n):
    if ind[i] == 0 :
        heapq.heappush(hq, i)

ans = []
while len(hq) != 0 :
    idx = heapq.heappop(hq)

    for i in order[idx]:
        ind[i] -= 1
        if ind[i] == 0:
            heapq.heappush(hq, i)

    ans.append(idx+1)

print(*ans)