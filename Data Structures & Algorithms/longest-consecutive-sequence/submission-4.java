class Solution {
    public int longestConsecutive(int[] nums) {
        final Set<Integer> unique = new HashSet<>();
        for (int n: nums) {
            unique.add(n);
        }
        int res = 0;
        for (int n: unique) {
            if (unique.contains(n - 1))
                continue;
            int currElem = n;
            int currLength = 1;
            while (unique.contains(++currElem)) {
                currLength++;
            }
            res = Math.max(res, currLength);
        }
        return res;
    }
}