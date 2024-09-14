import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
nums = [[] for _ in range(n)]
dist = [[0 for _ in range(n)] for _ in range(n)]

def bfs(num):
    visited = [False for _ in range(n)]
    visited[num] = True
    dq = deque([])
    dq.append(num)

    while len(dq) != 0 :
        a = dq.popleft()

        li = nums[a]
        for b in li:
            if not visited[b]:
                dist[num][b] = dist[num][a] + 1
                dq.append(b)
                visited[b] = True


for _ in range(m):
    a, b = map(int, input().split())
    nums[a-1].append(b-1)
    nums[b-1].append(a-1)


for i in range(n):
    bfs(i)
    dist[i] = sum(dist[i])

print(dist.index(min(dist))+1)