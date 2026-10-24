class Solution {
    private static final String delimiter = "#";

    public String encode(List<String> strs) {
        return strs.stream()
            .map(str -> str.length() + delimiter + str)
            .collect(Collectors.joining());
    }

    public List<String> decode(String str) {
        final List<String> res = new ArrayList<>();
        while (!str.isEmpty()) {
            int delimiterIdx = str.indexOf(delimiter);
            int length = Integer.parseInt(str.substring(0, delimiterIdx));
            int nextStrStart = delimiterIdx + 1 + length;
            res.add(str.substring(delimiterIdx + 1, nextStrStart));
            str = str.substring(nextStrStart);
        }
        return res;
    }
}
