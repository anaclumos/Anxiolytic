# not used

def solution(total_sp, skills):
    ss = SkillSet()
    for s in skills:
        ss.add(s)

    answer = []
    return answer

class SkillSet:
    def __init__(self):
        self.skillset = {}
        # id: Skill(prev skills)
        
    def add(self, skillIds):
        # skillIds = [스킬 1, 스킬 a 배우는데 필요한 스킬 b]
        skill0 = Skill(skillIDs[0]) if skill0 not in self.skillset else self.skillset[skillIDs[0]]
        skill1 = Skill(skillIDs[1]) if skill0 not in self.skillset else self.skillset[skillIDs[1]]

class Skill:
    def __init__(self, id):
        self.id = id
        self.preskills = []
    
    def addPreskill(self, preskill):
        self.preskills.append(preskill)

    # def findSp(self):
    #     node = self
    #     spSum = 0
    #     while node is not None:
    #         spSum += node.sp
    #         node = node.prev
    #     return spSum