class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
   int n = nums.size(), maxLen =0 ;
    unordered_set<int> freq(nums.begin(), nums.end());
    for (int i : freq) {
        if (!freq.count(i-1)) {
            int currLen = 1;
            while (freq.count(i+1)) {
                currLen++;
                i++;
            }
            maxLen = max(currLen, maxLen);
        }
    }
    return maxLen;
}
};