from collections import defaultdict


class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        pos = defaultdict(list)
        for i, num in enumerate(nums):
            pos[num].append(i)

        for key, val in pos.items():
            if len(val) < 2:
                continue
            for i in range(len(val) - 1):
                if val[i + 1] - val[i] <= k:
                    return True

        return False
