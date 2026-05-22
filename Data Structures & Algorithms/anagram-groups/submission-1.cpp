class Solution {
    vector<int> arrayByString(const string& str) {
        vector<int> arr;
        for (int i = 0; i < 26; ++i) {
            arr.push_back(0);
        }
        for (char c: str) {
            ++arr[c - 'a'];
        }
        return arr;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> result_map;
        for (string str: strs) {
            auto arr = arrayByString(str);
            if (result_map.find(arr) == result_map.end()) {
                result_map[arr] = { str };
            } else {
                result_map[arr].push_back(str);
            }
        }
        vector<vector<string>> result;
        for (const auto& [k, v] : result_map) {
            result.push_back(v);
        }
        return result;
    }
};
