class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        int res = 0;
        for(int num: nums){
            res += maxVal - num;
        }
        return res;
    }
};