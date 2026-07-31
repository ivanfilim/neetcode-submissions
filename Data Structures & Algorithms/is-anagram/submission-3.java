class Solution {
    public boolean isAnagram(String s, String t) {
        boolean v = s.length() == t.length();
        int i = 0;
        var letters = new int[26];
        while (v && i < s.length()) {
            letters[s.charAt(i) - 'a'] += 1;
            letters[t.charAt(i) - 'a'] -= 1;
            i++;
        }
        return v && Arrays.equals(letters, new int[26]);
    }
}
