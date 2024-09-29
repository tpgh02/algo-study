import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
board = [[] for _ in range(n)]

for i in range(n):
    board[i] = list(map(int, list(input().strip())))

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
visited = [[[False] * 2 for _ in range(m)] for _ in range(n)]
dq = deque([])
dq.append([(0, 0), True])
visited[0][0][1] = True

def bfs():
    ans = 1
    while len(dq) != 0 :
        l = len(dq)

        for _ in range(l):
            tmp = dq.popleft()
            x = tmp[0][1]
            y = tmp[0][0]
            isPossible = tmp[1]

            if x == m-1 and y == n-1 : return ans

            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]

                if nx < 0 or ny < 0 or nx >= m or ny >= n : continue
                if board[ny][nx] == 1 and isPossible :
                    dq.append([(ny, nx), False])
                    visited[ny][nx][0] = True
                    continue
                if board[ny][nx] == 0 and not visited[ny][nx][int(isPossible)] :
                    dq.append([(ny, nx), isPossible])
                    visited[ny][nx][int(isPossible)] = True


        ans += 1
    return -1
print(bfs())