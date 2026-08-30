class Solution {
public:
   int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int n = nums.size();
    int left =0, right = 0, ans = 0, currMul = 1;
    while (left<n) {
        if (right == n) {
            currMul = 1;
            left++;
            right = left;
            continue;
        }
        currMul *= nums[right];
        if (currMul<k) {
            ans++;
            right++;
        }else {
            currMul = 1;
            left++;
            right = left;
        }
    }
    return ans;
}
};