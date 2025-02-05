import sys
from collections import deque
input = sys.stdin.readline

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

n, m, k = map(int, input().split())

board = [[False for _ in range(m)] for _ in range(n)]

for _ in range(k):
    x1, y1, x2, y2 = map(int, input().split())
    for i in range(y1, y2):
        for j in range(x1, x2):
            board[i][j] = True

def bfs(a, b):
    dq = deque([[a, b]])
    area = 1
    board[b][a] = True

    while dq:

        x, y = dq.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or ny < 0 or nx >= m or ny >= n or board[ny][nx]: continue
            board[ny][nx] = True
            area += 1
            dq.append([nx, ny])


    return area

ans = []
for i in range(n):
    for j in range(m):
        if not board[i][j]:
            ans.append(bfs(j, i))
ans.sort()
print(len(ans))
print(*ans)
