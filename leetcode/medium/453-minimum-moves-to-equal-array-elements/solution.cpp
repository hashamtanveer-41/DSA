class Solution {
public:
    int minMoves(vector<int>& nums) {
    int small = *min_element(nums.begin(), nums.end());
    int res =0;
    for(int val: nums)
        res+=(val-small);
    
    return res;
    }
};