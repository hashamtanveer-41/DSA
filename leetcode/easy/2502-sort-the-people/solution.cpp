class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    unordered_map<int, string > freq;
    int n = names.size();
    for (int i=0; i<n; i++)
        freq[heights[i]] = names[i];

    vector<string> res;
    sort(heights.begin(), heights.end());
    reverse(heights.begin(), heights.end());
    for (int i=0; i<n; i++) {
        auto var = freq.find(heights[i]);
        res.push_back(var->second);
    }
    return res;
}
};