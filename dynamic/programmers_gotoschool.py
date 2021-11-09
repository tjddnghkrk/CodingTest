def solution(m, n, puddles):
    
    MAP = [[-1 for i in range(m)] for j in range(n)]   
    MAP[0][0] = 1
    
    for i in puddles:
        MAP[i[1] - 1][i[0] - 1] = 0
    
    for i in range(n):
        for j in range(m):
            if MAP[i][j] == 0:
                continue
            if j - 1 < 0 and i - 1 < 0:
                continue
            elif i - 1 < 0:
                MAP[i][j] = MAP[i][j - 1]
            elif j - 1 < 0:
                MAP[i][j] = MAP[i - 1][j]
            else:
                MAP[i][j] = MAP[i - 1][j] + MAP[i][j - 1]
            #print(MAP)
            
    return MAP[n-1][m-1] % 1000000007
