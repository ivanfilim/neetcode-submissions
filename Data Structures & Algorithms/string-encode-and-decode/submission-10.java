class Solution {
    private static String delimiter = "#";

    public String encode(List<String> strs) {
        return strs.stream()
            .map(str -> str.length() + delimiter + str)
            .collect(Collectors.joining());
    }

    public List<String> decode(String str) {
        final List<String> res = new ArrayList<>();
        int i = 0;
        while (i < str.length()) {
            int delimiterIdx = str.indexOf(delimiter, i);
            int length = Integer.parseInt(str.substring(i, delimiterIdx));
            i = delimiterIdx + 1 + length;
            res.add(str.substring(delimiterIdx + 1, i));
        }
        return res;
    }
}
