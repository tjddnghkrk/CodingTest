def solution(n, costs):
    NUM = 0
    checkList = [i for i in range(n)]
    costs.sort(key = lambda x:x[2])
    for i in costs:
        if checkList[i[0]] == checkList[i[1]]:
            continue
        NUM += i[2]
        MIN = min(checkList[i[0]], checkList[i[1]])
        MAX = max(checkList[i[0]], checkList[i[1]])
        for j in range(len(checkList)):
            if checkList[j] == MAX:
                checkList[j] = MIN
        print(checkList)
        CHECK = True
        for j in range(len(checkList)):
            if checkList[j] != 0:
                CHECK = False
                break
        if CHECK:
            break      
    return NUM
