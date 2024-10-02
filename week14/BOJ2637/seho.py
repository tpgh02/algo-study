import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
m = int(input())

part = [[] for _ in range(n+1)]
partCnt = [0 for _ in range(n+1)]
partCnt[-1] = 1
outDegree = [0 for _ in range(n+1)]
inDegree = [0 for _ in range(n+1)]
for _ in range(m):
    x, y, k = map(int, input().split())

    part[x].append([y, k])
    outDegree[x] += 1
    inDegree[y] += 1

dq = deque([])

for i in range(1, n+1):
    if inDegree[i] == 0 :
        dq.append(i)

while len(dq) != 0 :
    node = dq.popleft()

    for nextNodeInfo in part[node]:
        nextNode = nextNodeInfo[0]
        nextCnt = nextNodeInfo[1]

        inDegree[nextNode] -= 1
        partCnt[nextNode] += partCnt[node] * nextCnt

        if inDegree[nextNode] == 0 :
            dq.append(nextNode)

for i in range(1, n+1):
    if outDegree[i] == 0 :
        print(i, partCnt[i])