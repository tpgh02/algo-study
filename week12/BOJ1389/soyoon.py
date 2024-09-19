import sys
#딕셔너리 사용해서 하면 될듯.
#전체 수는 그냥 하나 입력될때마다 cnt += 1해주면 됨
#name이 들어왔을때 key값에 없으면 key 생성해주고 value = 1 로 설정, 만약 name이 있으면 value +1해주면 될듯
#하나씩 반복문으로 입력받아서 처리하기, 아무것도 안들어오면 break
tree_dict = dict()
cnt = 0
while 1:
    name = sys.stdin.readline().rstrip()
    cnt += 1
    if name == '':
        break
    if name in tree_dict:
        tree_dict[name] += 1
    else:
        tree_dict[name] =1

#백분율 계산하기
tree_lst = list(tree_dict.keys())
tree_lst.sort()
for t in tree_lst:
    print('%s %.4f' %(t, (tree_dict[t]/cnt)*100))

   
