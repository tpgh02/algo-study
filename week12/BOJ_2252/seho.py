import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())

graph = [[] for _ in range(n)]
topology = [0 for _ in range(n)]

for _ in range(m):
    a, b = map(int, input().split())

    graph[a-1].append(b-1)
    topology[b-1] += 1

dq = deque([])
order = []
for i in range(n):
    if topology[i] == 0 :
        dq.append(i)

while len(dq) != 0 :
    node = dq.popleft()
    order.append(node+1)
    for i in graph[node]:
        topology[i]-=1

        if topology[i] == 0:
            dq.append(i)

print(*order)