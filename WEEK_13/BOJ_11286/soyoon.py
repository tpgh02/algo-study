#정수가 입력되는데 0이면 절댓값이 가장 작은 걸 출력하고 배열에서 삭제
#정수가 0이 아니면 절댓값이 가장 작은 순으로 배열하기
import heapq
#양수 배열 (최소 힙)
plus =[]
#음수 배열 (최대 힙)
minus = []

n = int(input())
for _ in range(n):
    num = int(input())
    if num > 0:
        #num이 양수일때는 최소힙
        heapq.heappush(plus,num)
    elif num <0:
        #num이 음수면 최대힙
        heapq.heappush(minus,-num)
    else:
        #num이 0이면 절댓값 작은거 출력하기
        if plus and minus:
            #양수랑 음수 둘다 있을때
            if plus[0] < minus[0]:
                print(heapq.heappop(plus))
            else:
                print(heapq.heappop(minus)*(-1))
        elif plus:
            #양수만 있을때 
            print(heapq.heappop(plus))
        elif minus:
            #음수만 있을때
            print(heapq.heappop(minus)*(-1))
        else:
            #둘다 비어있을때
            print(0)
        
print(' ')