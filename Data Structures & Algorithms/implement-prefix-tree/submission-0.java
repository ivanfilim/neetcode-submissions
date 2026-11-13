class PrefixTree {
    final Set<String> set = new HashSet<>();

    public PrefixTree() {
         
    }

    public void insert(String word) {
        set.add(word);
    }

    public boolean search(String word) {
        return set.contains(word);
    }

    public boolean startsWith(String prefix) {
        return set.stream().anyMatch(word -> word.startsWith(prefix));
    }
}
