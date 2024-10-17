import sys

def solution():
    inp = sys.stdin.readline
    n = int(inp())
    dist, is_road = [list(map(int, inp().split())) for _ in range(n)], [[True for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if i != j:
                for k in range(n):
                    if i != k and j != k:
                        if dist[i][j] == dist[i][k] + dist[k][j]:
                            is_road[i][j], is_road[j][i] = False, False
                        elif dist[i][j] > dist[i][k] + dist[k][j]:
                            print(-1)
                            exit(0)
    
    s = 0
    for i in range(n - 1):
        for j in range(i + 1, n):
            if is_road[i][j]:
                s += dist[i][j]
    print(s)

if __name__ == "__main__":
    solution()
