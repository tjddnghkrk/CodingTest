def solution(n, computers):
    answer = 0
    
    def DFS(i):
        MAP[i] = 1
        for j in range(n):
            if computers[i][j] == 0:
                continue
            if i == j or MAP[j] != 0:
                continue
            if MAP[j] == 0:
                DFS(j)
        
    
    MAP = [0 for i in range(n)]
    for i in range(n):
        if MAP[i] == 0:
            DFS(i)
            answer += 1
    
    
    return answer
