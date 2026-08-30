class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
int n = nums.size();
    long long result = INT_MIN;
    for (int i=0; i< n; i++) {
        for (int j=i+1;j<n; j++ ) {
            long long gcd1 = gcd(nums[i], nums[j]);
result = max((1LL * nums[i] * nums[j]) / (gcd1 * gcd1), result);
        }
    }
    return result;
    }
};