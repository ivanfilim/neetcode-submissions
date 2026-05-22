class MinStack {
    stack<int> s;
    vector<int> min_vals;
public:
    MinStack() {}
    
    void push(int val) {
        if (min_vals.empty() || min_vals.back() > val) {
            min_vals.push_back(val);
        } else {
            min_vals.push_back(min_vals.back());
        }
        s.push(val);
    }
    
    void pop() {
        s.pop();
        min_vals.pop_back();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_vals.back();
    }
};
