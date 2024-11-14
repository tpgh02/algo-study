import sys
from collections import deque
#이동하다가 한번만 벽을 부수고 이동가능
#최단거리를 못구할떄는 -1을 출력
#0은 이동가능 , 1은 벽이라 이동불가능
#벽의 부숨 여부를 visited에도 넣어서 벽을 한번 부수면 다음번에는 못부수게 해야함.

n,m = map(int, sys.stdin.readline().split())
graph = []
for i in range(n):
    graph.append(list(map(int,input())))
#bfs
dx = [-1,1,0,0]
dy = [0,0,-1,1]
#3차원 배열로 해서, 좌표값에 해당하는 value값을 하나는 횟수값 ,하나는 벽을 부쉈는지 여부를 저장하기.[횟수,여부]*m*n 이런 방식
visited = [[[0]*2 for _ in range(m)]for _ in range(n)]
def bfs():
    q = deque()
    #시작위치를 넣어주기
    q.append((0,0,0))
    visited[0][0][0] = 1
    while q:
        x,y,check = q.popleft()
        if x == n-1 and y == m-1 :
            return visited[x][y][check]
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            #범위가 해당될때
            if 0 <= nx < n and 0 <= ny < m :
            #벽이 아니고 방문하지 않은 곳을 방문할때
                if graph[nx][ny] == 0 and visited[nx][ny][check] == 0:
                    visited[nx][ny][check] = visited[x][y][check] + 1
                    q.append((nx,ny,check))
            #벽인고 방문하지 않은 곳을 방문할때
                elif graph[nx][ny] == 1 and visited[nx][ny][check] == 0:
                    #check가 0이고 방문하지않았을때
                    if check == 0:
                        visited[nx][ny][1] = visited[x][y][check] + 1
                        q.append((nx,ny,1))
                    #체크가 1이면 그냥 무시 
                    elif check == 1:
                        continue
    return -1
            

print(bfs())