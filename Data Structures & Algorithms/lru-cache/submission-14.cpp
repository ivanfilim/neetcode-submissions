class LRUCache {
    struct Node {
        Node* prev;
        int key;
        int value;
        Node* next;

        Node(Node* prev, int key, int value, Node* next) {
            this->prev = prev;
            this->key = key;
            this->value = value;
            this->next = next;
        }
    };

    int capacity;
    map<int, Node*> m;
    Node* head;
    Node* tail;

    void insertToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        
        head->next->prev = node;
        head->next = node;
    }

    void touch(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        insertToHead(node);
    }
public:
    LRUCache(int capacity): capacity(capacity), m() {
        head = new Node(nullptr, 0, 0, nullptr);
        tail = new Node(head, 0, 0, nullptr);
        head->next = tail;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        auto node = m[key];
        touch(node);
        return node->value;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            m[key]->value = value;
            touch(m[key]);
            return;
        }
        if (static_cast<int>(m.size()) == capacity) {
            auto evictedNode = tail->prev;
            evictedNode->prev->next = tail;
            tail->prev = evictedNode->prev;
            m.erase(evictedNode->key);
            delete evictedNode;
        }
        auto node = new Node(nullptr, key, value, nullptr);
        insertToHead(node);
        m[key] = node;
    }
};
