struct StackEl {
    int val;
    StackEl* prev;

    StackEl(int val, StackEl* prev) {
        this->val = val;
        this->prev = prev;
    }
};

class MinStack {
    set<int> all_vals;
    map<int, int> vals_with_frequencies;

    StackEl* top_el;
public:
    MinStack() {
        top_el = 0;
    }
    
    void push(int val) {
        if (all_vals.find(val) != all_vals.end()) {
            ++vals_with_frequencies[val];
        } else {
            vals_with_frequencies[val] = 1;
            all_vals.insert(val);
        }
        top_el = new StackEl(val, top_el);
    }
    
    void pop() {
        if (top_el == 0) {
            throw runtime_error("Method 'pop' is called on an empty stack!");
        }
        StackEl* to_delete = top_el;
        int val_to_delete = to_delete->val; 
        if (--vals_with_frequencies[val_to_delete] == 0) {
            vals_with_frequencies.erase(val_to_delete);
            all_vals.erase(val_to_delete);
        }
        top_el = top_el->prev;
        delete to_delete;
    }
    
    int top() {
        if (top_el != 0) {
            return top_el->val;
        }
        throw runtime_error("Method 'top' is called on an empty stack!");
    }
    
    int getMin() {
        if (all_vals.empty()) {
            throw runtime_error("Method 'getMin' is called on an empty stack!");
        }
        return *all_vals.begin();
    }
};
