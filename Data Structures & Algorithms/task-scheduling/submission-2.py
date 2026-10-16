class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        freqs = defaultdict(int)
        for task in tasks:
            freqs[task] += 1
        heap = []
        for k, v in freqs.items():
            heap.append(-v)
        heapq.heapify(heap)
        queue = deque()
        time = 0
        while len(heap) > 0 or len(queue) > 0:
            if len(queue) > 0 and queue[0][1] == time:
                heapq.heappush(heap, -queue.popleft()[0])
            if len(heap) > 0:
                currTaskFreq = -heapq.heappop(heap)
                if currTaskFreq > 1:
                    queue.append((currTaskFreq - 1, time + n + 1))
            time += 1
        return time