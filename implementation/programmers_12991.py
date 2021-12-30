def makeTwo(n):
    
    a = ""
    while (n >= 1):
        a = str(n % 2) + a
        n = (int)(n / 2)
        
    return a

def findIndex(n2):
    
    start = False
    end = False
    
    for i in range(1, len(n2) + 1):
        if start == False:
            if n2[len(n2) - i] == '1':
                start = True
            else:
                continue
        
        if start and end == False:
            if n2[len(n2) - i] == '0':
                end = True
            else:
                continue
        
        if start and end:
            return (len(n2) - i)

    return -1 # 1111 ...

def Merge(n2, index):

    Back = n2[(index + 1):]
    countOne = Back.count('1')
    countOne -= 1
    
    if index == -1:
        result = "1"
        
    else:
        result = n2[:index] + "1"
        
    result = result + ("0" * (len(Back) - countOne))
    result = result + ("1" * countOne)
    
    return result

def makeTen(n):
    num = 0
    now = 1
    for i in range(1, len(n) + 1):
        if n[len(n) - i] == '1':
            num += now
        now *= 2
    return num

def solution(n):
    
    answer = 0
    
    n2 = makeTwo(n)
    index = findIndex(n2)
    result = Merge(n2, index)
    answer = makeTen(result)
    
    return answer
