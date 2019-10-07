# https://programmers.co.kr/learn/courses/30/lessons/42840

def solution(answers)
  members = [
    [1, 2, 3, 4, 5],
    [2, 1, 2, 3, 2, 4, 2, 5],
    [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
  ]

  l = members.collect {|m| m.length}
  correct = [0] * members.length

  for i in 0..answers.length-1
    for m in 0..members.length-1
      if members[m][i % l[m]] == answers[i]
        correct[m] += 1
      end
    end
  end

  max = 0
  top = []
  for i in 0..correct.length - 1
    if max < correct[i]
      max = correct[i]
      top = [i+1]
    elsif max == correct[i]
      top.append(i+1)
    end
  end
  return top
end

input = [1,3,2,4,2]
puts solution(input)

# 테스트 1  〉 통과 (0.31ms, 16.7MB)
# 테스트 2  〉 통과 (0.32ms, 16.8MB)
# 테스트 3  〉 통과 (0.37ms, 16.7MB)
# 테스트 4  〉 통과 (0.34ms, 16.6MB)
# 테스트 5  〉 통과 (0.37ms, 16.6MB)
# 테스트 6  〉 통과 (0.33ms, 16.5MB)
# 테스트 7  〉 통과 (2.72ms, 16.6MB)
# 테스트 8  〉 통과 (1.21ms, 16.7MB)
# 테스트 9  〉 통과 (5.44ms, 16.8MB)
# 테스트 10 〉 통과 (3.04ms, 16.8MB)
# 테스트 11 〉 통과 (5.32ms, 16.8MB)
# 테스트 12 〉 통과 (5.44ms, 16.8MB)
# 테스트 13 〉 통과 (0.58ms, 16.9MB)
# 테스트 14 〉 통과 (6.13ms, 16.8MB)