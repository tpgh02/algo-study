import sys

def solution():
    inp = sys.stdin.readline
    n, k = map(int, inp().split())
    dp = [1e9 for _ in range(k + 1)]
    coint_list = sorted(list(set([int(inp()) for _ in range(n)])))
    dp[0] = 0
    for i in range(k):
        for j in coint_list:
            try:
                if dp[i + j] > dp[i] + 1:
                    dp[i + j] = dp[i] + 1
            except:
                continue
    print(dp[k] if dp[k] != 1e9 else -1)

if __name__ == "__main__":
    solution()
