class LRUCache:
    class Node:
        def __init__(self, prev, key, value, next):
            self.prev = prev
            self.key = key
            self.value = value
            self.next = next

    def insertToHead(self, node):
        self.head.next.prev = node
        node.next = self.head.next
        self.head.next = node
        node.prev = self.head

    def touch(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev
        self.insertToHead(node)

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.head = self.Node(None, 0, 0, None)
        self.tail = self.Node(self.head, 0, 0, None)
        self.head.next = self.tail
        self.map = {}

    def get(self, key: int) -> int:
        if key not in self.map:
            return -1
        self.touch(self.map[key])
        return self.map[key].value

    def put(self, key: int, value: int) -> None:
        if key in self.map:
            self.map[key].value = value
            self.touch(self.map[key])
            return
        if len(self.map) == self.capacity:
            del self.map[self.tail.prev.key]
            self.tail.prev.prev.next = self.tail
            self.tail.prev = self.tail.prev.prev
        node = self.Node(None, key, value, None)
        self.map[key] = node
        self.insertToHead(node)