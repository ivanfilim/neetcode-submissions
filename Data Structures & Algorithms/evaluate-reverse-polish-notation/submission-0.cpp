class Solution {
public:
    int evalRPN(const vector<string>& tokens) {
        stack<string> s;
        for (string token: tokens) {
            if (token != "+" &&
                token != "-" &&
                token != "*" &&
                token != "/") {
                s.push(token);
            } else {
                int b = stoi(s.top());
                s.pop();
                int a = stoi(s.top());
                s.pop();
                int res;
                if (token == "+") {
                    res = a + b;
                } else if (token == "-") {
                    res = a - b;
                } else if (token == "*") {
                    res = a * b;
                } else {
                    res = a / b;
                }
                s.push(to_string(res));
            }
        }
        return stoi(s.top());
    }
};
