def solution(brown, yellow):
    answer = []
    
    sum = brown + yellow
    limit = int(sum ** 0.5)
    for i in range(2, limit + 1):
        if sum % i == 0:
            if i*2 + (sum // i)*2 - 4 == brown:
                if i * (sum // i) - brown == yellow:
                    answer.append(sum // i)
                    answer.append(i)
                    return answer     
    return -1
