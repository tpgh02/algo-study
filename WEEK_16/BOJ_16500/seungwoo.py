import sys

def solution():
    def DFS(idx):
        if idx == len(target):
            print(1)
            exit(0)
        if dp[idx]:
            return
        dp[idx] = True
        for i in range(n):
            if len(target) >= idx + len(str_list[i]):
                for j in range(len(str_list[i])):
                    if target[idx + j] != str_list[i][j]:
                        break
                else:
                    DFS(idx + len(str_list[i]))
        return

    inp = sys.stdin.readline
    target, n = inp().rstrip(), int(inp())
    str_list, dp = [inp().rstrip() for _ in range(n)], [False for _ in range(len(target))]
    DFS(0)
    print(0)

if __name__ == "__main__":
    solution()

