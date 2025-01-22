# 분할정복

import sys
input = sys.stdin.readline

n = int(input())
board = [list(input().strip()) for _ in range(n)]

def daq(x, y, n):
    standard = board[y][x]

    isAllSame = True
    for i in range(y, y+n):
        for j in range(x, x+n):
            if board[i][j] != standard:
                isAllSame = False
                break
        if not isAllSame:
            break

    if isAllSame:
        print(standard, end="")
    else:
        print("(", end="")
        n //= 2
        daq(x, y, n)
        daq(x+n, y, n)
        daq(x, y + n, n)
        daq(x+n, y+n, n)
        print(")", end="")

daq(0, 0, n)
# n = 4
# 0,0
# 0,4
# 4,0
# 4,4