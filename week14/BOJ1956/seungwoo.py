import sys

def solution():
    inp = sys.stdin.readline
    v, e = map(int, inp().split())
    startable, endable = [False] * (v + 1), [False] * (v + 1)
    floyd_warshall = [[1e9] * (v + 1) for _ in range(v + 1)]
    for _ in range(e):
        a, b, d = map(int, inp().split())
        floyd_warshall[a][b] = d
        startable[a] = True
        endable[b] = True
    
    for a in range(1, v + 1):
        for b in range(1, v + 1):
            for c in range(1, v + 1):
                floyd_warshall[a][c] = min(floyd_warshall[a][c], floyd_warshall[a][b] + floyd_warshall[b][c])

    res = 1e9
    for i in range(1, v + 1):
        if startable[i] and endable[i]:
            for j in range(1, v + 1):
                res = min(res, floyd_warshall[i][j] + floyd_warshall[j][i])
    print(res if res < 1e9 else -1)
    
if __name__ == "__main__":
    solution()
