import sys
import heapq

input = sys.stdin.readline

n, m = map(int, input().split())

graph = [[] for _ in range(n+1)]
cost = [sys.maxsize for _ in range(n+1)]
ansEdge = [[] for _ in range(n+1)]
visited = [False for _ in range(n+1)]

for _ in range(m):
    a,b,c = map(int, input().split())

    graph[a].append([b, c])
    graph[b].append([a, c])

q = []
heapq.heappush(q, (0, 1, 1))
while len(q) != 0 :
    c, a, b = heapq.heappop(q)

    for li in graph[b] :
        dest, co = li

        if cost[dest] > co + c :
            cost[dest] = co + c
            ansEdge[dest] = [b, dest]
            heapq.heappush(q, (cost[dest], b, dest))

print(n-1)
for i in range(2, len(ansEdge)):
    print(*ansEdge[i])