class Solution {
public:
    int missingNumber(vector<int>& nums) {
    unordered_map<int, int> freq;
    int n = nums.size();
    for (int i=0; i<n; i++) freq[nums[i]]++;
    int res = 0;
    for (int i=0; i<=n; i++) {
        if (freq.find(i)==freq.end()) res = i;
    }
    return res;
}
};