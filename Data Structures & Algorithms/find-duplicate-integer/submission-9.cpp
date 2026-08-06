class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        int newSlow = 0;
        while (slow != newSlow) {
            slow = nums[slow];
            newSlow = nums[newSlow];
        }
        return slow;
    }
};
