class Solution {
    public int trap(int[] height) {
        int res = 0;
        int l = 0, r = height.length - 1;
        int maxLeft = 0, maxRight = 0;
        while (l < r) {
            if (height[l] <= height[r]) {
                maxLeft = Math.max(maxLeft, height[l]);
                res += maxLeft - height[l];
                ++l;
            } else {
                maxRight = Math.max(maxRight, height[r]);
                res += maxRight - height[r];
                --r;
            }
        }
        return res;
    }
}
