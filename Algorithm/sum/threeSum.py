class Solution(object):
    """
    :type nums: List[int]
    :rtype: List[List[int]]
    """
    def threeSum(self, nums):
        triplets = []
        length = len(nums)
        if length < 3:
            return triplets
        
        nums.sort()
        for i in xrange(length):
            target = 0 - nums[i]
            # 2 sum
            hashmap = {}
            for j in xrange(i + 1, length):
                item_j = nums[j]
                if (target - item_j) in hashmap:
                    triplet = [nums[i], target - item_j, item_j]
                    if triplet not in triplets:
                        triplets.append(triplet)
                else:
                    hashmap[item_j] = j
        
        return triplets

# python这个就比较简单，list、map直接遍历
