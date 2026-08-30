class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        unordered_map<int, int> freq;
    for (int n: nums)freq[n]++;
    int i=lower;
    vector<vector<int>> res;
    while (i<=upper) {
        if (freq.find(i)==freq.end()) {
            // Element is missing
            int start = i;
            while (freq.find(++i)==freq.end() && i<=upper) {}
            // Either my i will reach end or an correct number which is not missing but the number previous to it
            // was missing
            i--;
            res.push_back({start, i});
        }
        i++;
    }
        return res;
    }
};