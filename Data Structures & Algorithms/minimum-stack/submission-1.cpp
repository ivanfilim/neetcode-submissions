class MinStack {
    struct node {
        int n;
        node* prev;

        node(int v, node* p) {
            n = v;
            prev = p;
        }
    };

    node* top_node = nullptr;
    set<int> all_nums;
    map<int, int> nums_to_freq;
public:
    MinStack() = default;

    void push(const int val) {
        if (top_node == nullptr) {
            top_node = new node(val, nullptr);
        } else {
            top_node = new node(val, top_node);
        }
        if (nums_to_freq.find(val) == nums_to_freq.end()) {
            nums_to_freq[val] = 1;
            all_nums.insert(val);
        } else {
            ++nums_to_freq[val];
        }
    }

    void pop() {
        if (top_node != nullptr) {
            const int val = top_node->n;
            const node* to_delete = top_node;
            top_node = top_node->prev;
            delete to_delete;
            --nums_to_freq[val];
            if (nums_to_freq[val] == 0) {
                nums_to_freq.erase(val);
                all_nums.erase(val);
            }
        }
    }

    int top() {
        if (top_node != nullptr) {
            return top_node->n;
        }
        throw runtime_error("Empty stack!");
    }

    int getMin() {
        if (!all_nums.empty()) {
            return *all_nums.begin();
        }
        throw runtime_error("Empty stack!");
    }
};