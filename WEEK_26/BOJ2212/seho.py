n = int(input())
k = int(input())
li = sorted(list(map(int, input().split())))

if k >= len(li) :
    print(0)
else :
    diff = [li[i+1] - li[i] for i in range(len(li)-1)]
    diff.sort()
    print(sum(diff[:n-1-k+1]))