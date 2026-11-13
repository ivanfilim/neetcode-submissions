class WordDictionary {
    private final Node root;

    public WordDictionary() {
        root = new Node();    
    }
    
    public void addWord(String word) {
        Node currNode = root;
        for (int i = 0; i < word.length(); ++i) {
            int idx = word.charAt(i) - 'a';
            if (currNode.children[idx] == null) {
                currNode.children[idx] = new Node();
            }
            currNode = currNode.children[idx];
        }
        currNode.end = true;
    }
    
    public boolean search(String word) {
        return search(word, 0, root);
    }

    private boolean search(String word, int position, Node root) {
        Node currNode = root;
        for (int i = position; i < word.length(); ++i) {
            int currChar = word.charAt(i);
            if (currChar == '.') {
                for (int j = 0; j < 26; ++j) {
                    if (currNode.children[j] == null) {
                        continue;
                    }
                    if (search(word, i + 1, currNode.children[j])) {
                        return true;
                    }
                }
                return false;
            } else {
                int idx = currChar - 'a';
                if (currNode.children[idx] == null) {
                    return false;
                }
                currNode = currNode.children[idx];
            }
        }
        return currNode.end;
    }

    private static class Node {
        final Node[] children = new Node[26];
        boolean end = false;
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */