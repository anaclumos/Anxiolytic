# https://programmers.co.kr/learn/courses/30/lessons/12977

require 'prime'

def solution(nums)
    sums = []
    for x in 0..nums.length-3
        for y in x+1..nums.length-2
            for z in y+1..nums.length-1
                sums.append(nums[x] + nums[y] + nums[z])
            end
        end
    end 

    answer = 0
    for s in sums
    	if Prime.prime?(s)
    		answer += 1
    	end
    end
    return answer
end