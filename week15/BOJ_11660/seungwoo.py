import sys

def solution():
    inp = sys.stdin.readline
    n, m = map(int, inp().split())
    num = [[0] * n] + [[0] + list(map(int, inp().split())) for _ in range(n)] # 처음부터 i번까지의 (i 포함) 합
    dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
    for x in range(1, n + 1):
        for y in range(1, n + 1):
            dp[y][x] = dp[y - 1][x] + dp[y][x - 1] - dp[y - 1][x - 1] + num[y][x]

    for _ in range(m):
        x1, y1, x2, y2 = map(int, inp().split())
        print(dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1])

if __name__ == "__main__":
    solution()
