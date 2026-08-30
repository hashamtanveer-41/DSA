class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxEnding = nums[0];
        int minEnding = nums[0];
        int res = nums[0];

        for(int i = 1; i<nums.size(); i++){
            int v1 = nums[i];
            int v2 = maxEnding*nums[i];
            int v3 = minEnding*nums[i];
            minEnding = min(v1, min(v2, v3));
            maxEnding = max(v1, max(v2, v3));
            res = max(res, max(minEnding, maxEnding));
        }
        return res;
    }
};