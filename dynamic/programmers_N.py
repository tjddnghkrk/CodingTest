def solution(N, number):
    answer = 0
    
    LIST = [[]]
    
    for i in range(1, 9):
        tmp = []
        for j in range(1, i):
            for k in LIST[j]:
                for u in LIST[i-j]:
                    tmp.append(k + u)
                    if k - u > 0:
                        tmp.append(k - u)
                    tmp.append(k * u)
                    if u != 0:
                        tmp.append(k // u)
        tmp.append(int(str(N) * i))
        
        if number in tmp:
            return i
        LIST.append(list(set(tmp)))
        
    return -1
