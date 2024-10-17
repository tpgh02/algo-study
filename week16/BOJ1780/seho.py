import sys
input = sys.stdin.readline

n = int(input())
ans = [0, 0, 0]
board = []
for _ in range(n):
    board.append(list(map(int, input().split())))

def dfs(x, y, n):
    c = board[x][y]

    for i in range(x, x+n):
        for j in range(y, y+n):
            if c != board[i][j]:
                for a in range(3):
                    for b in range(3):
                        m = n//3
                        dfs(x + m*a, y + m*b, m)
                return
    ans[c] += 1
dfs(0, 0, n)
for i in range(-1, 2, 1):
    print(ans[i])