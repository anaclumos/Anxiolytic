def solution(p):
    answer = p + 1
    while(not isBeautifulYear(answer)):
        answer += 1
    return answer

def isBeautifulYear(year):
	years = list(map(int, str(year)))
	return len(set([x for x in years])) == len(years)

print(solution(1987))