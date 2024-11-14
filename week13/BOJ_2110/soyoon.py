n,k = map(int,input().split())
arr = []
for i in range(n):
    num = int(input())
    arr.append(num)

arr.sort()
#이분탐색을 하되, 떨어져있는 거리를 mid로 놓고 푸는 걸 목표로 함.
start = 1
end = max(arr) - arr[0]
res = 0
while (start<=end):
    mid = (start+end)//2
    #직전에 설치한 공유기와 인접해야하니까?
    cur = arr[0]
    #인접한거리의 최대를 위해 첫번째 집에는 무조건 공유기 설치
    cnt = 1
    #배열을 돌면서 mid만큼 띄어져서 공유기를 설치할떄 설치할 수 있는 공유기 수
    for i in range(1,n):
        if arr[i] >= cur+mid:
            cnt += 1
            cur = arr[i]

    #공유기 수가 목표하던 수보다 많으면 거리(mid)를 더 증가시킴
    if cnt >= k:
        start = mid+1
        res = mid

    #공유기 수가 목표하던 수보다 작으면 거리(mid)를 더 줄여서 간격을 줄임
    else:
        end = mid -1

print(res)