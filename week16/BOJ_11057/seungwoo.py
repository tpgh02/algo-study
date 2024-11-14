import sys

def solution():
    n = int(sys.stdin.readline())
    dp = [1 for _ in range(10)]
    for _ in range(n - 1):
        for i in range(1, 10):
            dp[i] = dp[i] + dp[i - 1]
    print(sum(dp) % 10007)

if __name__ == "__main__":
    solution()
