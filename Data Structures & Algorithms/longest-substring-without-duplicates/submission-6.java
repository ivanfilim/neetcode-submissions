class Solution {
    public int lengthOfLongestSubstring(String s) {
        int res = 0;
        int l = 0;
        final Set<Character> unique = new HashSet<>();
        for (int r = 0; r < s.length(); ++r) {
            char currChar = s.charAt(r);
            while (unique.contains(currChar)) {
                unique.remove(s.charAt(l));
                ++l;
            }
            unique.add(currChar);
            res = Math.max(res, r - l + 1);
        }
        return res;
    }
}