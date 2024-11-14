import sys
from collections import deque

def solution():
    inp = sys.stdin.readline
    n, m = int(inp()), int(inp())
    parents_list = [[] for _ in range(n + 1)]
    res = [[0] * (n + 1) for _ in range(n + 1)]
    top = [0] * (n + 1)
    for _ in range(m):
        x, y, k = map(int, inp().split())
        parents_list[y].append((x, k))
        top[x] += 1
    dq = deque()

    for i, cnt in enumerate(top):
        if not cnt:
            dq.append(i)
    while dq:
        child = dq.popleft()
        for parent, cost in parents_list[child]:
            if res[child].count(0) == n + 1:
                res[parent][child] += cost
            else:
                for i in range(1, n + 1):
                    if res[child][i]:
                        res[parent][i] += res[child][i] * cost
            top[parent] -= 1
            if not top[parent]:
                dq.append(parent)

    for i in range(1, n):
        if res[n][i]:
            print(i, res[n][i])

if __name__ == "__main__":
    solution()
