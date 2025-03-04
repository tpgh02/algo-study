import sys
from queue import PriorityQueue
input = sys.stdin.readline

n = int(input())
m = int(input())

minCost = [sys.maxsize for _ in range(n)]
graph = [[] for _ in range(n)]

for _ in range(m):
    a, b, c = map(int, input().split())

    graph[a-1].append([b-1, c])

start, end = map(int, input().split())

pq = PriorityQueue()
pq.put([0, start-1])

while pq.qsize() != 0:
    node = pq.get()
    cost = node[0]
    currentNode = node[1]

    if minCost[currentNode] < cost : continue

    for nextNode, nextCost in graph[currentNode]:
        if nextCost+cost < minCost[nextNode]:
            minCost[nextNode] = nextCost+cost
            pq.put([nextCost+cost, nextNode])

print(minCost[end-1])