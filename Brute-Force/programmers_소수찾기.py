from itertools import permutations

def solution(numbers):
    count = 0
    a = set()
    for i in range(1, len(numbers) + 1):
        per = list(map(''.join, permutations(numbers, i)))
        for j in range(len(per)):
            a.add(int(per[j]))
    for k in a:
        #print(k)
        if k == 0:
            continue
        if k == 1:
            continue
        if k == 2:
            count += 1
            continue
        notPrime = 0
        for u in range(2, (k//2) + 1):
            if(k % u == 0):
                notPrime = 1
                break
        if notPrime == 0  :
            count += 1 
    answer = count    
    return answer
