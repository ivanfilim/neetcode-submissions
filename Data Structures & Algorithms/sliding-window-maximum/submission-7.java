class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        final int[] res = new int[nums.length - k + 1];
        final Deque<Integer> deque = new ArrayDeque<>();
        int l = 0, r = 0;
        while (r < nums.length) {
            while (!deque.isEmpty() && nums[deque.getLast()] < nums[r]) {
                deque.removeLast();
            }
            deque.addLast(r);
            if (r >= k - 1) {
                res[r - k + 1] = nums[deque.getFirst()];
                ++l;
            }
            if (l > deque.getFirst()) {
                deque.removeFirst();
            }
            ++r;
        }
        return res;
    }
}
