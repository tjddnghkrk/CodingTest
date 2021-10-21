
def solution(number, k):
    List = [number[0]]
    for i in number[1:]:
        while len(List) > 0 and List[-1] < i and k > 0:
            List.pop()
            k -= 1
        List.append(i)

    if k > 0:
        List = List[:-k]
        
    return ''.join(List)
