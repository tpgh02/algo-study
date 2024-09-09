import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
board = [[0 for _ in range(n)] for _ in range(n)]
k = int(input())
for _ in range(k):
    a, b = map(int, input().split())
    board[a-1][b-1] = 1
l = int(input())
operation = deque([])
for _ in range(l):
    operation.append(input().split())

board[0][0] = -1
time = 0
idx_oper = 0
direction = [(1, 0), (0, 1), (-1, 0), (0, -1)]
hd = 0
hx = 0
hy = 0
td = 0
tx = 0
ty = 0

while True:
    time += 1

    hx += direction[hd][0]
    hy += direction[hd][1]

    if hx >= n or hy >= n or hx < 0 or hy < 0 or board[hy][hx] == -1 or board[hy][hx] == "D" or board[hy][hx] == "L" : break

    if board[hy][hx] != 1 :
        if board[ty][tx] == "D":
            td += 1
        elif board[ty][tx] == "L":
            td -= 1
        td %= 4
        board[ty][tx] = 0
        tx += direction[td][0]
        ty += direction[td][1]
    board[hy][hx] = -1

    if idx_oper < l :
        if int(operation[idx_oper][0]) == time:
            if operation[idx_oper][1] == "D" :
                hd += 1
                board[hy][hx] = "D"
            else :
                hd -= 1
                board[hy][hx] = "L"
            hd %= 4
            idx_oper += 1

print(time)