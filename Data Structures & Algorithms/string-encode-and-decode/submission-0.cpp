class Solution {
public:

    string encode(const vector<string>& strs) {
        string result = "";
        for (const string& str: strs) {
            result += to_string(str.size()) + "_" + str;
        }
        return result;
    }

    vector<string> decode(const string& s) {
        vector<string> result;
        string length;
        for (int i = 0; i < s.length(); i++) {
            const char curr_char = s[i];
            if ((curr_char < '0' || curr_char > '9') && curr_char != '_') {
                throw runtime_error("Invalid character '" + to_string(curr_char) + "'");
            }
            if (curr_char == '_') {
                const int curr_str_len = stoi(length);
                result.push_back(s.substr(i + 1, curr_str_len));
                
                i += curr_str_len;
                length = "";
            } else {
                length += curr_char;
            }
        }
        return result;
    }
    
};
