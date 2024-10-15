# softwarecontest

# softwarecontetestcon
# tw ware soft contest

# softwarecontestconte
# software conte test con
import sys
input = sys.stdin.readline

s = input().strip()
n = int(input())
a = set([])
visited = [False for _ in range(len(s)+1)]
for _ in range(n):
    a.add(input().strip())

visited[0] = True
for i in range(len(s)):
    if not visited[i]:
        continue

    for c in a:
        if s[i:i+len(c)] == c:
            visited[i+len(c)] = True

if visited[-1]:
    print(1)
else:
    print(0)