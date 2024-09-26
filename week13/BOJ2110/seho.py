import sys
input = sys.stdin.readline

n, m = map(int, input().split())
coord = []
for _ in range(n):
    coord.append(int(input()))

coord.sort()
start = 1
end = coord[-1] - coord[0]
ans = 0

while start <= end :

    mid = (start + end) // 2
    cur = coord[0]
    cnt = 1

    for i in range(1, n):
        if coord[i] - cur >= mid:
            cnt += 1 # 공유기 개수
            cur = coord[i] # i번째 집과 cur집 사이의 거리가 mid보다 크거나 같으면 cur에 공유기를 설치.
    if cnt >= m :
        if ans < mid :
            ans = mid
        start = mid + 1
    else :
        end = mid - 1

print(ans)
# 거리를 이분 탐색

# 1 2 4 8 9