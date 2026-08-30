class Solution {
public:

vector<vector<string>> groupAnagrams(vector<string>& strs) {
   unordered_map<string, vector<string>> anagramMap;
    
    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end()); // Sort the string to create the key
        anagramMap[key].push_back(s); // Group the original string under this key
    }
    
    vector<vector<string>> result;
    for (auto pair : anagramMap) {
        result.push_back(pair.second);
    }
    
    return result;
    }
};