import sys
from collections import deque

def solution():

    inp = sys.stdin.readline
    n, dq, is_same = int(inp()), deque(), True
    grid, res = [list(map(int, inp().split())) for _ in range(n)], [0, 0, 0]
    dq.append((0, 0, n))

    while dq:
        (y, x, l), is_same = dq.pop(), True
        standard = grid[y][x]
        
        for ty in range(l):
            for tx in range(l):
                if standard != grid[y + ty][x + tx]:
                    is_same = False
                    break
            if not is_same:
                break
        if is_same:
            res[standard + 1] += 1
        else:
            l //= 3
            for i in range(3):
                for j in range(3):
                    dq.append((y + i * l, x + j * l, l))
    for r in res:
        print(r)

if __name__ == "__main__":
    solution()
