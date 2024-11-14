import sys

input = sys.stdin.readline


def find(x):
    if parent[x] == x: return parent[x]

    parent[x] = find(parent[x])
    return parent[x]


def union(a, b, t):
    a = find(a)
    b = find(b)

    if a < b:
        parent[b] = a
    elif a > b:
        parent[a] = b
    if a==b and t == 0 :
        parent[a] = 0
        parent[b] = 0

case = 0

while True:
    n, m = map(int, input().split())
    case += 1
    if m == 0 and n == 0:
        break

    parent = [x for x in range(n + 1)]
    edge = []
    for _ in range(m):
        a, b = map(int, input().split())

        edge.append((a, b))

    for t in range(2):
        for i in range(m):
            union(edge[i][0], edge[i][1], t)

    sp = set(parent)

    if len(sp) == 1 :
        print("Case {}: No trees.".format(case))
    elif len(sp) == 2 :
        print("Case {}: There is one tree.".format(case))
    else :
        print("Case {}: A forest of {} trees.".format(case, len(sp)-1))