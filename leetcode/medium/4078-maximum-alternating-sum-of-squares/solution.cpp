class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            nums[i] = nums[i]*nums[i];
        }
        int k = n/2;
        nth_element(nums.begin(), nums.begin() + k, nums.end());
        long long res = 0;
        for(int i=0; i<k; i++){
            res -= nums[i];
        }
        for(int i=k; i<n; i++){
            res += nums[i];
        }
        return res;
    }
};