class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    int low = 0, high = 0, res = INT_MAX, n = nums.size(), sum = 0;
    while(high<n){
        sum = sum + nums[high];

        while(sum>=target){
            int len = high -low +1;
            res = min(res, len);
            sum = sum-nums[low];
            low++;
        }
        high++;
    }
    if (low == 0)
    {
        return 0;
    }
    return res;
}
};