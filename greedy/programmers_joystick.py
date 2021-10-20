alphabets = ""
answer = 9999
direct = [1, -1]

def recurFind(index, now, value, depth):
    index = (index + len(now)) % len(now)
    global alphabets
    global answer
    
    if now == alphabets:
        if answer > value:
            answer = value
            return 0
    if value > answer:
        return 0
    if depth > 16:
        return 0
    if now[index] != alphabets[index]:
        List = list(now)
        List[index] = alphabets[index]
        now = ''.join(List)
        value += min(ord(alphabets[index]) - ord('A'), ord('Z') - ord(alphabets[index]) + 1)
    for i in direct:
        recurFind(index + i, now, value + 1, depth + 1)

def solution(name):
    global alphabets
    global answer

    alphabets += name
    now = 'A' * len(name)
    recurFind(0, now, 0, 0)
    
    return answer - 1
