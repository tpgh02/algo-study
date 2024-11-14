import sys
input = sys.stdin.readline

def find(x):
    if x == parent[x] : return parent[x]

    parent[x] = find(parent[x])
    return parent[x]

def union(a, b):
    a = find(a)
    b = find(b)

    if a < b : parent[b] = a
    else : parent[a] = b

n = int(input())
m = int(input())

parent = [i for i in range(n)]
for i in range(n):
    li = list(map(int, input().split()))

    for j in range(len(li)):
        if li[j] == 1 :
            if find(i) != find(j) :
                union(i, j)

destination = list(map(int, input().split()))
city = find(destination[0]-1)
for i in destination :
    if city != find(i-1):
        print("NO")
        break
else :
    print("YES")