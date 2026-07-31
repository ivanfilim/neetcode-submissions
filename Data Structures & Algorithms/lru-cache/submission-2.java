class LRUCache {

    private int capacity;
    

    private static class Node {
    Node prev, next;
    int key, val;
    Node(Node prev, Node next, int key, int val) {
        this.prev = prev;
        this.next = next;
        this.key = key;
        this.val = val;
    }

    }
    private Node head, tail;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.head = new Node(null, null, 0, 0);
        this.tail = new Node(head, null, 0, 0);
        this.head.next = this.tail;
    }

    private final Map<Integer, Node> m = new HashMap<>();
    
    public int get(int key) {
        if (!m.containsKey(key)) return -1;
        var n = m.get(key);
        n.prev.next = n.next;
        n.next.prev = n.prev;
        n.next = head.next;
        head.next.prev = n;
        n.prev = head;
        head.next = n;
        return n.val;
    }
    
    public void put(int key, int value) {
        if (m.containsKey(key)) {
            var n = m.get(key);
            n.prev.next = n.next;
            n.next.prev = n.prev;
            n.next = head.next;
            head.next.prev = n;
            n.prev = head;
            head.next = n;
            head.next.val = value;
            return;
        }
        if (m.size() == capacity) {
            m.remove(tail.prev.key);
            tail.prev.prev.next = tail;
            tail.prev = tail.prev.prev;
        }
        var n = new Node(head, head.next, key, value);
        head.next.prev = n;
        head.next = n;
        m.put(key, n);
    }
}
