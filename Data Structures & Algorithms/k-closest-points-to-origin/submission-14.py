class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []
        for point in points:
            distance = point[0] * point[0] + point[1] * point[1]
            heapq.heappush(heap, (-distance, point))
            if len(heap) > k:
                heapq.heappop(heap)
        res = []
        while len(heap) > 0:
            _, point = heapq.heappop(heap);
            res.append(point)
        return res