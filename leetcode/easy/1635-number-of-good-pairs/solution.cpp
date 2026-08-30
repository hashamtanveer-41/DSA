class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int i: nums) freq[i]++;
    int res=0;
    for (auto i: freq) {
        int n = i.second;
        if (n>=2) {
            int goodPairs = (n*(n-1))/2;
            res += goodPairs;
        }
    }
    return res;
}
};