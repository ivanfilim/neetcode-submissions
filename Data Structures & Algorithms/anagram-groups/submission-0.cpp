class Solution {
    map<char, int> createMapByString(const string& str) {
        map<char, int> m;
        for (char c: str) {
            if (m.find(c) == m.end()) {
                m[c] = 1;
            } else {
                ++m[c];
            }
        }
        return m;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> anagrams_map;
        for (string str: strs) {
            map<char, int> curr_map = createMapByString(str);
            if (anagrams_map.find(curr_map) == anagrams_map.end()) {
                anagrams_map[curr_map] = {str};
            } else {
                anagrams_map[curr_map].push_back(str);
            }
        }
        vector<vector<string>> result;
        for (const auto& [k, v] : anagrams_map)
            result.push_back(v);
        return result;
    }
};