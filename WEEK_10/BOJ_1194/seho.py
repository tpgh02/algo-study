import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int ,input().split())
maze = []
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
q = deque([])

for i in range(n):
    maze.append(list(input()))
    for j in range(m):
        if maze[i][j] == '0':
            q.append((i, j))
            maze[i][j] = '.'

def move() :
    ans = 0
    keys = bin(0)

    while len(q) != 0 :
        l = len(q)

        for _ in range(l):
            x = q[0][1]
            y = q[0][0]
            q.popleft()
            if 97 <= ord(maze[y][x]) <= 102:
                keys = keys | (2 ** (ord(maze[ny][nx]) - 97))
                maze[y][x] = '.'

            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]

                if nx < 0 or ny < 0 or nx > m or ny > n or maze[ny][nx] == '#': continue

                if 65 <= ord(maze[ny][nx]) <= 70 :
                    if (2 ** (ord(maze[ny][nx] - 65))) & keys :
                        maze[ny][nx] = '.'
                    else :
                        continue
                if maze[ny][nx] == '1' :
                    return ans

        ans += 1