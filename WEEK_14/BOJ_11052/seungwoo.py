import sys

def solution():
    inp = sys.stdin.readline
    n, dp = int(inp()), [0] + list(map(int, inp().split()))
    for i in range(1, n):
        for j in range(1, i + 1):
            try:
                dp[i + j] = max(dp[i + j], dp[i] + dp[j])
            except:
                break
    print(dp[n])

if __name__ == "__main__":
    solution()
