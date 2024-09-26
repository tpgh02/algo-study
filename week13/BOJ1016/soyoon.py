#제곱 ㄴㄴ수
#제곱수의 배수를  에라토스테네스의 체의 소수 거르기 방식으로 걸러내면 됨
minn,maxx = map(int,input().split())

#제곱수를 거르기 전 전체 수의 개수
res_num = maxx-minn+1
#제곱수인지 아닌지 체크하는 배열
check = [False]*res_num

for i in range(2, int(maxx**0.5+1)):
    s = i**2
    for j in range((((minn-1)//s)+1)*s,maxx+1,s):
        if check[j-minn] == False:
            check[j-minn] = True
            res_num -=1
print(res_num)
