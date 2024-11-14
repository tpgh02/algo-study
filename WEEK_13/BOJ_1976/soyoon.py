#여행가자_1976
#n개의 도시끼리 이어진 상태정보를 알려줌 -> 마지막 여행계획에 있는 노드들이 이어지기만 하면 yes 출력
#그냥 bfs로 다 탐색해보면 안되는건가? 여행계획에 나온거 노드 리스트에 넣어서 그것만 다 가면되는거 아닌가?
from collections import deque

n = int(input())
m = int(input())
arr = [list(map(int,input().split())) for _ in range(n)]
plan = list(map(int,input().split()))

def bfs(s, e):
    q = deque()
    q.append(s)
    visited = [False] * n
    visited[s] = True

    while q:
        here = q.popleft()

        if here == e:
            return True

        for i in range(n):
            if arr[here][i] == 1 and not visited[i]:
                visited[i] = True
                q.append(i)

    return False

answer = True
for i in range(m-1):
    if plan[i] != plan[i+1]:
        if not bfs(plan[i]-1, plan[i+1]-1):
            answer = False
            break

if answer:
    print('YES')
else:
    print('NO')
    