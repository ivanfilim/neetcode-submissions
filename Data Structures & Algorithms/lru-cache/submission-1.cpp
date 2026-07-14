class LRUCache {
    struct Node {
        int key, val;
        Node *prev, *next;

        Node(Node* prev, int key, int val, Node* next) : prev(prev), key(key), val(val), next(next) {}
    };

    int capacity;
    map<int, Node*> kvp;
    Node *begin, *end;

    void evictLeastUsed() {
        Node* toDelete = end;
        if (begin == end) {
            begin = nullptr;
            end = nullptr;
        } else {
            end = end -> prev;
            end -> next = nullptr;
        }
        kvp.erase(toDelete -> key);
        delete toDelete;
    }

    void touch(int key) {
        Node* node = kvp[key];
        if (node == begin) {
            return;
        }
        if (node == end) {
            end = node -> prev;
        }
        if (node -> prev) {
            node -> prev -> next = node -> next;
        }
        if (node -> next) {
            node -> next -> prev = node -> prev;
        }
        node -> prev = nullptr;
        node -> next = begin;
        begin -> prev = node;
        begin = node;
    }

public:
    LRUCache(int capacity) : begin(nullptr), end(nullptr) {
        this -> capacity = capacity;
    }
    
    int get(int key) {
        if (kvp.find(key) == kvp.end()) {
            return -1;
        }
        touch(key);
        return kvp[key] -> val;
    }
    
    void put(int key, int value) {
        if (kvp.find(key) != kvp.end()) {
            kvp[key] -> val = value;
            touch(key);
            return;
        }
        if (static_cast<int>(kvp.size()) == capacity) {
            evictLeastUsed();
        }
        kvp[key] = new Node(nullptr, key, value, begin);
        if (begin) {
            begin -> prev = kvp[key];
        } else {
            end = kvp[key];
        }
        begin = kvp[key];
    }
};
