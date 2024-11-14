import sys
import heapq

def solution():
    inp = sys.stdin.readline
    for _ in range(int(inp())):
        n, k = map(int, inp().split())
        q, top, parents, cost = [], [0 for _ in range(n + 1)], [[] for _ in range(n + 1)], [0] + list(map(int, inp().split()))
        for _ in range(k):
            x, y = map(int, inp().split())
            top[y] += 1
            parents[x].append(y)
        target = int(inp())

        for i in range(1, n + 1):
            if not top[i]:
                heapq.heappush(q, (cost[i], i))

        while True:
            c, n = heapq.heappop(q)

            if n == target:

                print(c)
                break

            for parent in parents[n]:
                top[parent] -= 1
                if not top[parent]:
                    heapq.heappush(q, (c + cost[parent], parent))

if __name__ == "__main__":
    solution()
