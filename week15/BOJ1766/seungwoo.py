import sys
import heapq

def solution():
    inp = sys.stdin.readline
    n, m = map(int, inp().split())
    q, top, parents = [], [0 for _ in range(n + 1)], [[] for _ in range(n + 1)]

    for _ in range(m):
        a, b = map(int, inp().split())
        top[b] += 1
        parents[a].append(b)
    
    for i in range(1, n + 1):
        if not top[i]:
            heapq.heappush(q, i)

    while q:
        n = heapq.heappop(q)
        print(n, end=" ")
        for parent in parents[n]:
            top[parent] -= 1
            if not top[parent]:
                heapq.heappush(q, parent)

if __name__ == "__main__":
    solution()
