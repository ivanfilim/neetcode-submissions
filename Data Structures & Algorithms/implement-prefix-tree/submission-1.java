class PrefixTree {

    private static class Node {
        final char val;
        final List<Node> children;
        boolean end;

        Node(char val) {
            this.val = val;
            this.children = new ArrayList<>();
            end = false;
        }
    }

    final Node root;

    public PrefixTree() {
        root = new Node('_');
    }

    public void insert(String word) {
        Node currNode = root;
        lettersLoop: for (int i = 0; i < word.length(); ++i) {
            char currLetter = word.charAt(i);
            for (Node child: currNode.children) {
                if (child.val == currLetter) {
                    currNode = child;
                    continue lettersLoop;
                }
            }
            Node newChild = new Node(currLetter);
            currNode.children.add(newChild);
            currNode = newChild;
        }
        currNode.end = true;
    }

    public boolean search(String word) {
        Node currNode = root;
        lettersLoop: for (char c: word.toCharArray()) {
            for (Node child: currNode.children) {
                if (child.val == c) {
                    currNode = child;
                    continue lettersLoop;
                }
            }
            return false;
        }
        return currNode.end;
    }

    public boolean startsWith(String prefix) {
        Node currNode = root;
        lettersLoop: for (char c: prefix.toCharArray()) {
            for (Node child: currNode.children) {
                if (child.val == c) {
                    currNode = child; 
                    continue lettersLoop;
                }
            }
            return false;
        }
        return true;
    }
}
