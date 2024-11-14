import sys
import heapq

dt = ((-1, 0), (0, 1), (1, 0), (0, -1))
def solution():
    inp = sys.stdin.readline
    (m, n), q = map(int, inp().split()), []
    grid = [inp().rstrip() for _ in range(n)]
    visit = [[False] * m for _ in range(n)]
    visit[0][0] = True
    heapq.heappush(q, (0, 0, 0))
    if n == 1 and m == 1:
        print(0)
        exit(0)

    while q:
        cnt, y, x = heapq.heappop(q)
        for dy, dx in dt:
            if 0 <= (ty := y + dy) < n and 0 <= (tx := x + dx) < m and not visit[ty][tx]:
                if ty == n - 1 and tx == m - 1:
                    print(cnt)
                    exit(0)

                visit[ty][tx] = True
                if grid[ty][tx] == "0":
                    heapq.heappush(q, (cnt, ty, tx))
                else:
                    heapq.heappush(q, (cnt + 1, ty, tx))

if __name__ == "__main__":
    solution()
