def orderCheck(skill, skill_tree):
    # skt => "BACDE"
    # sk  => "CBD"
    forbiddenList = []
    for s in skill_tree:
        if s not in skill:
            continue
        elif s in skill[1:]:
            return False
        elif s == skill[0]:
            skill = skill[1:]
    return True

def solution(skill, skill_trees):
    answer = 0
    for skill_tree in skill_trees:
        if orderCheck(skill, skill_tree):
            answer += 1
    return answer

s = "CBD"
st = ["BACDE", "CBADF", "AECB", "BDA"]

print(solution(s, st))