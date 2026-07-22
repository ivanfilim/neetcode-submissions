class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        numsToFreq = defaultdict(int)
        for n in nums:
            numsToFreq[n] += 1
        freqToNums = [[] for _ in range(len(nums))]
        for n, f in numsToFreq.items():
            freqToNums[f - 1].append(n)
        result = []
        for i in range(len(nums), 0, -1):
            for n in freqToNums[i - 1]:
                result.append(n)
                if len(result) == k:
                    return result