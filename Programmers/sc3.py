def solution(total_sp, skills):
    skillset = {}
    # skillset: id => [preskills]
    skillpointset = {}
    # skillpointset: id => required skillpoints
    for s in skills:
        # s: [skill, preskill]
        if s[0] in skillset:
            skillset[s[0]].append(s[1])
        else:
            skillset[s[0]] = [s[1]]

    answer = []
    skillMultiplierSum = 0
    for n in range(1, len(skills)+2):
        sm = getSkillMultiplier(n, skillset, skillpointset)
        skillMultiplierSum += sm
        answer.append(sm)
    return [x * int(total_sp / skillMultiplierSum) for x in answer]

def getSkillMultiplier(n, skillset, skillpointset):
    if n in skillpointset:
        return skillpointset[n]
    else:
        if n not in skillset:
            skillpointset[n] = 1
            return 1
        else:
            spSum = 0
            for preskill in skillset[n]:
                spSum += getSkillMultiplier(preskill, skillset, skillpointset)
            skillpointset[n] = spSum
            return spSum