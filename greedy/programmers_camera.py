def solution(routes):
    routes.sort(key = lambda x:x[1])
    result = 1
    lastPoint = 0
    startPoint = 1
    
    if len(routes) == 1:
        return result
    while True:
        if startPoint >= len(routes) or lastPoint >= len(routes):
            break
        if routes[startPoint][0] <= routes[lastPoint][1] and routes[lastPoint][1] <= routes[startPoint][1]:
            startPoint += 1
            continue
        else:
            result += 1
            lastPoint = startPoint
        
            
    return result
