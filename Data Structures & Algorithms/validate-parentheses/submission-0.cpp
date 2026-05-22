class Solution {
public:
    bool isValid(const string& str) {
        stack<char> s;
        for (char c: str) {
            if (c == '(' || c == '{' || c == '[') {
                s.push(c);
            } else if (s.empty()) {
                return false;
            } else if (c == ')' && s.top() != '(') {
                return false;
            } else if (c == '}' && s.top() != '{') {
                return false;
            } else if (c == ']' && s.top() != '[') {
                return false;
            } else {
                s.pop();
            }
        }
        return s.empty();
    }
};
