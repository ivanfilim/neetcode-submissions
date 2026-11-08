/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public Node cloneGraph(Node node) {
        if (node == null) return null;
        return clone(node, new HashMap<>());
    }

    private Node clone(Node node, Map<Node, Node> cloned) {
        Node newNode = new Node(node.val);
        cloned.put(node, newNode);
        for (Node neighbor: node.neighbors) {
            if (cloned.containsKey(neighbor)) {
                newNode.neighbors.add(cloned.get(neighbor));
            } else {
                newNode.neighbors.add(clone(neighbor, cloned));
            }
        }
        return newNode;
    }
}