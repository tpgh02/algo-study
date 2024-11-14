import sys
import heapq
input = sys.stdin.readline

n, m = map(int, input().split())
board = []
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
dist = [[sys.maxsize for _ in range(n)] for _ in range(m)]
for _ in range(m):
    board.append(list(map(int, list(input().strip()))))

def bfs():
    hq = []
    hq.append([0, 0, 0])

    while hq:
        tmp = heapq.heappop(hq)
        cnt = tmp[0]
        y = tmp[1]
        x = tmp[2]

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx<0 or ny<0 or nx >= n or ny>=m : continue

            if dist[ny][nx] > cnt + board[ny][nx]:
                dist[ny][nx] = cnt+board[ny][nx]
                heapq.heappush(hq, [dist[ny][nx], ny, nx])

bfs()
if n == 1 and m == 1 :
    print(board[-1][-1])
else :
    print(dist[-1][-1])