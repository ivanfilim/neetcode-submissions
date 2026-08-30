class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stonesHeap = [-stone for stone in stones]
        heapq.heapify(stonesHeap)
        while len(stonesHeap) > 1:
            newStone = abs(heapq.heappop(stonesHeap) - heapq.heappop(stonesHeap))
            if newStone > 0:
                heapq.heappush(stonesHeap, -newStone)
        if len(stonesHeap) == 0:
            return 0
        else:
            return -stonesHeap[0]