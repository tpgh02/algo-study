import sys
input = sys.stdin.readline

n = int(input())

tree = [[0, 0, 0, 0, 0] for _ in range(n + 1)]
visited = [False for _ in range(n+1)]
bottom = 1

def dfs(node, depth):
    global bottom

    visited[node] = True
    tree[node][3] = depth

    bottom = max(depth, bottom)

    for i in range(2):
        if not visited[tree[node][i]]:
            dfs(tree[node][i], depth+1)

def inOrder(node):
    global order
    if node == 0 :
        return

    inOrder(tree[node][0])
    tree[node][4] = order
    order += 1
    inOrder(tree[node][1])

for _ in range(n):
    a, b, c = map(int, input().split())

    if b == -1 :
        b = 0
    if c == -1 :
        c = 0

    tree[a][0] = b
    tree[a][1] = c

    tree[b][2] = a
    tree[c][2] = a

# if n == 1 or n == 2 :
#     print(1, 1)
#     exit()
root = 0

for i in range(1, n+1):
    if tree[i][2] == 0 :
        root = i

dfs(root, bottom)
order = 1
inOrder(root)

depthTree = [[] for _ in range(bottom+1)]

for node in range(1, n+1):
    d = tree[node][3]
    w = tree[node][4]

    depthTree[d].append(w)

ans = 1
maxWidth = 1

for i in range(2, bottom+1):
    if len(depthTree[i]) == 0 :
        break
    width = max(depthTree[i]) - min(depthTree[i])+1

    if width > maxWidth :
        ans = i
        maxWidth = width

print(ans, maxWidth)