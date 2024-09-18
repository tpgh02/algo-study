import sys

input = sys.stdin.readline

n, m, k = map(int, input().split())

hate = [0 for _ in range(m+1)]
visited = [False for _ in range(m+1)]

for _ in range(n):
    a, b = map(int, input().split())
    if hate[b] == 0 :
        hate[b] = a

ans = 0

while True :
    if hate[k] == 0 :
        print(ans)
        break

    k = hate[k]
    if visited[k] :
        print(-1)
        break
    visited[k] = True
    ans += 1


# [0, 5, 3, 1, 0, 0]