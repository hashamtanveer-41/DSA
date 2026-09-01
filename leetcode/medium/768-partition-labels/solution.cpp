class Solution {
public:
    vector<int> partitionLabels(string s) {
       int n = s.size();
    unordered_map<char, int> mp;
    for (int i =0; i<n; i++)
        mp[s[i]]= i;
    vector<int> res;
    int start = 0;
    int end = 0;
    for (int i =0; i<n; i++) {
        end = max(end, mp[s[i]]);
        if (i == end) {
            int len = end - start +1;
            start = end+1;
            res.push_back(len);     
        }
    }
    return res;
    }
};