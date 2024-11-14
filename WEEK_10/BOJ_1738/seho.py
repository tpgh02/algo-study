import sys

input = sys.stdin.readline

n, m = map(int, input().split())

graph = []
MIN = -sys.maxsize
for _ in range(m):
    a, b, c = map(int, input().split())

    graph.append((a-1, b-1, c))

dist = [MIN for _ in range(n)]
dist[0] = 0
channel = ['' for _ in range(n)]
channel[0] = '1 '

for i in range(1001):
    for curNode, nextNode, cost in graph:
        if dist[curNode] != MIN and dist[curNode] + cost > dist[nextNode]:
            dist[nextNode] = dist[curNode] + cost
            channel[nextNode] = channel[curNode] + str(nextNode+1) + " "

            if i > n-1 and nextNode == n-1:
                print(-1)
                exit()

print(channel[-1])