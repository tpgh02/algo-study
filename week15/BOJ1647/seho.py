import sys
import heapq
input = sys.stdin.readline

n, m = map(int, input().split())
path = []
parent = [i for i in range(n+1)]
for _ in range(m):
    a, b, c = map(int, input().split())
    heapq.heappush(path, [c, a, b])

def find(x):
    if x == parent[x] : return parent[x]

    parent[x] = find(parent[x])
    return parent[x]

def union(a, b):
    a = find(a)
    b = find(b)

    if a < b : parent[b] = a
    else : parent[a] = b

ans = 0
while len(path) != 0 :
    tmp = heapq.heappop(path)
    c = tmp[0]
    a = tmp[1]
    b = tmp[2]

    if find(a) != find(b):
        union(a, b)
        ans += c
        end = c

print(ans-end)