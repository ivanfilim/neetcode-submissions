class MinStack {
    struct pair {
        int left;
        int right;
        pair(int l, int r) {
            left = l;
            right = r;
        }
    };

    struct node {
        int n;
        node* prev;
        node(int v, node* p) {
            n = v;
            prev = p;
        }
    };

    node* top_node = nullptr;
    vector<pair> nums_to_min;
public:
    MinStack() = default;

    void push(const int val) {
        if (top_node == nullptr) {
            top_node = new node(val, nullptr);
            nums_to_min.push_back(pair(val, val));
        } else {
            int last_min = nums_to_min.back().right;
            if (val < last_min) {
                nums_to_min.push_back(pair(val, val));
            } else {
                nums_to_min.push_back(pair(val, last_min));
            }
            top_node = new node(val, top_node);
        }
    }

    void pop() {
        if (top_node != nullptr) {
            const node* to_delete = top_node;
            top_node = top_node->prev;
            delete to_delete;
            nums_to_min.pop_back();
        }
    }

    int top() {
        if (top_node != nullptr) {
            return top_node->n;
        }
        throw runtime_error("Empty stack!");
    }

    int getMin() {
        if (!nums_to_min.empty()) {
            return nums_to_min.back().right;
        }
        throw runtime_error("Empty stack!");
    }
};