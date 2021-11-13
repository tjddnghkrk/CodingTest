
def solution(begin, target, words):
    answer = 0
    MAP = [0 for i in range(len(words))]
    MIN = 99999999

    def DFS(word, num, MAP):
        if word == target:
            nonlocal MIN
            if num < MIN:
                MIN = num
                
        for i in range(len(words)):
            sign = 1
            if MAP[i] == 1:
                continue
            for j in range(len(word)):
                if word[j] == words[i][j]:
                    continue
                else:
                    sign -= 1
                if sign < 0:
                    break
            if sign == 0:
                MAP[i] = 1
                #print(words[i], num)
                DFS(words[i], num + 1, MAP)
                MAP[i] = 0
            
    DFS(begin, 0, MAP)
    if MIN < 99999999:
        return MIN
    else:
        return answer
