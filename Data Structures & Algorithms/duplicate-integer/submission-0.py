class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        map = {}
        for i in nums:
            if i not in map:
                map[i] = 1
            else:
                map[i] = map.get(i)+1
        
        for key in map:
            if map[key]>1:
                return True
        
        return False
    