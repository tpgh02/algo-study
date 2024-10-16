# 1 2 3 => 3
# 12 13 21 23 31 32 => 3 + 3
# 121 123 131 132 212 213 231 232 312 313 321 323 => (3 + 3) * 2
# 1213
n = int(input())

tree = [[] for _ in range(n)]
tree[0] = ['1', '2', '3']
def dfs(i):
    if i == n:
        print(tree[i-1][0])
        exit()
    for t in range(len(tree[i-1])):
        s = tree[i-1][t]
        for j in range(1, 4):
            s += str(j)
            l = len(s)
            for k in range(1, l//2 +1):
                if s[l-k:l] == s[l-2*k:l-k]:
                    break
            else:
                tree[i].append(s)
                dfs(i+1)
            s = s[:-1]
dfs(1)
# 12
# 121
# 1213
# 12131
# 121312
# 1213121
# 12131231
# 121312313
# 1213123132